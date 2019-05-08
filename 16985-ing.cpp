/*16985번 Maaaaaaaaaze*/
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
struct Pnt { int r, c, h; }temp;
int Cube[5][5][5];//r,c,h
int final_cube[5][5][5];
int visit[5][5][5];
int reset[5][5][5];
int spin_flag[5];//0:0도 1:90도 2:180도 3: 270도
int plate_order[5];
int drch[6][3] = { {1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1} };
int Min_d = 1e9;

int BFS() {
	queue<Pnt>Q;
	temp = { 0,0,0 };
	Q.push(temp);
	visit[0][0][0] = 1;
	int min_dis = 0;
	while (!Q.empty()) {
		int rrr = Q.front().r;
		int ccc = Q.front().c;
		int hhh = Q.front().h;
		Q.pop();
		for (int d = 0; d < 6; d++) {
			int nr = rrr + drch[d][0];
			int nc = ccc + drch[d][1];
			int nh = hhh + drch[d][2];
			if (!(nr < 0 || nc < 0 || nh < 0 || nr >= 5 || nc >= 5 || nh >= 5)) {
				if (visit[nr][nc][nh] == 0) {
					visit[nr][nc][nh] = 1;
					temp = { nr,nc,nh };
					Q.push(temp);
					min_dis++;
					if (nr == 4 && nc == 4 && nh == 4) {
						return min_dis;
					}
				}
			}
		}
	}

}

void stack_cube(int n) {
	if (n > 5) {
		for (int h = 0; h < 5; h++) {
			int put_height = plate_order[h];
			for (int r = 0; r < 5; r++) {
				for (int c = 0; c < 5; c++) {
					final_cube[h][r][c] = Cube[put_height][r][c];
				}
			}
		}
		if (final_cube[0][0][0] != 1 && final_cube[4][4][4] != 1) {
			int BFS_result = BFS();
			if (BFS_result <= Min_d) {
				Min_d = BFS_result;
			}
			memcpy(visit, reset, sizeof(reset));//visit 초기화
		}
	}
	else {
		for (int i = n - 1; i < 5; i++) {
			plate_order[i] = n;
			stack_cube(n + 1);
			plate_order[i] = 0;
		}
	}
}

void spin_plate() {
	for (int h = 0; h < 5; h++) { // 0이 맨위
		int spin = spin_flag[h];
		switch (spin)
		{
		case 1:
			for (int r = 0; r < 5; r++) {
				for (int c = 0; c < 5; c++) {
					Cube[h][r][c] = Cube[h][c][4 - r];
				}
			}
			break;
		case 2:
			for (int r = 0; r < 5; r++) {
				for (int c = 0; c < 5; c++) {
					Cube[h][r][c] = Cube[h][4 - c][4 - r];
				}
			}
			break;
		case 3:
			for (int r = 0; r < 5; r++) {
				for (int c = 0; c < 5; c++) {
					Cube[h][r][c] = Cube[h][4 - c][r];
				}
			}
			break;
		}
	}

	stack_cube(1);
}
void spin_comb(int n) {
	if (n == 5) {
		int backup_cube[5][5][5];
		memcpy(backup_cube, Cube, sizeof(Cube));
		spin_plate();
		memcpy(Cube, backup_cube, sizeof(Cube));
	}
	else {
		for (int i = 0; i < 4; i++) {
			int backup = spin_flag[n];
			spin_flag[n] = i;
			spin_comb(n + 1);
			spin_flag[n] = backup;
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int h = 0; h < 5; h++) {
		for (int r = 0; r < 5; r++) {
			for (int c = 0; c < 5; c++) {
				cin >> Cube[h][r][c];
			}
		}
	}
	
	spin_comb(0);
	if (Min_d < 1e9) {
		cout << Min_d;
	}
	else
		cout << -1;
}
/*
1. 5개의 판 회전 회전 규칙 << 0도:(r,c) 90도:(c,4-r) 180도:(4-r,4-c) 270도:(4-c,r) >> 
2. 판의 회전은 중복이 허락된 조합으로 구함 4^5
3. 각 판들을 쌓을 순서를 구함 5!
4. 다 쌓으면 3차원BFS이용해서 답을 구한다.
*/
/*15684번 사다리 조작*/
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int N, M, H, a, b;
int bridge_cnt;
int Map[32][20];
int visit[32][20];
struct Pnt { int r, c; bool match; }start[11], temp;
bool success_flag;
queue<Pnt>Q, Backup;

void Print_ladder() {
	cout << "  ";
	for (int c = 0; c < N * 2; c++) {
		if (c % 2 == 1) {
			cout << c / 2 + 1 << "   ";
		}
	}
	cout << endl;
	cout << "------------------------------------";
	cout << endl;
	for (int r = 0; r <= H + 1; r++) {
		for (int c = 0; c < N * 2; c++) {
			cout << Map[r][c] << ' ';
		}
		cout << endl;
	}
	cout << "------------------------------------" << endl;
}


bool game_start() {
	for (int i = 1; i <= N; i++) {
		int rr = start[i].r;
		int cc = start[i].c;
		while (1) {
			if (Map[rr][cc - 1] == 1 || Map[rr][cc + 1] == 1) {
				if (Map[rr][cc - 1] == 1) {
					cc = cc - 2;
					rr++;
				}
				else if (Map[rr][cc + 1] == 1){
					cc = cc + 2;
					rr++;
				}
			}
			else {
				rr++;
			}
			if (rr == H+1) {
				if (cc == start[i].c) {
					break;
				}
				//중간에 하나라도 결과가 잘못됬을 때,
				else return false;
			}
		}
	}
	//모든 사다리의 결과가 옳을 때,
	return true;
} 
void Add_bridge(int n,int cnt) { //다리 놓을 떄 가로선 연속되면 안됨
	if (n == cnt) {
		Print_ladder();
		//성공 여부를 확인 성공하면 true반환 실패하면 false 반환
		if (game_start() == true) {
			success_flag = true;
		}
	}
	else {
		for (int r = 1; r <= H; r++) {
			for (int c = 1; c < N * 2; c++) {
				if (c % 2 == 0 && Map[r][c] == 0&&visit[r][c]==0) {
					if (Map[r][c - 2] != 1 && Map[r][c + 2] != 1) {
						Map[r][c] = 1;
						visit[r][c] = 1;
						Add_bridge(n + 1, cnt);
						visit[r][c] = 0;
						Map[r][c] = 0;
						if (success_flag == true) {
							return;

						}
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M >> H;
	for (int i = 1; i < 11; i++) {
		start[i].c = i * 2 - 1;
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		Map[a][b * 2] = 1;
	}
	for (int r = 0; r <= H+1; r++) {
		for (int c = 1; c < N*2; c++) {
			if (c % 2 == 1) {
				Map[r][c] = 1;
			}
			if (r == a && b * 2 == c) {
				Map[r][c] = 1;
			}
		}
	}
	int cnt = 0;
	//Print_ladder();
	while (cnt < 4) {
		Add_bridge(0, cnt);
		if (success_flag == true) {
			break;
		}
		cnt++;
	}
	if (cnt <= 3) {
		cout << cnt;
	}
	else cout << -1;
}
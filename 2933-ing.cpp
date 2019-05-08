/*2933번 미네랄*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;
<<<<<<< HEAD
int R, C, N, throw_line;
string Map[101];
string visit[101];
int drc[] = { 0,0,-1,1,-1,1,0,0 };
int throw_arr[100];
struct Pnt { int r, c; }temp;
queue<Pnt>cluster;

void print_Map() {
	for (int r = 0; r < R; r++) cout << Map[r] << '\n';
}

void Drop() {

}

void BFS() {

}

void cluster_chk(int row,int cal) {
	if (Map[row][cal] == 'x') {
		Map[row][cal] == '.';
	}
	for (int d = 0; d < 4; d++) {
		int nr = row + drc[d];
		int nc = cal + drc[d + 4];
		if (!(nr < 0 || nr >= R || nc < 0 || nc >= C)) {
			if (Map[nr][nc] == 'x') {
				temp = { nr,nc };
				cluster.push(temp);
			}
		}
	}
}
void shot(int row,int dir) {
	//dir==1 : 왼 >> 오, dir==2 : 왼 << 오
	if (dir == 1) {
		for (int c = 0; c < C; c++) {
			cluster_chk(row, c);
		}
	}
	else {
		for (int c = C - 1; c >= 0; c--) {
			cluster_chk(row, c);
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		cin >> Map[r];
	}
	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> throw_line;
		if (n % 2 == 0) shot(throw_line, 1);
		else shot(throw_line, 2);
	}
}

/*
1. 미네랄 제거
2-1. 제거된 미네랄의 클러스터 부터 BFS를 해서 1층에 도달 하는지 확인
2-2. 1층에 도달하지 못하면 해당 클러스터 따로 저장, 도달하면 다른 클러스터 BFS
3-1. 1층에 도달하지 못한 클러스터가 존재하는 영역의 미네랄들을 Drop
3-2. Drop은 해당 영억의 최하단이 x나 맵의 최하층에 도달할 때 까지 진행 (열 단위로 진행)
4. 모든 명령이 끝날 때 까지 반복
=======
string Map[101];
int visit[101][101];
struct Pnt { int r, c; }temp;
queue<Pnt>Q;
int throw_stick[101];
int R, C, N, throw_hight;
int drc[] = { 0,0,-1,1,-1,1,0,0 };
int BFS() { // 바닥을 만나면 1반환
	while (!Q.empty()) {
		int rr = Q.front().r;
		int cc = Q.front().c;
		visit[rr][cc] = 1;
		Q.pop();
		for (int d = 0; d < 4; d++) {
			int nr = rr + drc[d];
			int nc = cc + drc[d + 4];
			
		}
	}
}
void fall() {

}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		cin >> Map[i];
	}
	cin >> N;
	for (int i = 1; i <= N; i++) {
		//cin >> throw_stick[i];
		cin >> throw_hight;
		if (i % 2 == 1) {//왼>오
			for (int c = 0; c < C; c++) {
				int rrr = R - throw_hight + 1;
				if (Map[rrr][c]=='x') {
					Map[rrr][c] = '.';

					for (int d = 0; d < 4; d++) {
						int nr = rrr + drc[d];
						int nc = c + drc[d + 4];
						if (!(nr<1 || nr>R || nc<1 || nc>C) && Map[nr][nc] == 'x') {
							temp = { nr,nc };
							Q.push(temp);
							if (BFS() != 1) {
								fall();
							}
						}
					}
					

				}
			}
		}
		else {//오>왼

		}
	}
}
/*
풀이과정
1.막대를 양 쪽에서 번갈아 가며 던짐 (왼->오, 오->왼)
2.막대가 x를 만나면 .으로 교체 (미네랄 파괴)
3. 2에서 파괴된 곳에서 클러스터를 확인하고 그 클러스터 를 시작점으로 BFS실행
	3-1.BFS해서 최하단(바닥)에 도달하면 그 영역은 낙하를 하지않는다.
	3-2.BFS해서 최하단에 도달하지 못하면 그 영역은 낙하를 한다.
4. 낙하시 제일 낮은 높이의 미네랄을 기준으로 x또는 바닥을 만날때 까지 이동
	4-1 최하단이 움직인 만큼 나머지도 움직여줌.
>>>>>>> bcd1a3d8addd363ddb37aa17f209ac20973fb989
*/
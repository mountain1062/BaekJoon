/*2206번 벽 부수고 이동하기*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;
int N, M;//가로,세로
string input;
int Map[1001][1001], visit[1001][1001];
bool crash_chk[1001][1001];
int drc[] = { 0,0,-1,1,-1,1,0,0 };
struct Pnt { int r, c; }temp;
queue<Pnt>Q;

void BFS(){
	while (!Q.empty()) {
		int rr = Q.front().r;
		int cc = Q.front().c;
		Q.pop();
		for (int d = 0; d < 4; d++) {
			int nr = rr + drc[d];
			int nc = cc + drc[d + 4];

			if (!(0 >= nr || nr > N || 0 >= nc || nc > M)) {
				if (visit[nr][nc] == 0) {
					if (Map[nr][nc] == 0) {
						Map[nr][nc] = Map[rr][cc] + 1;
						visit[nr][nc] = 1;
						crash_chk[nr][nc] = crash_chk[rr][cc];
						temp = { nr,nc };
						Q.push(temp);
					}
					else {//벽일 때
						if (crash_chk[rr][cc] == 0) {
							Map[nr][nc] = Map[rr][cc] + 1;
							visit[nr][nc] = 1;
							crash_chk[nr][nc] = 1;
							temp = { nr,nc };
							Q.push(temp);
						}
					}

					if (nr == N && nc == M) {
						return;
					}
				}
				else {//방문한곳일 때
					if (crash_chk[rr][cc] == 0) {//현위치 까지 상태가 벽을 부수지 않은 상태
						if (crash_chk[nr][nc] == 0) {//다음 위치 상태가 벽을 부수지 않은 상태
							if (Map[rr][cc] + 1 <= Map[nr][nc]) {
								Map[nr][nc] = Map[rr][cc] + 1;
								temp = { nr,nc };
								Q.push(temp);
							}
						}
						else {//다음 위치 상태가 벽을 부순 상태(crash_chk[nr][nc]==1)
							Map[nr][nc] = Map[rr][cc] + 1;
							crash_chk[nr][nc] = 0;
							temp = { nr,nc };
							Q.push(temp);
						}
					}
					else {//현위치 까지 상태가 벽을 부순 상태(crash_chk[rr][cc] == 1)
						if (crash_chk[nr][nc] == 1) {//다음 위치가 이미 벽을 부순상태
							if (Map[rr][cc] + 1 <= Map[nr][nc]) {
								Map[nr][nc] = Map[rr][cc] + 1;
								temp = { nr,nc };
								Q.push(temp);
							}
						}
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int r = 1; r <= N; r++) {
		cin >> input;
		for (int c = 0; c < input.size(); c++) {
			Map[r][c + 1] = input[c] - '0';
			if (Map[r][c + 1] == 1)Map[r][c + 1] = -1;
		}
	}
	temp = { 1,1 };
	Q.push(temp);
	Map[1][1] = 1;
	visit[1][1] = 1;
	BFS();
	if (Map[N][M]==0)cout << -1;
	else cout << Map[N][M];
}
/*
조건
1. 최대 벽 1개를 부술 수 있다.
2. ㅇㅇ
3. 시작점(1.1)과 도착점은 고정(N.M)
4. 최단경로는 시작점과 도착점도 포함해서 센다.
5-1. 방문하지 않았다면 벽을 부순 여부에 대한 우선순위 없이 BFS진행
5-2. 방문을 한 곳이라면 벽을 부순 여부에 대한 우선순위 적용
	벽을 부수지 않은 거리가 우선순위가 높다.
	5-2-1. 방문지역과 이전 지역의 벽을 부순 여부가 같다면 거리가 적은 쪽이 우선
	5-2-2. 방문지역과 이전 지역의 벽을 부순 여부가 다르다면 무조건 부수지 않은 쪽이 우선

과정
1.BFS를 진행하는데 방문 기록에 지나오면서 벽을 부쉈는지 체크
2.

**교수님께 질문드릴 것**
1. main 다차원 배열의 경우 전역에 선언시 메모리에 연속적으로 할당이 되는가?
*/
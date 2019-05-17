/*17135번 캐슬 디펜스*/
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int N, M, D, enemy_cnt, kill_cnt, except_cnt, Max_kill;
int Map[15][15], visit[15][15], archer[3] = { -1,-1,-1 };
int drc[] = { 0,-1,0,-1,0,1 };//(좌 상 우) 탐색
struct pnt { int r, c; }temp;
queue<pnt>Q;

void chk_kill_enemy() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (visit[r][c] != 0) {
				Map[r][c] = 0;
				kill_cnt++;//죽인적 ++
				except_cnt++;//죽거나 제외된 적 체크 변수++
				visit[r][c] = 0;//죽은 적 제거
			}
		}
	}
}

void BFS(queue<pnt>Q) {
	int distance = 1;
	if (Map[Q.front().r][Q.front().c] == 1) {
		visit[Q.front().r][Q.front().c] = 1;;
		return;
	}
	if (D == 1) return;
	while (distance<=D) {
		int rr = Q.front().r;
		int cc = Q.front().c;
		Q.pop();
		for (int d = 0; d < 3; d++) {
			int nr = rr + drc[d];
			int nc = cc + drc[d + 3];
			if (!(nr < 0 || nr >= N || nc < 0 || nc >= M)) {
				if (Map[nr][nc] == 1) {
					visit[nr][nc] = 1;
					return;
				}
				else {
					temp = { nr,nc };
					Q.push(temp);
					distance++;
				}

			}
		}
	}
}

void game() { // 게임이 끝날 때 까지 잡은 적의 수 누적
	int castle_row = N;//궁수(성) 위치
	while (except_cnt != enemy_cnt) {
		for (int i = 0; i < 3; i++) { //각 궁수들이 처지 하는 적 위치 구하기
			queue<pnt>Q;
			temp = { castle_row - 1,archer[i] };
			Q.push(temp);
			BFS(Q);
		}
		chk_kill_enemy();

		castle_row--;//궁수(성) 전진
		for (int c = 0; c < M; c++) {
			if (Map[castle_row][c] == 1) {
				except_cnt++;//성에 도착한 적을 제외
				Map[castle_row][c] = 0;//성에 도착한 적 맵에서 삭제
			}
		}
	}
}

void set_archer(int archer_cnt,int col) {
	if (archer_cnt == 3) {
		//여기서 맵 탐색 시작
		int visit_temp[15][15];
		int Map_temp[15][15];
		memcpy(visit_temp, visit, sizeof(visit));
		memcpy(Map_temp, Map, sizeof(Map));
		game();
		Max_kill = Max_kill < kill_cnt ? kill_cnt : Max_kill;//최대 킬
		//사용한 배열, 변수들 초기화
		memcpy(Map, Map_temp, sizeof(Map));
		memcpy(visit, visit_temp, sizeof(visit));
		kill_cnt = 0;
		except_cnt = 0;
		return;
	}
	else {
		for (int i = col; i < M; i++) {
			archer[archer_cnt] = i;
			set_archer(archer_cnt + 1, i + 1);
			archer[archer_cnt] = i;
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> D;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			cin >> Map[r][c];
			if (Map[r][c] == 1)enemy_cnt++;
		}
	}
	set_archer(0, 0);
	cout << Max_kill;
}
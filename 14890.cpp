/*14890번 경사로*/
#include <iostream>
using namespace std;
int Map[101][101];
bool road[101];
bool chk_list[10];
int N, L;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> L;
	
	int prev_height = 0;
	bool chk = false;//이후 L*2범위 이내에서 현재보다 높은 구역을 만나면 이전 도로 모두 사용 불가
	int same_height_cnt=0;
	bool set_able_incline = false;

	//가로로 가는길 탐색 
	for (int r = 0; r < N; r++) {
		prev_height = Map[r][0];
		same_height_cnt = 1;
		for (int c = 1; c < N; c++) {
			if (chk == true) {
				Map[r][c];
				same_height_cnt++;
				if (same_height_cnt == L * 2) chk = false;
			}
			else {
				//이전 구역과 높이가 같을 때
				if (prev_height == Map[r][c]) {
					same_height_cnt++;
				}
				//이전 구역이 현재보다 높을 때
				else if (prev_height > Map[r][c]) {
					prev_height = Map[r][c];
					same_height_cnt = 1;
					chk = true;
				}
			}
			if (same_height_cnt >= L) {
				for (int j = c; j > c - L; c--) {
					road[c] = true;
				}
			}
		}
	}
	//세로 탐색
	for (int c = 0; c < N; c++) {
		for (int r = 0; r < N; r++) {
			Map[r][c];
		}
	}
	/*
	1. 현재칸 다음칸의 높이를 확인

	*/
}
#include <iostream>
#include <queue>
using namespace std;

struct Point {
	int r, c;
}temp;
int T, M, N, K; //테스트 케이스 가로 세로 배추 개수
int Map[50][50];
int visit[50][50];
int dxy[] = { 0,0,-1,1,-1,1,0,0 };
queue<Point>Q;
int cnt;

void bfs() {
	while (!Q.empty()) {
		int r = Q.front().r;
		int c = Q.front().c;
		Q.pop();
		for (int d = 0; d < 4; d++) {
			int nr = r + dxy[d];
			int nc = c + dxy[d + 4];
			if (!(nr < 0 || nr >= M || nc < 0 || nc >= N) ) {
				if (Map[nr][nc]==1&&visit[nr][nc] == 0) {
					visit[nr][nc] = 1;
					temp.r = nr;
					temp.c = nc;
					Q.push(temp);
				}
			}
		}
		
	}

}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> M >> N >> K;
		for (int k = 0; k < K; k++) {
			int input_r, input_c;
			cin >> input_c >> input_r;
			Map[input_r][input_c] = 1;
			temp.r = input_r;
			temp.c = input_c;
			Q.push(temp);
		}	
		bfs();
		/*for (int n = 0; n < N; n++) {
			
			for (int m = 0; m < M; m++) {
				cout << Map[m][n]<<' ';
			}
			cout << "\n";
		}*/
	}
}
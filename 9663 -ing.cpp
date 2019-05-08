/*N-Queen*/
#include <iostream>
using namespace std;
int Map[15][15];
//int temp[15][15];
int N;
int output;

void Attack_range(int r, int c) {
	for (int i = 0; i <N; i++) {
		Map[r][i] = 1;
		Map[i][c] = 1;
		Map[r - i][c - i] = 1;
		Map[r + i][c - i] = 1;
		Map[r - i][c + i] = 1;
		Map[r + i][c + i] = 1;
	}
}
void put_Q(int r, int c, int q) { // q : 현재 놓인 퀸의 개수
	if (q > N) {
		output++;
//		cout << r << ' ' << c << endl;
		return;
	}
	else {
		for (int rr = 0; rr < N; rr++) {
			if()
			for (int cc = 0; cc < N; cc++) {
				if (Map[rr][cc] == 0) {
					int temp[15][15];
					memcpy(temp, Map, sizeof(temp));
					Attack_range(rr, cc);
					put_Q(rr, cc, q + 1);
					memcpy(Map, temp, sizeof(Map));
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			int temp[15][15];
			memcpy(temp, Map, sizeof(temp));
			Attack_range(r, c);
			put_Q(r, c, 2);// (r, c, Q개수)
			memcpy(Map, temp, sizeof(Map));

		}
	}
	
	cout << output;
}
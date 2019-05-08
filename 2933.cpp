///*2933�� �̳׶�*/
//#include <iostream>
//#include <string>
//#include <queue>
//using namespace std;
//string Map[101];
//int visit[101][101];
//struct Pnt { int r, c; }temp;
//queue<Pnt>Q;
//int throw_stick[101];
//int R, C, N, throw_hight;
//
//int BFS() { // �ٴ��� ������ 1��ȯ
//	while (!Q.empty()) {
//
//	}
//}
//void fall(){
//
//}
//
//int main() {
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	cin >> R >> C;
//	for (int i = 1; i <= R; i++) {
//		cin >> Map[i];
//	}
//	cin >> N;
//	for (int i = 1; i <= N; i++) {
//		cin >> throw_stick[i];
//		cin >> throw_hight;
//		if (i % 2 == 1) {//��>��
//			for (int c = 0; c < C; c++) {
//				if (Map[R - throw_hight + 1][c] == 'x') {
//					temp = { R - throw_hight + 1 ,c };
//					Q.push(temp);
//					if (BFS() != 1) {
//						fall();
//					}
//				}
//			}
//		}
//		else {//��>��
//
//		}
//	}
//}
///*
//Ǯ�̰���
//1.���븦 �� �ʿ��� ������ ���� ���� (��->��, ��->��)
//2.���밡 x�� ������ .���� ��ü (�̳׶� �ı�)
//3. 2���� �ı��� ������ Ŭ�����͸� Ȯ���ϰ� �� Ŭ������ �� ���������� BFS����
//3-1.BFS�ؼ� ���ϴ�(�ٴ�)�� �����ϸ� �� ������ ���ϸ� �����ʴ´�.
//3-2.BFS�ؼ� ���ϴܿ� �������� ���ϸ� �� ������ ���ϸ� �Ѵ�.
//4. ������ ��� ���ϴܺθ� üũ�ؼ� ���� �̵��Ÿ��� ���� �Ÿ��� ��������.
//*/


#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int r, c;
char mineral[111][111];
bool cluster[111][111];
int dx[4] = { -1, 1 , 0 , 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
	ios::sync_with_stdio(false);
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> mineral[i][j];
		}
	}
	int n;
	cin >> n;
	bool left = true;
	while (n--) {
		int height;
		cin >> height;
		height = r - height + 1;
		// del
		if (left == true) {
			for (int i = 1; i <= c; i++) {
				if (mineral[height][i] == 'x') {
					mineral[height][i] = '.';
					break;
				}
			}
		}
		else {
			for (int i = c; i >= 1; i--) {
				if (mineral[height][i] == 'x') {
					mineral[height][i] = '.';
					break;
				}
			}
		}
		left = !left;

		// check
		memset(cluster, false, sizeof(cluster));
		for (int j = 1; j <= c; j++) {
			if (mineral[r][j] == 'x') {
				queue<pair<int, int> > q;
				q.push(make_pair(r, j));
				cluster[r][j] = true;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx >= 1 && nx <= r && ny >= 1 && ny <= c) {
							if (!cluster[nx][ny] && mineral[nx][ny] == 'x') {
								cluster[nx][ny] = true;
								q.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
		}

		// down
		int down = r;
		for (int j = 1; j <= c; j++) {
			for (int i = r; i >= 1; i--) {
				if (mineral[i][j] == 'x' && cluster[i][j] == false) {
					int col_down = r - i;
					for (int k = i + 1; k <= r; k++) {
						if (cluster[k][j] == true) {
							col_down = k - i - 1;
							break;
						}
					}
					if (down > col_down) {
						down = col_down;
					}
				}
			}
		}
		for (int j = 1; j <= c; j++) {
			for (int i = r; i >= 1; i--) {
				if (i + down <= r && down != 0 && mineral[i][j] == 'x' && cluster[i][j] == false) {
					mineral[i + down][j] = mineral[i][j];
					mineral[i][j] = '.';
				}
			}
		}
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cout << mineral[i][j];
		}
		cout << '\n';
	}
	return 0;
}
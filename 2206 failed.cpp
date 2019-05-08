/*2206�� �� �μ��� �̵��ϱ�*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;
int N, M;//����,����
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
					else {//���� ��
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
				else {//�湮�Ѱ��� ��
					if (crash_chk[rr][cc] == 0) {//����ġ ���� ���°� ���� �μ��� ���� ����
						if (crash_chk[nr][nc] == 0) {//���� ��ġ ���°� ���� �μ��� ���� ����
							if (Map[rr][cc] + 1 <= Map[nr][nc]) {
								Map[nr][nc] = Map[rr][cc] + 1;
								temp = { nr,nc };
								Q.push(temp);
							}
						}
						else {//���� ��ġ ���°� ���� �μ� ����(crash_chk[nr][nc]==1)
							Map[nr][nc] = Map[rr][cc] + 1;
							crash_chk[nr][nc] = 0;
							temp = { nr,nc };
							Q.push(temp);
						}
					}
					else {//����ġ ���� ���°� ���� �μ� ����(crash_chk[rr][cc] == 1)
						if (crash_chk[nr][nc] == 1) {//���� ��ġ�� �̹� ���� �μ�����
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
����
1. �ִ� �� 1���� �μ� �� �ִ�.
2. ����
3. ������(1.1)�� �������� ����(N.M)
4. �ִܰ�δ� �������� �������� �����ؼ� ����.
5-1. �湮���� �ʾҴٸ� ���� �μ� ���ο� ���� �켱���� ���� BFS����
5-2. �湮�� �� ���̶�� ���� �μ� ���ο� ���� �켱���� ����
	���� �μ��� ���� �Ÿ��� �켱������ ����.
	5-2-1. �湮������ ���� ������ ���� �μ� ���ΰ� ���ٸ� �Ÿ��� ���� ���� �켱
	5-2-2. �湮������ ���� ������ ���� �μ� ���ΰ� �ٸ��ٸ� ������ �μ��� ���� ���� �켱

����
1.BFS�� �����ϴµ� �湮 ��Ͽ� �������鼭 ���� �ν����� üũ
2.

**�����Բ� �����帱 ��**
1. main ������ �迭�� ��� ������ ����� �޸𸮿� ���������� �Ҵ��� �Ǵ°�?
*/
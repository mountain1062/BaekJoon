/*11559�� PuyoPuyo*/
#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
struct Pnt { int r, c; }temp;
vector<Pnt> v;
queue<Pnt>Q;
string Map[12], Used_Map[12];
int visit[12][6];
int drc[] = { 0,0,1,-1,1,0 };//��,��,��
bool chaining = true;
int chain_cnt, start_he;

void BFS(int r, int c, char color) {
	temp = { r,c };
	Q.push(temp);
	while (!Q.empty()) {
		int rr = Q.front().r;
		int cc = Q.front().c;
		for (int d = 0; d < 3; d++) {
			int nr = rr + drc[d];
			int nc = cc + drc[d + 3];
			if (!(nr < 0 || nr >= 12 || nc < 0 || nc >= 6)) {
				if (visit[nr][nc] == 0 && Map[nr][nc] == color) {
					temp = { nr,nc };
					Q.push(temp);
					v.push_back(temp);
					visit[nr][nc] = 1;

				}
			}
		}
	}
	if (v.size() >= 4) {
		while (v.size() != 0) {
			Map[v.front().r][v.front().c] = '.';
			v.erase(v.begin());
		}
		chaining = true;
	}
	else
		v.clear();
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 0; i < 6; i++) cin >> Map[i];
	while (chaining == false) {//�ݺ� ���� ���� : �� ���� ���Ⱑ �Ͼ�� �ʾ��� ��
		chaining = false;
		for (int r = 0; r < 12; r++) {
			for (int c = 0; c < 6; c++) {
				if (Map[r][c] != '.') {
					BFS(r, c, Map[r][c]);
				}
			}
		}
		if (chaining == true) {
			chain_cnt++;
		}
		//�Ʒ��� ������

		//visit �ʱ�ȭ
		for (int r = 0; r < 12; r++) {
			for (int c = 0; c < 6; c++) {
				visit[r][c] = 0;
			}
		}
	}
}
/*
����
1. ��ũ��� 12*6 ����
2. 4���̻� �̾����� �ѿ�
3. �ѿ� �׷�

����
1. 12*6 ũ�⸦ ��ü üũ�ϸ鼭 RYG�κи� BFS�� ����

*/
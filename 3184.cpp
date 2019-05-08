/*3184�� ��*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;
struct pnt { int rr, cc; }temp;
int R, C;
string Map[250];
int area_chk[250][250];
queue<pnt>wolf_Q;
queue<pnt>sector;
int wolf, sheep, wolf_cnt, sheep_cnt;
int drc[] = { 0,0,-1,1,-1,1,0,0 };

int area_bfs(int r,int c) {
	temp.rr = r;
	temp.cc = c;
	sector.push(temp);
	if (Map[r][c] == 'v') {
		wolf_cnt = 1;
		sheep_cnt = 0;
	}
	else {
		wolf_cnt = 0;
		sheep_cnt = 1;
	}
	while (!sector.empty()) {
		int r = sector.front().rr;
		int c = sector.front().cc;
		area_chk[r][c] = 1;
		sector.pop();
		for (int d = 0; d < 4; d++) {
			int nr = r + drc[d];
			int nc = c + drc[d + 4];
			if (!(nr < 0 || nr >= R || nc < 0 || nc >= C)) {
				if (Map[nr][nc] != '#'&&area_chk[nr][nc] == 0) {
					temp.rr = nr;
					temp.cc = nc;
					sector.push(temp);
					area_chk[nr][nc] = 1;
					if (Map[nr][nc] == 'v') wolf_cnt++;
					if (Map[nr][nc] == 'o') sheep_cnt++;
				}
			}
		}
	}
	if (wolf_cnt >= sheep_cnt) return -1;
	else return 1;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		cin >> Map[r];
		for (int c = 0; c < Map[r].size(); c++) {
			if (Map[r][c] == 'v'|| Map[r][c] == 'o') {
				temp.rr = r;
				temp.cc = c;
				wolf_Q.push(temp);
			}
		}
	}
	while (!wolf_Q.empty()) {
		int r = wolf_Q.front().rr;
		int c = wolf_Q.front().cc;
		wolf_Q.pop();
		if (area_chk[r][c] == 0) {
			if (area_bfs(r, c) == 1)
				sheep += sheep_cnt;
			else
				wolf += wolf_cnt;
		}
	}
	
	cout << sheep << ' ' << wolf;
}


/*����
1. .�ʵ� #��Ÿ�� o�� v����
2. �� ������ ���� �� ������ ���� ����, ���밡 ���ų� �� ������ �� ����
����
1. ����� ���� ��ġ�� ť�� ����
2. ����� ���� ��ġ�� ������� BFS
2-1. ���� ����,�� ��ġ�� �湮�ߴ� ������ Ȯ�� �� �湮 ������ Pass, ���� �ʾ����� BFS����
2-2. BFS�ϸ鼭 ��� ���� ���� ī��Ʈ(���� ��ġ�� ���̸� ���� 1�� ����, ����� ���븦 1�ν���)
2-3. ���밡 ������ -1 ��ȯ ���� ������ 1 ��ȯ
3. BFS��ȯ���� -1�̸� ���� ���� ���ϰ� 1�̸� �� ���� ���Ѵ�.
4. ��� ������ ���� ���

*/
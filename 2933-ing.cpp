/*2933�� �̳׶�*/
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
	//dir==1 : �� >> ��, dir==2 : �� << ��
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
1. �̳׶� ����
2-1. ���ŵ� �̳׶��� Ŭ������ ���� BFS�� �ؼ� 1���� ���� �ϴ��� Ȯ��
2-2. 1���� �������� ���ϸ� �ش� Ŭ������ ���� ����, �����ϸ� �ٸ� Ŭ������ BFS
3-1. 1���� �������� ���� Ŭ�����Ͱ� �����ϴ� ������ �̳׶����� Drop
3-2. Drop�� �ش� ������ ���ϴ��� x�� ���� �������� ������ �� ���� ���� (�� ������ ����)
4. ��� ����� ���� �� ���� �ݺ�
=======
string Map[101];
int visit[101][101];
struct Pnt { int r, c; }temp;
queue<Pnt>Q;
int throw_stick[101];
int R, C, N, throw_hight;
int drc[] = { 0,0,-1,1,-1,1,0,0 };
int BFS() { // �ٴ��� ������ 1��ȯ
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
		if (i % 2 == 1) {//��>��
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
		else {//��>��

		}
	}
}
/*
Ǯ�̰���
1.���븦 �� �ʿ��� ������ ���� ���� (��->��, ��->��)
2.���밡 x�� ������ .���� ��ü (�̳׶� �ı�)
3. 2���� �ı��� ������ Ŭ�����͸� Ȯ���ϰ� �� Ŭ������ �� ���������� BFS����
	3-1.BFS�ؼ� ���ϴ�(�ٴ�)�� �����ϸ� �� ������ ���ϸ� �����ʴ´�.
	3-2.BFS�ؼ� ���ϴܿ� �������� ���ϸ� �� ������ ���ϸ� �Ѵ�.
4. ���Ͻ� ���� ���� ������ �̳׶��� �������� x�Ǵ� �ٴ��� ������ ���� �̵�
	4-1 ���ϴ��� ������ ��ŭ �������� ��������.
>>>>>>> bcd1a3d8addd363ddb37aa17f209ac20973fb989
*/
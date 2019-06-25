//#include <iostream>
//#include <queue>
//using namespace std;
//
//typedef struct pnt { int r, c; }pnt; pnt temp, swan1, swan2;
//typedef struct node{
//	pnt value;
//	node *next;
//}node;
//
//int R, C;
//char Map[1500][1501];
//int visit[1500][1500];
//int day[1500][1500];
//int drc[] = { -1,0,1,0,0,1,0,-1 };
//int day_cnt;
//queue<pnt>Q_ice1;
//queue<pnt>Q_ice2;
//
//int BFS_meet() {
//	queue<pnt>Q_swan;
//	Q_swan.push(swan1);
//	while (!Q_swan.empty()) {
//		int rr = Q_swan.front().r;
//		int cc = Q_swan.front().c;
//		Q_swan.pop();
//		for (int d = 0; d < 4; d++) {
//			int nr = rr + drc[d];
//			int nc = cc + drc[d + 4];
//			if (!(nr < 0 || nc < 0 || nr >= R || nc >= C)) {
//				if (nr == swan2.r && nc == swan2.c) { 
//					return 1; 
//				}
//				if (Map[nr][nc] =='.' && visit[nr][nc] == 0) {
//					visit[nr][nc] = 1;
//					temp = { nr,nc };
//					Q_swan.push(temp);
//				}
//			}
//		}
//	}
//	for (int r = 0; r < R; r++) {
//		for (int c = 0; c < C; c++) {
//			visit[r][c] = 0;
//		}
//	}
//	return 0;
//}
//
//void BFS_melt() {
//	while ((!Q_ice1.empty()) || !(Q_ice2.empty())) {
//		if (!Q_ice1.empty()) {
//			while (!Q_ice1.empty()) {
//				int rr = Q_ice1.front().r;
//				int cc = Q_ice1.front().c;
//				Q_ice1.pop();
//				for (int d = 0; d < 4; d++) {
//					int nr = rr + drc[d];
//					int nc = cc + drc[d + 4];
//					if (!(nr < 0 || nc < 0 || nr >= R || nc >= C)) {
//						if (Map[nr][nc] == 'X' && day[nr][nc] == 0) {
//							Map[nr][nc] = '.';
//							day[nr][nc] = day[rr][cc] + 1;
//							temp = { nr,nc };
//							Q_ice2.push(temp);
//						}
//					}
//				}
//			}
//		}
//		else {
//			while (!Q_ice2.empty()) {
//				int rr = Q_ice2.front().r;
//				int cc = Q_ice2.front().c;
//				Q_ice2.pop();
//				for (int d = 0; d < 4; d++) {
//					int nr = rr + drc[d];
//					int nc = cc + drc[d + 4];
//					if (!(nr < 0 || nc < 0 || nr >= R || nc >= C)) {
//						if (Map[nr][nc] == 'X' && day[nr][nc] == 0) {
//							Map[nr][nc] = '.';
//							day[nr][nc] = day[rr][cc] + 1;
//							temp = { nr,nc };
//							Q_ice1.push(temp);
//						}
//					}
//				}
//			}
//		}
//		day_cnt++;
//		if (BFS_meet() == 1) return;
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	cin >> R >> C;
//	int flag = 0;
//	for (int i = 0; i < R; i++) cin >> Map[i];
//	for (int r = 0; r < R; r++) {
//		for (int c = 0; c < C; c++) {
//			if (Map[r][c] == '.'||Map[r][c]=='L') {
//				temp = { r,c };
//				Q_ice1.push(temp);
//			}
//			if (Map[r][c] == 'L') {
//				if (flag == 0) {
//					swan1 = { r,c };
//					flag = 1;
//				}
//				else {
//					swan2 = { r,c };
//				}
//			}
//		}
//	}
//
//	BFS_melt();
//	cout << day_cnt;
//}
///*
//1. 모든 물위치 큐에 삽입
//2. BFS1회 진행마다 백조끼리 만나는지 BFS진행
//		->만나면 종료
//		->안만나면 반복
//
//*/
//

//백준 코드
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
string a[1500];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool wcheck[1500][1500];
bool scheck[1500][1500];
int main() {
	int n, m;
	cin >> n >> m;
	int sx, sy, ex, ey;
	sx = sy = ex = ey = -1;
	queue<pair<int, int>> swan, nswan, water, nwater;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'L') {
				if (sx == -1) {
					sx = i;
					sy = j;
				}
				else {
					ex = i;
					ey = j;
				}
				a[i][j] = '.';
			}
			if (a[i][j] == '.') {
				water.push(make_pair(i, j));
				wcheck[i][j] = true;
			}
		}
	}

	swan.push(make_pair(sx, sy));
	scheck[sx][sy] = true;
	for (int i = 0;; i++) {
		while (!water.empty()) {
			int x = water.front().first;
			int y = water.front().second;
			water.pop();
			a[x][y] = '.';
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (wcheck[nx][ny]) continue;
				if (a[nx][ny] == '.') {
					water.push(make_pair(nx, ny));
					wcheck[nx][ny] = true;
				}
				else {
					nwater.push(make_pair(nx, ny));
					wcheck[nx][ny] = true;
				}
			}
		}
		while (!swan.empty()) {
			int x = swan.front().first;
			int y = swan.front().second;
			swan.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (scheck[nx][ny]) continue;
				if (a[nx][ny] == '.') {
					swan.push(make_pair(nx, ny));
					scheck[nx][ny] = true;
				}
				else {
					nswan.push(make_pair(nx, ny));
					scheck[nx][ny] = true;
				}
			}
		}
		if (scheck[ex][ey]) {
			cout << i << '\n';
			break;
		}
		water = nwater;
		swan = nswan;
		nwater = queue<pair<int, int>>();
		nswan = queue<pair<int, int>>();
	}
	return 0;
}
/*17136번 색종이 붙이기*/
#include <iostream>
#include <string.h>
using namespace std;
int Map[10][10], visit[10][10];
int paper[6];

bool put_chk(int sr, int sc, int scale) {
	int er = 10 - scale + sr;
	int ec = 10 - scale + sc;
	for (int r = sr; r < er; r++) {
		for (int c = sc; c < ec; c++) {
			if (Map[r][c] != 1)return false;
		}
	}
	return true;
}

void cover(int sr,int sc,int scale) {
	int er = 10 - scale + sr;
	int ec = 10 - scale + sc;
	for (int r = sr; r < er; r++) {
		for (int c = sc; c < ec; c++) {
			Map[r][c] = 0;
		}
	}
}

void cover_DFS(int r,int c, int scale) {
	bool cover_able = true;
	if (paper[scale]==5||cover_able == false) {
		
	}
	else {
		for (int nr = r; nr < 10 - scale; nr++) {
			for (int nc = c; nc < 10 - scale; nc++) {
				if (put_chk(nr, nc, scale)) { cover(nr, nc, scale); }
				cover_DFS(nr+1, nc, scale);
			}
		}
		return false;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	for (int r = 0; r < 10; r++)
		for (int c = 0; c < 10; c++)
			cin >> Map[r][c];

	for (int s = 5; s > 0; s--) {
		DFS(0, 0, s);
	}
}
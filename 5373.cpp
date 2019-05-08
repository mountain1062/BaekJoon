/*5373번 큐빙*/
#include <iostream>
#include <string.h>
using namespace std;
char U[3][3] = {
	'W','W','W',
	'W','W','W',
	'W','W','W'
};
char D[3][3] = {
	'Y','Y','Y',
	'Y','Y','Y',
	'Y','Y','Y'
}; 
char F[3][3] = {
	'R','R','R',
	'R','R','R',
	'R','R','R'
}; 
char B[3][3] = {
	'O','O','O',
	'O','O','O',
	'O','O','O'
}; 
char L[3][3] = {
	'G','G','G',
	'G','G','G',
	'G','G','G'
};
char R[3][3] = {
	'B','B','B',
	'B','B','B',
	'B','B','B'
};
char commd[2];
int T,commd_cnt;

void reset() {
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			U[r][c] = 'W';
			D[r][c] = 'Y';
			F[r][c] = 'R';
			B[r][c] = 'O';
			L[r][c] = 'G';
			R[r][c] = 'B';
		}
	}
}

void spin() {
	int r = 2;
	switch (commd[0]) {
	case 'F': 
		if (commd[1] == '+') {
			//사이드에 달린거 회전
			for (int c = 0; c < 3; c++) {
				int temp = U[r][c];
				U[r][c] = L[2 - c][r];
				L[2 - c][r] = D[2 - r][2 - c];
				D[2 - r][2 - c] = R[c][2 - r];
				R[c][2 - r] = temp;
			}
			//본체 회전
			int temp_side[3][3];
			for (int rr = 0; rr < 3; rr++) {
				for (int cc = 0; cc < 3; cc++) {
					if (rr == 1 && cc == 1) continue;
					temp_side[rr][cc] = F[2 - cc][rr];
				}
			}
			memcpy(F, temp_side, sizeof(F));
		}
		else {
			//사이드에 달린거 회전
			for (int c = 0; c < 3; c++) {
				int temp = U[r][c];
				U[r][c] = R[2 - c][r];
				R[2 - c][r] = D[2 - r][2 - c];
				D[2 - r][2 - c] = L[c][2 - r];
				L[c][2 - r] = temp;
			}
			//본체 회전
			int temp_side[3][3];
			for (int rr = 0; rr < 3; rr++) {
				for (int cc = 0; cc < 3; cc++) {
					if (rr == 1 && cc == 1) continue;
					temp_side[rr][cc] = F[cc][2 - rr];
				}
			}
			memcpy(F, temp_side, sizeof(F));
		}
		break;
	case 'B': 
		if (commd[1] == '+') {
			//사이드에 달린거 회전
			for (int c = 0; c < 3; c++) {
				int temp = U[r][c];
				U[r][c] = R[2 - c][r];
				R[2 - c][r] = D[2 - r][2 - c];
				D[2 - r][2 - c] = L[c][2 - r];
				L[c][2 - r] = temp;
			}
			//본체 회전
			int temp_side[3][3];
			for (int rr = 0; rr < 3; rr++) {
				for (int cc = 0; cc < 3; cc++) {
					if (rr == 1 && cc == 1) continue;
					temp_side[rr][cc] = B[2 - cc][rr];
				}
			}
			memcpy(B, temp_side, sizeof(B));
		}
		else {
			//사이드에 달린거 회전
			for (int c = 0; c < 3; c++) {
				int temp = U[r][c];
				U[r][c] = L[2 - c][r];
				L[2 - c][r] = D[2 - r][2 - c];
				D[2 - r][2 - c] = R[c][2 - r];
				R[c][2 - r] = temp;
			}
			//본체 회전
			int temp_side[3][3];
			for (int rr = 0; rr < 3; rr++) {
				for (int cc = 0; cc < 3; cc++) {
					if (rr == 1 && cc == 1) continue;
					temp_side[rr][cc] = B[cc][2 - rr];
				}
			}
			memcpy(B, temp_side, sizeof(B));
		}
		break;
	case 'U': 
		if (commd[1] == '+') {
			//사이드에 달린거 회전
			for (int c = 0; c < 3; c++) {
				int temp = B[r][c];
				B[r][c] = L[2 - c][r];
				L[2 - c][r] = F[2 - r][2 - c];
				F[2 - r][2 - c] = R[c][2 - r];
				R[c][2 - r] = temp;
			}
			//본체 회전
			int temp_side[3][3];
			for (int rr = 0; rr < 3; rr++) {
				for (int cc = 0; cc < 3; cc++) {
					if (rr == 1 && cc == 1) continue;
					temp_side[rr][cc] = U[2 - cc][rr];
				}
			}
			memcpy(U, temp_side, sizeof(U));
		}
		else {
			//사이드에 달린거 회전
			for (int c = 0; c < 3; c++) {
				int temp = F[r][c];
				F[r][c] = L[2 - c][r];
				L[2 - c][r] = B[2 - r][2 - c];
				B[2 - r][2 - c] = R[c][2 - r];
				R[c][2 - r] = temp;
			}
			//본체 회전
			int temp_side[3][3];
			for (int rr = 0; rr < 3; rr++) {
				for (int cc = 0; cc < 3; cc++) {
					if (rr == 1 && cc == 1) continue;
					temp_side[rr][cc] = U[cc][2 - rr];
				}
			}
			memcpy(U, temp_side, sizeof(U));
		}
		break;
	case 'D':
		if (commd[1] == '+') {
			//사이드에 달린거 회전
			for (int c = 0; c < 3; c++) {
				int temp = F[r][c];
				F[r][c] = L[2 - c][r];
				L[2 - c][r] =B[2 - r][2 - c];
				B[2 - r][2 - c] = R[c][2 - r];
				R[c][2 - r] = temp;
			}
			//본체 회전
			int temp_side[3][3];
			for (int rr = 0; rr < 3; rr++) {
				for (int cc = 0; cc < 3; cc++) {
					if (rr == 1 && cc == 1) continue;
					temp_side[rr][cc] = D[2 - cc][rr];
				}
			}
			memcpy(D, temp_side, sizeof(D));
		}
		else {
			//사이드에 달린거 회전
			for (int c = 0; c < 3; c++) {
				int temp = B[r][c];
				B[r][c] = L[2 - c][r];
				L[2 - c][r] = F[2 - r][2 - c];
				F[2 - r][2 - c] = R[c][2 - r];
				R[c][2 - r] = temp;
			}
			//본체 회전
			int temp_side[3][3];
			for (int rr = 0; rr < 3; rr++) {
				for (int cc = 0; cc < 3; cc++) {
					if (rr == 1 && cc == 1) continue;
					temp_side[rr][cc] = D[cc][2 - rr];
				}
			}
			memcpy(D, temp_side, sizeof(D));
		}
		break;
	case 'L':
		if (commd[1] == '+') {
			//사이드에 달린거 회전
			for (int c = 0; c < 3; c++) {
				int temp = U[r][c];
				U[r][c] = B[2 - c][r];
				B[2 - c][r] = D[2 - r][2 - c];
				D[2 - r][2 - c] = F[c][2 - r];
				F[c][2 - r] = temp;
			}
			//본체 회전
			int temp_side[3][3];
			for (int rr = 0; rr < 3; rr++) {
				for (int cc = 0; cc < 3; cc++) {
					if (rr == 1 && cc == 1) continue;
					temp_side[rr][cc] = L[2 - cc][rr];
				}
			}
			memcpy(L, temp_side, sizeof(L));
		}
		else {
			//사이드에 달린거 회전
			for (int c = 0; c < 3; c++) {
				int temp = U[r][c];
				U[r][c] = F[2 - c][r];
				F[2 - c][r] = D[2 - r][2 - c];
				D[2 - r][2 - c] = B[c][2 - r];
				B[c][2 - r] = temp;
			}
			//본체 회전
			int temp_side[3][3];
			for (int rr = 0; rr < 3; rr++) {
				for (int cc = 0; cc < 3; cc++) {
					if (rr == 1 && cc == 1) continue;
					temp_side[rr][cc] = L[cc][2 - rr];
				}
			}
			memcpy(L, temp_side, sizeof(L));
		}
		break;
	case 'R':
		if (commd[1] == '+') {
			//사이드에 달린거 회전
			for (int c = 0; c < 3; c++) {
				int temp = U[r][c];
				U[r][c] = F[2 - c][r];
				F[2 - c][r] = D[2 - r][2 - c];
				D[2 - r][2 - c] = B[c][2 - r];
				B[c][2 - r] = temp;
			}
			//본체 회전
			int temp_side[3][3];
			for (int rr = 0; rr < 3; rr++) {
				for (int cc = 0; cc < 3; cc++) {
					if (rr == 1 && cc == 1) continue;
					temp_side[rr][cc] = R[2 - cc][rr];
				}
			}
			memcpy(R, temp_side, sizeof(R));
		}
		else {
			//사이드에 달린거 회전
			for (int c = 0; c < 3; c++) {
				int temp = U[r][c];
				U[r][c] = B[2 - c][r];
				B[2 - c][r] = D[2 - r][2 - c];
				D[2 - r][2 - c] = F[c][2 - r];
				F[c][2 - r] = temp;
			}
			//본체 회전
			int temp_side[3][3];
			for (int rr = 0; rr < 3; rr++) {
				for (int cc = 0; cc < 3; cc++) {
					if (rr == 1 && cc == 1) continue;
					temp_side[rr][cc] = R[cc][2 - rr];
				}
			}
			memcpy(R, temp_side, sizeof(R));
		}
		break;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> commd_cnt;
		for (int i = 0; i < commd_cnt; i++) {
			cin >> commd;
			spin();
		}
		
		for (int r = 0; r < 3; r++) {
			for (int c = 0; c < 3; c++) {
				cout << U[r][c];
			}
			cout << '\n';
		}
		reset();
	}
}
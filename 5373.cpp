/*5373¹ø Å¥ºù*/
#include <iostream>
#include <string>
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
string commd;
int T, commd_cnt;

void print_U() {
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			cout << U[r][c];
		}
		cout << '\n';
	}
}

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

void spin_facade(char facade[][3], char dir) {
	char temp[3][3];
	if (dir == '+') {
		for (int r = 0; r < 3; r++) {
			for (int c = 0; c < 3; c++) {
				if (r == 1 && c == 1)continue;
				temp[r][c] = facade[2 - c][r];
			}
		}
		memcpy(facade, temp, sizeof(facade));
	}
	else {
		for (int r = 0; r < 3; r++) {
			for (int c = 0; c < 3; c++) {
				if (r == 1 && c == 1)continue;
				temp[r][c] = facade[c][2 - r];
			}
		}
		memcpy(facade, temp, sizeof(facade));
	}
}

void spin_side(string commd) {
	int r = 2;
	switch (commd[0]) {
	case 'F':
		if (commd[1] == '+') {
			for (int c = 0; c < 3; c++) {
				char temp = U[r][c];
				U[r][c] = L[2 - c][r];
				L[2 - c][r] = D[2 - r][2 - c];
				D[2 - r][2 - c] = R[c][2 - r];
				R[c][2 - r] = temp;
			}
		}
		else {
			for (int c = 0; c < 3; c++) {
				char temp = U[r][c];
				U[r][c] = R[c][2 - r];
				R[c][2 - r] = D[2 - r][2 - c];
				D[2 - r][2 - c] = L[2 - c][r];
				L[2 - c][r] = temp;
			}
		}
		break;
	case 'B':
		if (commd[1] == '+') {
			for (int c = 0; c < 3; c++) {
				char temp = D[r][c];
				D[r][c] = L[2 - c][r];
				L[2 - c][r] = U[2 - r][2 - c];
				U[2 - r][2 - c] = R[c][2 - r];
				R[c][2 - r] = temp;
			}
		}
		else {
			for (int c = 0; c < 3; c++) {
				char temp = D[r][c];
				D[r][c] = R[c][2 - r];
				R[c][2 - r] = U[2 - r][2 - c];
				U[2 - r][2 - c] = L[2 - c][r];
				L[2 - c][r] = temp;
			}
		}
		break;
	case 'U':
		if (commd[1] == '+') {
			for (int c = 0; c < 3; c++) {
				char temp = B[r][c];
				B[r][c] = L[2 - c][r];
				L[2 - c][r] = F[2 - r][2 - c];
				F[2 - r][2 - c] = R[c][2 - r];
				R[c][2 - r] = temp;
			}
		}
		else {
			for (int c = 0; c < 3; c++) {
				char temp = B[r][c];
				B[r][c] = R[c][2 - r];
				R[c][2 - r] = F[2 - r][2 - c];
				F[2 - r][2 - c] = L[2 - c][r];
				L[2 - c][r] = temp;
			}
		}
		break;
	case 'D':
		if (commd[1] == '+') {
			for (int c = 0; c < 3; c++) {
				char temp = F[r][c];
				F[r][c] = L[2 - c][r];
				L[2 - c][r] = B[2 - r][2 - c];
				B[2 - r][2 - c] = R[c][2 - r];
				R[c][2 - r] = temp;
			}
		}
		else {
			for (int c = 0; c < 3; c++) {
				char temp = F[r][c];
				F[r][c] = R[c][2 - r];
				R[c][2 - r] = B[2 - r][2 - c];
				B[2 - r][2 - c] = L[2 - c][r];
				L[2 - c][r] = temp;
			}
		}
		break;
	case 'R':
		if (commd[1] == '+') {
			for (int c = 0; c < 3; c++) {
				char temp = U[r][c];
				U[r][c] = F[2 - c][r];
				F[2 - c][r] = D[2 - r][2 - c];
				D[2 - r][2 - c] = B[c][2 - r];
				B[c][2 - r] = temp;
			}
		}
		else {
			for (int c = 0; c < 3; c++) {
				char temp = U[r][c];
				U[r][c] = B[c][2 - r];
				B[c][2 - r] = D[2 - r][2 - c];
				D[2 - r][2 - c] = F[2 - c][r];
				F[2 - c][r] = temp;
			}
		}
		break;
	case 'L':
		if (commd[1] == '+') {
			for (int c = 0; c < 3; c++) {
				char temp = U[r][c];
				U[r][c] = B[2 - c][r];
				B[2 - c][r] = D[2 - r][2 - c];
				D[2 - r][2 - c] = F[c][2 - r];
				F[c][2 - r] = temp;
			}
		}
		else {
			for (int c = 0; c < 3; c++) {
				char temp = U[r][c];
				U[r][c] = F[c][2 - r];
				F[c][2 - r] = D[2 - r][2 - c];
				D[2 - r][2 - c] = B[2 - c][r];
				B[2 - c][r] = temp;
			}
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
			spin_side(commd);
			switch (commd[0])
			{
			case 'F': spin_facade(F, commd[1]); break;
			case 'B': spin_facade(B, commd[1]); break;
			case 'U': spin_facade(U, commd[1]); break;
			case 'D': spin_facade(D, commd[1]); break;
			case 'L': spin_facade(L, commd[1]); break;
			case 'R': spin_facade(R, commd[1]); break;
			}
		}
		print_U();
		reset();
	}
}
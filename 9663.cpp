<<<<<<< HEAD
#include <iostream>
using namespace std;
int N;
int Map[15][15];
int row[15], cal[15];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

=======
/*9663�� N-Queen*/
#include <iostream>
#include <math.h>
using namespace std;
int N, cnt;
int Q_loc[15];
bool promising(int r, int c) {//r,c�� ���� ���� ���� ��ġ
	if (r == 1) return true;
	else {
		for (int i = 1; i < r; i++) { // i: ���� ���� ���� ���� ���� ���
			if (c == Q_loc[i] || abs(r-i) == abs(c - Q_loc[i])) return false; 
		}
		return true;
	}
}
void put_Q(int now_row) {
	if (now_row > N) {
		cnt++;
	}
	else {
		for (int c = 1; c <= N; c++) {
			if (Q_loc[now_row] == 0 && promising(now_row, c) == true) {
				Q_loc[now_row] = c;
				put_Q(now_row + 1);
				Q_loc[now_row] = 0;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	put_Q(1);
	cout << cnt;
>>>>>>> bcd1a3d8addd363ddb37aa17f209ac20973fb989
}
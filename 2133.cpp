/*2133�� Ÿ�� ä���*/
#include <iostream>
using namespace std;
int N;
int tile[30] = { 1,0,3, };
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	if (N % 2 == 0) {
		for (int i = 4; i <= N; i += 2) {
			tile[i] = tile[i - 2] * 3;//����� �� Ÿ�Ϸ� ���ϴ� ���
			for (int j = 4; i - j >= 0; j+=2) tile[i] += tile[i - j] * 2; //�������� ���
		}
	}
	cout << tile[N];
}
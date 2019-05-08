/*1929�� �Ҽ� ���ϱ�*/
#include <iostream>
using namespace std;
int M, N;
int num[1000001] = {0,-1,};//0 : �Ҽ�, -1 : 1 �Ǵ� �ռ���

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> M >> N;

	for (int i = 2; i*i <= N; i++) { //üũ ������ ��N ������ �д�.
		for (int j = i * i; j <= N; j += i) {//i�� ��� �κ��� �� �ռ����� üũ�Ѵ�.
			if (num[j] == -1) continue;//���� ������ ó���� �Ǿ��ٸ� �ٷ� �������� �Ѿ��.
			num[j] = -1;
		}
	}
	for (int i = M; i <= N; i++) {
		if (num[i] == 0) cout << i << '\n';
	}
}
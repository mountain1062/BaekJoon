/*1978�� �Ҽ�ã��*/
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[101];
int num[1001];//0�� �� �Ҽ�, -1�� �� �ռ��� or 1
int prime_cnt;

void eratos(int n) {
	if (n == 1) num[n] = -1;
	if (n > 2) {
		for (int i = 2; i < n; i++) {
			if (n%i == 0) {
				num[n] = -1;
				break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> arr[i];
	for (int i = 0; i < n; i++) {
		eratos(arr[i]);
		if (num[arr[i]] == 0) prime_cnt++;
	}
	cout << prime_cnt;
}
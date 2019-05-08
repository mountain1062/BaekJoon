#include <iostream>
using namespace std;
int N, M;
void comb(int n, int m) {
	for (int i = 1; i <= n; i++) {
		if (i != m) comb(m, i);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M;
	comb(N, M);
}
/*11651�� ��ǥ �����ϱ� 2*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
pair<int, int>temp;
vector<pair<int, int>>v;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);s
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp.second >> temp.first;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		cout << v[i].second << ' ' << v[i].first << '\n';
	}
}
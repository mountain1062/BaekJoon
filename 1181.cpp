/*1181�� �ܾ� ����*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int N;
string in;
vector<string>v;
vector<pair<int,string>>out;
pair<int, string>temp;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> in;
		v.push_back(in);
	}
	sort(v.begin(), v.end());//�Է� �������� �����ؼ�
	v.erase(unique(v.begin(), v.end()),v.end());//�ߺ� ����
	//�ܾ��� ���̿� �ܾ �����ϴ� ���Ϳ� �־���
	for (int i = 0; i < v.size(); i++) {
		temp = { v[i].size(),v[i] };
		out.push_back(temp);
	}
	sort(out.begin(), out.end());//pair�� �����ϸ� first �������� ���ĵǰ�, �������� second�������� ������ �ȴ�.
	for (int i = 0; i < out.size(); i++) {
		cout << out[i].second << '\n';
	}
}
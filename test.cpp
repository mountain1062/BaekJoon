#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
using namespace std;
struct info { 
	int a;
	char b;
}temp;
list<char>L;
vector<int> v = { 1,1,8,3,2,1,4,7,0,0,2 };

int main() {
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << i << ' ';
	}
	cout << endl;
	for (int i=0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	cout << endl;
	cout << upper_bound(v.begin(), v.end(), 2) - v.begin() << endl;

	cout << lower_bound(v.begin(), v.end(), 2) - v.begin() << endl;
	
}
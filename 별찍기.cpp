#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	///*�����2*/
	/*for (int i = N-1; i >= 0; i--) {
		for (int j = 0; j < i; j++) cout << ' ';
		for (int j = 0; j < N - i; j++) cout << '*';
		cout << '\n';
	}*/
	///*�����3*/
	/*for (int i = N; i > 0; i--) {
		for (int j = 0; j < i; j++) cout << '*';
		cout << '\n';
	}*/
	///*�����4*/
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) cout << ' ';
		for (int j = 0; j < N - i; j++) cout << '*';
		cout << '\n';
	}*/
	///*�����5*/
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1 - i; j++) cout << ' ';
		for (int j = 0; j < i * 2 + 1; j++) cout << '*';
		cout << '\n';
	}*/
	///*�����6*/
	/*for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) cout << ' ';
		for (int j = 0; j < (N - i) * 2 - 1; j++) cout << '*';
		cout << '\n';
	}*/
	///*�����7*/
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1 - i; j++) cout << ' ';
		for (int j = 0; j < i * 2 + 1; j++) cout << '*';
		cout << '\n';
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) cout << ' ';
		for (int j = 0; j < (N - i) * 2 - 1; j++) cout << '*';
		cout << '\n';
	}*/
	///*�����9*/
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) cout << ' ';
		for (int j = 0; j < (N - i) * 2 - 1; j++) cout << '*';
		cout << '\n';
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N - 1 - i; j++) cout << ' ';
		for (int j = 0; j < i * 2 + 1; j++) cout << '*';
		cout << '\n';
	}*/

}
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int>v;
<<<<<<< HEAD
int T, n, input_num, front_p , end_p, dir_flag, error_flag; // dir = 0 : -> , 1 : <-
=======
int T, n, input_num, front_p, end_p, dir_flag, error_flag; // dir = 0 : -> , 1 : <-
>>>>>>> bcd1a3d8addd363ddb37aa17f209ac20973fb989
string command, input_number_arr, temp_num;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> command;
		cin >> n;
		cin >> input_number_arr;
		dir_flag = 0;
<<<<<<< HEAD
		error_flag = 0;
		front_p = end_p = -1;
		//�Է�
		if (n > 0) {
			//���ڿ� number�� ó���� �������� '[' �̱� ������ �������� �����ϰ� ����, ������ ]�� ���ڸ� �����ϱ� ���� Ʈ���ŷ� ���ܳ���
			for (int i = 1; i < input_number_arr.size(); i++) {
=======
		front_p = end_p = -1;
		//�Է�
		if (n > 0) {
			for (int i = 1; i < input_number_arr.size(); i++) {//���ڿ� number�� ó���� �������� '[' �̱� ������ �������� �����ϰ� ����, ������ ]�� ���ڸ� �����ϱ� ���� Ʈ���ŷ� ���ܳ���
>>>>>>> bcd1a3d8addd363ddb37aa17f209ac20973fb989
				if (input_number_arr[i] == ',' || input_number_arr[i] == ']') {
					int made_num = stoi(temp_num);
					v.push_back(made_num);
					temp_num.clear();
				}
				else {
					temp_num.push_back(input_number_arr[i]);
				}
			}
		}
<<<<<<< HEAD
=======
		/*for (int i = 0; i < n * 2 + 1; i++) {
			if (i % 2 == 0) cin >> junk;
			else {
				cin >> input;
				v.push_back(input);
			}
		}
		*/
>>>>>>> bcd1a3d8addd363ddb37aa17f209ac20973fb989
		if (n != 0) {
			front_p = 0;
			end_p = v.size() - 1;
		}
		//��ɾ� ����
		for (int c = 0; c < command.size(); c++) {
			if (command[c] == 'R') {
				if (dir_flag == 0) {
					dir_flag = 1; //������ -> ������
				}
				else {
					dir_flag = 0; //������ -> ������
				}
			}
			else {//command == D
				if (front_p == -1 && end_p == -1) {
					cout << "error" << '\n';
					error_flag = 1;
					break;
				}
				else {
					if (dir_flag == 0) {
						front_p++;
					}
					else {
						end_p--;
					}
					if (front_p > end_p) front_p = end_p = -1;//front_p�� end_p������ ũ�ٴ� ���� �迭�� ����ٴ� ��.
				}
			}
		}
		//���
		if (error_flag == 0) {
			if (front_p != -1) { //�迭�� ���� �ʾ��� ��
				cout << '[';
				if (dir_flag == 0) {
					for (int i = front_p; i < end_p; i++) cout << v[i] << ',';
					cout << v[end_p] << ']' << '\n';
				}
				else {
					for (int i = end_p; i > front_p; i--) cout << v[i] << ',';
					cout << v[front_p] << ']' << '\n';
				}
			}
			else cout << "[]" << '\n';//�迭�� ����� ��

		}
		//�ʱ�ȭ �κ�
		v.clear();
		command.clear();
<<<<<<< HEAD
=======
		//cin.clear();
		//cin.ignore(200001, '\n');
		error_flag = 0;
>>>>>>> bcd1a3d8addd363ddb37aa17f209ac20973fb989
	}
}
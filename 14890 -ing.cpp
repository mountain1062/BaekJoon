/*14890�� ����*/
#include <iostream>
using namespace std;
int Map[101][101];
bool road[101];
bool chk_list[10];
int N, L;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> L;
	
	int prev_height = 0;
	bool chk = false;//���� L*2���� �̳����� ���纸�� ���� ������ ������ ���� ���� ��� ��� �Ұ�
	int same_height_cnt=0;
	bool set_able_incline = false;

	//���η� ���±� Ž�� 
	for (int r = 0; r < N; r++) {
		prev_height = Map[r][0];
		same_height_cnt = 1;
		for (int c = 1; c < N; c++) {
			if (chk == true) {
				Map[r][c];
				same_height_cnt++;
				if (same_height_cnt == L * 2) chk = false;
			}
			else {
				//���� ������ ���̰� ���� ��
				if (prev_height == Map[r][c]) {
					same_height_cnt++;
				}
				//���� ������ ���纸�� ���� ��
				else if (prev_height > Map[r][c]) {
					prev_height = Map[r][c];
					same_height_cnt = 1;
					chk = true;
				}
			}
			if (same_height_cnt >= L) {
				for (int j = c; j > c - L; c--) {
					road[c] = true;
				}
			}
		}
	}
	//���� Ž��
	for (int c = 0; c < N; c++) {
		for (int r = 0; r < N; r++) {
			Map[r][c];
		}
	}
	/*
	1. ����ĭ ����ĭ�� ���̸� Ȯ��

	*/
}
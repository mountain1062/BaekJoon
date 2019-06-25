#include <iostream>
#include <stdio.h>
using namespace std;
int T, flag = 0;
long long x, y, cnt, max_;
long long temp[450000];

long long BS(long long start, long long target) {
	long long front = 0, rear = 447214,idx;
	while (front <= rear) {
		long long mid = (front + rear) / 2;
		long long mid_value = start + temp[mid];
		if (mid_value > target) rear = mid - 1;
		else if (mid_value < target) front = mid + 1;
		else return mid;
		if(mid_value<=target)idx = mid;
	}
	return idx;
}

void jump(long long start,long long target) {
	if (flag == 1) return;
	if (start == target) {
		flag = 1;
		return;
	}
	long long HV = BS(start, target);
	cnt += HV;
	if (start + temp[HV] > target)return;
	jump(start+temp[HV], target);
}

int main() {
	setbuf(stdout, NULL);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	//T = 1;
	long long i = 1;
	long long max = 0;
	while (max <= 100000000000) {
		temp[i - 1] = i * (i - 1) / 2;
		max = temp[i - 1];
		i++;
	}

	for (int t = 1; t <= T; t++) {
		cin >> x >> y;
	  /*  for (int i = temp[BS(0,y)-1]-1; i <= y; i++) {
			jump(0, i);
			if (cnt >= max_) max_ = cnt;
			cnt = 0;
			flag = 0;
		}*/
		
		long long max_1 = 0;
		//////////////////////////////////////////////
		for (long long ii = temp[BS(0, y)-1] - 1; ii < y; ii++) {
			long long xx = LLONG_MAX;
			long long yy = ii;
			long long cnt_ = 0;
			while (xx > 0) {
				xx = yy - temp[BS(0, yy)];
				cnt_ += BS(0, yy);
				yy = xx;
			}
			if (max_1 < cnt_)max_1 = cnt_;
		}
		cout << "Case #" << t << '\n';
		cout << max_1<<'\n';
		////////////////////////////////////////////////
		//xx = LLONG_MAX;
		//yy = y - 1;
		//cnt_ = 0;
		//while (xx > 0) {
		//	xx = yy - temp[BS(0, yy)];
		//	cnt_ += BS(0, yy);
		//	yy = xx;
		//}
		//if (max_1 < cnt_)max_1 = cnt_;
		/////////////////////////////////////////////////
		//xx = LLONG_MAX;
		//yy = temp[BS(0,y)]-1;
		//cnt_ = 0;
		//while (xx > 0) {
		//	xx = yy - temp[BS(0, yy)];
		//	cnt_ += BS(0, yy);
		//	yy = xx;
		//}
		//if (max_1 < cnt_)max_1 = cnt_;
		//////////////////////////////////////////////////
		//xx = LLONG_MAX;
		//yy = temp[BS(0, y)-1] - 1;
		//cnt_ = 0;
		//while (xx > 0) {
		//	xx = yy - temp[BS(0, yy)];
		//	cnt_ += BS(0, yy);
		//	yy = xx;
		//}
		//if (max_1 < cnt_)max_1 = cnt_;


		/*cout << "Case #" << t << '\n';
		cout << max_ << '\n';
		max_ = 0;*/
	}
}
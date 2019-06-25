#include <iostream>
#include <math.h>
#define PI 3.14159265359
using namespace std;

int T, N;
double R, S, E, dist;
struct Block {
	double l, r, h;
}temp[1002];

int main() {
	setbuf(stdout, NULL);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> R >> S >> E;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> temp[i].l >> temp[i].r >> temp[i].h;
		}
		double prev_x;
		prev_x = S;
		for (int i = 0; i < N; i++) {
			if (temp[i].h >= R) {//블록 높이가 R보다 클때
				dist += ((temp[i].l - prev_x - R) + (PI*R) + (temp[i].r - temp[i].l) + (temp[i].h - R) * 2);
				prev_x = temp[i].r + R;
			}
			else {//블록 높이가 R보다 작을 때,
				double spot = sqrt(R * R - (R - temp[i].h)*(R - temp[i].h));
				double x = asin((R - temp[i].h) / R);
				dist += (2 * (((PI * R) / 2) - ((2 * PI * R) * ((x * (180 / PI)) / 360)) - (R * cos(x)))) + (temp[i].r + spot) - prev_x;
				prev_x = temp[i].r + spot;
			}
		}
		dist += E - prev_x;
		cout.precision(12);
		cout << "Case #" << t << '\n';
		cout << fixed << dist << '\n';
		dist = 0;
	}
}
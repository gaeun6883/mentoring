//meentoring 112. 2022.2.3
//3분 탐색

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

//3분 탐색 코드
double distance(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double start(double start, double end) {
	return start + (end - start) / 3;
}
double end(double start, double end) {
	return end - (end - start) / 3;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	double ax, ay, bx, by, cx, cy, dx, dy;
	cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

	double mid1 = 0, mid2 = 0;
	while(true){
		mid1 = distance(ax, ay, cx, cy);
		mid2 = distance(bx, by, dx, dy);
		if (mid1 > mid2) {
			ax = start(ax, bx);
			ay = start(ay, by);
			cx = start(cx, dx);
			cy = start(cy, dy);
		}
		else if (mid1 < mid2) {
			bx = end(ax, bx);
			by = end(ay, by);
			dx = end(cx, dx);
			dy = end(cy, dy);
		}
		else
			break;
	}
	cout << fixed;
	cout.precision(10);
	cout << min(mid1, mid2);
	return 0;
}


//초기코드
/*int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ax, ay, bx, by, cx, cy, dx, dy;
	cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

	int minX = cx - ax, minY = cy - ay;
	int gangX = dx - bx, gangY = dy - bx;

	double min_distance = distance(minX, minY, gangX, gangY);
	for (int i = 1; i <= MAX; i++) {
		double d = distance(minX+minX*i, minY+minY*i, gangX+gangX*i, gangY+gangY*i);
		min_distance = min(min_distance, d);
	}

	cout << min_distance;
	return 0;
}*/

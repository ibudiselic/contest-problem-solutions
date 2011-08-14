/*
ID: ivan.bu1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
bool isLeap(int y) {
	return y%4==0 && (y%100!=0 || y%400==0);
}
struct Date {
	int d, m, y, wd;
	Date(int d_, int m_, int y_, int wd_): d(d_), m(m_), y(y_), wd(wd_) {}
	void next() {
		wd = (wd+1)%7;
		++d;
		if (d > days[m]+(m==2)*isLeap(y)) {
			d = 1;
			++m;
		}
		if (m > 12) {
			++y;
			m = 1;
		}
	}
};

int cnt[7];
int main() {
	ifstream fin("friday.in");
    ofstream fout("friday.out");

	int N;
	fin >> N;

	Date d(1, 1, 1900, 2);
	while (1) {
		if (d.y==1900+N-1 && d.m==12 && d.d==31)
			break;
		d.next();
		if (d.d == 13)
			++cnt[d.wd];
	}

	for (int i=0; i<7; ++i) {
		if (i)
			fout << ' ';
		fout << cnt[i];
	}
	fout << '\n';

	return 0;
}

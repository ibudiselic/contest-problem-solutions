/*
ID: ivan.bu1
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

char digit(int d) {
	if (d < 10)
		return '0'+d;
	else
		return 'A' + (d-10);
}
string convert(int x, int B) {
	static char buff[128];
	int n = 127;
	while (x > 0) {
		int d = x%B;
		x /= B;
		buff[n--] = digit(d);
	}

	return string(buff+n+1, buff+128);
}

bool isPalin(const string &s) {
	for (int i=0; i<(int)s.size()/2; ++i)
		if (s[i] != s[(int)s.size()-1-i])
			return false;
	return true;
}
bool isPalin(int x, int B) {
	return isPalin(convert(x, B));
}
int main() {
	ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");

	int B;
	fin >> B;

	for (int i=1; i<=300; ++i)
		if (isPalin(i*i, B))
			fout << convert(i, B) << ' ' << convert(i*i, B) << '\n';

	return 0;
}

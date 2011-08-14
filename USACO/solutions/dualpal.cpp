/*
ID: ivan.bu1
PROG: dualpal
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
	return '0'+d;
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
bool isDualPal(int x) {
	int cntBases = 0;
	for (int B=2; B<=10; ++B)
		if ((cntBases += isPalin(x, B)) == 2)
			return true;
	return false;
}
int main() {
	ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");

	int N, S;
	fin >> N >> S;

	while (true) {
		++S;
		if (isDualPal(S)) {
			fout << S << '\n';
			if (--N == 0)
				break;
		}
	}
	return 0;
}

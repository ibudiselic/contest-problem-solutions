/*
ID: ivan.bu1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int calc(const string &s) {
	int ret = 1;
	for (int i=0; i<(int)s.size(); ++i)
		ret = (ret * (s[i]-'A'+1))%47;

	return ret;
}
int main() {
    ofstream fout("ride.out");
    ifstream fin("ride.in");

	string a, b;
	fin >> a >> b;
	int x = calc(a);
	int y = calc(b);

	fout << (x==y ? "GO" : "STAY") << '\n';
	return 0;
}

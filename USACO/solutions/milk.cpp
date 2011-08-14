/*
ID: ivan.bu1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <utility>

using namespace std;

int main() {
	ifstream fin("milk.in");
    ofstream fout("milk.out");

	int total, n;
	fin >> total >> n;

	vector< pair<long long, long long> > v;
	for (int i=0; i<n; ++i) {
		long long p, a;
		fin >> p >> a;
		v.push_back(make_pair(p, a));
	}

	sort(v.begin(), v.end());

	int i = 0;
	long long sol = 0;
	while (total > 0) {
		if (total - v[i].second < 0) {
			sol += total*v[i].first;
			total = 0;
		} else {
			sol += v[i].second*v[i].first;
			total -= v[i].second;
		}
		++i;
	}

	fout << sol << '\n';

	return 0;
}

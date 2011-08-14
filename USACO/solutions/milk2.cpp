/*
ID: ivan.bu1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
	ifstream fin("milk2.in");
    ofstream fout("milk2.out");

	int N;
	fin >> N;
	vector<int> start(N+1, 0);
	vector<int> end(N+1, 0);
	for (int i=0; i<N; ++i)
		fin >> start[i] >> end[i];
	start[N] = 1234567890;
	end[N] = 1234567890;
	sort(start.begin(), start.end());
	sort(end.begin(), end.end());

	int cnt = 0;
	int i=0, j=0;
	int startW = -1;
	int startWO = -1;
	int longestWith = 0;
	int longestWO = 0;
	while (true) {
		int time = min(start[i], end[j]);
		if (time == 1234567890)
			break;
		while (start[i] == time) {
			++i;
			++cnt;
		}
		while (end[j] == time) {
			++j;
			--cnt;
		}

		if (cnt == 0) {
			if (startW != -1)
				longestWith = max(longestWith, time-startW);
			startW = -1;
			if (startWO == -1)
				startWO = time;
		} else {
			if (startW == -1)
				startW = time;
			if (startWO != -1)
				longestWO = max(longestWO, time-startWO);
			startWO = -1;
		}
	}

	fout << longestWith << ' ' << longestWO << '\n';
	return 0;
}

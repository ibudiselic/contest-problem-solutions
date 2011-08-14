/*
ID: ivan.bu1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

/*
 Line 1:  	 The single integer, NP
Lines 2..NP+1: 	Each line contains the name of a group member
Lines NP+2..end: 	NP groups of lines organized like this:
The first line in the group tells the person's name who will be giving gifts.
The second line in the group contains two numbers: The initial amount of money (in the range 0..2000) to be divided up into gifts by the giver and then the number of people to whom the giver will give gifts, NGi (0 = NGi = NP-1).
If NGi is nonzero, each of the next NGi lines lists the the name of a recipient of a gift.
*/
int main() {
	ifstream fin("gift1.in");
    ofstream fout("gift1.out");

	int n;
	fin >> n;

	vector<string> names(n);
	map<string, int> ind;
	for (int i=0; i<n; ++i) {
		fin >> names[i];
		ind[names[i]] = i;
	}

	vector<int> has(n, 0);
	vector< vector<int> > to(n, vector<int>());
	string name;
	for (int i=0; i<n; ++i) {
		fin >> name;
		int cnt;
		fin >> has[ind[name]] >> cnt;

		string t;
		for (int j=0; j<cnt; ++j) {
			fin >> t;
			to[ind[name]].push_back(ind[t]);
		}
	}

	vector<int> had = has;
	vector<int> after(n, 0);
	for (int i=0; i<n; ++i)
		if (to[i].size() > 0) {
			int add = has[i]/to[i].size();
			has[i] -= add*to[i].size();
			for (int j=0; j<(int)to[i].size(); ++j)
				after[to[i][j]] += add;
		}

	for (int i=0; i<n; ++i)
		fout << names[i] << ' ' << has[i]+after[i] - had[i] << '\n';

	return 0;
}

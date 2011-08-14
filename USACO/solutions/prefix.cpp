/*
ID: ivan.bu1
PROG: prefix
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>

using namespace std;

bool can[200001];
int main() {
	ifstream fin("prefix.in");
    vector<string> primitives;
    string s;
    while (true) {
        fin >> s;
        if (s == ".") {
            break;
        }
        primitives.push_back(s);
    }
    sort(primitives.begin(), primitives.end());
    
    string S;
    while (fin >> s) {
        S += s;
    }
    fin.close();

    can[0] = true;
    int sol = 0;
    for (int i=0; i<(int)S.size(); ++i) {
        if (can[i]) {
            sol = i;
            string tmp;
            for (int len=1; len<=10; ++len) {
                if (i + len > (int)S.size()) {
                    break;
                }
                tmp += S[i+len-1];
                if (can[i+len]) {
                    continue;
                }
                int pos = lower_bound(primitives.begin(), primitives.end(), tmp) - primitives.begin();
                if (pos<(int)primitives.size() && primitives[pos]==tmp) {
                    can[i+len] = true;
                }
            }
        }
    }
    if (can[S.size()]) {
        sol = S.size();
    }
    ofstream fout("prefix.out");
    fout << sol << endl;
    fout.close();

	return 0;
}


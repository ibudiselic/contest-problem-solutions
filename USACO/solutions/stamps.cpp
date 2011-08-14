/*
ID: ivan.bu1
PROG: stamps
LANG: C++
*/
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <queue>

using namespace std;

unsigned char cnt[2000002];
int main() {
	ifstream fin("stamps.in");
    int k, n;
    fin >> k >> n;
    vector<int> v;
    copy(istream_iterator<int>(fin), istream_iterator<int>(), back_inserter(v));
    fin.close();
    
    sort(v.begin(), v.end());
    
    ofstream fout("stamps.out");
    if (n == 1) {
        if (v[0] == 1) {
            fout << k << '\n';
        } else {
            fout << 0 << '\n';
        }
    } else {
        memset(cnt, 0xff, sizeof cnt);
        cnt[0] = 0;
        int i = 0;
        while (cnt[i] <= k) {
            ++i;
            for (int j=0; j<(int)v.size(); ++j) {
                if (i-v[j] >= 0) {
                    cnt[i] = min(cnt[i], (unsigned char)(cnt[i-v[j]] + 1));
                }
            }
        }
        fout << i-1 << '\n';
    }
    fout.close();

	return 0;
}

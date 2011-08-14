/*
ID: ivan.bu1
PROG: kimbits
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

using namespace std;

int N, L;
long long dp[32][32];
long long get_cnt(int p, int rem1) {
    long long &ret = dp[p][rem1];
    if (ret != -1) {
        return ret;
    }
    if (p == N) {
        return ret = 1;
    }
    ret = get_cnt(p+1, rem1);
    if (rem1 > 0) {
        ret += get_cnt(p+1, rem1-1);
    }
    return ret;
}
int main() {
	ifstream fin("kimbits.in");
    long long k;
    fin >> N >> L >> k;
    fin.close();

    --k;
    string sol;
    int rem1 = L;
    memset(dp, 0xff, sizeof dp);
    for (int i=0; i<N; ++i) {
        long long t = get_cnt(i+1, rem1);
        if (t > k) {
            sol += '0';
        } else {
            k -= t;
            sol += '1';
            --rem1;
        }
    }
    ofstream fout("kimbits.out");
    fout << sol << '\n';
    fout.close();

	return 0;
}

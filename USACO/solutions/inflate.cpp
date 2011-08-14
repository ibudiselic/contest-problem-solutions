/*
ID: ivan.bu1
PROG: inflate
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

int value[10000], duration[10000];
int dp[10001];
int main() {
	ifstream fin("inflate.in");
    int T, n;
    fin >> T >> n;
    for (int i=0; i<n; ++i) {
        fin >> value[i] >> duration[i];
    }
    fin.close();
    
    dp[0] = 0;
    for (int i=1; i<=T; ++i) {
        dp[i] = dp[i-1];
        for (int j=0; j<n; ++j) {
            if (duration[j] <= i) {
                dp[i] = max(dp[i], dp[i-duration[j]] + value[j]);
            }
        }
    }

    ofstream fout("inflate.out");
    fout << dp[T] << '\n';
    fout.close();

	return 0;
}

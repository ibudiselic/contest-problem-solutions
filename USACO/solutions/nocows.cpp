/*
ID: ivan.bu1
PROG: nocows
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

int dp[100][200][2];
const int mod = 9901;
int go(int k, int n, bool eq_k) {
    int &ret = dp[k][n][eq_k];
    if (ret != -1) {
        return ret;
    }
    if (k == 1) {
        if (eq_k) {
            return ret = (n==1);
        } else {
            return ret = (n==0);
        }
    }
    if (--n == 0) {
        return ret = !eq_k;
    } else {
        ret = 0;
        if (eq_k) {
            for (int i=1; i<n; ++i) {
                for (int eq1=0; eq1<2; ++eq1) {
                    for (int eq2=0; eq2<2; ++eq2) {
                        if (eq1 || eq2) {
                            ret += go(k-1, i, eq1)*go(k-1, n-i, eq2)%mod;
                        }
                    }
                }
            }
        } else {
            for (int i=1; i<n; ++i) {
                ret += go(k-1, i, 0)*go(k-1, n-i, 0)%mod;
            }
        }
    }
    ret %= mod;
    return ret;
}
int main() {
    int N, K;
	ifstream fin("nocows.in");
    fin >> N >> K;
    fin.close();
    
    memset(dp, 0xff, sizeof dp);
    ofstream fout("nocows.out");
    fout << go(K, N, 1) << '\n';
    fout.close();

	return 0;
}

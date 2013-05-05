#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

int N, K;
const int MAXN = 1000000;
char S[MAXN+1];
const int mod = 1000000007;
int waysB[MAXN], waysW[MAXN], totalW[MAXN];
int total_ways[MAXN];
int cntA[MAXN+1], cntB[MAXN+1];
int add(int a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
    return a;
}
int sub(int a, int b) {
    a -= b;
    if (a < 0) {
        a += mod;
    }
    return a;
}
void calc(char need, int *ways) {
    for (int i=0; i<N; ++i) {
        cntA[i+1] = cntA[i];
        cntB[i+1] = cntB[i];
        if (S[i] == need) {
            ++cntA[i+1];
        } else if (S[i] != 'X') {
            ++cntB[i+1];
        }
    }
    for (int i=0; i+1<K; ++i) {
        total_ways[i] = i>0 ? total_ways[i-1] : 1;
        if (S[i] == 'X') {
            total_ways[i] = add(total_ways[i], total_ways[i]);
        }
        ways[i] = 0;
    }
    for (int i=K-1; i<N; ++i) {
        total_ways[i] = i>0 ? total_ways[i-1] : 1;
        if (S[i] == 'X') {
            total_ways[i] = add(total_ways[i], total_ways[i]);
        }

        if (need == 'W') {
            ways[i] = 0; // for 'W' compute only the ways to end exactly on K Ws
        } else {
            ways[i] = i>0 ? ways[i-1] : 0;
            if (S[i] == 'X') {
                ways[i] = add(ways[i], ways[i]);
            }
        }
        totalW[i] = i>0 ? totalW[i-1] : 0;
        if (S[i] == 'X') {
            totalW[i] = add(totalW[i], totalW[i]);
        }

        if (i-K>=0 && S[i-K]==need) continue;
        int other = cntB[i+1] - cntB[i-K+1];
        if (other == 0) {
            int prev = 1;
            if (i-K >= 0) {
                assert(S[i-K] != need);
                if (i-K-1 >= 0) {
                    prev = sub(total_ways[i-K-1], totalW[i-K-1]);
                }
            }
            ways[i] = add(ways[i], prev);
            totalW[i] = add(totalW[i], prev);
        }

        if (need == 'B') {
            assert(ways[i] == totalW[i]);
        }
    }
}
int main() {
    scanf("%d %d", &N, &K);
    scanf("%s", S);
    calc('B', waysB);
    reverse(S, S+N);
    calc('W', waysW);

    long long sol = 0;
    for (int i=K-1; i+K<N; ++i) {
        sol = (sol + (long long)waysB[i]*waysW[N-i-2])%mod;
    }
    printf("%d\n", int(sol));
    return 0;
}

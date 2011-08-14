/*
ID: ivan.bu1
PROG: shopping
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
#include <utility>

using namespace std;

int transl[1010];
int C[5], K[5], P[5];
int dp[6][6][6][6][6];
int main() {
    vector< pair<int, vector< pair<int, int> > > > special;
	ifstream fin("shopping.in");
    int s;
    fin >> s;
    for (int i=0; i<s; ++i) {
        int n;
        fin >> n;
        vector< pair<int, int> > v;
        for (int j=0; j<n; ++j) {
            int c, k;
            fin >> c >> k;
            v.push_back(make_pair(c, k));
        }
        int p;
        fin >> p;
        special.push_back(make_pair(p, v));
    }
    int n;
    fin >> n;
    memset(transl, 0xff, sizeof transl);
    for (int i=0; i<n; ++i) {
        fin >> C[i] >> K[i] >> P[i];
        transl[C[i]] = i;
    }
    int nxt = 1000;
    while (n < 5) {
        C[n] = nxt;
        K[n] = 0;
        P[n] = 0;
        transl[nxt] = n;
        ++n;
    }
    
    fin.close();
    
    memset(dp, 0x3f, sizeof dp);
    dp[0][0][0][0][0] = 0;
    int inf;
    memset(&inf, 0x3f, sizeof inf);
    for (int i=0; i<s; ++i) {
        int I[5] = {0};
        int p = special[i].first;
        const vector< pair<int, int> > &v = special[i].second;
        for(I[0]=0; I[0]<6; ++I[0]) {
            for(I[1]=0; I[1]<6; ++I[1]) {
                for(I[2]=0; I[2]<6; ++I[2]) {
                    for(I[3]=0; I[3]<6; ++I[3]) {
                        for(I[4]=0; I[4]<6; ++I[4]) {
                            int J[5] = {0};
                            memcpy(J, I, sizeof J);
                            for (int j=0; j<(int)v.size(); ++j) {
                                if (transl[v[j].first] == -1) {
                                    J[0] = -1;
                                    break;
                                }
                                int k = transl[v[j].first];
                                J[k] += v[j].second;
                                if (J[k] > K[k]) {
                                    J[0] = -1;
                                    break;
                                }
                            }
                            if (J[0] == -1) {
                                continue;
                            }
                            dp[J[0]][J[1]][J[2]][J[3]][J[4]] = min(dp[J[0]][J[1]][J[2]][J[3]][J[4]], dp[I[0]][I[1]][I[2]][I[3]][I[4]] + p);
                        }
                    }
                }
            }
        }
    }

    int I[5] = {0};
    int sol = inf;
    for(I[0]=0; I[0]<=K[0]; ++I[0]) {
        int add = (K[0]-I[0]) * P[0];
        for(I[1]=0; I[1]<=K[1]; ++I[1]) {
            add += (K[1]-I[1]) * P[1];
            for(I[2]=0; I[2]<=K[2]; ++I[2]) {
                add += (K[2]-I[2]) * P[2];
                for(I[3]=0; I[3]<=K[3]; ++I[3]) {
                    add += (K[3]-I[3]) * P[3];
                    for(I[4]=0; I[4]<=K[4]; ++I[4]) {
                        add += (K[4]-I[4]) * P[4];
                        sol = min(sol, dp[I[0]][I[1]][I[2]][I[3]][I[4]] + add);
                        add -= (K[4]-I[4]) * P[4];
                    }
                    add -= (K[3]-I[3]) * P[3];
                }
                add -= (K[2]-I[2]) * P[2];
            }
            add -= (K[1]-I[1]) * P[1];
        }
    }
    
    ofstream fout("shopping.out");
    fout << sol << '\n';
    fout.close();

	return 0;
}

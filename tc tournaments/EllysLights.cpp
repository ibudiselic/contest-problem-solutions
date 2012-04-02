#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void remlight(int j, string &L, vector<string> &S, int &m, int &n) {
    L = L.substr(0, j) + (j+1<(int)L.size() ? L.substr(j+1) : string());
    for (int i=0; i<m; ++i) {
        S[i] = S[i].substr(0, j) + (j+1<(int)S[i].size() ? S[i].substr(j+1) : string());
    }
    --n;
}
void remswitch(int i, string &L, vector<string> &S, int &m, int &n) {
    S.erase(S.begin()+i);
    --m;
}
void press(string &L, const string &S) {
    int n = L.size();
    for (int i=0; i<n; ++i) {
        if (S[i] == 'Y') {
            L[i] = (L[i]=='Y' ? 'N' : 'Y');
        }
    }
}
bool G[100][100];
int C[100];
void dfs(int u, int n, int comp) {
    C[u] = comp;
    for (int i=0; i<n; ++i) {
        if (G[u][i] && C[i]==-1) {
            dfs(i, n, comp);
        }
    }
}
bool decided[50];
class EllysLights {
public:
    int getMinimum(string initial, vector <string> switches) {
        int n = initial.size();
        int m = switches.size();
        
        int sol = 0;
        while (true) {
            bool change = false;
            for (int j=0; j<n; ++j) {
                int s1 = -1;
                int s2 = -1;
                for (int i=0; i<m; ++i) {
                    if (switches[i][j] == 'Y') {
                        if (s1 == -1) {
                            s1 = i;
                        } else {
                            assert(s2 == -1);
                            s2 = i;
                        }
                    }
                }
                if (initial[j] == 'Y') {
                    if (s1 == -1) {
                        return -1;
                    }
                    if (s2 == -1) {
                        ++sol;
                        press(initial, switches[s1]);
                        remlight(j, initial, switches, m, n);
                        remswitch(s1, initial, switches, m, n);
                        change = true;
                        break;
                    }
                } else {
                    if (s1 == -1) {
                        remlight(j, initial, switches, m, n);
                        change = true;
                    } else if (s2 == -1) {
                        remlight(j, initial, switches, m, n);
                        remswitch(s1, initial, switches, m, n);
                        change = true;
                        break;
                    }
                }
            }
            if (!change) {
                break;
            }
        }
        
        if (n == 0) {
            return sol;
        }
        if (m == 0) {
            return initial==string(n, 'N') ? sol : -1;
        }
        
        memset(G, 0, sizeof G);
        for (int j=0; j<n; ++j) {
            int s1 = -1;
            int s2 = -1;
            for (int i=0; i<m; ++i) {
                if (switches[i][j] == 'Y') {
                    if (s1 == -1) {
                        s1 = i;
                    } else {
                        assert(s2 == -1);
                        s2 = i;
                    }
                }
            }
            assert(s1!=-1 && s2!=-1);
            // 2-sat
            // each (u | v) clause adds edges !u -> v and !v -> u
            if (initial[j] == 'N') { // neither or both: (!s1&!s2) | (s1&s2) = (!s1&!s2 | s1) & (!s1&!s2 | s2) = ((!s1|s1) & (!s2|s1)) & ((!s1|s2) & (!s2|s2)) = (s1|!s2) & (!s1|s2)
                // !s1 -> !s2 and !!s2 -> s1 == s2 -> s1
                // !!s1 -> s2 == s1 -> s2 and !s2 -> !s1
                G[2*s1][2*s2] = G[2*s2][2*s1] = true;
                G[2*s1+1][2*s2+1] = G[2*s2+1][2*s1+1] = true;
            } else { // exactly one: (s1|s2) & (!s1|!s2)
                // !s1 -> s2 and !s2 -> s1
                // s1 -> !s2 and s2 -> !s1
                G[2*s1][2*s2+1] = G[2*s2+1][2*s1] = true;
                G[2*s1+1][2*s2] = G[2*s2][2*s1+1] = true;
            }
        }
        
        memset(C, 0xff, sizeof C);
        int ncomps = 0;
        for (int i=0; i<2*m; ++i) {
            if (C[i] == -1) {
                dfs(i, 2*m, ncomps++);
            }
            if ((i&1) && C[i]==C[i-1]) { // no 2-sat if u and !u in same component
                return -1;
            }
        }
        
        memset(decided, 0, sizeof decided);
        for (int i=0; i<2*m; i+=2) {
            if (decided[i/2]) {
                continue;
            }
            int on = 1;
            int off = 0;
            for (int j=i+1; j<2*m; ++j) {
                if (decided[j/2]) {
                    ++j;
                    continue;
                }
                if (C[j] == C[i]) {
                    decided[j/2] = true;
                    on += (j&1)^1;
                    off += (j&1);
                }
            }
            decided[i/2] = true;
            sol += min(on, off);
        }
        
        return sol;
    }
};

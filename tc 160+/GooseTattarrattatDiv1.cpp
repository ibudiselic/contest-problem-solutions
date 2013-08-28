#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <numeric>
#include <utility>

using namespace std;

struct UF {
    vector<int> P;
    UF(int n): P(n, -1) {}
    int root(int x) {
        if (P[x] == -1) return x;
        return (P[x] = root(P[x]));
    }
    void join(int x, int y) {
        x = root(x);
        y = root(y);
        if (x != y) {
            P[x] = y;
        }
    }
};

class GooseTattarrattatDiv1 {
public:
    int getmin(string S) {
        int n = S.size();
        UF U(26);
        for (int i=0; i<n; ++i) {
            U.join(S[i]-'a', S[n-1-i]-'a');
        }
        int sol = 0;
        for (int c=0; c<26; ++c) {
            if (U.root(c) == c) {
                vector<int> cnts;
                for (int c2=0; c2<26; ++c2) {
                    if (U.root(c2) == c) {
                        cnts.push_back(count(S.begin(), S.end(), char('a'+c2)));
                    }
                }
                sort(cnts.begin(), cnts.end(), greater<int>());
                sol += accumulate(cnts.begin()+1, cnts.end(), 0);
            }
        }
        return sol;
    }
};

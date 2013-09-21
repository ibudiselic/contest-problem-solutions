#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class FoxAndHandle {
public:
    string lexSmallestName(string S) {
        vector<int> cnt(26);
        for (int i=0; i<(int)S.size(); ++i) {
            ++cnt[S[i]-'a'];
        }
        for (int i=0; i<26; ++i) {
            cnt[i] /= 2;
        }
        int n = S.size()/2;
        string sol(n, ' ');
        vector<int> have(26);
        vector<int> phave(26);
        int where = 0;
        for (int i=0; i<n; ++i) {
            int lowest = 27;
            int pos = -1;
            vector<int> change(26);
            for (int j=where; j<2*n; ++j) {
                if (S[j]-'a'<lowest && have[S[j]-'a']+1<=cnt[S[j]-'a']) {
                    bool ok = true;
                    for (int c=0; c<26; ++c) {
                        if (phave[c]+change[c] > cnt[c]) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        lowest = S[j]-'a';
                        pos = j;
                    }
                }
                ++change[S[j]-'a'];
            }
            assert(pos != -1);
            sol[i] = char(lowest+'a');
            ++have[lowest];
            for (int j=where; j<pos; ++j) {
                ++phave[S[j]-'a'];
            }
            where = pos+1;
        }

        return sol;
    }
};

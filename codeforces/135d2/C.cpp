#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <utility>

using namespace std;

pair<int, string> alternate(string s, char last) {
    int cnt = 0;
    for (int i=0; i<(int)s.size(); ++i) {
        if (s[i] == last) {
            ++cnt;
            s[i] = (last=='A' ? 'B' : 'A');
        }
        last = s[i];
    }
    return make_pair(cnt, s);
}
int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    if (k == 2) {
        pair<int, string> best = alternate(s, 'B');
        pair<int, string> cand = alternate(s, 'A');
        if (cand.first < best.first) {
            best = cand;
        }
        cout << best.first << '\n' << best.second << '\n';
    } else {
        int sol = 0;
        for (int i=1; i<n; ++i) {
            if (s[i] == s[i-1]) {
                ++sol;
                int j;
                for (j=0; j<3; ++j) {
                    if (s[i-1]!=char('A'+j) && (i+1==n || s[i+1]!=char('A'+j))) {
                        break;
                    }
                }
                assert(j < 3);
                s[i] = char('A' + j);
            }
        }
        cout << sol << '\n' << s << '\n';
    }
    return 0;
}

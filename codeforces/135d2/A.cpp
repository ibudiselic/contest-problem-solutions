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

int cnt[26];
int main() {
    int k;
    string s;
    cin >> k >> s;
    if ((int)s.size()%k != 0) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i=0; i<(int)s.size(); ++i) {
        ++cnt[s[i]-'a'];
    }
    string sol;
    for (int i=0; i<26; ++i) {
        if (cnt[i]>0) {
            if (cnt[i]%k!=0) {
                break;
            }
            sol += string(cnt[i]/k, char('a'+i));
        }
    }
    string S;
    for (int i=0; i<k; ++i) {
        S += sol;
    }
    cout << (S.size()==s.size() ? S : string("-1")) << '\n';
    return 0;
}

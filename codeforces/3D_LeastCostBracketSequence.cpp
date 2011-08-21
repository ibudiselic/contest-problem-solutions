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
#include <set>

using namespace std;

string S;
int main() {
    cin >> S;
    int bc = 0;
    long long sol = 0;
    set< pair<int, int> > fix;
    for (int i=0; i<(int)S.size(); ++i) {
        if (S[i] == '(') {
            ++bc;
        } else if (S[i] == ')') {
            --bc;
        } else {
            int a, b;
            cin >> a >> b;
            S[i] = ')';
            --bc;
            sol += b;
            fix.insert(make_pair(a-b, i));
        }
        if (bc < 0) {
            if (fix.size() == 0) {
                cout << "-1\n";
                return 0;
            }
            pair<int, int> tmp = *fix.begin();
            fix.erase(fix.begin());
            sol += tmp.first;
            S[tmp.second] = '(';
            bc += 2;
        }
    }
    
    if (bc != 0) {
        cout << "-1\n";
        return 0;
    }
    
    cout << sol << '\n' << S << '\n';
    return 0;
}

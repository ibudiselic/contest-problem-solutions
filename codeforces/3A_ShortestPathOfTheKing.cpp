#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    cout << max(abs(s[0]-t[0]), abs(s[1]-t[1])) << '\n';
    
    while (s[0]!=t[0] || s[1]!=t[1]) {
        if (s[0] < t[0]) { cout << 'R'; ++s[0]; }
        else if (s[0] > t[0]) { cout << 'L'; --s[0]; }
        if (s[1] < t[1]) { cout << 'U'; ++s[1]; }
        else if (s[1] > t[1]) { cout << 'D'; --s[1]; }
        cout << '\n';
    }
    return 0;
}

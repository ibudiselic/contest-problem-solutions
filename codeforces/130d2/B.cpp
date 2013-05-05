#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string FACES = "TJQKA";
string SUITS = "SDHC";
int val(char c) {
    if ('2'<=c && c<='9') {
        return c-'2';
    } else {
        return 8 + FACES.find(c);
    }
}
int suite(char c) {
    return SUITS.find(c);
}
int encode(const string &vs) {
    return val(vs[0])*4 + suite(vs[1]);
}
void decode(int code, int &v, int &s) {
    v = code/4;
    s = code%4;
}
bool dp[54][54][54][54];
bool done[54][54][54][54];
int n;
vector<int> A;
bool match(int c1, int c2) {
    int v1, s1, v2, s2;
    decode(c1, v1, s1);
    decode(c2, v2, s2);
    return v1==v2 || s1==s2;
}
bool can(int i, int a, int b, int c) {
    bool &ret = dp[i][a][b][c];
    if (done[i][a][b][c]) {
        return ret;
    }
    done[i][a][b][c] = 1;
    if (i == 0) {
        ret = 1;
    } else {
        ret = (match(c, b) && can(i-1, (i-3>=0 ? A[i-3] : 0), a, c))
                ||
              (i-3>=0 && match(c, A[i-3]) && can(i-1, c, a, b));
    }
    return ret;
}
int main() {
    cin >> n;
    for (int i=0; i<n; ++i) {
        string vs;
        cin >> vs;
        A.push_back(encode(vs));
    }
    memset(done, 0, sizeof done);
    if (n == 1) {
        cout << "YES";
    } else if (n == 2) {
        cout << (match(A[1], A[0]) ? "YES" : "NO");
    } else {
        cout << (can(n-1, A[n-3], A[n-2], A[n-1]) ? "YES" : "NO");
    }
    cout << '\n';
    return 0;
}

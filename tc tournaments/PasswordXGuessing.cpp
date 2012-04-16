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

bool ok(const string &s, const string &t) {
    int diff = 0;
    for (int i=0; i<(int)s.size(); ++i) {
        diff += (s[i]!=t[i]);
    }
    return diff==1;
}
bool ok(const string &s, const vector<string> &V) {
    for (int i=0; i<(int)V.size(); ++i) {
        if (!ok(s, V[i])) {
            return false;
        }
    }
    return true;
}
class PasswordXGuessing {
public:
    long long howMany(vector <string> guesses) {
        long long sol = 0;
        int n = guesses[0].size();
        for (int j=0; j<n; ++j) {
            string guess = guesses[0];
            for (char c='0'; c<='9'; ++c) {
                if (c != guesses[0][j]) {
                    guess[j] = c;
                    sol += ok(guess, guesses);
                }
            }
        }
        return sol;
    }
};

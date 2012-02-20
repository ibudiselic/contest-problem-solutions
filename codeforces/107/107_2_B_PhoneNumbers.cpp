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

bool is_taxi(const string &s) {
    char c = s[0];
    for (int i=0; i<(int)s.size(); ++i) {
        if (s[i]!='-' && s[i]!=c) {
            return false;
        }
    }
    return true;
}
bool is_pizza(const string &s) {
    char c = s[0];
    for (int i=1; i<(int)s.size(); ++i) {
        if (s[i] == '-') continue;
        if (s[i] >= c) {
            return false;
        }
        c = s[i];
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    vector<string> names;
    vector<int> taxi, pizza, girls;
    int T=-1, P=-1, G=-1;
    for (int i=0; i<n; ++i) {
        int sz;
        string s;
        cin >> sz >> s;
        names.push_back(s);
        int t=0, p=0, g=0;
        for (int j=0; j<sz; ++j) {
            cin >> s;
            assert(s.size() == 8);
            if (is_taxi(s)) {
                ++t;
            } else if (is_pizza(s)) {
                ++p;
            } else {
                ++g;
            }
        }
        T = max(T, t);
        taxi.push_back(t);
        P = max(P, p);
        pizza.push_back(p);
        G = max(G, g);
        girls.push_back(g);
    }
    
    cout << "If you want to call a taxi, you should call: ";
    int cnt = 0;
    for (int i=0; i<n; ++i) {
        if (taxi[i] == T) {
            if (cnt > 0) {
                cout << ", ";
            }
            ++cnt;
            cout << names[i];
        }
    }
    cout << ".\n";
    cout << "If you want to order a pizza, you should call: ";
    cnt = 0;
    for (int i=0; i<n; ++i) {
        if (pizza[i] == P) {
            if (cnt > 0) {
                cout << ", ";
            }
            ++cnt;
            cout << names[i];
        }
    }
    cout << ".\n";
    cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
    cnt = 0;
    for (int i=0; i<n; ++i) {
        if (girls[i] == G) {
            if (cnt > 0) {
                cout << ", ";
            }
            ++cnt;
            cout << names[i];
        }
    }
    cout << ".\n";
    return 0;
}

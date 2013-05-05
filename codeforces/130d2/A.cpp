#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool iswub(int i, const string &s) {
    return i+2<(int)s.size() && s[i]=='W' && s[i+1]=='U' && s[i+2]=='B';
}
int main() {
    string s;
    cin >> s;
    vector<string> words;
    int start = 0;
    for (int i=0; i<(int)s.size(); ++i) {
        if (iswub(i, s)) {
            if (start < i) {
                words.push_back(s.substr(start, i-start));
            }
            i += 2;
            start = i+1;
        }
    }
    if (start < (int)s.size()) {
        words.push_back(s.substr(start));
    }
    for (int i=0; i<(int)words.size(); ++i) {
        if (i > 0) cout << ' ';
        cout << words[i];
    }
    cout << '\n';
    return 0;
} 

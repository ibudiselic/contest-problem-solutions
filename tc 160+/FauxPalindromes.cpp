//# 
//# => trivial
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

bool palin(string &s) {
    for (int i=0; 2*i<(int)s.size(); ++i) {
        if (s[i] != s[s.size()-1-i]) {
            return false;
        }
    }
    return true;
}
bool fpalin(string &s) {
    string t;
    s += '.';
    for (int i=0; i+1<(int)s.size(); ++i) {
        if (s[i] != s[i+1]) {
            t += s[i];
        }
    }
    return palin(t);
}
class FauxPalindromes {
public:
    string classifyIt(string word) {
        if (palin(word)) return "PALINDROME";
        return (fpalin(word) ? "FAUX" : "NOT EVEN FAUX");
    }
};

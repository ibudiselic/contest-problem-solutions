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

bool ew(const string &a, const string &b) {
    if (a.size() < b.size()) {
        return false;
    }
    return a.substr(a.size()-b.size()) == b;
}
class TwiceString {
public:
    string getShortest(string s) {
        for (int i=1; i<(int)s.size(); ++i) {
            if (ew(s, s.substr(0, s.size()-i))) {
                return s + s.substr(s.size()-i);
            }
        }
        return s + s;
    }
};

//# implementation, strings
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

string V = "aeiouy";
bool isV(char c) {
    return V.find(c) != string::npos;
}
class EllysNewNickname {
public:
    int getLength(string nickname) {
        int sol = 0;
        bool prev = false;
        for (int i=0; i<(int)nickname.size(); ++i) {
            if (isV(nickname[i])) {
                if (!prev) {
                    ++sol;
                    prev = true;
                }
            } else {
                ++sol;
                prev = false;
            }
        }
        return sol;
    }
};

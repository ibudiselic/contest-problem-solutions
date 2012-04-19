#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class KingXNewBaby {
public:
    string isValid(string name) {
        if (name.size() != 8) {
            return "NO";
        }
        string V = "aeiou";
        bool vow = false;
        for (int i=0; i<(int)V.size(); ++i) {
            int cnt = 0;
            for (int j=0; j<(int)name.size(); ++j) {
                cnt += (name[j] == V[i]);
            }
            if (cnt>0 && (cnt!=2 || vow)) {
                return "NO";
            }
            if (cnt > 0) {
                vow = true;
            }
        }
        return vow ? "YES" : "NO";
    }
};

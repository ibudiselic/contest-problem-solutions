//# trivial, implementation
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

class EasyHomework {
public:
    string determineSign(vector <int> A) {
        int cnt = 0;
        for (int i=0; i<(int)A.size(); ++i) {
            if (A[i] == 0) {
                return "ZERO";
            } else if (A[i] < 0) {
                ++cnt;
            }
        }
        return (cnt&1) ? "NEGATIVE" : "POSITIVE";
    }
};

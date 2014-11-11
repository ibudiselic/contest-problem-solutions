//# numbers, squares, implementation, trivial
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

class SemiPerfectSquare {
public:
    string check(int N) {
        for (int a=1; a<=N; ++a) {
            for (int b=a+1; b<=N; ++b) {
                if (a*b*b == N) {
                    return "Yes";
                }
            }
        }
        return "No";
    }
};

#include <algorithm>
#include <cassert>
#include <cctype>
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

class HyperKnight {
public:
    long long countCells(long long a, long long b, long long R, long long C, int k) {
        if (a < b) {
            swap(a, b);
        }
        switch (k) {
            case 8: return (R-2*a)*(C-2*a);
            case 6: return 2*(a-b)*(R-2*a + C-2*a);
            case 4: return 4*(a-b)*(a-b) + 2*b*(R-2*a + C-2*a);
            case 3: return 8*b*(a-b);
            case 2: return 4*b*b;
            default: return 0;
        }
    }
};

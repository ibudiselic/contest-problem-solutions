//# dp, simple dp
//# => can use the same version as in div1 or just enumerate all possible choices as n is at most 20
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

long long best[110];
const long long inf = 12345678901234567ll;
class MonstersValley2 {
public:
    int minimumPrice(vector <int> dread, vector <int> price) {
        int n = dread.size();
        for (int p=0; p<=2*n; ++p) {
            best[p] = -inf;
        }
        best[0] = 0;
        for (int i=0; i<n; ++i) {
            for (int p=2*n; p>=price[i]; --p) {
                best[p] = max(best[p], best[p-price[i]]+dread[i]);
            }
            for (int p=0; p<=2*n; ++p) {
                if (best[p] < dread[i]) {
                    best[p] = -inf;
                }
            }
        }

        for (int p=0; p<=2*n; ++p) {
            if (best[p] >= 0) {
                return p;
            }
        }
        return -1;
    }
};

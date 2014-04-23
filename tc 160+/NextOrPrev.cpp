//# strings, transformations, implementation, graph
//# => Draw a picture. Write out the characters found in start in the first row and the characters found in goal in the second row and connect them with directed edges. Iff the edges cross, there is no solution, otherwise there is a unique solution that can be easily computed.
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

bool intersects(char a, char b, char c, char d) {
    return c>a && d<b;
}
class NextOrPrev {
public:
    int getMinimum(int nextCost, int prevCost, string start, string goal) {
        int n = start.size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (i!=j && intersects(start[i], goal[i], start[j], goal[j])) {
                    return -1;
                }
            }
        }
        int sol = 0;
        for (int i=0; i<n; ++i) {
            if (start[i] < goal[i]) {
                sol += (goal[i]-start[i])*nextCost;
            } else if (start[i] > goal[i]) {
                sol += (start[i]-goal[i])*prevCost;
            }
        }
        return sol;
    }
};

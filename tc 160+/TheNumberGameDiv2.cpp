//# bfs, strings, transformation
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
#include <sstream>

using namespace std;

string tostr(int A) {
    ostringstream os;
    os << A;
    return os.str();
}
class TheNumberGameDiv2 {
public:
    int minimumMoves(int A, int B) {
        string a = tostr(A);
        string b = tostr(B);
        set<string> done;
        done.insert(a);
        queue<string> Q;
        Q.push(a);
        int dist = 0;
        int sz = 1;
        while (!Q.empty()) {
            if (sz == 0) {
                sz = Q.size();
                ++dist;
            }
            a = Q.front();
            Q.pop();
            --sz;
            if (a == b) {
                return dist;
            }
            if (a.size() < b.size()) continue;
            if (a.size() > 1) {
                string t = a.substr(0, a.size()-1);
                if (!done.count(t)) {
                    done.insert(t);
                    Q.push(t);
                }
            }
            reverse(a.begin(), a.end());
            if (!done.count(a)) {
                done.insert(a);
                Q.push(a);
            }
        }
        return -1;
    }
};

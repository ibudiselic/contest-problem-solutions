//# implementation, strings, sorting
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

string fname(int x) {
    ostringstream os;
    os << x << ".mp3";
    return os.str();
}
void go(int x, int n, vector<string> &sol) {
    if (sol.size()==50 || x>n) return;
    do {
        sol.push_back(fname(x));
        go(x*10, n, sol);
        ++x;
    } while (x%10!=0 && x<=n && sol.size()<50);
}
class FoxAndMp3Easy {
public:
    vector <string> playList(int n) {
        vector<string> sol;
        go(1, n, sol);
        return sol;
    }
};

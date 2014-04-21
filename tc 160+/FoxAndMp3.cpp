//# recursion, implementation, strings, order
//# => Have a recursive function that creates all the files with a certain fixed number of digits
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

string fname(long long x) {
    ostringstream os;
    os << x << ".mp3";
    return os.str();
}
void go(long long x, long long n, vector<string> &sol) {
    if (sol.size()==50 || x>n) return;
    do {
        sol.push_back(fname(x));
        go(x*10, n, sol);
        ++x;
    } while(x%10!=0 && sol.size()<50 && x<=n);
}
class FoxAndMp3 {
public:
    vector <string> playList(int n) {
        vector<string> sol;
        go(1, n, sol);
        return sol;
    }
};

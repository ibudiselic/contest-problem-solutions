#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int cnt(const vector<string> &a) {
    int ret = 0;
    for (int i=0; i<(int)a.size(); ++i) {
        ret += count(a[i].begin(), a[i].end(), '1');
    }
    return ret;
}
class P8XMatrixTransformation {
public:
    string solve(vector <string> original, vector <string> target) {
        return cnt(original)==cnt(target) ? "YES" : "NO";
    }
};

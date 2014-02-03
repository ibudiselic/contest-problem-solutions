//# implementation
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

class TheJediTestDiv2 {
public:
    int countSupervisors(vector <int> students, int Y, int J) {
        int n = students.size();
        int sol = 1234567;
        for (int y=0; y<n; ++y) {
            int cand = 0;
            students[y] -= Y;
            for (int i=0; i<n; ++i) {
                cand += (max(0, students[i]) + J - 1)/J;
            }
            students[y] += Y;
            sol = min(sol, cand);
        }
        return sol;
    }
};

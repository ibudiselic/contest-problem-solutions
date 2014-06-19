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

class TheExperimentDiv2 {
public:
    vector <int> determineHumidity(vector <int> intensity, int L, vector <int> leftEnd) {
        int n = leftEnd.size();
        vector<int> sol(n);
        for (int i=0; i<(int)intensity.size(); ++i) {
            int add = intensity[i];
            for (int j=0; j<n; ++j) {
                if (leftEnd[j]<=i && i<leftEnd[j]+L) {
                    sol[j] += add;
                    break;
                }
            }
        }
        return sol;
    }
};

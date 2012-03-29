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

int calc(vector<int> T, vector<int> S) {
    int ret = 0;
    for (int i=0; i<(int)T.size(); ++i) {
        ret += abs(T[i]-S[i]);
    }
    return ret/2;
}
class GogoXBallsAndBinsEasy {
public:
    int solve(vector <int> T) {
        vector<int> S = T;
        int sol = 0;
        do {
            sol = max(sol, calc(S, T));
        } while (next_permutation(S.begin(), S.end()));
        return sol;
    }
};

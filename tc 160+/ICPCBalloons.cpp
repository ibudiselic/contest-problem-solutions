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

const int inf = 987654321;
int calc(vector<int> &have, vector<int> &need) {
    int can = 0;
    int must = 0;
    int j = 0;
    for (int i=0; i<(int)need.size(); ++i) {
        if (j == (int)have.size()) {
            must += need[i];
        } else if (need[i] > have[j]) {
            must += need[i]-have[j++];
        } else {
            can += have[j++]-need[i];
        }
    }
    while (j < int(have.size())) {
        can += have[j++];
    }
    return must>can ? inf : must;
}
class ICPCBalloons {
public:
    int minRepaintings(vector <int> balloonCount, string balloonSize, vector <int> maxAccepted) {
        vector<int> big, small;
        for (int i=0; i<(int)balloonSize.size(); ++i) {
            if (balloonSize[i] == 'L') {
                big.push_back(balloonCount[i]);
            } else {
                small.push_back(balloonCount[i]);
            }
        }
        sort(big.begin(), big.end(), greater<int>());
        sort(small.begin(), small.end(), greater<int>());
        sort(maxAccepted.begin(), maxAccepted.end(), greater<int>());

        int sol = inf;
        int n = maxAccepted.size();
        for (int smask=0; smask<(1<<n); ++smask) {
            vector<int> bneed, sneed;
            for (int i=0; i<n; ++i) {
                if (smask & (1<<i)) {
                    sneed.push_back(maxAccepted[i]);
                } else {
                    bneed.push_back(maxAccepted[i]);
                }
            }
            sol = min(sol, calc(small, sneed) + calc(big, bneed));
        }
        return sol==inf ? -1 : sol;
    }
};

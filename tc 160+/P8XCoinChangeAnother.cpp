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

class P8XCoinChangeAnother {
public:
    vector<long long> solve(int N, long long coins_sum, long long coins_count) {
        if (coins_count > coins_sum) {
            return vector<long long>();
        }
        vector<long long> sol(N, 0);
        sol[0] = coins_sum;
        long long need = coins_sum - coins_count;
        for (int i=1; need>0 && i<N; ++i) {
            long long rmv = min(sol[i-1], 2*need);
            sol[i] = rmv/2;
            sol[i-1] -= rmv/2*2;
            need -= rmv/2;
        }
        if (need > 0) {
            return vector<long long>();
        }
        
        return sol;
    }
};

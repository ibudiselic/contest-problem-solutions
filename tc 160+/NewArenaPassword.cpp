//# strings, implementation, graph, tricky
//# => For each i<K, the characters i, i+n-K, i+2*(n-K)... need to be the same, and each of these paths is independent. Count the frequencies of characters on these paths and change all the characters to the most frequent one.
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

class NewArenaPassword {
public:
    int minChange(string P, int K) {
        int n = P.size();
        if (K == n) return 0;
        vector<char> done(n);
        char token = 0;
        int sol = 0;
        for (int i=0; i<K; ++i) {
            if (!done[i]) {
                ++token;
                int j = i;
                map<char, int> cnt;
                int best = 0;
                int total = 0;
                while (j < K) {
                    ++total;
                    done[j] = token;
                    best = max(best, ++cnt[P[j]]);
                    j += n-K;
                }
                if (j < n) {
                    ++total;
                    done[j] = token;
                    best = max(best, ++cnt[P[j]]);
                }
                sol += total - best;
            }
        }
        return sol;
    }
};

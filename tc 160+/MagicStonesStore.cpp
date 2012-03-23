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

class MagicStonesStore {
public:
    string ableToDivide(int n) {
        vector<int> primes;
        for (int i=2; i<2*n; ++i) {
            int d = 2;
            bool is_prime = true;
            while (d*d <= i) {
                if (i%d == 0) {
                    is_prime = false;
                    break;
                }
                ++d;
            }
            if (is_prime) {
                primes.push_back(i);
            }
        }
        primes.push_back(2*n + 123);
        
        for (int i=0; i<(int)primes.size(); ++i) {
            int p = primes[i];
            if (*lower_bound(primes.begin(), primes.end(), 2*n-p) == 2*n-p) {
                return "YES";
            }
        }
        return "NO";
    }
};

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
#include <set>

using namespace std;

// the editorial sol
class BinaryPolynomialDivOne {
public:
    int findCoefficient(vector <int> a, long long m, long long k) {
        int n = a.size();
        set<long long> cur;
        cur.insert(0);
        while (m > 0) {
            long long p = m&(-m);
            set<long long> next;
            for (set<long long>::const_iterator it=cur.begin(); it!=cur.end(); ++it) {
                if ((*it & (p-1)) == (k & (p-1))) {
                    for (int i=0; i<n; ++i) {
                        if (a[i]) {
                            next.insert(*it + i*p);
                        }
                    }
                }
            }
            m -= p;
            cur.swap(next);
        }
        return cur.count(k);
    }
};

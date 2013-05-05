#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class StrangeDictionary {
public:
    vector <double> getExpectedPositions(vector <string> words) {
        int n = words.size();
        int len = words[0].size();

        vector<double> sol;
        for (int i=0; i<n; ++i) {
            const string &u = words[i];
            double val = 0.0;
            for (int j=0; j<n; ++j) {
                if (i == j) {
                    continue;
                }
                const string &v = words[j];
                int nlt = 0;
                int neq = 0;
                int ngt = 0;
                for (int k=0; k<len; ++k) {
                    if (v[k] < u[k]) {
                        ++nlt;
                    } else if (v[k] == u[k]) {
                        ++neq;
                    } else {
                        ++ngt;
                    }
                }
                double p = 1.0;
                for (int k=0; k<=neq; ++k) {
                    double pp = p*nlt/(k+1);
                    for (int l=k+1; l<len; ++l) {
                        pp = pp*(len-l)/(l+1);
                    }
                    val += pp;
                    p = p*(neq-k)/(k+1);
                }
            }
            sol.push_back(val);
        }

        return sol;
    }
};

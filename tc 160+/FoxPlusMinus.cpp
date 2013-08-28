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

class FoxPlusMinus {
public:
    vector <int> maximize(vector <int> first, int N) {
        sort(first.begin(), first.end());
        int m = int(first.size()) + 1;
        int k = first.size()/2;
        if (N < int(first.size())) {
            int x = first.back();
            first.pop_back();
            first.insert(first.begin()+N, x);
            return first;
        } else if (first.size() & 1) {
            if (N%m == (int)first.size()) {
                vector<int> sol;
                for (int i=0; i<k; ++i) {
                    sol.push_back(first[k+i]);
                    sol.push_back(first[i]);
                }
                sol.push_back(first.back());
                return sol;
            } else {
                int x = first.back();
                first.pop_back();
                first.insert(first.begin()+N%m, x);
                return first;
            }
        } else {
            vector<int> coeff;
            int T = N - int(first.size());
            for (int i=0; i<min(T, int(first.size())); ++i) {
                coeff.push_back(i+1);
            }
            for (int i=T; i<(int)first.size(); ++i) {
                coeff.push_back(T+1);
            }
            for (int i=0; i<(int)coeff.size(); ++i) {
                if ((i&1) != ((N%int(coeff.size())) & 1)) {
                    coeff[i] = -coeff[i];
                }
            }

            vector<pair<int, int> > v;
            for (int i=0; i<(int)coeff.size(); ++i) {
                v.push_back(make_pair(coeff[i], i));
            }
            sort(v.begin(), v.end());
            vector<int> sol(m-1);
            for (int i=0; i<(int)v.size(); ++i) {
                sol[v[i].second] = first[i];
            }

            return sol;
        }
    }
};

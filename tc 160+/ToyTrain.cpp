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

bool buy[10];
class ToyTrain {
public:
    int getMinCost(vector <string> A) {
        int m = A.size();
        int n = A[0].size();

        bool any = false;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (A[i][j]=='A' || A[i][j]=='B') {
                    any = true;
                    break;
                }
            }
        }
        if (!any) {
            return -1;
        }

        memset(buy, 0, sizeof buy);
        for (int iter=0; iter<2; ++iter) {
        for (int i=0; i<m; ++i) {
            int last = -1;
            char type = '0';
            for (int j=0; j<n; ++j) {
                if (A[i][j]=='A' || A[i][j]=='B') {
                    if (last == -1) {
                        last = j;
                        type = A[i][j];
                    } else {
                        if (type == A[i][j]) {
                            return -1;
                        }
                        for (int k=last+1; k<j; ++k) {
                            if (isdigit(A[i][k])) {
                                buy[A[i][k]-'0'] = true;
                                A[i][k] = '.';
                            }
                            if (A[i][k]=='.' || A[i][k]=='S') {
                                A[i][k] = 't'; // taken in this direction
                            } else {
                                return -1;
                            }
                        }
                        last = -1;
                    }
                }
            }
            if (last != -1) {
                return -1;
            }
        }
        vector<string> B(n, string(m, ' '));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                B[j][i] = A[i][j];
            }
        }
        swap(m, n);
        A.swap(B);
        }
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (A[i][j] == 'S') {
                    return -1;
                }
            }
        }
        int sol = 0;
        for (int i=0; i<10; ++i) {
            if (buy[i]) {
                sol += i;
            }
        }
        return sol;
    }
};

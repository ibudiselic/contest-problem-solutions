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

class MagicalSquare {
public:
    long long getCount(vector <string> R, vector <string> C) {
        long long sol = 0;
        int a = -1;
        do {
            ++a;
            int b = -1;
            do {
                ++b;
                if (b>0 && C[0].substr(C[0].size()-b)!=R[2].substr(0, b)) {
                    continue;
                }
                int c0mid = C[0].size() - a - b;
                if (c0mid>(int)R[1].size() || (c0mid>0 && R[1].substr(0, c0mid)!=C[0].substr(a, c0mid))) {
                    continue;
                }
                int c = -1;
                do {
                    ++c;
                    if (c>0 && C[2].substr(0, c)!=R[0].substr(R[0].size()-c)) {
                        continue;
                    }
                    int r0mid = R[0].size() - a - c;
                    if (r0mid>(int)C[1].size() || (r0mid>0 && C[1].substr(0, r0mid)!=R[0].substr(a, r0mid))) {
                        continue;
                    }
                    int d = -1;
                    do {
                        ++d;
                        int c1end = C[1].size() - r0mid - d;
                        if (c1end+b>(int)R[2].size() || (c1end>0 && R[2].substr(b, c1end)!=C[1].substr(r0mid+d))) {
                            continue;
                        }
                        int r1end = R[1].size() - c0mid - d;
                        if (r1end+c>(int)C[2].size() || (r1end>0 && C[2].substr(c, r1end)!=R[1].substr(c0mid+d))) {
                            continue;
                        }
                        
                        int c2end = (int)C[2].size() - r1end - c;
                        if (c2end < 0) {
                            continue;
                        }
                        int r2end = (int)R[2].size() - c1end - b;
                        if (r2end!=c2end || (r2end>0 && R[2].substr(c1end+b)!=C[2].substr(r1end+c))) {
                            continue;
                        }
                        
                        ++sol;
                    } while (c0mid+d<(int)R[1].size() && r0mid+d<(int)C[1].size() && R[1][c0mid+d]==C[1][r0mid+d]);
                } while (a+c<(int)R[0].size() && c<(int)C[2].size());
            } while (a+b<(int)C[0].size() && b<(int)R[2].size());
        } while (a<(int)R[0].size() && a<(int)C[0].size() && R[0][a]==C[0][a]);
        
        return sol;
    }
};

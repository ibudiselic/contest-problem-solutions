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

int can_match(int i, int itr, vector<int> &match, vector<int> &rmatch, vector<int> &A, vector<int> &B, vector<string> &G, vector<int> &vis) {
    vis[i] = itr;
    for (int j=0; j<(int)B.size(); ++j) {
        if (G[A[i]][B[j]] == 'N') continue;
        if (rmatch[j]==-1 || (vis[rmatch[j]]!=itr && can_match(rmatch[j], itr, match, rmatch, A, B, G, vis))) {
            rmatch[j] = i;
            match[i] = j;
            return 1;
        }
    }
    return 0;
}
int bimatch(vector<int> &A, vector<int> &B, vector<string> &G) {
    vector<int> match(A.size(), -1);
    vector<int> rmatch(B.size(), -1);
    vector<int> vis(A.size(), -1);
    int ret = 0;
    for (int i=0; i<(int)A.size(); ++i) {
        ret += can_match(i, i, match, rmatch, A, B, G, vis);
    }
    return ret;
}
class GearsDiv1 {
public:
    int getmin(string color, vector <string> graph) {
        string colors = "RGB";
        int sol = 1234;
        for (int iteration=0; iteration<3; ++iteration) {
            vector<int> A, B;
            for (int i=0; i<(int)color.size(); ++i) {
                if (color[i] == colors[0]) {
                    A.push_back(i);
                } else if (color[i] == colors[1]) {
                    B.push_back(i);
                }
            }
            sol = min(sol, bimatch(A, B, graph));
            rotate(colors.begin(), colors.begin()+1, colors.end());
        }
        return sol;
    }
};

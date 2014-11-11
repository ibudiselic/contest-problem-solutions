//# buidlings, colors, dp, advanced dp
//# => The highest building is always visible so it's sensible to start with it. Process the buildings in decreasing order of height. The simple dp approach with state space [first_i_buidlings_considered][color_of_the_leftmost_building][number_of_colors] is too slow. The key idea is to notice that when updating dp values for the ith building, all the lastcolor values except color[i] have a very simple formula and only the color[i] case is "special". The simple case can be handled independent of the number of colors by lazy multiplication and the special case of color[i] is rewritten in a way that it only depends on the [i-1] values for the same color[i] and a total that is kept up to date. This makes it possible to apply the lazy multiplication to the color[i] values of [i-1] before they get used... Additionally, the whole thing needs to be stored in a single "layer" on the first dimension (similar to some knapsack variations e.g.) so that we don't need to copy the values...
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

vector<int> f(vector <string> color1, vector <string> color2) {
    string s1 = accumulate(color1.begin(), color1.end(), string());
    string s2 = accumulate(color2.begin(), color2.end(), string());
    map<string, int> M;
    int cnt = 0;
    int n = s1.size();
    vector<int> C(n, 0);
    for (int i=0; i<n; ++i) {
        string c{s1[i], s2[i]};
        if (M.count(c)) {
            C[i] = M[c];
        } else {
            C[i] = cnt;
            M[c] = cnt++;
        }
    }
    return C;
}
const int mod = 1000000009;
inline int modmul(long long a, long long b) {
    a *= b;
    return int(a>=mod ? a%mod : a);
}
inline int modadd(int a, int b) {
    a += b;
    return a>=mod ? a-mod : a;
}

int ways[1500][1500];
int total[1500];
int colmul[1500];
class ColorfulBuilding {
public:
    int count(vector <string> color1, vector <string> color2, int L) {
        vector<int> C = f(color1, color2);
        reverse(begin(C), end(C));

        int n = C.size();
        int cnum = *max_element(begin(C), end(C)) + 1;

        memset(ways, 0, sizeof ways);
        memset(total, 0, sizeof total);

        for (int i=0; i<cnum; ++i) {
            colmul[i] = 1;
        }

        ways[C[0]][1] = 1;
        total[1] = 1;
        for (int i=1; i<n; ++i) {
            for (int cols=1; cols<=L; ++cols) {
                ways[C[i]][cols] = modmul(ways[C[i]][cols], colmul[C[i]]);
            }
            colmul[C[i]] = 1;

            for (int cols=L; cols>=1; --cols) {
                total[cols] = modmul(total[cols], i);
                total[cols] = modadd(total[cols], ways[C[i]][cols]);
                int add = modadd(total[cols-1], mod-ways[C[i]][cols-1]);
                total[cols] = modadd(total[cols], add);

                ways[C[i]][cols] = modmul(ways[C[i]][cols], i+1);
                ways[C[i]][cols] = modadd(ways[C[i]][cols], add);
            }
            for (int c=0; c<cnum; ++c) {
                if (c != C[i]) {
                    colmul[c] = modmul(colmul[c], i);
                }
            }
        }

        return total[L];
    }
};

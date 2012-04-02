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
#include <map>
#include <utility>

using namespace std;

void winner(const vector<string> &P, set<string> &sol) {
    int t = (1<<(P.size()+2));
    int have[2] = {t, t};
    map<string, int> M;
    for (int i=0; i<(int)P.size(); ++i) {
        M[P[i]] += have[i&1]/2;
        have[i&1] /= 2;
    }
    vector< pair<int, string> > v;
    for (map<string, int>::const_iterator it=M.begin(); it!=M.end(); ++it) {
        v.push_back(make_pair(it->second, it->first));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    if (v.size()==1 || v[0].first>v[1].first) {
        sol.insert(v[0].second);
    }
}
class EllysJuice {
public:
    vector <string> getWinners(vector <string> players) {
        set<string> sol;
        sort(players.begin(), players.end());
        do {
            winner(players, sol);
        } while (next_permutation(players.begin(), players.end()));
        return vector<string>(sol.begin(), sol.end());
    }
};

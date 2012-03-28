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
#include <map>
#include <utility>

using namespace std;

int V[256];
int from_roman(const string &s) {
    int ret = 0;
    int n = s.size();
    for (int i=n-1; i>=0; --i) {
        int j = i-1;
        int t = V[s[i]];
        while (j>=0 && V[s[j]]<V[s[i]]) {
            t -= V[s[j]];
            --j;
        }
        ret += t;
        i = j + 1;
    }
    return ret;
}
class KingSort {
public:
    vector <string> getSortedList(vector <string> kings) {
        V['I'] = 1;
        V['V'] = 5;
        V['X'] = 10;
        V['L'] = 50;
        int n = kings.size();
        map<string, vector< pair<int, int> > > M;
        for (int i=0; i<n; ++i) {
            int p = kings[i].find(' ');
            string name = kings[i].substr(0, p);
            int val = from_roman(kings[i].substr(p+1));
            M[name].push_back(make_pair(val, i));
        }
        
        vector<string> sol;
        for (map<string, vector< pair<int, int> > >::iterator it=M.begin(); it!=M.end(); ++it) {
            vector< pair<int, int> > &v = it->second;
            sort(v.begin(), v.end());
            for (int i=0; i<(int)v.size(); ++i) {
                sol.push_back(kings[v[i].second]);
            }
        }
        return sol;
    }
};

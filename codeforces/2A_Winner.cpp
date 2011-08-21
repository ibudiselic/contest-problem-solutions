#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<string> name(n);
    vector<int> val(n);
    for (int i=0; i<n; ++i) {
        cin >> name[i] >> val[i];
    }

    map<string, int> V;
    for (int i=0; i<n; ++i) {
        V[name[i]] += val[i];
    }

    int maxval = 0;
    for (map<string, int>::const_iterator it=V.begin(); it!=V.end(); ++it) {
        maxval = max(maxval, it->second);
    }
    
    set<string> S;
    for (map<string, int>::const_iterator it=V.begin(); it!=V.end(); ++it) {
        if (it->second == maxval) {
            S.insert(it->first);
        }
    }
    
    map<string, int> V2;
    for (int i=0; i<n; ++i) {
        if (S.count(name[i]) && (V2[name[i]]+=val[i])>=maxval) {
            cout << name[i] << '\n';
            break;
        }
    }
    
    return 0;
}

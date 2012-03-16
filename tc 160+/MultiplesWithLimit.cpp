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
#include <queue>

using namespace std;

vector<int> digs;
int Prem[10000];
int Pdig[10000];
string reconstruct() {
    string sol;
    int rem = 0;
    do {
        sol += Pdig[rem]+'0';
        rem = Prem[rem];
    } while (rem != 0);
    reverse(sol.begin(), sol.end());
    if (sol.size() < 9) {
        return sol;
    } else {
        ostringstream os;
        os << sol.substr(0, 3) << "..." << sol.substr((int)sol.size()-3) << '(' << sol.size() << " digits)";
        return os.str();
    }
}
class MultiplesWithLimit {
public:
    string minMultiples(int N, vector <int> forbiddenDigits) {
        digs.clear();
        vector<int> ok(10, 1);
        for (int i=0; i<(int)forbiddenDigits.size(); ++i) {
            ok[forbiddenDigits[i]] = false;
        }
        for (int i=0; i<10; ++i) {
            if (ok[i]) {
                digs.push_back(i);
            }
        }
        
        memset(Prem, -1, sizeof Prem);
        queue<int> Q;
        Q.push(0);
        while (!Q.empty()) {
            int rem = Q.front();
            Q.pop();
            for (int i=0; i<(int)digs.size(); ++i) {
                if (rem==0 && digs[i]==0) {
                    continue;
                }
                int nrem = (rem*10 + digs[i])%N;
                if (Prem[nrem] != -1) {
                    continue;
                }
                Prem[nrem] = rem;
                Pdig[nrem] = digs[i];
                if (nrem == 0) {
                    return reconstruct();
                }
                Q.push(nrem);
            }
        }
        
        return "IMPOSSIBLE";
    }
};

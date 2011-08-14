/*
ID: ivan.bu1
PROG: packrec
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <set>

using namespace std;

int sz[4][2];
void upd(int a, int b, int &best, set< pair<int, int> > &cands) {
    if (a*b < best) {
        best = a*b;
        cands.clear();
        cands.insert(make_pair(min(a, b), max(a, b)));
    } else if (a*b == best) {
        cands.insert(make_pair(min(a, b), max(a, b)));
    }
}
int main() {
	ifstream fin("packrec.in");
    for (int i=0; i<4; ++i) {
        fin >> sz[i][0];
        fin >> sz[i][1];
    }
    fin.close();
    
    vector<int> p;
    p.reserve(4);
    for (int i=0; i<4; ++i) {
        p.push_back(i);
    }
    
    int best = 12345678;
    set< pair<int, int> > cands;
    do {
        for (int rot=0; rot<16; ++rot) {
            vector< pair<int, int> > r;
            r.reserve(4);
            for (int i=0; i<4; ++i) {
                if ((rot>>i) & 1) {
                    r.push_back(make_pair(sz[p[i]][1], sz[p[i]][0]));
                } else {
                    r.push_back(make_pair(sz[p[i]][0], sz[p[i]][1]));
                }
            }
            
            int a = 0;
            int b = 0;
            for (int i=0; i<4; ++i) {
                a = max(a, r[i].first);
                b += r[i].second;
            }
            upd(a, b, best, cands);
            
            int y = max(r[3].second, b-r[3].second);
            int x = max_element(r.begin(), r.begin()+3)->first + r[3].first;
            upd(x, y, best, cands);
            
            if (r[0].first < r[1].first) {
                upd(max(r[0].first+r[3].first, max(r[1].first, r[2].first)), max(r[0].second, r[3].second) + r[1].second + r[2].second, best, cands);
            } else if (r[0].first < r[2].first) {
                upd(max(r[0].first+r[3].first, max(r[1].first, r[2].first)), max(r[0].second+r[1].second, r[3].second) + r[2].second, best, cands);
            }
            
            if (r[1].first < r[0].first) {
                if (r[1].first >= r[2].first) {
                    upd(max(r[1].first+r[3].first, max(r[0].first, r[2].first)), r[0].second + max(r[1].second+r[2].second, r[3].second), best, cands);
                } else if (r[1].second >= r[3].second) {
                    upd(max(r[1].first+r[3].first, max(r[0].first, r[2].first)), r[0].second + r[1].second + r[2].second, best, cands);
                }
            }
            
            if (r[0].first >= r[1].first) {
                upd(max(r[0].first+r[3].first, r[1].first+r[2].first), max(r[0].second+r[1].second, r[2].second+max(r[3].second, r[0].second)), best, cands);
            }
        }
    } while (next_permutation(p.begin(), p.end()));
    ofstream fout("packrec.out");
    fout << best << '\n';
    for (set< pair<int, int> >::const_iterator it=cands.begin(); it!=cands.end(); ++it) {
        fout << it->first << ' ' << it->second << '\n';
    }
    fout.close();

	return 0;
}

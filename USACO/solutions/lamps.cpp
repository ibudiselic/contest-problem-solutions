/*
ID: ivan.bu1
PROG: lamps
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

void do_b1(vector<int> &v) {
    for (int i=0; i<(int)v.size(); ++i) {
        v[i] = 1-v[i];
    }
}
void do_b2(vector<int> &v) {
    for (int i=0; i<(int)v.size(); i+=2) {
        v[i] = 1-v[i];
    }
}
void do_b3(vector<int> &v) {
    for (int i=1; i<(int)v.size(); i+=2) {
        v[i] = 1-v[i];
    }
}
void do_b4(vector<int> &v) {
    for (int i=0; 3*i<(int)v.size(); ++i) {
        v[3*i] = 1-v[3*i];
    }
}
bool matches(const vector<int> &a, const vector<int> &b) {
    for (int i=0; i<(int)a.size(); ++i) {
        if (b[i]!=-1 && a[i]!=b[i]) {
            return false;
        }
    }
    return true;
}
int main() {
	ifstream fin("lamps.in");
    int N, C;
    fin >> N >> C;
    vector<int> final_state(N, -1);
    int x;
    int set_to = 1;
    while (fin >> x) {
        if (x == -1) {
            set_to = 0;
        } else {
            final_state[x-1] = set_to;
        }
    }
    fin.close();
    
    vector<int> start_state(N, 1);
    set< vector<int> > sols;
    for (int b1=0; b1<2; ++b1) {
        if (b1 > C) {
            break;
        }
        for (int b2=0; b2<2; ++b2) {
            if (b1+b2 > C) {
                break;
            }
            for (int b3=0; b3<2; ++b3) {
                if (b1+b2+b3 > C) {
                    break;
                }
                int b4 = (C-b1-b2-b3) & 1;
                vector<int> cur = start_state;
                if (b1) {
                    do_b1(cur);
                }
                if (b2) {
                    do_b2(cur);
                }
                if (b3) {
                    do_b3(cur);
                }
                if (b4) {
                    do_b4(cur);
                }
                if (matches(cur, final_state)) {
                    sols.insert(cur);
                }
            }
        }
    }
    
    ofstream fout("lamps.out");
    if (sols.size() == 0) {
        fout << "IMPOSSIBLE\n";
    } else {
        for (set< vector<int> >::const_iterator it=sols.begin(); it!=sols.end(); ++it) {
            for (int i=0; i<N; ++i) {
                fout << it->operator[](i);
            }
            fout << '\n';
        }
    }
    fout.close();

	return 0;
}

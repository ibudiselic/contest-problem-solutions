/*
ID: ivan.bu1
PROG: spin
LANG: C++
*/
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

const int ITER_CHUNK_SIZE = 1000;

clock_t start_time_;
const double CLOCK_LIMIT_ = 0.8*CLOCKS_PER_SEC;
void init_timer() {
    start_time_ = clock();
}
bool timeout() {
    return clock()-start_time_ > CLOCK_LIMIT_;
}

int speed[5], start[5];
vector< pair<int, int> > wedges[5];
bool ok(int i, int a=-1, int b=-1) { // [a, b]
    if (i == 5) {
        return true;
    }
    if (a >= 360) {
        a -= 360;
    }
    if (b >= 360) {
        b -= 360;
    }
    int aa = a, bb;
    if (a <= b) {
        bb = b;
    } else {
        bb = b + 360;
    }
    for (int j=0; j<(int)wedges[i].size(); ++j) {
        int l = start[i] + wedges[i][j].first;
        int r = l + wedges[i][j].second;
        l %= 360;
        r %= 360;
        int ll = l, rr;
        if (l <= r) {
            rr = r;
        } else {
            rr = r + 360;
        }
        if (a != -1) {
            ll = max(ll, aa);
            rr = min(rr, bb);
        }
        if (wedges[i][j].second == 359) { // full circle
            ll = aa;
            rr = bb;
        }
        if (ll<=rr && ok(i+1, ll, rr)) {
            return true;
        }
        if (a!=-1 && wedges[i][j].second!=359) {
            if (l > r) {
                ll = l-360;
                rr = r;
            }
            ll = max(ll, aa);
            rr = min(rr, bb);
            if (ll<=rr && ok(i+1, ll, rr)) {
                return true;
            }
        }
    }
    return false;
}
void tick() {
    for (int i=0; i<5; ++i) {
        start[i] += speed[i];
        if (start[i] >= 360) {
            start[i] -= 360;
        }
    }
}
int main() {
    init_timer();
	ifstream fin("spin.in");
    for (int i=0; i<5; ++i) {
        fin >> speed[i];
        int cnt;
        fin >> cnt;
        for (int j=0; j<cnt; ++j) {
            int a, b;
            fin >> a >> b;
            wedges[i].push_back(make_pair(a, b));
        }
    }
    fin.close();
    
    for (int k=0; k<5; ++k) {
        for (int i=0; i+1<(int)wedges[k].size(); ++i) {
            for (int j=i+1; j<(int)wedges[k].size(); ++j) {
                if (wedges[k][i].second > wedges[k][j].second) {
                    swap(wedges[k][i], wedges[k][j]);
                }
            }
        }
    }
    for (int i=0; i<4; ++i) {
        for (int j=i+1; j<5; ++j) {
            if (wedges[i].back().second > wedges[j].back().second) {
                wedges[i].swap(wedges[j]);
                swap(speed[i], speed[j]);
            }
        }
    }
    
    if (wedges[0].back().second == 359) {
        return 0; // all are full circle
    }
    
    int sol = -1;
    int t = 0;
    //while (!timeout()) {
        for (int iter=0; iter<ITER_CHUNK_SIZE; ++iter) {
            if (ok(0)) {
                sol = t;
                goto DONE;
            }
            ++t;
            tick();
        }
    //}

DONE: ;
    ofstream fout("spin.out");
    if (sol == -1) {
        fout << "none\n";
    } else {
        fout << sol << '\n';
    }
    fout.close();

	return 0;
}

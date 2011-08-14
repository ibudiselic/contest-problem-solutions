#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int cx, cy;
long long D[50][50];
bool has[50];
vector<int> x, y;
int n;
inline long long sqr(long long x) {
    return x * x;
}
inline long long dist2(int i, int j) {
    return sqr(x[i]-x[j]) + sqr(y[i]-y[j]);
}
struct City {
    int i;
    City(int i_): i(i_) {}
};
int rel;
bool operator<(const City &a, const City &b) {
    if (D[a.i][rel] != D[b.i][rel]) {
        return D[a.i][rel] < D[b.i][rel];
    } else if (x[a.i] != x[b.i]) {
        return x[a.i] < x[b.i];
    } else {
        return y[a.i] < y[a.i];
    }
}

vector< vector<int> > G;
int sol;
int score[50];
void upd() {
    memset(score, 0xff, sizeof score);
    queue<int> Q;
    Q.push(0);
    score[0] = 0;
    for (int i=0; i<n; ++i) {
        if (has[i]) {
            Q.push(i);
            score[i] = 0;
        }
    }
    int s = 0;
    int t = 0;
    while (!Q.empty()) {
        if (t == 0) {
            t = Q.size();
            ++s;
        }
        --t;
        int x = Q.front();
        Q.pop();
        for (int i=0; i<(int)G[x].size(); ++i) {
            const int y = G[x][i];
            if (score[y] == -1) {
                score[y] = s;
                Q.push(y);
            }
        }
    }

    sol = min(sol, *max_element(score, score+n));
}
void go(int x, int left) {
    if (left == 0) {
        upd();
        return;
    }
    if (x == n) {
        return;
    }
    go(x+1, left);
    has[x] = 1;
    go(x+1, left-1);
    has[x] = 0;
}
class TeleportsNetwork {
	public:
	int distribute(int T, vector <int> x_, vector <int> y_) {
        x = x_;
        y = y_;
		cx = x[0];
        cy = y[0];
        n = x.size();
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                D[i][j] = dist2(i, j);
            }
        }

        G.assign(n, vector<int> ());
        for (int i=1; i<n; ++i) {
            rel = i;
            vector<City> v(1, City(0));
            for (int j=1; j<n; ++j) {
                if (D[j][0] < D[i][0]) {
                    v.push_back(City(j));
                }
            }

            sort(v.begin(), v.end());
            G[i].push_back(v[0].i);
            G[v[0].i].push_back(i);
        }

        sol = 1234567890;
        go(0, T);

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {0,1,1,1,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,0,1,2,0,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, distribute(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arr1[] = {0,1,1,1,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,0,1,2,0,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, distribute(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 0; int Arr1[] = {0,1,1,1,2,3,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1,2,0,0,0,2,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(2, Arg3, distribute(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1; int Arr1[] = {0,1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,0,0,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(3, Arg3, distribute(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 4; int Arr1[] = {64,200,384,294,175,107,303,374,224,220,223,99,442}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {79,161,83,281,344,217,184,336,431,262,75,474,257}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(4, Arg3, distribute(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TeleportsNetwork ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

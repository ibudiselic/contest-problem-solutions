#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <numeric>

using namespace std;

int P[1000];
int N;
void init() {
    for (int i=0; i<N; ++i) {
        P[i] = i;
    }
}
int root(int x) {
    return x==P[x] ? x : (P[x] = root(P[x]));
}
void join(int x, int y) {
    x = root(x);
    y = root(y);
    if (rand() % 2) {
        P[x] = y;
    } else {
        P[y] = x;
    }
}
class TimeTravellingSalesman {
	public:
	long long determineCost(int N_, vector <string> roads) {
        N = N_;
		init();
        string R = accumulate(roads.begin(), roads.end(), string());
        istringstream is(R);
        string s;
        vector< pair<int, pair<int, int> > > E;
        while (is >> s) {
            int a, b, d;
            sscanf(s.c_str(), "%d,%d,%d", &a, &b, &d);
            E.push_back(make_pair(d, make_pair(a, b)));
        }
        
        sort(E.begin(), E.end());
        int n = 0;
        int sol = 0;
        for (int i=0; i<(int)E.size() && n<N; ++i) {
            int a = E[i].second.first;
            int b = E[i].second.second;
            int d = E[i].first;
            if (root(a) != root(b)) {
                sol += d;
                ++n;
                join(a, b);
            }
        }
        
        return n==N-1 ? sol : -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"0,1,1 0,2,1 1,2,2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(0, Arg2, determineCost(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 6; string Arr1[] = {"0,1,2 1,4,2 4,3,3 2,4,4 0,5,3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 14LL; verify_case(1, Arg2, determineCost(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; string Arr1[] = {"0,2,2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = -1LL; verify_case(2, Arg2, determineCost(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; string Arr1[] = {"1,0",",10","0 2,1",",584 3,2",",754"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1438LL; verify_case(3, Arg2, determineCost(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TimeTravellingSalesman ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

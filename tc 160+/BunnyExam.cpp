#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

int my_abs(int x) {
    return x<0 ? -x : x;
}
vector< pair<int, int> > V;
bool G[10][10];
int C[10];
bool color(int p, int K) {
    if (p == (int)V.size()) {
        return true;
    }
    for (int c=0; c<K; ++c) {
        bool ok = true;
        for (int i=0; i<(int)V.size(); ++i) {
            if (G[p][i] && C[i]==c) {
                ok = false;
                break;
            }
        }
        if (ok) {
            C[p] = c;
            if (color(p+1, K)) {
                return true;
            }
        }
    }
    C[p] = -1;
    return false;
}
class BunnyExam {
	public:
	double getExpected(int m, int k, vector <int> linkage) {
        for (int i=0; 2*i<(int)linkage.size(); ++i) {
            if (my_abs(linkage[2*i]-linkage[2*i+1]) == 1) {
                return -1.0;
            }
        }
        double ans = double(m)/k;
        if (k > 4) {
            return ans;
        }
        if (k == 1) {
            return (m==1 ? 1.0 : -1.0);
        }
        if (k == 2) {
            for (int i=0; 2*i<(int)linkage.size(); ++i) {
                int a = linkage[2*i];
                int b = linkage[2*i+1];
                if (a%2 != b%2) {
                    return -1.0;
                }
            }
            return ans;
        }
        
        V.clear();
        for (int i=0; 2*i<(int)linkage.size(); ++i) {
            V.push_back(make_pair(linkage[2*i], linkage[2*i+1]));
            if (V.back().first > V.back().second) {
                swap(V.back().first, V.back().second);
            }
        }
        sort(V.begin(), V.end());
        
        memset(G, 0, sizeof G);
        for (int i=0; i<(int)V.size(); ++i) {
            for (int j=0; j<(int)V.size(); ++j) {
                if (i == j) {
                    continue;
                }
                if (V[i].first+1==V[j].first || V[i].first+1==V[j].second ||
                    V[i].second+1==V[j].first || V[i].second+1==V[j].second) {
                            G[i][j] = G[j][i] = 1;
                }
            }
        }
        
        memset(C, 0xff, sizeof C);
        if (color(0, k)) {
            return ans;
        } else {
            return -1.0;
        }
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arr2[] = { 1, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 1.5; verify_case(0, Arg3, getExpected(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 2; int Arr2[] = { 1, 4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = -1.0; verify_case(1, Arg3, getExpected(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 8; int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.25; verify_case(2, Arg3, getExpected(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1000000000; int Arg1 = 1; int Arr2[] = { 11, 13, 2010, 487 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = -1.0; verify_case(3, Arg3, getExpected(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 128; int Arg1 = 64; int Arr2[] = { 32, 16, 8, 4, 2, 1 }
; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = -1.0; verify_case(4, Arg3, getExpected(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 13; int Arg1 = 3; int Arr2[] = { 1, 3, 7, 9, 13, 10, 6, 2  }
; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 4.333333333333333; verify_case(5, Arg3, getExpected(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BunnyExam ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

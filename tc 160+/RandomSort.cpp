#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <utility>

using namespace std;

const int SZ = 40320;
double A1[SZ], A2[SZ];
double *P, *Q;
class RandomSort {
	public:
	double getExpected(vector <int> perm) {
		map< vector<int>, int > ind;
        vector< vector<int> > rev;
        vector< vector< pair<int, int> > > pairs;

        int n = perm.size();
        vector<int> v(n, 1);
        for (int i=0; i<n; ++i) {
            v[i] += i;
        }

        do {
            ind[v] = rev.size();
            rev.push_back(v);
            pairs.push_back(vector< pair<int, int> >());
            for (int i=0; i<n; ++i) {
                for (int j=i+1; j<n; ++j) {
                    if (v[i] > v[j]) {
                        pairs.back().push_back(make_pair(i, j));
                    }
                }
            }
        } while (next_permutation(v.begin(), v.end()));

        int m = rev.size();
        fill(A1, A1+SZ, 0.0);
        P = A1;
        Q = A2;
        P[ind[perm]] = 1.0;

        double sol = 0.0;
        double maxval = 1.0;
        for (int t=0; maxval>1e-12; ++t) {
            sol += P[0]*t;
            fill(Q, Q+SZ, 0.0);
            maxval = P[0];
            for (int i=1; i<m; ++i) {
                maxval = max(maxval, P[i]);
                if (P[i] > 1e-13) {
                    for (int j=0; j<(int)pairs[i].size(); ++j) {
                        const int a = pairs[i][j].first;
                        const int b = pairs[i][j].second;
                        swap(rev[i][a], rev[i][b]);
                        Q[ind[rev[i]]] += P[i]/pairs[i].size();
                        swap(rev[i][a], rev[i][b]);
                    }
                }
            }
            swap(P, Q);
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(0, Arg1, getExpected(Arg0)); }
	void test_case_1() { int Arr0[] = {4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 4.066666666666666; verify_case(1, Arg1, getExpected(Arg0)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(2, Arg1, getExpected(Arg0)); }
	void test_case_3() { int Arr0[] = {2,5,1,6,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 5.666666666666666; verify_case(3, Arg1, getExpected(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RandomSort ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

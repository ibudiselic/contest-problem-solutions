#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int T[10001];
int B[10001];
int L[10001];
vector<int> S, E;
class DrawingLines {
	public:
	double countLineCrossings(int n, vector <int> startDot, vector <int> endDot) {
		S = startDot;
        E = endDot;
        memset(T, 0xff, sizeof T);
        memset(B, 0xff, sizeof B);
        
        for (int i=0; i<(int)S.size(); ++i) {
            T[S[i]] = i;
            B[E[i]] = i;
        }
        L[0] = 0;
        for (int i=1; i<=n; ++i) {
            L[i] = L[i-1] + (B[i]==-1);
        }
        
        double N = n;
        double M = n - (int)S.size();
        double sol = 0.0;
        for (int i=1; i<n; ++i) {
            if (T[i] != -1) {
                int b = E[T[i]];
                for (int j=i+1; j<=n; ++j) {
                    if (T[j] != -1) {
                        if (b > E[T[j]]) {
                            sol += 1.0;
                        }
                    } else {
                        sol += L[b]/M;
                    }
                }
            } else {
                for (int j=i+1; j<=n; ++j) {
                    if (T[j] != -1) {
                        sol += (M-L[E[T[j]]])/M;
                    } else {
                        sol += 0.5;
                    }
                }
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 1.5; verify_case(0, Arg3, countLineCrossings(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {1,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 5.5; verify_case(1, Arg3, countLineCrossings(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arr1[] = {4,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.5; verify_case(2, Arg3, countLineCrossings(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 8; int Arr1[] = {1,4,3,6,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,3,2,4,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 7.5; verify_case(3, Arg3, countLineCrossings(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    DrawingLines ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

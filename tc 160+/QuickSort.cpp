#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

map< vector<int>, double> M;
double go(const vector<int> &L) {
    if (M.count(L)) {
        return M[L];
    }
    if (L.size() < 2) {
        return (M[L] = 0);
    }
    
    double &ret = M[L];
    for (int i=0; i<(int)L.size(); ++i) {
        vector<int> A, B;
        for (int j=0; j<(int)L.size(); ++j) {
            if (L[j] < L[i]) {
                A.push_back(L[j]);
                ret += (j>i);
            } else if (L[j] > L[i]) {
                B.push_back(L[j]);
                ret += (j<i);
            }
        }
        ret += go(A) + go(B);
    }
    ret /= L.size();
    return ret;
}
class QuickSort {
	public:
	double getEval(vector <int> L) {
        M.clear();
        return go(L);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(0, Arg1, getEval(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,4,3,5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(1, Arg1, getEval(Arg0)); }
	void test_case_2() { int Arr0[] = {3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.6666666666666665; verify_case(2, Arg1, getEval(Arg0)); }
	void test_case_3() { int Arr0[] = {50,40,30,20,10,15,25,35,45}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 11.07698412698413; verify_case(3, Arg1, getEval(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    QuickSort ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

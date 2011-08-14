#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class AfraidOfEven {
	public:
	vector <int> restoreProgression(vector <int> seq) {
        vector<int> sol(51, 1234567890);
        vector<int> cand;
        for (int i=0; i<(int)seq.size(); ++i) {
            for (int d=-1000; d<=1000; ++d) {
                cand = seq;
                bool ok = true;
                for (int j=0; j<i; ++j) {
                    int need = seq[i] - (i-j)*d;
                    while (cand[j] < need) {
                        cand[j] *= 2;
                    }
                    if (cand[j]!=need || cand[j]>sol[j]) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) {
                    continue;
                }
                for (int j=i+1; j<(int)seq.size(); ++j) {
                    int need = seq[i] + (j-i)*d;
                    while (cand[j] < need) {
                        cand[j] *= 2;
                    }
                    if (cand[j] != need) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    sol = min(sol, cand);
                }
            }
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1, 1, 3, 1, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, restoreProgression(Arg0)); }
	void test_case_1() { int Arr0[] = {9, 7, 5, 3, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9, 7, 5, 3, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, restoreProgression(Arg0)); }
	void test_case_2() { int Arr0[] = {999, 999, 999, 999}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {999, 999, 999, 999 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, restoreProgression(Arg0)); }
	void test_case_3() { int Arr0[] = {7, 47, 5, 113, 73, 179, 53}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {14, 47, 80, 113, 146, 179, 212 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, restoreProgression(Arg0)); }
	void test_case_4() { int Arr0[] = {749, 999, 125, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1498, 999, 500, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, restoreProgression(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    AfraidOfEven ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

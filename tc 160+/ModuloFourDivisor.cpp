#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool test(long long a1, long long a3) {
    return a1==a3 && a1>0 || a1>a3 && a1%(a1-a3)==0;
}
bool test(long long a0, long long a1, long long a2, long long a3) {
    return (a0==0 && a2==0 || a2>0 && a2==a1+a3 && a0%a2==0) && test(a1, a3);
}
class ModuloFourDivisor {
	public:
	int countQuadruplets(vector<long long> A, vector<long long> B, vector<long long> C, vector<long long> D) {
		int sol = 0;
        for (int i=0; i<(int)A.size(); ++i) {
            for (int j=0; j<(int)B.size(); ++j) {
                for (int k=0; k<(int)C.size(); ++k) {
                    for (int l=0; l<(int)D.size(); ++l) {
                        sol += test(A[i], B[j], C[k], D[l]);
                    }
                }
            }
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long Arr0[] = {1}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {1}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long Arr2[] = {1}; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long Arr3[] = {0}; vector<long long> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(0, Arg4, countQuadruplets(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { long Arr0[] = {0}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {0}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long Arr2[] = {0}; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long Arr3[] = {0}; vector<long long> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(1, Arg4, countQuadruplets(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { long Arr0[] = {0}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {0,1}; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long Arr2[] = {0}; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long Arr3[] = {0}; vector<long long> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; verify_case(2, Arg4, countQuadruplets(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ModuloFourDivisor ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

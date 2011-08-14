#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> A, B;
bool done[1601][41][41];
double dp[1601][41][41];
double john[1601][41][41];
long long C[41][41];

double go(int people, int p, int cities) {
    double &ret = dp[people][p][cities];
    if (done[people][p][cities]) {
        return ret;
    }
    done[people][p][cities] = true;
    if (people == 0) {
        return (ret = (cities==0 ? 1.0 : 0.0));
    }
    if (cities==0 || p==(int)A.size()) {
        return (ret = 0.0);
    }
    
    ret = go(people, p+1, cities);
    for (int i=A[p]; i<=B[p]; ++i) {
        if (i <= people) {
            ret += go(people-i, p+1, cities-1)/(B[p]-A[p]+1);
        }
    }
    
    return ret;
}
class TheFansAndMeetingsDivOne {
	public:
	double find(vector <int> minJ, vector <int> maxJ, vector <int> minB, vector <int> maxB, int k) {
		A = minJ;
        B = maxJ;
        memset(done, 0, sizeof done);
        for (int i=1; i<=1600; ++i) {
            go(i, 0, k);
        }
        memcpy(john, dp, sizeof john);
        A = minB;
        B = maxB;
        memset(done, 0, sizeof done);
        double sol = 0.0;
        for (int i=1; i<=1600; ++i) {
            sol += go(i, 0, k) * john[i][0][k];
        }
        
        C[0][0] = 1;
        for (int i=1; i<41; ++i) {
            C[i][0] = C[i][i] = 1;
            for (int j=1; j<i; ++j) {
                C[i][j] = C[i-1][j] + C[i-1][j-1];
            }
        }
        
        return sol/C[minJ.size()][k]/C[minJ.size()][k];
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; double Arg5 = 0.1111111111111111; verify_case(0, Arg5, find(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arr0[] = {5, 2, 5, 1, 1, 2, 4, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 6, 7, 3, 4, 3, 5, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {8, 9, 7, 11, 12, 7, 8, 40}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {9, 10, 9, 33, 14, 7, 11, 40}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; double Arg5 = 4.724111866969009E-5; verify_case(1, Arg5, find(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arr0[] = {4, 7, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 7, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {40, 40, 40}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {40, 40, 40}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1; double Arg5 = 0.0; verify_case(2, Arg5, find(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arr0[] = {3, 6, 2, 1, 1, 10, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 9, 5, 6, 5, 10, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 1, 1, 8, 3, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 9, 7, 3, 10, 6, 5}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; double Arg5 = 0.047082056525158976; verify_case(3, Arg5, find(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TheFansAndMeetingsDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

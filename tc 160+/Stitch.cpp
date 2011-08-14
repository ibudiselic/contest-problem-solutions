#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

/* ((overlap+1-i)*a+(i*b))/(overlap+1) */
string f(string a, const string &b) {
	for (int i=0; i<(int)a.size(); ++i) {
		int x = ((int)a.size()+1-(i+1))*a[i] + (i+1)*b[i];
		int val = x/((int)a.size()+1) + (10*(x - x/((int)a.size()+1)*((int)a.size()+1)) >= 5*((int)a.size()+1));

		a[i] = val;
	}
	return a;
}
class Stitch {
	public:
	vector <string> stitch(vector <string> A, vector <string> B, int overlap) {
		vector<string> sol;

		for (int i=0; i<(int)A.size(); ++i)
			sol.push_back(A[i].substr(0, A[i].size()-overlap) + (overlap > 0 ? f(A[i].substr(A[i].size()-overlap), B[i]) : "") + ((int)B[i].size()>overlap ? B[i].substr(overlap) : ""));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"AAAAAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"JJJJJ"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; string Arr3[] = { "AACEFHJ" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, stitch(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"14ABCD",
 "25EFGH",
 "36IJKL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ABCD14",
 "EFGH25",
 "IJKL36"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; string Arr3[] = { "14ABCD14",  "25EFGH25",  "36IJKL36" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, stitch(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {" 32ygfd",
 "3uh53G:",
 ")O83gh3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"hsd$*(PH",
 "3G:$)(*P",
 "gh86$PBB"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; string Arr3[] = { " 32ygmd$*(PH",  "3uh53G:$)(*P",  ")O83gh76$PBB" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, stitch(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; string Arr3[] = { "AA" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, stitch(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Stitch ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

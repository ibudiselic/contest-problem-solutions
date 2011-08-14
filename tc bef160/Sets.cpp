#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Sets {
	public:
	vector <int> operate(vector <int> A, vector <int> B, string operation) {
		vector<int> sol;
		set<int> all;
		set<int> a;
		set<int> b;
		for (int i=0; i<(int)A.size(); ++i) {
			all.insert(A[i]);
			a.insert(A[i]);
		}
		for (int i=0; i<(int)B.size(); ++i) {
			all.insert(B[i]);
			b.insert(B[i]);
		}
		if (operation == "UNION") {
			for (set<int>::const_iterator i=all.begin(); i!=all.end(); ++i)
				sol.push_back(*i);
		} else if (operation == "INTERSECTION") {
			for (set<int>::const_iterator i=all.begin(); i!=all.end(); ++i)
				if (a.count(*i) && b.count(*i))
					sol.push_back(*i);
		} else {
			for (set<int>::const_iterator i=all.begin(); i!=all.end(); ++i)
				if (!a.count(*i) || !b.count(*i))
					sol.push_back(*i);
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "INTERSECTION"; int Arr3[] = { 3,  4 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, operate(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "UNION"; int Arr3[] = { 1,  2,  3,  4,  5,  6 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, operate(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {432,756,123}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {534,76,1209}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "INTERSECTION"; int Arr3[] = { }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, operate(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {6,5,7,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7,6,4,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "SYMMETRIC DIFFERENCE"; int Arr3[] = { 5,  10 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, operate(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {342,654,897,312,76,23,78}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {21,43,87,98,23,756,897,234,645,876,123}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "SYMMETRIC DIFFERENCE"; int Arr3[] = { 21,  43,  76,  78,  87,  98,  123,  234,  312,  342,  645,  654,  756,  876 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, operate(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Sets ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

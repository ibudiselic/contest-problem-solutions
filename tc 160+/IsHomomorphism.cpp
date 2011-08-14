#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class IsHomomorphism {
	public:
	vector <string> numBad(vector <string> source, vector <string> target, vector <int> mapping) {
		vector<string> sol;
		const int len = (int)source.size();

		for (int i=0; i<len; ++i)
			for (int j=0; j<len; ++j)
				if (mapping[source[i][j]-'0'] != target[mapping[i]][mapping[j]]-'0')
					sol.push_back(string("(")+(char)(i+'0')+','+(char)(j+'0')+')');
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"0000",
 "0123",
 "0202",
 "0321"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0000",
 "0123",
 "0202",
 "0321"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, numBad(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"0123456",
 "1234560",
 "2345601",
 "3456012",
 "4560123",
 "5601234",
 "6012345"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0123456",
 "1234560",
 "2345601",
 "3456012",
 "4560123",
 "5601234",
 "6012345"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,3,2,1,2,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { "(0,0)",  "(0,1)",  "(0,2)",  "(0,3)",  "(0,4)",  "(0,5)",  "(0,6)",  "(1,0)",  "(1,1)",  "(1,2)",  "(1,3)",  "(1,4)",  "(1,5)",  "(1,6)",  "(2,0)",  "(2,1)",  "(2,2)",  "(2,3)",  "(2,4)",  "(2,5)",  "(3,0)",  "(3,1)",  "(3,2)",  "(3,3)",  "(3,4)",  "(3,5)",  "(4,0)",  "(4,1)",  "(4,2)",  "(4,3)",  "(4,4)",  "(4,5)",  "(4,6)",  "(5,0)",  "(5,1)",  "(5,2)",  "(5,3)",  "(5,4)",  "(5,5)",  "(6,0)",  "(6,1)",  "(6,4)",  "(6,6)" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, numBad(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"012",
 "120",
 "210"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"012",
 "120",
 "110"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { "(2,0)" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, numBad(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"012",
 "120",
 "210"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"012",
 "120",
 "210"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { "(0,0)",  "(0,1)",  "(0,2)",  "(1,0)",  "(1,2)",  "(2,0)",  "(2,2)" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, numBad(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"01","10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"10","01"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, numBad(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    IsHomomorphism ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

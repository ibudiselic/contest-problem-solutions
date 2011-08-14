#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string toStr(long long x) {
	ostringstream os;
	os << x;
	return os.str();
}
bool in(long long x, const vector<long long> &left, const vector<long long> &right, int n) {
	for (int i=0; i<n; ++i)
		if (left[i]<=x && x<=right[i])
			return true;

	return false;
}
class BigCube {
	public:
	string largestCube(vector <string> range) {
		int n = range.size();
		vector<long long> left(n, 0);
		vector<long long> right(n, 0);

		for (int i=0; i<n; ++i)
			sscanf(range[i].c_str(), "%lld-%lld", &left[i], &right[i]);

		for (long long x=100000; x>=0; --x)
			if (in(x*x*x, left, right, n))
				return toStr(x*x*x);

		return "";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1-1000000000001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "1000000000000"; verify_case(0, Arg1, largestCube(Arg0)); }
	void test_case_1() { string Arr0[] = {"10-999999999999990","11-999999999999991","12-999999999999992",
 "13-999999999999993","14-999999999999994","15-999999999999995",
 "16-999999999999996","17-999999999999993","18-999999999999994",
 "19-999999999999999"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "999970000299999"; verify_case(1, Arg1, largestCube(Arg0)); }
	void test_case_2() { string Arr0[] = {"0-3","10-20","30-60","80-120"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "1"; verify_case(2, Arg1, largestCube(Arg0)); }
	void test_case_3() { string Arr0[] = {"999700030000-999999999999","999400119993-999700029998",
 "999100269974-999400119991","998800479937-999100269972"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ""; verify_case(3, Arg1, largestCube(Arg0)); }
	void test_case_4() { string Arr0[] = {"0-0","2-2","3-3","4-4","5-5","6-6","7-7","9-9","10-10","12-12",
 "14-14","16-16","18-18","20-20","22-22","24-24","26-26","28-28",
 "30-30","32-32","34-34","36-36","38-38","40-40","42-42","44-44",
 "46-46","48-48","50-50","52-52","54-54","56-56","58-58","60-60",
 "62-62","65-65","67-67","69-69","71-71","73-73","75-75","77-77",
 "79-79","81-81","83-83","85-85","87-87","89-89","99-99",
  "999970000300000-999999999999999" }
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "0"; verify_case(4, Arg1, largestCube(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BigCube ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

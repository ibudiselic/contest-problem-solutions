#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
template<class T>
vector<T> tokenize(string s, const string &delim=" ") {
  vector<T> ret;
  string::size_type i=0;
  string::size_type len = delim.length();
  if (delim != " ")
    while ((i=s.find(delim)) != string::npos)
      s.replace(i, len, " ");

  istringstream is(s);
  T val;
  while (is >> val)
    ret.push_back(val);
  return ret;
}
const int di[] = { -1, -1, 0, 1, 1,  1,  0, -1 };
const int dj[] = {  0,  1, 1, 1, 0, -1, -1, -1 };
bool valid(int i, int j) {
	return i>=0 && i<9 && j>=0 && j<9;
}
class MineField {
	public:
	vector <string> getMineField(string mloc) {
		vector<string> t = tokenize<string>(mloc, ")(");
		vector<string> sol(9, string(9, '0'));

		if (t.size()) {
			t[0] = t[0].substr(1);
			t[t.size()-1] = t[t.size()-1].substr(0, t[t.size()-1].size()-1);
		}
		for (int i=0; i<(int)t.size(); ++i) {
			vector<int> tt = tokenize<int>(t[i], ",");
			sol[tt[0]][tt[1]] = 'M';
			for (int dir=0; dir<8; ++dir)
				if (valid(tt[0]+di[dir], tt[1]+dj[dir]) && sol[tt[0]+di[dir]][tt[1]+dj[dir]]!='M')
					++sol[tt[0]+di[dir]][tt[1]+dj[dir]];
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "(0,0)(1,0)(2,0)(3,0)(4,0)"; string Arr1[] = { "M20000000",  "M30000000",  "M30000000",  "M30000000",  "M20000000",  "110000000",  "000000000",  "000000000",  "000000000" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getMineField(Arg0)); }
	void test_case_1() { string Arg0 = "(0,0)(0,8)(8,0)(8,8)"; string Arr1[] = { "M1000001M",  "110000011",  "000000000",  "000000000",  "000000000",  "000000000",  "000000000",  "110000011",  "M1000001M" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getMineField(Arg0)); }
	void test_case_2() { string Arg0 = "(3,2)(3,3)(3,4)(4,2)(4,4)(5,2)(5,3)(5,4)(7,4)(6,7)"; string Arr1[] = { "000000000",  "000000000",  "012321000",  "02MMM2000",  "03M8M3000",  "02MMM2111",  "0124321M1",  "0001M1111",  "000111000" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getMineField(Arg0)); }
	void test_case_3() { string Arg0 = ""; string Arr1[] = { "000000000",  "000000000",  "000000000",  "000000000",  "000000000",  "000000000",  "000000000",  "000000000",  "000000000" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getMineField(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MineField ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template<class T> vector<T> tokenize(string s, const string &delim=" ") {
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
class AustrianLotto {
	public:
	int match(const string &s, const string &t) {
		vector<int> a = tokenize<int>(s);
		vector<int> b = tokenize<int>(t);

		int ret = 0;
		for (int i=0; i<(int)a.size(); ++i)
			if (find(b.begin(), b.end(), a[i]) != b.end())
				++ret;
		return ret;
	}
	vector <int> evaluate(string drawing, vector <string> picks) {
		vector<int> sol(7, 0);

		for (int i=0; i<(int)picks.size(); ++i)
			++sol[match(drawing, picks[i])];

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "3 11 18 23 37 45"; string Arr1[] = {"4 7 14 30 33 35", "1 11 12 25 37 38", "11 18 19 20 21 22"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 1,  0,  2,  0,  0,  0,  0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, evaluate(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "3 18 23 11 37 45"; string Arr1[] = {"3 11 18 23 37 45"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0,  0,  0,  0,  0,  0,  1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, evaluate(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "42 26 33 2 13 14"; string Arr1[] = {"13 4 36 42 26 12"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0,  0,  0,  1,  0,  0,  0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, evaluate(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    AustrianLotto ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

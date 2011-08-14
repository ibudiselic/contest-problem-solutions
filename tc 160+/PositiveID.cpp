#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>

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
class PositiveID {
	public:
	int maximumFacts(vector <string> suspects) {
		int n = suspects.size();
		vector< vector<string> > A(n, vector<string>());
		for (int i=0; i<n; ++i)
			A[i] = tokenize<string>(suspects[i], ",");

		int sol = 0;
		for (int i=0; i<n; ++i)
			for (int j=i+1; j<n; ++j) {
				int cnt = 0;
				for (int k=0; k<(int)A[i].size(); ++k)
					cnt += (find(A[j].begin(), A[j].end(), A[i][k]) != A[j].end());
				sol = max(sol, cnt);
			}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"blond,tall,skinny",
"short,skinny,blond,tattooed",
"scarred,bald"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, maximumFacts(Arg0)); }
	void test_case_1() { string Arr0[] = {"gigantic,fluorescent,loud,male"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, maximumFacts(Arg0)); }
	void test_case_2() { string Arr0[] = {"medium,average,nondescript",
"medium,average,nondescript"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, maximumFacts(Arg0)); }
	void test_case_3() { string Arr0[] = {"big,tall,loud,happy,male,scarred,tattooed,dirty",
"short,male,beard,quiet,happy,tanned,handsome",
"female,pretty,blond,quiet",
"somnambulistic",
"happy,tiny,stout,male,tanned,beard,blond"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, maximumFacts(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PositiveID ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

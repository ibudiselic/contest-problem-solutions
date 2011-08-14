#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

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

vector< vector<int> > v;
int M, N;
class SumOfSelectedCells {
	public:
	string hypothesis(vector <string> table) {
		v.clear();
		int M = table.size();
		for (int i=0; i<M; ++i)
			v.push_back(tokenize<int>(table[i]));
		int N = v[0].size();

		if (M < N) {
			vector< vector<int> > t(N, vector<int>(M, 0));
			for (int i=0; i<M; ++i)
				for (int j=0; j<N; ++j)
					t[j][i] = v[i][j];
			swap(M, N);
			v.swap(t);
		}

		if (M == N) {
			for (int i=0; i<M; ++i)
				for (int j=i+1; j<M; ++j)
					for (int x=0; x<N; ++x)
						for (int y=x+1; y<N; ++y)
							if (v[i][x]+v[j][y] != v[i][y]+v[j][x])
								return "INCORRECT";
		} else {
			for (int j=0; j<N; ++j)
				for (int i=1; i<M; ++i)
					if (v[i][j] != v[0][j])
						return "INCORRECT";
		}

		return "CORRECT";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"5 6 6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "INCORRECT"; verify_case(0, Arg1, hypothesis(Arg0)); }
	void test_case_1() { string Arr0[] = {"11 12 13 14",
 "21 22 23 24",
 "31 32 33 34",
 "41 42 43 44"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CORRECT"; verify_case(1, Arg1, hypothesis(Arg0)); }
	void test_case_2() { string Arr0[] = {"3 7",
 "3 7",
 "3 7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CORRECT"; verify_case(2, Arg1, hypothesis(Arg0)); }
	void test_case_3() { string Arr0[] = {"1 2 3",
 "4 5 6",
 "9 8 7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "INCORRECT"; verify_case(3, Arg1, hypothesis(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SumOfSelectedCells ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

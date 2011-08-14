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
void go(int x, const vector<vector<bool> > &a, vector<bool> &used, const vector<bool> &done) {
	used[x] = true;
	for (int i=0; i<(int)used.size(); ++i)
		if (!done[i] && !used[i] && a[x][i])
			go(i, a, used, done);
}
bool can_remove(int x, const vector<int> &from, vector<vector<bool> > &a, const vector<bool> &done) {
	vector<bool> used(done.size(), false);
	go(0, a, used, done);
	bool good = true;
	for (int i=0; good && i<(int)done.size(); ++i)
		if (!done[i] && !used[i])
			good = false;

	return good;
}
class UndergroundVault {
	public:
	vector <int> sealOrder(vector <string> rooms) {
		const int n = rooms.size();
		vector<vector<bool> > adj(n, vector<bool>(n, false));
		vector<vector<int> > from(n);

		for (int i=0; i<n; ++i) {
			from[i] = tokenize<int>(rooms[i], ",");
			if (from[i].size() > 0)
				for (int j=0; j<(int)from[i].size(); ++j)
					adj[i][from[i][j]] = true;
			adj[i][i] = true;
		}


		vector<bool> used(n, false);
		vector<int> sol;
		for (int cnt=1; cnt<n; ++cnt) {
			for (int i=1; i<n; ++i) {
				if (!used[i]) {
					used[i] = true;
					if (can_remove(i, from[i], adj, used)) {
						sol.push_back(i);
						break;
					}
					used[i] = false;
				}
			}
		}
		sol.push_back(0);
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"1","2",""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 2,  1,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, sealOrder(Arg0)); }
	void test_case_1() { string Arr0[] = {"1","2","3","1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 3,  2,  1,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, sealOrder(Arg0)); }
	void test_case_2() { string Arr0[] = {"3,5","2","8","","","6,7","","1,8","4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 2,  1,  3,  4,  6,  8,  7,  5,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, sealOrder(Arg0)); }
	void test_case_3() { string Arr0[] = {"1,2","3","3,5","4","",""}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  4,  3,  5,  2,  0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, sealOrder(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    UndergroundVault ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
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
class PipePath {
	public:
	double capCost(vector <string> caps, vector <string> costs, int source, int sink) {
		const int n = caps.size();
		vector<vector<vector<int> > > cap(n, vector<vector<int> >(n, vector<int>()));
		vector<vector<vector<int> > > cost(n, vector<vector<int> >(n, vector<int>()));
		set<int> cut;
		for (int i=0; i<n; ++i) {
			vector<string> t = tokenize<string>(caps[i]);
			vector<string> v = tokenize<string>(costs[i]);
			for (int j=0; j<(int)t.size(); ++j) {
				int x, y;
				sscanf(t[j].c_str(), "%d,%d", &x, &y);
				cap[i][x].push_back(y);
				cut.insert(y);
				sscanf(v[j].c_str(), "%d,%d", &x, &y);
				cost[i][x].push_back(y);
			}
		}

		double sol = 0.0;
		for (set<int>::const_iterator it=cut.begin(); it!=cut.end(); ++it) {
			vector<vector<int> > t(n, vector<int>(n, 1000000000));
			for (int i=0; i<n; ++i)
				for (int j=0; j<n; ++j)
					for (int k=0; k<(int)cap[i][j].size(); ++k)
						if (cap[i][j][k] >= *it)
							t[i][j] = min(t[i][j], cost[i][j][k]);

			for (int k=0; k<n; ++k)
				for (int i=0; i<n; ++i)
					for (int j=0; j<n; ++j)
						t[i][j] = min(t[i][j], t[i][k] + t[k][j]);

			if (t[source][sink] != 1000000000)
				sol = max(sol, (double)*it/t[source][sink]);
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1,10 2,9","","1,100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1,100 2,50","","1,50"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 1; double Arg4 = 0.1; verify_case(0, Arg4, capCost(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"1,3 3,5","3,2 2,6","3,2","1,1 2,4 4,6",
 "0,3 2,7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1,3 3,5","3,2 2,6","3,2","1,1 2,4 4,6",
 "0,3 2,7"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 4; double Arg4 = 0.45454545454545453; verify_case(1, Arg4, capCost(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"1,15 1,20","2,10",""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1,10 1,10","2,15",""}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 2; double Arg4 = 0.4; verify_case(2, Arg4, capCost(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PipePath ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

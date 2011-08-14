#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

long long fact[18];
bool a[17][17];
map<pair<int, int>, long long> memo;
template<class T>
vector<T> tokenize(string s, const string &delim=" ")
{
    vector<T> ret_val;
    string::size_type i=0;
    string::size_type len = delim.length();
    if (delim != " ")
        while ((i=s.find(delim)) != string::npos)
            s.replace(i, len, " ");

    istringstream is(s);
    T val;

    while (is >> val)
        ret_val.push_back(val);
    return ret_val;
}
class PossibleOrders {
	public:
	void dfs(int x, vector<bool> &used) {
		used[x] = true;
		for (vector<bool>::size_type i=0; i<used.size(); ++i)
			if (!used[i] && a[x][i])
				dfs((int)i, used);
	}
	long long stirling(int n, int x) {
		if (x<=0 || x>n) return 0;
		if (x==1 || x==n) return 1;
		long long &ret = memo[make_pair(n, x)];
		if (ret) return ret;

		return ret = stirling(n-1, x)*x + stirling(n-1, x-1);
	}
	long long howMany(int num, vector <string> facts) {
		fact[0] = 1;
		memo.clear();
		for (int i=1; i<=17; ++i)
			fact[i] = fact[i-1]*i;

		memset(a, 0, sizeof a);
		vector<bool> used(num, false);
		for (vector<string>::size_type i=0; i<facts.size(); ++i) {
			vector<int> t = tokenize<int>(facts[i], "=");
			if (t[0]==t[1]) continue;
			a[t[0]][t[1]] = a[t[1]][t[0]] = true;
		}

		num = 0;
		for (vector<bool>::size_type i=0; i<used.size(); ++i)
			if (!used[i]) {
				dfs(i, used);
				++num;
			}

		long long sol = 0;
		for (int i=1; i<=num; ++i)
			sol += fact[i]*stirling(num, i);
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; string Arr1[] = {"0=2","1=3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 3LL; verify_case(0, Arg2, howMany(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 75LL; verify_case(1, Arg2, howMany(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; string Arr1[] = {"1=1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 13LL; verify_case(2, Arg2, howMany(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; string Arr1[] = {"1=2","2=1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 3LL; verify_case(3, Arg2, howMany(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 17; string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 130370767029135901LL; verify_case(4, Arg2, howMany(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PossibleOrders ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

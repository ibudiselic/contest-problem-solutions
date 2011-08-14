#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string best[51][27];
bool dp[51][27];

int lastChar(const string &s) {
	return s[s.size()-1]-'A';
}
int firstChar(const string &s) {
	return s[0]-'A';
}
class WordTrain {
	public:
	string hookUp(vector <string> cars) {
		for (int i=0; i<(int)cars.size(); ++i) {
			string t = cars[i];
			reverse(t.begin(), t.end());
			if (t[0]<cars[i][0] || (t[0]==cars[i][0] && t<cars[i]))
				cars[i] = t;
		}

		sort(cars.begin(), cars.end());

		memset(dp, 0, sizeof dp);

		int n = cars.size();
		for (int i=0; i<=n; ++i)
			for (int j=0; j<27; ++j)
				best[i][j].clear();

		for (int i=0; i<n; ++i)
			for (int j=i+1; j<n; ++j)
				if (firstChar(cars[i])==firstChar(cars[j]) && firstChar(cars[j])==lastChar(cars[j]) && (firstChar(cars[i])!=lastChar(cars[i]) || firstChar(cars[i])==lastChar(cars[i]) && cars[i]>cars[j]))
					swap(cars[i], cars[j]);

		for (int last=0; last<26; ++last)
			dp[0][last] = 1;

		for (int i=1; i<=n; ++i) {
			for (int j=i-1; j>=0; --j)
				if (dp[j][firstChar(cars[i-1])])
					if (!dp[j+1][lastChar(cars[i-1])] || (best[j][firstChar(cars[i-1])] + '-' + cars[i-1] < best[j+1][lastChar(cars[i-1])])) {
						dp[j+1][lastChar(cars[i-1])] = 1;
						best[j+1][lastChar(cars[i-1])] = best[j][firstChar(cars[i-1])] + '-' + cars[i-1];
					}
		}

		for (int i=n; i>=0; --i) {
			int j=0;
			while (j<26 && !dp[i][j])
				++j;
			if (j < 26) {
				vector<string> sol;
				for (j=0; j<26; ++j)
					if (dp[i][j])
						sol.push_back(best[i][j]);
				sort(sol.begin(), sol.end());
				return sol[0].substr(1);
			}
		}

		return "";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"CBA","DAA","CXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ABC-CXX"; verify_case(0, Arg1, hookUp(Arg0)); }
	void test_case_1() { string Arr0[] = {"ACBA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ABCA"; verify_case(1, Arg1, hookUp(Arg0)); }
	void test_case_2() { string Arr0[] = {"AUTOMATA","COMPUTER","ROBOT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "COMPUTER-ROBOT"; verify_case(2, Arg1, hookUp(Arg0)); }
	void test_case_3() { string Arr0[] = {"AAA","AAAA","AAA","AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AAA-AAA-AAA-AAAA"; verify_case(3, Arg1, hookUp(Arg0)); }
	void test_case_4() { string Arr0[] = {"ABA","BBB","COP","COD","BAD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BBB-BAD"; verify_case(4, Arg1, hookUp(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WordTrain ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

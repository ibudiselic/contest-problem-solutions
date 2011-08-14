#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

vector<string> names;
vector<long long> val;
map<string, int> M;
int getInd(const string &s) {
	if (M.count(s) == 0) {
		M[s] = names.size();
		names.push_back(s);
		val.push_back(1);
	}
	return M[s];
}
bool T[1500][1500], G[1500][1500];
class WebsiteRank {
	public:
	long long countVotes(vector <string> votes, string website) {
		M.clear();
		names.clear();
		val.clear();

		memset(G, 0, sizeof G);
		for (int i=0; i<(int)votes.size(); ++i) {
			istringstream is(votes[i]);
			string w;
			is >> w;
			int a = getInd(w);
			while (is >> w) {
				int b = getInd(w);
				G[b][a] = 1;
			}
		}

		memcpy(T, G, sizeof T);
		int n = names.size();
		for (int k=0; k<n; ++k)
			for (int i=0; i<n; ++i)
				if (G[i][k])
					for (int j=0; j<n; ++j)
						if (G[k][j])
							G[i][j] = 1;


		bool change = 1;
		while (change) {
			change = 0;
			for (int i=0; i<n; ++i) {
				long long x = 1;
				for (int j=0; j<n; ++j)
					if (i!=j && T[j][i] && !G[i][j])
						x += val[j];
				if (x != val[i]) {
					assert(x > val[i]);
					change = 1;
					val[i] = x;
				}
			}
		}

		return val[getInd(website)];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"C A B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "C"; long long Arg2 = 3LL; verify_case(0, Arg2, countVotes(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"A B C D", "B C D", "C D"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "A"; long long Arg2 = 8LL; verify_case(1, Arg2, countVotes(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "A"; long long Arg2 = 1LL; verify_case(2, Arg2, countVotes(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"A B", "B A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "A"; long long Arg2 = 1LL; verify_case(3, Arg2, countVotes(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"A B C D E F", "B A", "C B", "D B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "A"; long long Arg2 = 3LL; verify_case(4, Arg2, countVotes(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"MYSITE OTHERSITE ANOTHERSITE THIRDSITE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "MYSITE"; long long Arg2 = 4LL; verify_case(5, Arg2, countVotes(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WebsiteRank ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

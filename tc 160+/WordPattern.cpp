#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string makeStr(int len, const string &w) {
	int padding = w.size()-1-len;
	string s = w.substr(w.size()-1-len);
	reverse(s.begin(), s.end());

	return string(padding, ' ') + s.substr(0, s.size()-1) + w.substr(w.size()-1-len) + string(padding, ' ');
}
const int di[] = { -1, 0, 1, 0 };
const int dj[] = { 0, 1, 0, -1 };
long long A[100][100], B[100][100];
bool isEdge(int i, int j, int m, int n, const vector<string> &P) {
	if (i==0 || j==0 || i==m-1 || j==n-1)
		return true;

	for (int d=0; d<4; ++d) {
		int r = i + di[d];
		int c = j + dj[d];
		if (P[r][c] == ' ')
			return true;
	}
	return false;
}
class WordPattern {
	public:
	long long countWords(string word) {
		vector<string> P;
		for (int i=0; i<(int)word.size(); ++i)
			P.push_back(makeStr(i, word));
		for (int i=(int)word.size()-2; i>=0; --i)
			P.push_back(makeStr(i, word));

		memset(A, 0, sizeof A);
		int m = P.size();
		int n = P[0].size();
		A[word.size()-1][word.size()-1] = 1;

		long long (*p)[100];
		long long (*q)[100];

		p = A; q = B;

		for (int x=1; x<(int)word.size(); ++x) {
			for (int i=0; i<m; ++i)
				for (int j=0; j<n; ++j) {
					q[i][j] = 0;
					if (P[i][j] == word[x])
						for (int d=0; d<4; ++d) {
							int r = i + di[d];
							int c = j + dj[d];
							if (r>=0 && r<m && c>=0 && c<n && P[r][c]==word[x-1])
								q[i][j] += p[r][c];
						}
				}
			swap(p, q);
		}

		long long sol = 0;
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (isEdge(i, j, m, n, P))
					sol += p[i][j];

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "HELLO"; long long Arg1 = 60LL; verify_case(0, Arg1, countWords(Arg0)); }
	void test_case_1() { string Arg0 = "TC"; long long Arg1 = 4LL; verify_case(1, Arg1, countWords(Arg0)); }
	void test_case_2() { string Arg0 = "ABCDEFGHIJKLMNOPQRST"; long long Arg1 = 2097148LL; verify_case(2, Arg1, countWords(Arg0)); }
	void test_case_3() { string Arg0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJ"; long long Arg1 = 137438953468LL; verify_case(3, Arg1, countWords(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WordPattern ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

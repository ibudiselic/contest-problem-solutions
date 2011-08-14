#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>

using namespace std;
typedef pair<int, int> PII;
vector<vector<int> > c;
vector<vector<int> > f;
int n;
vector<string> tokenize_to_string(const string &s, const char delim=' ') {
	vector<string> ret;

	string t;
	for (string::size_type i=0; i<s.size(); ++i) {
		if (s[i]==delim) {
			ret.push_back(t);
			t.clear();
		} else {
			t += s[i];
		}
	}
	ret.push_back(t);

	return ret;
}
class RookAttack {
	public:
	bool bfs(int s, int t) {
		vector<PII> q;
		vector<bool> used(n, false);
		used[s] = true;
		q.push_back(PII(s, -1));
		int head = 0;

		while (head < (int)q.size()) {
			int x = q[head].first;

			for (int i=0; i<n; ++i)
				if (!used[i] && c[x][i]-f[x][i]>0) {
					used[i] = true;
					q.push_back(PII(i, head));
					if (i == t)
						goto kraj;
				}
			++head;
		}
		return false;

		kraj:
		head = q.size()-1;
		while (q[head].second != -1) {
			const int x = q[head].first;
			head = q[head].second;
			++f[q[head].first][x];
			f[x][q[head].first] = -f[q[head].first][x];
		}
		return true;
	}
	int howMany(int rows, int cols, vector <string> cutouts) {
		n = rows+cols+2;
		c.assign(n, vector<int>(n, 0));
		f.assign(n, vector<int>(n, 0));

		for (int i=2; i-2<rows; ++i)
			c[0][i] = 1;
		for (int i=2; i-2<rows; ++i)
			for (int j=2+rows; j-rows-2<cols; ++j)
				c[i][j] = 1;
		for (int i=2+rows; i-rows-2<cols; ++i)
			c[i][1] = 1;

		for (int i=0; i<(int)cutouts.size(); ++i) {
			vector<string> t = tokenize_to_string(cutouts[i], ',');
			for (int j=0; j<(int)t.size(); ++j) {
				int rr, cc;
				sscanf(t[j].c_str(), "%d %d", &rr, &cc);
				c[2+rr][2+rows+cc] = 0;
			}
		}

		int sol = 0;
		while (bfs(0, 1))
			++sol;


		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 8; int Arg1 = 8; string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 8; verify_case(0, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; string Arr2[] = {"0 0","0 1","1 1","1 0"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(1, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = {"0 0","1 0","1 1","2 0","2 1","2 2"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(2, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = {"0 0","1 2","2 2"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(3, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 200; int Arg1 = 200; string Arr2[] = {}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 200; verify_case(4, Arg3, howMany(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RookAttack ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

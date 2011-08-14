#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef pair<int, int> PII;
struct Entry {
	PII pos;
	int len;
	Entry(PII p, int l): pos(p), len(l) {}
};
const int di[] = { -1, 0, 1,  0 };
const int dj[] = {  0, 1, 0, -1 };
bool valid(int i, int j, int m, int n) {
	return i>=0 && i<m && j>=0 && j<n;
}
class Orchard {
	public:
	vector <int> nextTree(vector <string> orchard) {
		int best = 0;
		PII loc = make_pair(-1, -1);
		const int m(orchard.size());
		const int n(orchard[0].size());
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (orchard[i][j]=='-') {
					vector<vector<bool> > used(m, vector<bool>(n, false));
					queue<Entry> q;
					used[i][j] = true;
					q.push(Entry(make_pair(i, j), 0));
					while (!q.empty()) {
						const Entry t = q.front();
						q.pop();
						for (int dir=0; dir<4; ++dir) {
							const int ii = t.pos.first+di[dir];
							const int jj = t.pos.second+dj[dir];
							if (valid(ii, jj, m, n) && used[ii][jj])
								continue;
							if (!valid(ii, jj, m, n) || orchard[ii][jj]=='T') {
								if (t.len+1 > best) {
									best = t.len+1;
									loc = make_pair(i, j);
								}
								goto kraj;
							} else {
								q.push(Entry(make_pair(ii, jj), t.len+1));
								used[ii][jj] = true;
							}
						}
					}
		kraj: ;
				}
		vector<int> sol;
		sol.push_back(loc.first+1);
		sol.push_back(loc.second+1);
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = { "----" , "T---" , "----" , "----" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 2,  3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, nextTree(Arg0)); }
	void test_case_1() { string Arr0[] = {"---T--","------","------","----T-","------","------"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 3,  3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, nextTree(Arg0)); }
	void test_case_2() { string Arr0[] = {"------------","------------","------------","------------",
"------------","------------","------------","------------",
"------------","------------","------------","------------"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 6,  6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, nextTree(Arg0)); }
	void test_case_3() { string Arr0[] = {"-T----T",
 "T---T--",
 "-----TT",
 "---TT--",
 "T-----T",
 "-------",
 "T-T--T-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 2,  3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, nextTree(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Orchard ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

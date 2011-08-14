#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <set>

using namespace std;
const int MAXVAL = 20000;
bool can[MAXVAL+2];
bool done[MAXVAL+2];
queue<int> Q;
void go(int x) {
	if (x>=0 && x<=MAXVAL+1) {
		can[x] = 1;
		if (!done[x])
			Q.push(x);
		done[x] = 1;
	}
}

class AntiMatter {
	public:
	string unstable(vector <int> xform) {
		set<int> D_;
		for (int i=0; i<4; ++i)
			for (int j=i+1; j<4; ++j) {
				const int d = abs(xform[i] - xform[j]);
				if (d > 0)
					D_.insert(d);
			}
		vector<int> diff(D_.begin(), D_.end());
		memset(can, 0, sizeof can);
		memset(done, 0, sizeof done);
		can[0] = 1;
		done[0] = 1;
		Q.push(0);
		while (!Q.empty()) {
			const int cur = Q.front();
			Q.pop();
			for (int i=0; i<(int)diff.size(); ++i) {
				go(cur - diff[i]);
				go(cur + diff[i]);
			}
		}

		int cnt = 0;
		for (int i=-4999; i<=5000; ++i)
			for (int j=-4999; j<=5000; ++j)
				cnt += can[abs(i - j)];

		if (cnt == 10000*10000) return "1."+string(8, '0');
		else {
			ostringstream os;
			os << cnt;
			string sol = os.str();
			return "." + string(8-sol.size(), '0') + sol;
		}
		return "PARO";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {6,6,6,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ".00010000"; verify_case(0, Arg1, unstable(Arg0)); }
	void test_case_1() { int Arr0[] = {1,-1,1,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ".50000000"; verify_case(1, Arg1, unstable(Arg0)); }
	void test_case_2() { int Arr0[] = {0,1,-1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "1.00000000"; verify_case(2, Arg1, unstable(Arg0)); }
	void test_case_3() { int Arr0[] = {0,0,0,792}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = ".00126448"; verify_case(3, Arg1, unstable(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    AntiMatter ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <utility>
#include <cctype>

using namespace std;

typedef pair<int, int> point;

const int dy[] = { 1, 0, -1, 0 };
const int dx[] = { 0, 1, 0, -1 };
const string dirs = "URDL";
class MedievalCity {
	public:
	int getDangerousBlocks(vector <string> boundary, int dangerBound) {
		string s;
		for (int i=0; i<(int)boundary.size(); ++i)
			s += boundary[i];

		vector<int> X, Y;
		X.push_back(0);
		Y.push_back(0);
		int x=0, y=0;
		int dblArea = 0;
		for (int i=0; i<(int)s.size(); ++i)
			if (!isdigit(s[i])) {
				int d = dirs.find(s[i]);
				int n = 0;
				for (++i; i<(int)s.size() && isdigit(s[i]); ++i)
					n = 10*n + s[i]-'0';

				x += max(n, 1)*dx[d];
				y += max(n, 1)*dy[d];

				dblArea += x*Y.back() - y*X.back();

				X.push_back(x);
				Y.push_back(y);
				--i;
			} else {
				assert(0);
			}

		if (dblArea < 0) {
			reverse(X.begin(), X.end());
			reverse(Y.begin(), Y.end());
		}

		set<point> in, out;
		for (int i=1; i<(int)X.size(); ++i) {
			int xx = (X[i]-X[i-1]==0 ? 0 : (X[i]-X[i-1]>0 ? 1 : -1));
			int yy = (Y[i]-Y[i-1]==0 ? 0 : (Y[i]-Y[i-1]>0 ? 1 : -1));

			x = X[i-1];
			y = Y[i-1];
			while (x!=X[i] || y!=Y[i]) {
				if (xx == +1) {
					in.insert(point(x, y));
					out.insert(point(x, y+1));
				}
				if (xx == -1) {
					in.insert(point(x-1, y+1));
					out.insert(point(x-1, y));
				}
				if (yy == +1) {
					in.insert(point(x, y+1));
					out.insert(point(x-1, y+1));
				}
				if (yy == -1) {
					in.insert(point(x-1, y));
					out.insert(point(x, y));
				}
				x += xx;
				y += yy;
			}
		}

		int sol = 0;
		for (int i=0; i<=dangerBound; ++i) {
			sol += in.size();
			set<point> newin;
			for (set<point>::const_iterator it=in.begin(); it!=in.end(); ++it)
				for (int d=0; d<4; ++d) {
					y = it->second + dy[d];
					x = it->first + dx[d];

					if (!out.count(point(x, y)) && !in.count(point(x, y)))
						newin.insert(point(x, y));
				}

			out = in;
			in = newin;
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"LURD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; verify_case(0, Arg2, getDangerousBlocks(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"LUUR7D4RDLDDDL7UURU2UU"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 44; verify_case(1, Arg2, getDangerousBlocks(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"L50U50R50D50"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 1716; verify_case(2, Arg2, getDangerousBlocks(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"L50U50U50U50U50R50D50D50D50D50"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 3744; verify_case(3, Arg2, getDangerousBlocks(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MedievalCity ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

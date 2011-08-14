#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

bool G[370][370];
bool done[370];
int N;

int bfs(int x) {
	done[x] = 1;
	queue<int> Q;
	Q.push(x);
	int sz = 0;
	while (!Q.empty()) {
		x = Q.front();
		Q.pop();
		++sz;

		for (int i=0; i<N; ++i) {
			if (G[x][i] && !done[i]) {
				done[i] = 1;
				Q.push(i);
			}
		}
	}

	return sz/2 * 2;
}

int calc() {
	memset(done, 0, sizeof done);

	int ret = 0;
	for (int i=0; i<N; ++i) {
		if (!done[i]) {
			ret += bfs(i);
		}
	}
	return ret;
}
class PointsOnACircle {
	public:
	int color(vector <string> points) {
		string s;
		for (int i=0; i<(int)points.size(); ++i) {
			s += points[i];
		}

		vector<int> x;
		{
			istringstream is(s);
			int t;
			while (is >> t) {
				x.push_back(t);
			}
		}

		N = x.size();
		int sol = 0;
		for (int deg=1; deg<360; ++deg) {
			memset(G, 0, sizeof G);
			for (int i=0; i<N; ++i) {
				for (int j=0; j<N; ++j) {
					if ((x[i]-x[j] + 720) % 360 == deg) {
						G[i][j] = 1;
						G[j][i] = 1;
					}
				}
			}
			sol = max(sol, calc());
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0 10 15 25 40 50 60"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, color(Arg0)); }
	void test_case_1() { string Arr0[] = {"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, color(Arg0)); }
	void test_case_2() { string Arr0[] = {"0 1 3 7 15 31 63 127"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, color(Arg0)); }
	void test_case_3() { string Arr0[] = {"1","2"," ","3","4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(3, Arg1, color(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PointsOnACircle ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

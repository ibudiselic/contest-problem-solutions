#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int m, n;
enum {
	INFTY = 100000
};
class DesertWind {
	public:
	inline bool inbounds(int x, int y) {
		return x>=0&&x<m && y>=0&&y<n;
	}
	int daysNeeded(vector<string> board) {
		m = (int)board.size();
		n = (int)board[0].size();

		int sol[50][50];
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				sol[i][j] = (board[i][j]=='*')?0:INFTY;

		bool updated;
		do {
			updated = false;
			for (int i=0; i<m; ++i)
				for (int j=0; j<n; ++j) {
					int best=INFTY, second_best=INFTY;
					for (int dx=-1; dx<2; ++dx)
						for (int dy=-1; dy<2; ++dy)
							if (dx!=0 || dy!=0) {
								const int x = i+dx;
								const int y = j+dy;
								if (inbounds(x, y) && board[x][y]!='X') {
									if (sol[x][y] < best) {
										second_best = best;
										best = sol[x][y];
									} else if (sol[x][y] < second_best)
										second_best = sol[x][y];
								}
							}
					if (best+3 < sol[i][j]) {
						sol[i][j] = best+3;
						updated = true;
					}
					if (second_best+1 < sol[i][j]) {
						sol[i][j] = second_best+1;
						updated = true;
					}
				}
		} while (updated);

		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (board[i][j] == '@')
					return (sol[i][j]==INFTY)? -1:sol[i][j];
		return -2;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"--*","@-*","X--"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, daysNeeded(Arg0)); }
	void test_case_1() { string Arr0[] = {"-X-*","-@X-","---X","--**"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, daysNeeded(Arg0)); }
	void test_case_2() { string Arr0[] = {"*--X-----",
 "--XX--@--",
 "*-X------"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, daysNeeded(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    DesertWind ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int di[] = { 1, 0 };
int dj[] = { 0, 1 };

int n, m;

class Gems {
	public:
	bool inbounds(int i, int j) {
		return i>=0 && i<n && j>=0 && j<m;
	}
	bool ok(vector<string> a, int i, int j, int di, int dj, char c) {
		int t = 0;
		while (inbounds(i+t*di, j+t*dj) && a[i+t*di][j+t*dj]==c)
			++t;

		return t>=3;
	}
	int numMoves(vector <string> board) {
		int sol = 0;

		n = (int)board.size();
		m = (int)board[0].size();
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				for (int k=0; k<2; ++k) {
					int x = i+di[k];
					int y = j+dj[k];

					if (!inbounds(x, y))
						continue;
					char c = board[i][j]; board[i][j] = board[x][y]; board[x][y] = c;
					if (ok(board, i-2, j, 1, 0, board[i][j]) || ok(board, i-1, j, 1, 0, board[i][j]) || ok(board, i, j, 1, 0, board[i][j])
							||
							ok(board, x-2, y, 1, 0, board[x][y]) || ok(board, x-1, y, 1, 0, board[x][y]) || ok(board, x, y, 1, 0, board[x][y])
							||
							ok(board, i, j-2, 0, 1, board[i][j]) || ok(board, i, j-1, 0, 1, board[i][j]) || ok(board, i, j, 0, 1, board[i][j])
							||
							ok(board, x, y-2, 0, 1, board[x][y]) || ok(board, x, y-1, 0, 1, board[x][y]) || ok(board, x, y, 0, 1, board[x][y]))
						++sol;
					c = board[i][j]; board[i][j] = board[x][y]; board[x][y] = c;
				}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ABC",
 "ABC",
 "BAD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, numMoves(Arg0)); }
	void test_case_1() { string Arr0[] = {"ABB",
 "BAA",
 "ABB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, numMoves(Arg0)); }
	void test_case_2() { string Arr0[] = {"ABA",
 "BAB",
 "ABA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, numMoves(Arg0)); }
	void test_case_3() { string Arr0[] = {"ABC",
 "DEF",
 "GHI"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, numMoves(Arg0)); }
	void test_case_4() { string Arr0[] = {"SUMEEMEEPGPPG",
 "USPMIPSUSIISG",
 "UPSPGEGGPKEII",
 "KEMGISMKKIUIG",
 "MGSIIKMSISGKM",
 "SPGMSMIGMSMGM",
 "SSIIUKMPEPPUI",
 "UKUIUEMEEIGKE",
 "IPUPGUSEGSSUS",
 "EUPMKGGUKKEMI",
 "PEPSMUUEUSSIP",
 "SUMEEUSESUEKG",
 "EPSKUISGMSKGI",
 "IUGGUGGSIGUUP",
 "IUPIKKSGPPEEP",
 "KGEESGISPGGEM",
 "UEIUSSKPSSGPE",
 "KSUMKGEIMKPSE",
 "ESKEUEMMPPIGG",
 "UUIEUGGIGMEMK",
 "GPGMPPIUMEPMU",
 "IKIGGPIUEMIGS",
 "IPUSGUMKPKIPP",
 "UEEMUUEEGIPUS",
 "PPEKIKEMGGMSS",
 "EMKPMPUUMKEPU",
 "UKPGPKSUIEUPM",
 "PSUUMUKGIIPMS",
 "ESMGSKUEPGGEM",
 "SMEEIKGKGGPEG",
 "UEIEKPMESMEPP",
 "IPUIMGGMIPKMG",
 "ISSEKPKGKIUGU",
 "SSESKUGKISPUK"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 83; verify_case(4, Arg1, numMoves(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Gems ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

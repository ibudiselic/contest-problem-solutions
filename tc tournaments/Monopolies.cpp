#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
/*If he lands on square 7, 22, or 36 he draws a card which
2 cards say "go to jail"
1 card says "go to square 11"
1 card says "go to square 24"
1 card says "go to square 29"
1 card says "go to square 39"
14 cards don't cause him to move*/
double dp[40][21][3];
int card_sq[] = {39, 29, 24, 11 };
class Monopolies {
	public:
	double probability(int square) {
		for (int i=0; i<40; ++i)
			for (int j=0; j<21; ++j)
				for (int k=0; k<3; ++k)
					dp[i][j][k] = 0.0;

		dp[0][0][0] = 1.0;
		for (int sq=0; sq<40; ++sq) {
			if (sq == 30)
				continue;
			for (int m=0; m<21; ++m)
				for (int dup=0; dup<3; ++dup) {
					double roll_prob = 1.0;
					if (sq==7 || sq==22 || sq==36) {
						roll_prob = 14.0/20.0;
						for (int i=0; i<4 && card_sq[i]>sq; ++i)
							dp[card_sq[i]][m][dup] += dp[sq][m][dup]/20.0;
					}
					for (int d1=1; d1<=6; ++d1)
						for (int d2=1; d2<=6; ++d2) {
							const int next = sq + d1+d2;
							if (next >= 40)
								continue;
							if (d1==d2 && dup==2)
								continue;

							dp[next][m + (dup==0)][(d1==d2) * (dup+(d1==d2))] += dp[sq][m][dup]/36.0 * roll_prob;
						}
				}
		}

		double sol = 0.0;
		double not_first = 1.0;
		for (int m=0; m<21; ++m) {
			double prob = 0;
			for (int dup=0; dup<3; ++dup)
				prob += dp[square][m][dup];
			not_first -= prob;
			sol += not_first*prob;
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; double Arg1 = 0.0; verify_case(0, Arg1, probability(Arg0)); }
	void test_case_1() { int Arg0 = 22; double Arg1 = 0.12122739832411301; verify_case(1, Arg1, probability(Arg0)); }
	void test_case_2() { int Arg0 = 30; double Arg1 = 0.11905533142891316; verify_case(2, Arg1, probability(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Monopolies ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

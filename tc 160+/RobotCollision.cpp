#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int di[] = { -1, 1, 0, 0 };
const int dj[] = { 0, 0, -1, 1 };
const string dirs = "UDLR";

int M, N;
vector<int> A, B;
inline bool valid(int i, int j) {
	if (i<0 || j<0 || i>=M || j>=N)
		return false;
	return true;
}

inline void calc(int &a, int &b, int i, int j, int d) {
	a = i + di[d];
	b = j + dj[d];
	if (valid(a, b))
		return;
	a = i;
	b = j;
}
inline bool collide(int i, int j, int r, int c) {
	if (!valid(r, c))
		return false;

	int move = 0;
	while (true) {
		if (i==r && j==c)
			return true;
		if (move == (int)A.size())
			break;

		int ni, nj, nr, nc;
		calc(ni, nj, i, j, A[move]);
		calc(nr, nc, r, c, B[move]);

		if (ni==r && nj==c && nr==i && nc==j)
			return true;
		i = ni;
		j = nj;
		r = nr;
		c = nc;

		++move;
	}

	return false;
}
class RobotCollision {
	public:
	double probability(int xSize, int ySize, string commandsRobbie, string commandsSpeedy) {
		M = xSize;
		N = ySize;
		A.clear();
		B.clear();
		for (int i=0; i<(int)commandsRobbie.size(); ++i) {
			A.push_back(dirs.find(commandsRobbie[i]));
			B.push_back(dirs.find(commandsSpeedy[i]));
		}

		int cnt = 0;

		for (int i=0; i<M; ++i)
			for (int j=0; j<N; ++j)
				for (int dr=-20; dr<=20; ++dr)
					for (int dc=-20; dc<=20; ++dc)
						if (collide(i, j, i+dr, j+dc))
							++cnt;

		return double(cnt)/(M*M*N*N);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 10; string Arg2 = "L"; string Arg3 = "R"; double Arg4 = 0.27; verify_case(0, Arg4, probability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; string Arg2 = "DRUL"; string Arg3 = "DRUL"; double Arg4 = 1.0; verify_case(1, Arg4, probability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 2; string Arg2 = "DRUL"; string Arg3 = "RULD"; double Arg4 = 0.4375; verify_case(2, Arg4, probability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 10; string Arg2 = "D"; string Arg3 = "D"; double Arg4 = 0.012; verify_case(3, Arg4, probability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 20; int Arg1 = 50; string Arg2 = ""; string Arg3 = ""; double Arg4 = 0.0010; verify_case(4, Arg4, probability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 100; int Arg1 = 100; string Arg2 = "U"; string Arg3 = "D"; double Arg4 = 2.97E-4; verify_case(5, Arg4, probability(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RobotCollision ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

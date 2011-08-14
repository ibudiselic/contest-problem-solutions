#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

/*
In this problem you will implement a particular randomized solution. The board is setup as follows starting with column 1 on the left, and ending with column n on the right:
1) Choose a random number R between 1 and n inclusive.
2) Place a queen in row R of the current column (row 1 is the top; row n is the bottom).
An alteration step works as follows:
1) Compute T, the number of columns containing reachable queens.
2) Choose a random number K between 1 and T inclusive. Let C denote the Kth column, counting from the left, that contains a reachable queen. In effect, we have randomly chosen one of the reachable queens.
3) For each of the n positions in column C, compute how many queens from other columns can currently reach that position.
4) Move the queen in column C to the position in column C reachable by the fewest number of queens. If multiple positions are tied, continue to step 5, otherwise the alteration step is complete.
5) Compute P, the number of positions that tied in step 4.
6) Choose a random number Q between 1 and P inclusive. Counting from the top down, move the queen to the Qth of the tied positions in 4.
Note that an alteration step may not cause any movement at all. You will return how many alteration steps are required before no two queens interfere with one another. The ith random value used in the algorithms above will be (a(i) % Up)+1 where Up is the inclusive upper bound on the random number required and a(i) is given by the following formula:
a( 1 ) = 1 ,
a( k+1 ) = ( 16807 * a( k ) ) % 2147483647 for k > 0.
*/

int qr[100];
long long my_rand(long long &seed) {
	return seed = (16807 * seed) % 2147483647;
}
int rRows(vector<int> &v, int n) {
	v.clear();
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j)
			if (j!=i && (qr[j]==qr[i] || (j+qr[j] == i+qr[i]) || (j-qr[j] == i-qr[i]))) {
				v.push_back(i);
				goto NEXT;
			}
		NEXT:;
	}

	return (int)v.size();
}
class QueenInterference {
	public:
	int numSteps(int n) {
		qr[0] = 1;
		long long rnd = 1;
		for (int i=1; i<n; ++i)
			qr[i] = my_rand(rnd)%n;

		int sol = 0;

		vector<int> reachable;
		int T = 0;
		while (T = rRows(reachable, n)) {
			++sol;
			int K = my_rand(rnd)%T;
			int C = reachable[K];

			vector<int> cntReach(n, 0);
			for (int i=0; i<n; ++i)
				for (int j=0; j<n; ++j)
					if (j != C)
						cntReach[i] += (qr[j]==i || (C+i==j+qr[j]) || (C-i==j-qr[j]));

			int lowest = *min_element(cntReach.begin(), cntReach.end());
			vector<int> cand;
			for (int i=0; i<n; ++i)
				if (cntReach[i] == lowest)
					cand.push_back(i);

			if (cand.size() == 1) {
				qr[C] = cand[0];
			} else {
				int P = (int)cand.size();
				int Q = my_rand(rnd)%P;
				qr[C] = cand[Q];
			}
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 4; verify_case(0, Arg1, numSteps(Arg0)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 6; verify_case(1, Arg1, numSteps(Arg0)); }
	void test_case_2() { int Arg0 = 19; int Arg1 = 475; verify_case(2, Arg1, numSteps(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    QueenInterference ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

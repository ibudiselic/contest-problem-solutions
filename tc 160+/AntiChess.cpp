#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct Position {
	int r, c;
	Position() {}
	Position(const string &p) {
		r = p[1] - '0';
		c = p[0] - 'a';
	}
};

int taken;
bool alive[8];
vector<Position> P;
Position Q;

/*
alpha-beta pruned minimax algorithm
  maximizer (pawns) knows he can make alpha so he never returns less then that
  minimizer (queen) knows he can make beta so he never retrurns more then that
  maximizer also knows the minimizer can make beta so he'll never return more then beta
  minimizer also knows the maximizer can make alpha so he'll never return less then alpha
   => both maximizer and minimizer return in the interval [alpha, beta]
   this invariant is here only to make the code simpler... the functions could return the actual values and then
   those should be compared to alpha or beta and discarded if they are out of range etc.
*/
int queen(int alpha, int beta);
int pawns(int alpha, int beta) {
	assert(alpha <= beta);

	if (alpha == beta)
		return alpha;
	if (taken >= beta)
		return beta;

	if (taken > alpha)
		alpha = taken;

	// a pawn must eat the queen if it can
	for (int i=0; i<(int)P.size(); ++i)
		if (alive[i])
			if (P[i].r+1 == Q.r && abs(P[i].c-Q.c) == 1)
				return alpha;

	// no living pawn can eat the queen so the maximizer tries pawn moves...
	for (int i=0; i<(int)P.size(); ++i)
		if (alive[i]) {
			if (P[i].r==8 || (P[i].c==Q.c && P[i].r+1==Q.r)) // this pawn is either at row 8 or blocked by the queen so it can't move
				continue;
			// note that the pawn can't be blocked by another pawn since that would mean the other pawn ate the queen (the only way to change columns for a pawn is to eat)
			// and that would have ended the game already

			++P[i].r;
			alpha = queen(alpha, beta); // this is a nonminimizing move (that is, almost-maximizing) since the minimizer can only return in the range [alpha, beta]

			// special case for 2nd row pawns
			if (alpha<beta && P[i].r==3 && (Q.r!=4 || Q.c!=P[i].c)) {
				++P[i].r;
				alpha = queen(alpha, beta); // this is a nonminimizing move (that is, almost-maximizing) since the minimizer can only return in the range [alpha, beta]
				--P[i].r;
			}

			--P[i].r;

			// if beta is already reached with the nonminimizing moves then there's no point in continuing since the minimizer (queen) is guaranteed to be able to make beta by some other means
			if (alpha == beta)
				return alpha;
		}

	return alpha;
}

int queen(int alpha, int beta) {
	assert(alpha <= beta); // invariant of the problem
	assert(taken <= alpha); // this is true because the caller (an instance of the 'pawns' function) doesn't change 'taken' and it makes sure at the start that alpha is atleast as big as 'taken' (and from there on, alpha is nondecreasing in 'pawns')

	if (alpha == beta)
		return alpha;

	bool canEatSome = false;
	// try to eat a pawn
	for (int di=-1; di<=1; ++di)
		for (int dj=-1; dj<=1; ++dj)
			if (di!=0 || dj!=0) {
				int closestDist = 1234567890; // distance to the nearest pawn in this direction
				int closestInd = -1; // index of the nearest pawn in this direction

				for (int p=0; p<(int)P.size(); ++p)
					if (alive[p]) {
						int dr = Q.r - P[p].r;
						int dc = Q.c - P[p].c;
						int dist = 0;
						if (di != 0)
							dist = dr/di;
						else
							dist = dc/dj;

						if (dist>0 && dist*di==dr && dist*dj==dc) { // pawn p is in the given direction
							if (dist < closestDist) {
								closestDist = dist;
								closestInd = p;
							}
						}
					}

				if (closestInd != -1) {
					canEatSome = true;

					alive[closestInd] = false;
					++taken;
					Position temp = Q;
					Q = P[closestInd];
					beta = pawns(alpha, beta); // this is a nonmaximizing move (that is, almost-minimizing) since the maximizer can only return in the range [alpha, beta]
					Q = temp;
					--taken;
					alive[closestInd] = true;

					if (alpha == beta)
						return alpha;
				}
			}

	if (!canEatSome) // the best situation for the queen where she can eat nothing - she still must return alpha (and not 'taken' that might be less then alpha) because the caller won't do this move anyway and the invariant is to return in the range [alpha, beta]
		return alpha;

	return beta;
}

class AntiChess {
	public:
	int sacrifice(vector <string> white, string black) {
		P.clear();
		for (int i=0; i<(int)white.size(); ++i)
			P.push_back(Position(white[i]));
		memset(alive, 1, sizeof alive);

		Q = Position(black);

		taken = 0;

		return pawns(0, P.size());
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"a2","c2","d2","e3","h4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "b6"; int Arg2 = 5; verify_case(0, Arg2, sacrifice(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"a2","h2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "g3"; int Arg2 = 0; verify_case(1, Arg2, sacrifice(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"a2","e2","h2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "e6"; int Arg2 = 3; verify_case(2, Arg2, sacrifice(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"a7","h7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "a8"; int Arg2 = 1; verify_case(3, Arg2, sacrifice(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"a3","b3","c3","d3","e3","f3","g3","h3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "d8"; int Arg2 = 7; verify_case(4, Arg2, sacrifice(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    AntiChess ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

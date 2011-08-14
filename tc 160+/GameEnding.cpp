#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

bool B[7][7];
bool R[7], C[7];
int N;
vector< pair<int, int> > P;
vector< pair<int, int> > M;

inline bool kAttack(const pair<int, int> &p, int r, int c) {
	const int dr = abs(p.first - r);
	const int dc = abs(p.second - c);

	return (dr==2 && dc==1 || dr==1 && dc==2);
}
bool test(int r, int c) {
	assert(r>=0 && r<N && c>=0 && c<N);
	if (R[r] || C[c] || B[r][c])
		return false;

	for (int i=0; i<(int)P.size(); ++i)
		if (kAttack(P[i], r, c))
			return false;

	return true;
}
inline void add(int r, int c) {
	R[r] = C[c] = B[r][c] = true;
	P.push_back(make_pair(r, c));
}
inline void removeLast() {
	const int r = P.back().first;
	const int c = P.back().second;
	R[r] = C[c] = B[r][c] = false;
	P.pop_back();
}

bool go() {
	for (int i=0; i<N*N; ++i)
		if (test(M[i].first, M[i].second)) {
			add(M[i].first, M[i].second);
			if (!go()) {
				removeLast();
				return true;
			}
			removeLast();
		}

	return false;
}
class GameEnding {
	public:
	string result(int n, vector <string> moves) {
		N = n;
		memset(B, 0, sizeof B);
		memset(R, 0, sizeof R);
		memset(C, 0, sizeof C);
		P.clear();
		for (int i=0; i<(int)moves.size(); ++i) {
			int r = moves[i][0]-'a';
			int c = moves[i][1]-'1';
			if (!test(r, c))
				return "Invalid input";
			add(r, c);
		}

		M.clear();
		for (int i=0; i<N; ++i)
			for (int j=0; j<N; ++j)
				M.push_back(make_pair(i, j));

		random_shuffle(M.begin(), M.end());

		if (go())
			return string(moves.size()%2==0 ? "First" : "Second") + " player wins";
		else
			return string(moves.size()%2!=0 ? "First" : "Second") + " player wins";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; string Arr1[] = {"b2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "First player wins"; verify_case(0, Arg2, result(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; string Arr1[] = {"a2","b3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Second player wins"; verify_case(1, Arg2, result(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; string Arr1[] = {"a3","b3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Invalid input"; verify_case(2, Arg2, result(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; string Arr1[] = {"a1","b2","c3","d4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Second player wins"; verify_case(3, Arg2, result(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 7; string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "First player wins"; verify_case(4, Arg2, result(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 7; string Arr1[] = {"b5","g3","f2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Second player wins"; verify_case(5, Arg2, result(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    GameEnding ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

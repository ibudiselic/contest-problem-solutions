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

bool done[7][7][1<<7][1<<7];
int M, N;
vector<string> A;

struct State {
	int i, j, R, C;
};

bool valid(int i, int j) {
	if (i<0 || j<0 || i>=M || j>=N) {
		return false;
	}
	return true;
}
bool upd(queue<State> &Q, int i, int j, int R, int C, int di=0, int dj=0) {
	if (!valid(i, j) || done[i][j][R][C]) {
		return false;
	}

	if (abs(di) + abs(dj) == 1) {
		bool rot = ((R&(1<<i))!=0) ^ ((C&(1<<j))!=0);
		if (A[i][j] == 'C') {
			if (!rot && dj!=0 || rot && di!=0) {
				return false;
			}
		} else if (A[i][j] == 'D') {
			if (!rot && di!=0 || rot && dj!=0) {
				return false;
			}
		} else if (A[i][j] == 'B') {
			return false;
		}
	}

	if (i==M-1 && j==N-1) {
		return true;
	}

	done[i][j][R][C] = 1;
	Q.push((State) {i, j, R, C});
	return false;
}
	
class TurningMaze {
	public:
	int minTime(vector <string> maze) {
		A = maze;
		M = A.size();
		N = A[0].size();
		
		memset(done, 0, sizeof done);
		done[0][0][0][0] = 1;
		queue<State> Q;
		Q.push((State) {0, 0, 0, 0});
		int sol = 0;
		int t = 0;
		while (!Q.empty()) {
			if (t == 0) {
				t = Q.size();
				++sol;
			}
			--t;
			int i = Q.front().i;
			int j = Q.front().j;
			int R = Q.front().R;
			int C = Q.front().C;
			Q.pop();

			upd(Q, i, j, R^(1<<i), C^(1<<j));

			if (A[i][j] == 'A') {
				for (int di=-1; di<2; ++di) {
					for (int dj=-1; dj<2; ++dj) {
						if (abs(di) + abs(dj) == 1) {
							if (upd(Q, i+di, j+dj, R, C, di, dj)) {
								return sol;
							}
						}
					}
				}
			} else if (A[i][j] == 'C') {
				bool rot = ((R&(1<<i))!=0) ^ ((C&(1<<j))!=0);
				if (!rot) {
					if (upd(Q, i-1, j, R, C, -1, 0) || upd(Q, i+1, j, R, C, 1, 0)) {
						return sol;
					}
				} else if (upd(Q, i, j-1, R, C, 0, -1) || upd(Q, i, j+1, R, C, 0, 1)) {
					return sol;
				}
			} else if (A[i][j] == 'D') {
				bool rot = ((R&(1<<i))!=0) ^ ((C&(1<<j))!=0);
				if (rot) {
					if (upd(Q, i-1, j, R, C, -1, 0) || upd(Q, i+1, j, R, C, 1, 0)) {
						return sol;
					}
				} else if (upd(Q, i, j-1, R, C, 0, -1) || upd(Q, i, j+1, R, C, 0, 1)) {
					return sol;
				}
			}
		}

		return -1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AA", "AA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minTime(Arg0)); }
	void test_case_1() { string Arr0[] = {"AAA", "BBA", "AAA", "ABB", "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(1, Arg1, minTime(Arg0)); }
	void test_case_2() { string Arr0[] = {"AAACAAA", "BBBBBBA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(2, Arg1, minTime(Arg0)); }
	void test_case_3() { string Arr0[] = {"ACDCDCA", "BBBBBBA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(3, Arg1, minTime(Arg0)); }
	void test_case_4() { string Arr0[] = {"CA", "BA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, minTime(Arg0)); }
	void test_case_5() { string Arr0[] = {"CAA", "DAA", "ACA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(5, Arg1, minTime(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TurningMaze ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

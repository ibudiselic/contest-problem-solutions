#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> V;
void go(vector<int> &state, int n, int left) {
	if (left == 0) {
		return;
	}
	assert(n >= 0);
	if (n == 0) {
		assert(left == 1);
		state[0] = V[0];
		return;
	}

	if (state[n] == V[n]) {
		go(state, n-1, left);
		return;
	}

	int a=V[n], b;
	for (b=0; b<3; ++b) {
		if (b!=state[n] && b!=a) {
			break;
		}
	}

	int ca=0, cb=0, cc=0;
	for (int i=0; i<n; ++i) {
		if (state[i] == a) {
			++ca;
		} else if (state[i] == b) {
			++cb;
		} else {
			++cc;
		}
	}

	assert(ca+cb==0 || cb+cc==0 || cc+ca==0);

	if (cc != 0) {
		int moves = (1<<n)-1;
		if (left >= moves) {
			left -= moves;
			for (int i=0; i<n; ++i) {
				if (state[i] == state[n]) {
					state[i] = b;
				}
			}
		} else {
			for (int i=0; i<n; ++i) {
				V[i] = b;
			}
			go(state, n-1, left);
			return;
		}
	} else if (ca != 0) {
		int moves = (1<<n)-1;
		if (left >= moves) {
			left -= moves;
			for (int i=0; i<n; ++i) {
				if (state[i] == a) {
					state[i] = b;
				}
			}
		} else {
			for (int i=0; i<n; ++i) {
				V[i] = b;
			}
			go(state, n-1, left);
			return;
		}
	}

	if (left > 0) {
		--left;
		state[n] = a;
	}
	go(state, n-1, left);
}
class HanoiState {
	public:
	string partwayState(string target, int moves) {
		int n = target.size();
		V.assign(n, 0);
		for (int i=0; i<n; ++i) {
			V[i] = target[i]-'A';
		}
		vector<int> state(n, 0);
		
		go(state, n-1, moves);

		for (int i=0; i<n; ++i) {
			target[i] = state[i] + 'A';
		}
		return target;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "CCC"; int Arg1 = 4; string Arg2 = "BBC"; verify_case(0, Arg2, partwayState(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "AAC"; int Arg1 = 7; string Arg2 = "AAC"; verify_case(1, Arg2, partwayState(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAA"; int Arg1 = 0; string Arg2 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAA"; verify_case(2, Arg2, partwayState(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ABCABCABCABCABCABCABCABCABCABC"; int Arg1 = 100000000; string Arg2 = "CCCCCCCCBAAAABBBBACBAAAAACBAAA"; verify_case(3, Arg2, partwayState(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    HanoiState ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

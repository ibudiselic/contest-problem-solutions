#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

int set(int i, int j, int x) {
	return x | (1<<(i*4 + j));
}
int reset(int i, int j, int x) {
	return (x & ~(1<<(i*4 + j)));
}
int test(int i, int j, int x) {
	return (x >> (i*4 + j)) & 1;
}
int v[1<<16];
void print(int state, int have) {
	cerr << have << '\n';
	for (int i=0; i<4; ++i) {
		for (int j=0; j<4; ++j) {
			cerr << test(i, j, state);
		}
		cerr << '\n';
	}
	cerr << '\n';
}
int best(int state) {
	memset(v, 0x80, sizeof v);
	priority_queue< pair<int, int> > PQ;
	PQ.push(make_pair(0, state));
	
	while (!PQ.empty()) {
		int have = PQ.top().first;
		state = PQ.top().second;
		PQ.pop();
		if (have < v[state]) {
			continue;
		}
		v[state] = have;

		for (int i=0; i<4; ++i) {
			for (int j=0; j<4; ++j) {
				if (test(i, j, state)) {
					if (i-2>=0 && !test(i-2, j, state) && test(i-1, j, state)) {
						int ns = set(i-2, j, reset(i-1, j, reset(i, j, state)));
						if (have+2 > v[ns]) {
							v[ns] = have+2;
							PQ.push(make_pair(have+2, ns));
						}
					}
					if (i+2<4 && !test(i+2, j, state) && test(i+1, j, state)) {
						int ns = set(i+2, j, reset(i+1, j, reset(i, j, state)));
						if (have+2 > v[ns]) {
							v[ns] = have+2;
							PQ.push(make_pair(have+2, ns));
						}
					}
					if (j>0 && !test(i, j-1, state)) {
						int ns = set(i, j-1, reset(i, j, state));
						if (have-1 > v[ns]) {
							v[ns] = have-1;
							PQ.push(make_pair(have-1, ns));
						}
					}
					if (j<3 && !test(i, j+1, state)) {
						int ns = set(i, j+1, reset(i, j, state));
						if (have-1 > v[ns]) {
							v[ns] = have-1;
							PQ.push(make_pair(have-1, ns));
						}
					}
				}
			}
		}
	}

	return *max_element(v, v + (1<<16));
}
class JollyJumpers {
	public:
	int maxScore(vector <string> layout) {
		int x = 0;
		for (int i=0; i<4; ++i) {
			for (int j=0; j<4; ++j) {
				if (layout[i][j] == '#') {
					x = set(i, j, x);
				}
			}
		}

		return best(x);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"....",
".#..",
"..#.",
"...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, maxScore(Arg0)); }
	void test_case_1() { string Arr0[] = {
"....",
"....",
"....",
"...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, maxScore(Arg0)); }
	void test_case_2() { string Arr0[] = {
".#..",
".#..",
"..#.",
"...#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, maxScore(Arg0)); }
	void test_case_3() { string Arr0[] = {
"####",
"####",
"####",
"####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, maxScore(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    JollyJumpers ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

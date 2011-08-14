#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector< vector<long long> > matmul(const vector<vector<long long> > &A, const vector< vector<long long> > &B) {
	vector< vector<long long> > ret(A.size(), vector<long long> (B[0].size(), 0));
	for (int i=0; i<(int)ret.size(); ++i) {
		for (int j=0; j<(int)ret.size(); ++j) {
			for (int k=0; k<(int)ret.size(); ++k) {
				ret[i][j] = (ret[i][j] + A[i][k]*B[k][j]) % 1000000007LL;
			}
		}
	}

	return ret;
}

vector< vector<long long> > matexp(vector< vector<long long> > A, int n) {
	vector< vector<long long> > ret(A.size(), vector< long long> (A.size(), 0));
	for (int i=0; i<(int)ret.size(); ++i) {
		ret[i][i] = 1;
	}

	while (n > 0) {
		if (n & 1) {
			ret = matmul(A, ret);
		}
		A = matmul(A, A);
		n >>= 1;
	}

	return ret;
}
class GameOnAGraph {
	public:
	vector <int> getMarks(vector <string> adj, string colors, string marks, int K) {
		int N = adj.size();

		vector< vector<long long> > W(N, vector<long long> (N, 0)), B(N, vector<long long> (N, 0));

		for (int i=0; i<N; ++i) {
			if (colors[i] == 'W') {
				W[i][i] = 1;
			} else {
				B[i][i] = 1;
			}
			for (int j=0; j<N; ++j) {
				if (adj[i][j] == '1') { 
					if (colors[i] == 'W') {
						W[j][i] = 1;
					} else {
						B[j][i] = 1;
					}
				}
			}
		}

		vector< vector<long long> > turn = matmul(B, W);
		vector< vector<long long> > trans = matexp(turn, K/2);
		
		if (K & 1) {
			trans = matmul(W, trans);
		}

		vector<int> sol(N, 0);
		for (int i=0; i<N; ++i) {
			for (int j=0; j<N; ++j) {
				sol[i] = (int)((sol[i] + (marks[j]-'0')*trans[i][j]) % 1000000007LL);
			}
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"0110","1000","1000","0000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WBBW"; string Arg2 = "1000"; int Arg3 = 1; int Arr4[] = {1, 1, 1, 0 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, getMarks(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"00000","00000","00000","00000","00000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BBWWW"; string Arg2 = "99999"; int Arg3 = 1; int Arr4[] = {0, 0, 9, 9, 9 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, getMarks(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"01","10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BW"; string Arg2 = "56"; int Arg3 = 2; int Arr4[] = {6, 6 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, getMarks(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"010101","101010","010101","101010","010101","101010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BWBWBW"; string Arg2 = "012345"; int Arg3 = 10; int Arr4[] = {59049, 177147, 59049, 177147, 59049, 177147 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, getMarks(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    GameOnAGraph ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

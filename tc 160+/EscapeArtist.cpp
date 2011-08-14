#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int inf = 123456789;
int N;
int dist[25][25];
bool adj[25][25];
vector<int> AS, AE;
int A;
int S, E;

int dp[25];
long long getways_(int at, int end, int pos, const vector<int> &path) {
	int &ret = dp[at];
	if (ret != -1) {
		return ret;
	}

	ret = 0;
	if (at == end) {
		ret = 1;
		if (pos<(int)path.size() && find(path.begin()+pos+1, path.end(), end)!=path.end()) {
			ret = 0;
		}
	} else {
		for (int to=0; to<N; ++to) {
			if (adj[at][to] && dist[at][end]==dist[to][end]+1) {
				if (pos+1<(int)path.size() && path[pos+1]==to) {
					continue;
				}
				if (pos+1<(int)path.size() && path[pos]==to && path[pos+1]==at) {
					continue;
				}
				ret += getways_(to, end, pos+1, path);
			}
		}
	}

	return ret;
}
long long getways(int start, int end, const vector<int> &path) {
	memset(dp, 0xff, sizeof dp);
	return getways_(start, end, 0, path);
}

double succ(vector<int> &path, const vector<long long> &waysnotdead) {
	int at = path.back();
	if (at == E) {
		return 1.0;
	}

	double ret = 0.0;
	for (int to=0; to<N; ++to) {
		if (adj[at][to] && dist[at][E]==dist[to][E]+1) {
			path.push_back(to);
			vector<long long> nw(A);
			for (int i=0; i<A; ++i) {
				nw[i] = getways(AS[i], AE[i], path);
			}

			double p = 1.0;
			for (int i=0; i<A; ++i) {
				p *= double(nw[i])/waysnotdead[i];
			}
			if (p > 0) {
				p *= succ(path, nw);
				ret = max(ret, p);
			}
			path.pop_back();
		}
	}

	return ret;
}
class EscapeArtist {
	public:
	double bestRoute(vector <string> corridors, vector <int> agentStart, vector <int> agentTarget, int start, int finish) {
		N = corridors.size();
		for (int i=0; i<N; ++i) {
			for (int j=0; j<N; ++j) {
				adj[i][j] = (corridors[i][j] == '1');
				dist[i][j] = (corridors[i][j]=='1' ? 1 : inf);
			}
			dist[i][i] = 0;
		}
		for (int k=0; k<N; ++k) {
			for (int i=0; i<N; ++i) {
				if (dist[i][k] < inf) {
					for (int j=0; j<N; ++j) {
						dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
					}
				}
			}
		}
		
		S = start;
		E = finish;
		AS = agentStart;
		AE = agentTarget;
		A = AS.size();

		vector<int> path;
		path.push_back(S);
		vector<long long> waysnotdead(A);
		for (int i=0; i<A; ++i) {
			waysnotdead[i] = getways(AS[i], AE[i], path);
		}

		return 1.0 - succ(path, waysnotdead);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"0100",
"1011",
"0100",
"0100"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; int Arg4 = 2; double Arg5 = 1.0; verify_case(0, Arg5, bestRoute(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { string Arr0[] = {
"01000",
"10110",
"01000",
"01001",
"00010"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; int Arg4 = 2; double Arg5 = 0.0; verify_case(1, Arg5, bestRoute(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { string Arr0[] = {
"010000",
"101011",
"010111",
"001000",
"011000",
"011000"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; int Arg4 = 3; double Arg5 = 0.5; verify_case(2, Arg5, bestRoute(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { string Arr0[] = {
"010000",
"101001",
"010110",
"001000",
"001000",
"010000"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; int Arg4 = 3; double Arg5 = 1.0; verify_case(3, Arg5, bestRoute(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { string Arr0[] = {
"01100",
"10011",
"10010",
"01100",
"01000"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; int Arg4 = 3; double Arg5 = 0.5; verify_case(4, Arg5, bestRoute(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { string Arr0[] = {
"0100",
"1010",
"0101",
"0010"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; int Arg4 = 3; double Arg5 = 1.0; verify_case(5, Arg5, bestRoute(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_6() { string Arr0[] = {"0101", "1010", "0101", "1010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; int Arg4 = 1; double Arg5 = 1.0; verify_case(6, Arg5, bestRoute(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_7() { string Arr0[] = {"011", "101", "110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 1; double Arg5 = 1.0; verify_case(7, Arg5, bestRoute(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    EscapeArtist ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

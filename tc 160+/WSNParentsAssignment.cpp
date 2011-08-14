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

int C[150][150], F[150][150];
int N, sink, source;
inline int left(int x) { return x*2; }
inline int right(int x) { return x*2 + 1; }
vector<string> network;
string nearest;
int P[150];

bool bfs(int s, int t) {
	memset(P, 0xff, sizeof P);
	queue<int> Q;
	Q.push(s);
	while (!Q.empty()) {
		s = Q.front();
		Q.pop();
		for (int i=0; i<2*(N+1); ++i) {
			if (C[s][i]-F[s][i]>0 && P[i]==-1) {
				P[i] = s;
				if (i == t) {
					return true;
				}
				Q.push(i);
			}
		}
	}

	return false;
}
int maxflow() {
	memset(F, 0, sizeof F);
	int ret = 0;
	while (bfs(source, sink)) {
		++ret;
		int t = sink;
		while (t != source) {
			F[P[t]][t] += 1;
			F[t][P[t]] -= 1;
			t = P[t];
		}
	}
	for (int i=0; i<2*(N+1); ++i) {
		for (int j=0; j<2*(N+1); ++j) {
			cerr << F[i][j] << ' ';
		}
		cerr << '\n';
	}
	cerr << '\n';
	return ret;
}
void set_burden(int burden) {
	for (int i=0; i<N; ++i) {
		C[source][left(i)] = burden;
	}
}
class WSNParentsAssignment {
	public:
	vector <int> minNetworkBurdenLevel(vector <string> network, string nearest) {
		::network = network;
		::nearest = nearest;
		N = (int)network.size();
		source = 2*N;
		sink = source+1;

		for (int i=0; i<N; ++i) {
			if (nearest[i] == 'Y') {
				C[source][right(i)] += 1;
			}
			C[right(i)][sink] += 1;
			for (int j=0; j<N; ++j) {
				if (network[i][j] == 'Y') {
					C[left(j)][right(i)] += 1;
				}
			}
		}

		int max_burden = 0;
		while (max_burden < N) {
			set_burden(max_burden);
			if (maxflow() == N) {
				break;
			}
			++max_burden;
		}

		if (max_burden == N) {
			return vector<int>();
		}

		vector<int> sol(N, -1);
		for (int i=0; i<N; ++i) {
			cerr << string(10, '*') << i << '\n';
			for (int a=0; a<2*(N+1); ++a) {
				for (int b=0; b<2*(N+1); ++b) {
					cerr << C[a][b] << ' ';
				}
				cerr << '\n';
			}
				cerr << '\n';
			for (int j=0; j<N; ++j) {
				if (network[i][j]=='Y' && C[source][left(j)]>0) {
					C[source][left(j)] -= 1;
					C[left(j)][right(i)] = 0;
					C[right(i)][sink] = 0;
					if (maxflow() == N-1-i) {
						sol[i] = j;
						break;
					}
					C[source][left(j)] += 1;
					C[left(j)][right(i)] = 1;
					C[right(i)][sink] = 1;
				}
			}
			if (sol[i] == -1) {
				sol[i] = N;
				C[right(i)][sink] = 0;
			}
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"NNY","NNY","NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NNY"; int Arr2[] = {2, 2, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, minNetworkBurdenLevel(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"NYY","NNY","NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NNY"; int Arr2[] = {1, 2, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, minNetworkBurdenLevel(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"NYNNNN","NNNNNN","NYNYNN","NNNNNN","NYNYNN","NYNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NYNYNN"; int Arr2[] = {1, 6, 3, 6, 3, 1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, minNetworkBurdenLevel(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Y"; int Arr2[] = {1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, minNetworkBurdenLevel(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "N"; int Arr2[] = { }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, minNetworkBurdenLevel(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"NNNNN","YNNNY","NNNYN","NNNNN","YNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YNNYN"; int Arr2[] = {5, 4, 3, 5, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, minNetworkBurdenLevel(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    WSNParentsAssignment ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

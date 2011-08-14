#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct Edge {
	int to, cap, f, cost;
};

int N;
int source, sink;
vector< vector<Edge> > G;

int best[200];
int from[200];
int augment() {
	memset(best, 0x3f, sizeof best);
	best[source] = 0;

	for (int t=0; t<N; ++t) {
		for (int i=0; i<N; ++i) {
			if (best[i] >= 123456789) {
				continue;
			}
			for (int e=0; e<(int)G[i].size(); ++e) {
				Edge &edge = G[i][e];
				if (edge.cap - edge.f <= 0) {
					continue;
				}
				int nc = best[i] + edge.cost;
				if (best[edge.to] > nc) {
					best[edge.to] = nc;
					from[edge.to] = i;
				}
			}
		}
	}

	if (best[sink] >= 123456789) {
		return 123456789;
	}

	int t = sink;
	while (t != source) {
		int s = from[t];
		for (int e=0; e<(int)G[s].size(); ++e) {
			Edge &edge = G[s][e];
			if (edge.to == t) {
				++edge.f;
			}
		}
		for (int e=0; e<(int)G[t].size(); ++e) {
			Edge &edge = G[t][e];
			if (edge.to == s) {
				--edge.f;
			}
		}
		t = s;
	}

	return best[sink];
}
class RadarGuns {
	public:
	vector <int> getRange(vector <int> A, vector <int> B, int speed, int cap) {
		source = 2*A.size();
		sink = source+1;
		N = sink + 1;

		G.assign(N, vector<Edge>());
		for (int i=0; i<(int)A.size(); ++i) {
			G[source].push_back((Edge) { i, 1, 0, 0 });
			G[i].push_back((Edge) { source, 0, 0, 0 });
			G[i+A.size()].push_back((Edge) { sink, 1, 0, 0 });
			G[sink].push_back((Edge) { i+A.size(), 0, 0, 0 });
			for (int j=0; j<(int)B.size(); ++j) {
				if (B[j] > A[i]) {
					int t = B[j]-A[i];
					int cost = min(cap, (t<speed ? (speed-t)*(speed-t) : 0));
					G[i].push_back((Edge) { j+A.size(), 1, 0, cost });
					G[j+A.size()].push_back((Edge) { i, 0, 0, -cost });
				}
			}
		}

		cerr << "tu\n";

		int flow = 0;
		int cost = 0;
		int step = 0;
		while ((step = augment()) < 123456789) {
			++flow;
			cost += step;
		}

		if (flow < (int)A.size()) {
			return vector<int>();
		}

		vector<int> sol;
		sol.push_back(cost);

		for (int i=0; i<N; ++i) {
			for (int j=0; j<(int)G[i].size(); ++j) {
				G[i][j].f = 0;
				G[i][j].cost *= -1;
			}
		}

		cost = 0;
		while ((step = augment()) < 123456789) {
			cost += step;
		}
		sol.push_back(-cost);

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 100; int Arr4[] = {0, 1 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, getRange(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {60,40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; int Arg3 = 100; int Arr4[] = {200, 200 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, getRange(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {1000, 584, 390, 392, 109}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {987, 724, 814, 597, 422}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 30; int Arr4[] = { }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, getRange(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; int Arg3 = 42; int Arr4[] = {48, 56 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, getRange(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RadarGuns ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

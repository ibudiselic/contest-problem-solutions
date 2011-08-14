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

int G[50][50];
int F[50][50];
int P[50];
int N;

bool bfs(int s, int d) {
	queue<int> q;

	P[s] = -2;
	q.push(s);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i=0; i<N; ++i)
			if (P[i]==-1 && G[x][i]-F[x][i]>0) {
				q.push(i);
				P[i] = x;
				if (i == d)
					return true;
			}
	}

	return false;
}
int maxflow(int s, int d) {
	int ret = 0;

	memset(F, 0, sizeof F);
	memset(P, 0xff, sizeof P);
	while (bfs(s, d)) {
		int t = d;
		int w = 1234567890;
		while (P[t] != -2) {
			w = min(w, G[P[t]][t]-F[P[t]][t]);
			t = P[t];
		}
		ret += w;
		t = d;
		while (P[t] != -2) {
			F[P[t]][t] += w;
			F[t][P[t]] -= w;
			t = P[t];
		}
		memset(P, 0xff, sizeof P);
	}

	return ret;
}

class Terrorists {
	public:
	int requiredCost(vector <string> roads) {
		N = roads.size();
		for (int i=0; i<N; ++i)
			for (int j=0; j<N; ++j)
				G[i][j] = roads[i][j]-'0';


		int sol = 1234567890;
		for (int i=1; i<N; ++i)
			sol = min(sol, maxflow(0, i));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0911",
 "9011",
 "1109",
 "1190"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, requiredCost(Arg0)); }
	void test_case_1() { string Arr0[] = {"0399",
 "3033",
 "9309",
 "9390"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(1, Arg1, requiredCost(Arg0)); }
	void test_case_2() { string Arr0[] = {"030900",
 "304120",
 "040174",
 "911021",
 "027207",
 "004170"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(2, Arg1, requiredCost(Arg0)); }
	void test_case_3() { string Arr0[] = {"044967263",
 "409134231",
 "490642938",
 "916036261",
 "634306024",
 "742660550",
 "229205069",
 "633625604",
 "318140940"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 27; verify_case(3, Arg1, requiredCost(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Terrorists ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
#define INF 1000000111

vector< vector<int> > mg() {
	vector< vector<int> > v(100, vector<int>(100, INF));
	for (int i=0; i<100; ++i)
		v[i][i] = 0;
	return v;
}
int ind(const string &s) {
	return 10*(s[0]-'A') + (s.size()>1 ? s[1]-'0' : 0);
}
void fw(vector< vector<int> > &w) {
	for (int k=0; k<100; ++k)
		for (int i=0; i<100; ++i)
			for (int j=0; j<100; ++j)
				w[i][j] = min(w[i][j], w[i][k]+w[k][j]);
}
class RecursiveGraph {
	public:
	int shortestPath(vector <string> edges, char start, char end) {
		int s = start-'A';
		int t = end-'A';
		s *= 10;
		t *= 10;

		vector< vector<int> > v = mg();
		for (int i=0; i<(int)edges.size(); ++i) {
			istringstream is(edges[i]);
			string a_, b_;
			int x;
			is >> a_ >> b_ >> x;
			const int a = ind(a_);
			const int b = ind(b_);
			v[a][b] = x;
			v[b][a] = x;
		}
		vector< vector<int> > last = mg();
		for (int i=0; i<100; ++i)
			for (int j=0; j<100; ++j)
				if (v[i][j] != INF)
					last[i][j] = 0;

		fw(last);
		for (int level=20; level>=0; --level) {
			vector< vector<int> > next = mg();
			for (int i=0; i<100; ++i)
				for (int j=0; j<100; ++j)
					if (i%10==0 || j%10==0) {
						next[i][j] = (v[i][j]==INF ? INF : v[i][j]>>level);
						next[j][i] = (v[i][j]==INF ? INF : v[i][j]>>level);
					} else if (i%10 != j%10) {
						next[i][j] = next[j][i] = (v[i][j]==INF ? INF : v[i][j]>>level);
					} else {
						next[i][j] = last[i/10*10][j/10*10];
						next[j][i] = last[i/10*10][j/10*10];
					}
			last = next;
			fw(last);
		}

		return (last[s][t]<INF ? last[s][t] : -1);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"A B 20",
"C D 13",
"A C1 1",
"D1 C2 2",
"D2 B 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); char Arg1 = 'A'; char Arg2 = 'B'; int Arg3 = 18; verify_case(0, Arg3, shortestPath(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"A B 800",
"A C1 4",
"D1 B 4",
"C A2 4",
"B2 D 4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); char Arg1 = 'A'; char Arg2 = 'B'; int Arg3 = 14; verify_case(1, Arg3, shortestPath(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"A A1 1",
"B B1 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); char Arg1 = 'A'; char Arg2 = 'B'; int Arg3 = -1; verify_case(2, Arg3, shortestPath(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = { "A E1 10", "H2 J 11",
"E F 50", "F1 G2 5", "G H 60",
"A C4 12", "D4 J 13",
"C E1 14", "F1 D 15",
"E G8 6", "F H8 8" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); char Arg1 = 'J'; char Arg2 = 'A'; int Arg3 = 49; verify_case(3, Arg3, shortestPath(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = { "E H 3", "C J 3", "D E9 0", "H9 A 0", "A C3 0", "J3 F 0" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); char Arg1 = 'D'; char Arg2 = 'F'; int Arg3 = 2; verify_case(4, Arg3, shortestPath(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RecursiveGraph ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

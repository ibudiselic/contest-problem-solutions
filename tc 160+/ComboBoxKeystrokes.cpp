#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

int dist[50][50];
int getNext(const vector<string> &v, int x, char c) {
	for (int i=x+1; i<(int)v.size(); ++i)
		if (tolower(v[i][0]) == c)
			return i;

	for (int i=0; i<x; ++i)
		if (tolower(v[i][0]) == c)
			return i;

	return x;
}
class ComboBoxKeystrokes {
	public:
	int minimumKeystrokes(vector <string> elements) {
		memset(dist, 0x3f, sizeof dist);

		int n = elements.size();
		for (int i=0; i<n; ++i)
			for (int c='a'; c<='z'; ++c) {
				int t = getNext(elements, i, c);
				if (t != i)
					dist[i][t] = 1;
			}

		for (int k=0; k<n; ++k)
			for (int i=0; i<n; ++i)
				for (int j=0; j<n; ++j)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

		int sol = 0;
		for (int i=0; i<n; ++i)
			for (int j=i+1; j<n; ++j)
				sol = max(sol, max(dist[i][j], dist[j][i]));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"alpha","beta","gamma","delta"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, minimumKeystrokes(Arg0)); }
	void test_case_1() { string Arr0[] = {"kyky","kalinov","kalmakka","Kavan","Kawigi","kaylin","Klinck","krijgertje","kupo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, minimumKeystrokes(Arg0)); }
	void test_case_2() { string Arr0[] = {"a","b","c","b","d","b","e","b","f"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, minimumKeystrokes(Arg0)); }
	void test_case_3() { string Arr0[] = {"apple","Boy","CaRD","Dog","egG","FruiT",
 "Grape","hand","Ant","eagle","ice cream",
 "air","East","Exit","Door","camerA","bad",
 "fast","Zealot","internAtional","Bead",
 "Bread","Exit","fast", "actiVe","Cats",
 "beast","Alligator","drag","castle",
 "clean","iLlEgAl","crab","Free Willy",
 "first","dean","Fourth of July","King",
 "fellow","FrEaK","Elephant","bird","Bible",
 "creep","create","Deal","eEl","entrance",
 "cream","Fleece"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, minimumKeystrokes(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ComboBoxKeystrokes ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

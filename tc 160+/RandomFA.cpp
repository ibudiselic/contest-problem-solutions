#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int prob[51][51][3];
int final, len, n;
double sol[51];

void parse(const vector<string> &a, int j) {
	for (int i=0; i<(int)a.size(); ++i) {
		istringstream is(a[i]);
		string s;
		int sum = 0;
		while (is >> s) {
			int state, p;
			sscanf(s.c_str(), "%d:%d", &state, &p);
			sum += p;
			prob[i][state][j] = p;
		}
		prob[i][n][j] = 100-sum;
	}
}

class RandomFA {
	public:
	double getProbability(vector <string> rulesa, vector <string> rulesb, vector <string> rulesc, int finalState, int maxLength) {
		len = maxLength;
		n = rulesa.size();
		final = finalState==999 ? n : finalState;

		for (int i=0; i<51; ++i)
			for (int j=0; j<51; ++j)
				for (int k=0; k<3; ++k)
					prob[i][j][k] = 0;

		rulesa.push_back("");
		parse(rulesa, 0);
		rulesb.push_back("");
		parse(rulesb, 1);
		rulesc.push_back("");
		parse(rulesc, 2);

		for (int i=0; i<51; ++i)
			sol[i] = 0.0;

		int weight = 1;
		int cnt = 0;
		vector<double> p(n+1, 0.0);
		p[0] = 1.0;
		for (int i=0; i<=len; ++i, weight*=3) {
			cnt += weight;
			for (int j=0; j<=n; ++j)
				sol[j] += p[j]*weight;

			vector<double> t(n+1, 0.0);
			for (int x=0; x<=n; ++x)
				for (int y=0; y<=n; ++y)
					for (int j=0; j<3; ++j)
						t[y] += p[x]*prob[x][y][j]/300;
			p = t;
		}
		return sol[final]/cnt;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0:100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {""}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {""}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 999; int Arg4 = 1; double Arg5 = 0.5; verify_case(0, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { string Arr0[] = {"1:100","0:100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1:100","0:100"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1:100","0:100"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; int Arg4 = 3; double Arg5 = 0.75; verify_case(1, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { string Arr0[] = {"1:25 2:25 3:25 4:25","0:100","0:100","0:100","0:100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"","","","",""}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"","","","",""}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 5; double Arg5 = 0.0020604395604395605; verify_case(2, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { string Arr0[] = {"1:25 2:25 3:25 4:25","0:100","0:100","0:100","0:100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"","","","",""}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"","","","",""}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 999; int Arg4 = 5; double Arg5 = 0.9835164835164837; verify_case(3, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { string Arr0[] = {"2:9 0:7 3:4 1:2 5:35","2:9 0:7 3:4 1:2 5:35",
 "2:9 0:7 3:4 1:2 5:35","2:9 0:7 3:4 1:2 5:35",
 "2:9 0:7 3:4 1:2 5:35","2:9 0:7 3:4 1:2 5:35"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0:10 4:7 5:1","0:10 4:7 5:1","0:10 4:7 5:1",
 "0:10 4:7 5:1","0:10 4:7 5:1","3:79 2:10"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1:100","2:100","3:100","4:100","5:100","0:100"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 10; double Arg5 = 0.002676338903044717; verify_case(4, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { string Arr0[] = {"2:9 0:7 3:4 1:2 5:35","2:9 0:7 3:4 1:2 5:35",
 "2:9 0:7 3:4 1:2 5:35","2:9 0:7 3:4 1:2 5:35",
 "2:9 0:7 3:4 1:2 5:35","2:9 0:7 3:4 1:2 5:35"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0:10 4:7 5:1","0:10 4:7 5:1","0:10 4:7 5:1",
 "0:10 4:7 5:1","0:10 4:7 5:1","3:79 2:10"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1:100","2:100","3:100","4:100","5:100","0:100"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 0; double Arg5 = 0.0; verify_case(5, Arg5, getProbability(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    RandomFA ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

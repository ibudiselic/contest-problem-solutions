#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int best[1<<12];
int dp[1<<12][50];
vector<int> S, E;
int dist[50][50];
int go(int m, int pos) {
	if (m == 0)
		return pos==0 ? 0 : dist[pos][0];
	if (dp[m][pos] != -1)
		return dp[m][pos];

	int ret = 1234567890;
	for (int i=0; i<(int)S.size(); ++i)
		if (m & (1<<i))
			ret = min(ret, (pos!=S[i] ? dist[pos][S[i]] : 0) + dist[S[i]][E[i]] + go(m ^ (1<<i), E[i]));

	return dp[m][pos] = ret;
}
class TaxiManager {
	public:
	int schedule(vector <string> R, vector <string> customers) {
		S.clear();
		E.clear();
		for (int i=0; i<(int)customers.size(); ++i) {
			istringstream is(customers[i]);
			int s, e;
			is >> s >> e;
			S.push_back(s);
			E.push_back(e);
		}
		for (int i=0; i<(int)R.size(); ++i)
			for (int j=0; j<(int)R.size(); ++j) {
				dist[i][j] = R[i][j]-'0';
				if (dist[i][j] == 0)
					dist[i][j] = 987654321;
			}

		for (int k=0; k<(int)R.size(); ++k)
			for (int i=0; i<(int)R.size(); ++i)
				for (int j=0; j<(int)R.size(); ++j)
					dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

		for (int cur=0; cur<(1<<S.size()); ++cur) {
			memset(dp, 0xff, sizeof dp);
			best[cur] = go(cur, 0);
		}

		int sol = 1234567890;
		for (int cur=0; cur<(1<<S.size()); ++cur)
			sol = min(sol, max(best[cur], best[~cur & ((1<<S.size()) - 1)]));

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"020200"
,"202020"
,"020002"
,"200020"
,"020202"
,"002020"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"5 3","2 4","1 5","3 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 16; verify_case(0, Arg2, schedule(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] =
{"00020251090265906661"
,"00763002550100090081"
,"06003699000080062771"
,"00000710460400035310"
,"50000039119198350060"
,"66060004050810046028"
,"02333108565000200880"
,"40212560000209205231"
,"02601150098329905062"
,"00210383709951005203"
,"10111087340780827070"
,"05065800003095040140"
,"15604020082000100090"
,"83430030070580600750"
,"10588355007006001150"
,"14400080790005400536"
,"23400990400933060004"
,"11053016300602000090"
,"90040920084059282502"
,"61300007077904050900"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 19","4 16","15 16","4 18","2 7","9 15","11 6","7 13","19 13","12 19","14 12","16 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 33; verify_case(1, Arg2, schedule(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] =
{"095222800320504"
,"107600288090501"
,"760973530769345"
,"963093337510830"
,"338404069255826"
,"291700050155264"
,"002783031709004"
,"404730701707712"
,"068870030090995"
,"320025180036103"
,"468695042801904"
,"233626561000105"
,"070014432197086"
,"887301000143802"
,"230852749990330"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"3 6","0 4","2 7","9 7","13 9","1 6","7 13","14 2","8 7","10 1","11 13","7 12"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 28; verify_case(2, Arg2, schedule(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"00401","50990","00062","08008","03000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14; verify_case(3, Arg2, schedule(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TaxiManager ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

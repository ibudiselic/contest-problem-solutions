#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct Contest {
	int s, t, p;
	Contest(int s_, int t_, int p_): s(s_), t(t_), p(p_) {}
};
bool operator<(const Contest &a, const Contest &b) {
	if (a.s != b.s)
		return a.s < b.s;
	else if (a.t != b.t)
		return a.t < b.t;
	else
		return a.p < b.p;
}

double dp[50];
int N;
vector<Contest> C;

double go(int x) {
	if (x == N)
		return 0.0;
	if (dp[x] > -0.5)
		return dp[x];

	double ret = max(double(C[x].p)/100, go(x+1));
	int next = x+1;
	while (next<N && C[next].s<C[x].t)
		++next;
	if (next < N)
		ret = max(ret, double(C[x].p)/100 + go(next));

	return dp[x] = ret;
}
class ContestSchedule {
	public:
	double expectedWinnings(vector <string> contests) {
		N = contests.size();
		C.clear();
		for (int i=0; i<N; ++i) {
			int s, t, p;
			sscanf(contests[i].c_str(), "%d %d %d", &s, &t, &p);
			C.push_back(Contest(s, t, p));
		}

		sort(C.begin(), C.end());
		for (int i=0; i<N; ++i)
			dp[i] = -1.0;

		return go(0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 10 100","10 20 100","20 30 100","30 40 100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 4.0; verify_case(0, Arg1, expectedWinnings(Arg0)); }
	void test_case_1() { string Arr0[] = {"10 20 20","30 40 60","15 35 90"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.9; verify_case(1, Arg1, expectedWinnings(Arg0)); }
	void test_case_2() { string Arr0[] = {"1 100 85","99 102 100","101 200 60"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.45; verify_case(2, Arg1, expectedWinnings(Arg0)); }
	void test_case_3() { string Arr0[] = {"1 1000000000 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.01; verify_case(3, Arg1, expectedWinnings(Arg0)); }
	void test_case_4() { string Arr0[] = {
"1361955 8940967 10","628145516 644285978 17","883515280 910484865 36",
"762888635 769291174 52","98152102 136328674 1","9580638 20450682 50",
"646139319 664648341 20","484027666 505290970 57","841082555 879295329 99",
"940563715 966953344 4","579113528 595261527 25","925801172 962952912 9",
"285845005 307916055 45","403573723 410697485 10","9467290 25698952 90",
"631265400 650639733 3","520690249 559261759 96","491747709 531061081 86",
"643215695 672420161 94","614608448 617341712 44","456517316 491770747 24",
"806956091 828414045 88","528156706 559510719 15","158398859 190439269 4",
"743974602 761975244 49","882264704 887725893 1","877444309 884479317 59",
"785986538 806192822 19","732553407 747696021 81","132099860 148305810 97",
"555144412 572785730 99","506507263 535927950 82","489726669 505160939 90",
"793692316 804153358 99","901329638 919179990 10","29523791 44318662 58",
"570497239 595701008 73","706091347 730328348 23","118054686 135301010 39",
"307178252 337804001 93","896162463 900667971 39","271356542 273095245 80",
"865692962 891795950 91","593986003 596160000 58","807688147 831190344 59",
"468916697 496462595 92"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 14.12; verify_case(4, Arg1, expectedWinnings(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ContestSchedule ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

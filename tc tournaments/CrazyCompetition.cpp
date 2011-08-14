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

int val(char c) {
	if (c == '0')
		return 0;
	else
		return (c-(isupper(c) ? 'A' : 'a')+1) * (isupper(c) ? -1 : 1);
}
class CrazyCompetition {
	public:
	double differenceTemperature(int daysSummer, int daysWinter, vector <string> temperature) {
		string s;

		for (int i=0; i<(int)temperature.size(); ++i)
			s += temperature[i];

		int N = s.size();

		vector< vector<int> > sum(N, vector<int> (N, 0));

		for (int i=0; i<N; ++i)
			sum[i][i] = val(s[i]);

		for (int offset=1; offset<N; ++offset)
			for (int i=0; i+offset<N; ++i)
				sum[i][i+offset] = sum[i][i+offset-1] + val(s[i+offset]);

		double sol = -1e32;
		for (int i=0; i+daysSummer<=N; ++i) {
			double avgSummer = double(sum[i][i+daysSummer-1])/daysSummer;
			for (int j=0; j+daysWinter<=i; ++j) {
				double avgWinter = double(sum[j][j+daysWinter-1])/daysWinter;
				sol = max(sol, avgSummer - avgWinter);
			}
			for (int j=i+daysSummer; j+daysWinter<=N; ++j) {
				double avgWinter = double(sum[j][j+daysWinter-1])/daysWinter;
				sol = max(sol, avgSummer - avgWinter);
			}
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; string Arr2[] = {"aa"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.0; verify_case(0, Arg3, differenceTemperature(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; string Arr2[] = {"ba"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 1.0; verify_case(1, Arg3, differenceTemperature(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; string Arr2[] = {"az"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 25.0; verify_case(2, Arg3, differenceTemperature(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 3; string Arr2[] = {"aaaa","x"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 11.5; verify_case(3, Arg3, differenceTemperature(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 2; int Arg1 = 3; string Arr2[] = {"a","a","a","a","x"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 11.5; verify_case(4, Arg3, differenceTemperature(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 4; int Arg1 = 1; string Arr2[] = {"00A00"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = -0.25; verify_case(5, Arg3, differenceTemperature(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CrazyCompetition ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

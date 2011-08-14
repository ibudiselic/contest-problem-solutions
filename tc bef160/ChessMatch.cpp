#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


/*** real code starts here ***/

vector<vector<double> > score;
class ChessMatch {
	public:
	double bestExpectedScore(vector <int> teamA, vector <int> teamB, int lim) {
		score = vector<vector<double> > (teamA.size(), vector<double> (teamB.size(), 0.0));
		
		for (int i=0; i<(int)teamA.size(); ++i)
			for (int j=0; j<(int)teamB.size(); ++j)
				score[i][j] = 1.0/(1+pow(10, (teamB[j]-teamA[i])/400.0)));
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2239,2412,2399,2267}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2534,2429,2340,2389}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; double Arg3 = 1.4835736078879815; verify_case(0, Arg3, bestExpectedScore(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {2239,2412,2399,2267}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2534,2429,2340,2389}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 150; double Arg3 = 1.5332458652994558; verify_case(1, Arg3, bestExpectedScore(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {2500,2503}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1500,1503}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; double Arg3 = 1.9936953816334797; verify_case(2, Arg3, bestExpectedScore(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1786,2080,2156,2132,2187,2380,2191}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1885,1851,1743,1714,2338,2167,1789}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1500; double Arg3 = 5.227676657319362; verify_case(3, Arg3, bestExpectedScore(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {1868,1797,2213,2085,1611,2002,2167,1908,
 1773,1834,1766,2245,1582,2009,2233,2030}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2138,2259,2109,2160,2295,2022,2043,2131,
 1655,1716,1648,1779,1518,1570,1560,1677}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 200; double Arg3 = 9.229777079272512; verify_case(4, Arg3, bestExpectedScore(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    ChessMatch ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

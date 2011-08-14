#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int pow3[9];
int trits[6561][9];
int dist[6561][40][40];
double dp[40][6561];
vector<double> P;
int nLines, dest;
int lines[40];

double go(int pos, int mask) {
	if (pos == dest)
		return 0;

	int newInfo = 0;
	for (int i=0; i<nLines; ++i)
		if (trits[mask][i]==2 && (lines[pos] & (1<<i)))
			newInfo |= (1<<i);

	if (newInfo == 0)
		return 1e15;

	double ret = 0.0;
	int newDel = 0;
	do {
		double p = 1.0;
		int nMask = mask;
		for (int i=0; i<nLines; ++i)
			if (newDel & (1<<i)) {
				p *= P[i];
				nMask -= pow3[i];
			} else if (newInfo & (1<<i)) {
				p *= (1-P[i]);
				nMask -= 2*pow3[i];
			}

		double &best = dp[pos][nMask];
		if (best > -0.5) {
			ret += p*best;
		} else {
			best = 1e15;
			for (int target=0; target<40; ++target)
				best = min(best, dist[nMask][pos][target] + go(target, nMask));

			ret += p*best;
		}
		newDel = (newDel + ~newInfo + 1) & newInfo;
	} while (newDel != 0);

	return ret;
}

class MetroNetwork {
	public:
	double minimizeTime(int start, int destination, vector <string> lines_, vector <string> times, vector <int> probabilities, int changeTime, int delay) {
		nLines = lines_.size();
		P.clear();
		for (int i=0; i<nLines; ++i)
			P.push_back(probabilities[i]/100.0);

		dest = destination;
		pow3[0] = 1;
		for (int i=1; i<=nLines; ++i)
			pow3[i] = pow3[i-1] * 3;

		for (int mask=0; mask<pow3[nLines]; ++mask) {
			int x = mask;
			for (int i=0; i<nLines; ++i, x/=3)
				trits[mask][i] = x%3; // 0 not-delayed, 1 delayed, 2 unknown

			for (int i=0; i<40; ++i)
				for (int j=0; j<40; ++j)
					dist[mask][i][j] = 987654321;
		}

		memset(lines, 0, sizeof lines);
		for (int i=0; i<nLines; ++i) {
			vector<int> stations;
			vector<int> t;
			istringstream statIn(lines_[i]);
			istringstream timesIn(times[i]);

			int x;
			while (statIn >> x)
				stations.push_back(x);
			while (timesIn >> x)
				t.push_back(x);

			for (int mask=0; mask<pow3[nLines]; ++mask)
				if (trits[mask][i] != 2) {
					int d = trits[mask][i] * delay;
					for (int a=0; a<(int)stations.size(); ++a) {
						int trip = 0;
						lines[stations[a]] |= (1<<i);
						for (int b=a+1; b<(int)stations.size(); ++b) {
							trip += t[b-1]+d;
							dist[mask][stations[a]][stations[b]] = min(dist[mask][stations[a]][stations[b]], 2*changeTime + trip);
							dist[mask][stations[b]][stations[a]] = min(dist[mask][stations[b]][stations[a]], 2*changeTime + trip);
						}
					}
				}
		}

		for (int mask=0; mask<pow3[nLines]; ++mask)
			for (int k=0; k<40; ++k)
				for (int i=0; i<40; ++i)
					for (int j=0; j<40; ++j)
						dist[mask][i][j] = min(dist[mask][i][j], dist[mask][i][k] + dist[mask][k][j]);

		for (int i=0; i<40; ++i)
			for (int mask=0; mask<pow3[nLines]; ++mask)
				dp[i][mask] = -1.0;


		double sol = go(start, pow3[nLines]-1);

		return sol<1e8 ? sol : -1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 7; string Arr2[] = {"0 1 2 3 4 5 6 7"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"2 2 2 2 2 2 2"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {50}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 5; int Arg6 = 5; double Arg7 = 41.5; verify_case(0, Arg7, minimizeTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 3; string Arr2[] = {"0 1","0 2","1 3","2 3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"5","5","5","5"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0,0,50,50}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 5; int Arg6 = 20; double Arg7 = 40.0; verify_case(1, Arg7, minimizeTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arg0 = 0; int Arg1 = 3; string Arr2[] = {"0 1","0 2","0 1 3","2 3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"5","5","100 5","5"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0,0,50,50}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 5; int Arg6 = 20; double Arg7 = 35.0; verify_case(2, Arg7, minimizeTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arg0 = 0; int Arg1 = 4; string Arr2[] = {"0 1 2 3","1 3 4","2 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"10 10 20","100 10","80"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0,50,0}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 5; int Arg6 = 100; double Arg7 = 105.0; verify_case(3, Arg7, minimizeTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_4() { int Arg0 = 12; int Arg1 = 9; string Arr2[] = {"0 30 1 2 3 4 31 5 6 7",
"38 6 8 32 9 33 10 34 11 0 12 13 14 15 16 36 5 38",
"17 39 18 19 5 8 9 20 21",
"17 39 22 16 23 24 3 25 20 21",
"28 9 20 25 2 27 14 17",
"12 13 27 26 24 4 9 28",
"29 10 1 27 15 22 19",
"11 10 2 26 23 16 22 18"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"3 3 2 3 2 3 2 2 5",
"2 1 3 4 3 2 4 2 4 5 1 4 4 2 4 5 4",
"2 4 4 2 2 6 2 4",
"2 8 2 1 1 2 3 1 6",
"6 1 2 2 2 2 6",
"1 7 1 2 2 4 8",
"7 2 3 2 2 4",
"4 4 2 2 1 2 9"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {20,5,15,50,45,5,10,5}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 3; int Arg6 = 10; double Arg7 = 23.228506624999994; verify_case(4, Arg7, minimizeTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_5() { int Arg0 = 0; int Arg1 = 3; string Arr2[] = {"0 1","2 3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"2","2"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {50,50}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 5; int Arg6 = 5; double Arg7 = -1.0; verify_case(5, Arg7, minimizeTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_6() { int Arg0 = 31; int Arg1 = 8; string Arr2[] = {"35 38 1 3 4 7 9 10 12 14 16 18 19 20 21 24 25 26"
,"7 10 11 13 15 16 19 22 23 25 26 27 30 33 35 38 1"
,"35 38 1 3 5 6 9 11 13 16 17 19 22 25 26 29 30 32"
,"24 26 28 29 32 34 37 39 1 4 6 8 11 13 16 17 18 19"
,"13 15 17 20 22 25 26 29 30 32 35 37 0 2 3 6 7 8"
,"20 22 24 26 29 31 32 33 36 38 0 3 6 8 9 12 13 14"
,"12 15 16 18 19 21 22 24 25 26 28 30 31 32 33 35"
,"32 34 37 38 39 0 2 4 7 9 12 15 17 20 22 23 24 27"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"2 4 9 9 4 4 2 9 7 5 8 3 3 6 7 4 1"
,"1 6 6 8 8 10 7 1 8 10 9 8 9 3 3 2"
,"2 2 7 9 9 1 9 7 9 6 4 4 1 1 10 2 3"
,"10 10 6 5 1 9 9 6 10 5 4 7 5 3 1 2 2"
,"5 1 3 9 2 5 5 6 5 6 3 5 8 8 5 1 6"
,"4 10 4 1 7 1 9 3 5 3 6 9 2 10 3 9 7"
,"9 3 6 6 6 3 5 6 10 10 2 2 5 2 6"
,"1 7 3 6 1 10 2 1 7 4 7 9 7 10 7 3 2"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {81,5,54,32,6,12,80,38}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 4; int Arg6 = 88; double Arg7 = 56.38865447903488; verify_case(6, Arg7, minimizeTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MetroNetwork ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

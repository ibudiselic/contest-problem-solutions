#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<int> G;
int me, N;
int sol;
vector< vector<int> > change;
void go(int mask, int night) {
	if ((mask & me) == 0) {
		sol = max(sol, night-1);
		return;
	}
	if (mask == me) {
		sol = max(sol, night);
		return;
	}

	for (int i=0; i<N; ++i)
		if (mask & (1<<i)) {
			for (int j=0; j<N; ++j)
				G[j] += change[i][j];

			int best = -1234567890;
			int ind = -1;
			for (int j=0; j<N; ++j)
				if (j!=i && (mask & (1<<j))!=0 && G[j]>best) {
					best = G[j];
					ind = j;
				}

			go(mask ^ (1<<i) ^ (1<<ind), night+1);

			for (int j=0; j<N; ++j)
				G[j] -= change[i][j];
		}
}

class Mafia {
	public:
	int play(vector <int> guilt, vector <string> responses, int playerIndex) {
		G = guilt;
		N = G.size();
		change.assign(N, vector<int>(N, 0));

		for (int i=0; i<N; ++i)
			for (int j=0; j<N; ++j)
				change[i][j] = (responses[i][j] <= 'Z' ? responses[i][j]-'A'+1 : -(responses[i][j]-'a'+1));

		me = (1<<playerIndex);

		sol = 0;
		int mask = (1<<N)-1;
		if (N & 1) {
			int ind = 0;
			for (int i=1; i<N; ++i)
				if (G[i] > G[ind])
					ind = i;
			go(mask ^ (1<<ind), 1);
		} else {
			go(mask, 1);
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {500,500,500,500}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ADCb",
 "bADC",
 "CbAD",
 "DCbA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 2; verify_case(0, Arg3, play(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {500,500,500,500,501}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ADCbE",
 "bADCE",
 "CbADE",
 "DCbAE",
 "EDCbA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 2; verify_case(1, Arg3, play(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {500,500,500,500,500,500}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"cccccc",
 "BBBBBB",
 "dddddd",
 "FFFFFF",
 "GGGGGG",
 "hhhhhh"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 1; verify_case(2, Arg3, play(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {501, 499, 499, 499}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ABCD",
 "zfAg",
 "ESAS",
 "atsm"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 2; verify_case(3, Arg3, play(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {800}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"E"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 0; verify_case(4, Arg3, play(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {643,457,642,710,595,631,566,634}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"APOSIfjf",
 "ewFOJWeJ",
 "jElLLoSS",
 "GeOSSmff",
 "zWSTsOuu",
 "fmfOPPsa",
 "MSoPPWXn",
 "FeojwFAM"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 3; verify_case(5, Arg3, play(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Mafia ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

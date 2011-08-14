#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int sol;
bool done[5], have[5];
vector<int> at, s, d;
class SmartElevator {
	public:
	void go(int t, int f, int n) {
		/*for (vector<int>::size_type i=0; i<at.size(); ++i) {
			if (!done[i] && !have[i] && s[i]==f && t>=at[i])
				have[i] = true;
			if (!done[i] && have[i] && d[i]==f) {
				done[i] = true;
				--n;
			}
		}*/
		if (n == 0) {
			if (t < sol)
				sol = t;
			return;
		}
		for (vector<int>::size_type i=0; i<at.size(); ++i) {
			if (!done[i] && !have[i]) {
				have[i] = true;
				go(max(t+abs(s[i]-f), at[i]), s[i], n);
				have[i] = false;
			}
			if (have[i]) {
				done[i] = true;
				have[i] = false;
				go(t+abs(d[i]-f), d[i], n-1);
				have[i] = true;
				done[i] = false;
			}
		}
		return;
	}
	int timeWaiting(vector <int> arrt, vector <int> start, vector <int> dest) {
		sol = 2000000000;
		memset(done, 0, sizeof done);
		memset(have, 0, sizeof have);
		at = arrt;
		s = start;
		d = dest;
		go(0, 1, (int)arrt.size());

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {50}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 49; verify_case(0, Arg3, timeWaiting(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {50}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 120; verify_case(1, Arg3, timeWaiting(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {10,120}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {210,200}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 230; verify_case(2, Arg3, timeWaiting(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {10,500}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {210,200}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 600; verify_case(3, Arg3, timeWaiting(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {1000,1200,1600,2000,2400}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {500,500,500,500,500}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {700,300,700,300,700}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2600; verify_case(4, Arg3, timeWaiting(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {775397,261225,870141,287698,884334}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {82225,958610,998971,413596,21922}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {769962,78706,477861,237168,258488}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2724059; verify_case(5, Arg3, timeWaiting(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SmartElevator ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

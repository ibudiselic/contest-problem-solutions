#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

class DownloadingFiles {
	public:
	double actualTime(vector <string> tasks) {
		int total = 0;
		vector< pair<int, int> > v;
		for (int i=0; i<(int)tasks.size(); ++i) {
			int ss, tt;
			sscanf(tasks[i].c_str(), "%d %d", &ss, &tt);
			v.push_back(make_pair(tt, ss));
			total += ss;
		}

		sort(v.begin(), v.end());
		int surplus = 0;
		double sol = 0.0;
		for (int i=0; i<(int)v.size(); ++i) {
			double t = v[i].first - sol;
			assert(t >= -1e-9);
			double s = v[i].second + surplus;
			surplus += v[i].second;

			double real = (t*v[i].second)/s;
			sol += real;
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"3 57","2 22"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 43.0; verify_case(0, Arg1, actualTime(Arg0)); }
	void test_case_1() { string Arr0[] = {"3 1057","2 1022"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1043.0; verify_case(1, Arg1, actualTime(Arg0)); }
	void test_case_2() { string Arr0[] = {"25 1000","5 5000","10 5000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2500.0; verify_case(2, Arg1, actualTime(Arg0)); }
	void test_case_3() { string Arr0[] = {"1 10","1 20","2 40"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 27.5; verify_case(3, Arg1, actualTime(Arg0)); }
	void test_case_4() { string Arr0[] = {"6 88","39 7057","63 2502","45 2285","28 8749","62 3636","1 5546","49 5741"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 4414.542662116041; verify_case(4, Arg1, actualTime(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    DownloadingFiles ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

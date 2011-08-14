#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

class Iditarod {
	public:
	int avgMinutes(vector <string> times) {
		const int start = 8*60;
		int x = 0;

		for (int i=0; i<(int)times.size(); ++i) {
			int h, m, d;
			char c;
			sscanf(times[i].c_str(), "%d:%d %cM, DAY %d", &h, &m, &c, &d);
			int sum = (d-1)*24*60;
			if (h == 12) {
				if (c == 'P')
					sum += 12*60;
				sum += m;
			} else {
				if (c == 'P')
					h += 12;
				sum += h*60 + m;
			}
			x += sum-start;
		}
		return (int)((double)x/times.size() + 0.5);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"12:00 PM, DAY 1","12:01 PM, DAY 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 241; verify_case(0, Arg1, avgMinutes(Arg0)); }
	void test_case_1() { string Arr0[] = {"12:00 AM, DAY 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 960; verify_case(1, Arg1, avgMinutes(Arg0)); }
	void test_case_2() { string Arr0[] = {"02:00 PM, DAY 19","02:00 PM, DAY 20", "01:58 PM, DAY 20"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 27239; verify_case(2, Arg1, avgMinutes(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Iditarod ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

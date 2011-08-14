#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class PaternityTest {
	public:
	vector <int> possibleFathers(string child, string mother, vector <string> men) {
		vector<int> sol;
		vector<bool> a(child.size(), false);
		int mcnt = 0;
		for (string::size_type i=0; i<child.size(); ++i)
			if (child[i] == mother[i]) {
				++mcnt;
				a[i] = true;
			}
		for (vector<string>::size_type i=0; i<men.size(); ++i) {
			int t = 0;
			int cnt = 0;
			for (string::size_type j=0; j<men[i].size(); ++j)
				if (men[i][j]==child[j])
					if (!a[j])
						++cnt;
					else ++t;
			if (cnt+::min(t, mcnt - (int)child.size()/2) >= (int)child.size()/2)
				sol.push_back(i);
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "ABCD"; string Arg1 = "AXCY"; string Arr2[] = { "SBTD", "QRCD" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 0 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, possibleFathers(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "ABCD"; string Arg1 = "ABCX"; string Arr2[] = { "ABCY", "ASTD", "QBCD" } ; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 1,  2 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, possibleFathers(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "ABABAB"; string Arg1 = "ABABAB"; string Arr2[] = { "ABABAB", "ABABCC", "ABCCDD", "CCDDEE" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 0,  1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, possibleFathers(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "YZGLSYQT"; string Arg1 = "YUQRWYQT"; string Arr2[] = {"YZQLDPWT", "BZELSWQM", "OZGPSFKT", "GZTKFYQT", "WQJLSMQT"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, possibleFathers(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "WXETPYCHUWSQEMKKYNVP"; string Arg1 = "AXQTUQVAUOSQEEKCYNVP"; string Arr2[] = { "WNELPYCHXWXPCMNKDDXD",
  "WFEEPYCHFWDNPMKKALIW",
  "WSEFPYCHEWEFGMPKIQCK",
  "WAEXPYCHAWEQXMSKYARN",
  "WKEXPYCHYWLLFMGKKFBB" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 1,  3 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, possibleFathers(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PaternityTest ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

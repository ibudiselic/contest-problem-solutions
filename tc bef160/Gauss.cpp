#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

template<class T>
string to_str(T x)
{
    string ret;
    ostringstream os(ret);

    os << x;
    return os.str();
}

class Gauss {
	public:
	vector <string> whichSums(string target) {
		long long t;
		vector<string> sol;
		stringstream os;
		os << target;
		os >> t;

		int n = (int)(-0.5 + sqrt(0.25+2*t));
		for (int i=n; i>=2; --i)
			if (i%2==0 && t%i==i/2)
				sol.push_back('['+to_str<long long>(t/i-i/2+1)+", "+to_str<long long>(t/i+i/2)+']');
			else if (i%2!=0 && t%i==0)
				sol.push_back('['+to_str<long long>(t/i-i/2)+", "+to_str<long long>(t/i+i/2)+']');

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "42"; string Arr1[] = { "[3, 9]",  "[9, 12]",  "[13, 15]" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, whichSums(Arg0)); }
	void test_case_1() { string Arg0 = "4"; string Arr1[] = { }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, whichSums(Arg0)); }
	void test_case_2() { string Arg0 = "17"; string Arr1[] = { "[8, 9]" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, whichSums(Arg0)); }
	void test_case_3() { string Arg0 = "55"; string Arr1[] = { "[1, 10]",  "[9, 13]",  "[27, 28]" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, whichSums(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Gauss ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

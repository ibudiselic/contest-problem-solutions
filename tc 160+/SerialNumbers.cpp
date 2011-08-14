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

int sum(const string &s) {
	int ret = 0;
	for (int i=0; i<(int)s.size(); ++i)
		if (isdigit(s[i]))
			ret += s[i]-'0';
	return ret;
}

bool my_less(const string &a, const string &b) {
	if (a.size() != b.size())
		return a.size() < b.size();
	if (sum(a) != sum(b))
		return sum(a) < sum(b);
	return a < b;
}
class SerialNumbers {
	public:
	vector <string> sortSerials(vector <string> v) {
		int n = v.size();
		for (int i=0; i<n; ++i)
			for (int j=i+1; j<n; ++j)
				if (my_less(v[j], v[i]))
					swap(v[i], v[j]);

		return v;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"ABCD","145C","A","A910","Z321"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"A", "ABCD", "Z321", "145C", "A910" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, sortSerials(Arg0)); }
	void test_case_1() { string Arr0[] = {"Z19", "Z20"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Z20", "Z19" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, sortSerials(Arg0)); }
	void test_case_2() { string Arr0[] = {"34H2BJS6N","PIM12MD7RCOLWW09","PYF1J14TF","FIPJOTEA5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"FIPJOTEA5", "PYF1J14TF", "34H2BJS6N", "PIM12MD7RCOLWW09" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, sortSerials(Arg0)); }
	void test_case_3() { string Arr0[] = {"ABCDE", "BCDEF", "ABCDA", "BAAAA", "ACAAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ABCDA", "ABCDE", "ACAAA", "BAAAA", "BCDEF" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, sortSerials(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SerialNumbers ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

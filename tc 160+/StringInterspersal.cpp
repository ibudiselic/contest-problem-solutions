#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool sw(const string &a, const string &b) {
    if (a.size() < b.size()) {
        return false;
    }
    for (int i=0; i<(int)b.size(); ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

class StringInterspersal {
	public:
	string minimum(vector <string> W) {
		string sol;
        while (W.size() > 0) {
            sort(W.begin(), W.end());
            int i = 1;
            while (i<(int)W.size() && sw(W[i], W[i-1])) {
                ++i;
            }
            --i;
            if (i != 0) {
                swap(W[0], W[i]);
            }
            sol += W[0][0];
            if (W[0].size() == 1) {
                W.erase(W.begin(), W.begin()+1);
            } else {
                W[0] = W[0].substr(1);
            }
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"DESIGN","ALGORITHM","MARATHON"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ADELGMAORARISIGNTHMTHON"; verify_case(0, Arg1, minimum(Arg0)); }
	void test_case_1() { string Arr0[] = {"TOMEK","PETR","ACRUSH","BURUNDUK","KRIJGERTJE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ABCKPERIJGERRTJETOMEKTRURUNDUKUSH"; verify_case(1, Arg1, minimum(Arg0)); }
	void test_case_2() { string Arr0[] = {"CCCA","CCCB","CCCD","CCCE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "CCCACCCBCCCCCCDE"; verify_case(2, Arg1, minimum(Arg0)); }
	void test_case_3() { string Arr0[] = {"BKSDSOPTDD","DDODEVNKL","XX","PODEEE","LQQWRT"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BDDKLODEPODEEEQQSDSOPTDDVNKLWRTXX"; verify_case(3, Arg1, minimum(Arg0)); }
	void test_case_4() { string Arr0[] = {"TOPCODER","BETFAIR","NSA","BT","LILLY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BBELILLNSATFAIRTOPCODERTY"; verify_case(4, Arg1, minimum(Arg0)); }
	void test_case_5() { string Arr0[] = {"QITHSQARQV","BYLHVGMLRY","LKMAQTJEAM","AQYICVNIKK","HKGZZFFEWC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ABHKGLKMAQIQQTHSQARQTJEAMVYICVNIKKYLHVGMLRYZZFFEWC"; verify_case(5, Arg1, minimum(Arg0)); }
	void test_case_6() { string Arr0[] = {"XHCYBTUQUW","EKBISADSSN","LOOISPOFAK","MIXBDHPJUQ","BNMNDHMOTC"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "BEKBILMINMNDHMOOIOSADSPOFAKSSNTCXBDHPJUQXHCYBTUQUW"; verify_case(6, Arg1, minimum(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    StringInterspersal ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

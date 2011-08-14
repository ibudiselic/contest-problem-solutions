#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int sqr(int x) {
    return x*x;
}
int lcp_length(const string &a, const string &b) {
    int i = 0;
    while (i<(int)a.size() && i<(int)b.size() && a[i]==b[i]) {
        ++i;
    }
    return i;
}
class YetAnotherHamiltonianPath {
	public:
	int leastCost(vector <string> label) {
        string start, end;
        start = label[0];
        end = label[1];
        int base = 0;
        for (int i=0; i<(int)label.size(); ++i) {
            base += (i<2 ? 1 : 2)*sqr(label[i].size());
        }
		sort(label.begin(), label.end());
        
        label.push_back(label[0]);
        for (int i=1; i<(int)label.size(); ++i) {
            base -= sqr(lcp_length(label[i-1], label[i]));
        }
        
        return base + sqr(lcp_length(start, end));
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"home", "school", "pub"} ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 70; verify_case(0, Arg1, leastCost(Arg0)); }
	void test_case_1() { string Arr0[] = {"school", "home", "pub", "stadium"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 167; verify_case(1, Arg1, leastCost(Arg0)); }
	void test_case_2() { string Arr0[] = {"abcd","aecgh","abef","aecd"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 91; verify_case(2, Arg1, leastCost(Arg0)); }
	void test_case_3() { string Arr0[] = {"canada", "cyprus", "croatia", "colombia", "chile", "china", "cameroon"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 509; verify_case(3, Arg1, leastCost(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    YetAnotherHamiltonianPath ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

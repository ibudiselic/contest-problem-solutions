#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int f(const string &a, char c) {
    return count(a.begin(), a.end(), c);
}
int calc(const string &a, const string &b) {
    int L = f(a, 'L') + f(b, 'L');
    int O = f(a, 'O') + f(b, 'O');
    int V = f(a, 'V') + f(b, 'V');
    int E = f(a, 'E') + f(b, 'E');
    return ((L+O)*(L+V)%100*(L+E)*(O+V)%100*(O+E)*(V+E)) % 100;
}
class LoveCalculator {
	public:
	string findBoy(string girl, vector <string> boys) {
		int best = -1;
        string sol(50, 'Z');
        
        for (int i=0; i<(int)boys.size(); ++i) {
            int t = calc(girl, boys[i]);
            if (t>best || t==best && boys[i]<sol) {
                best = t;
                sol = boys[i];
            }
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LOVE"; string Arr1[] = {"JACOB","FRANK","DANO"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "FRANK"; verify_case(0, Arg2, findBoy(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "JANE"; string Arr1[] = {"THOMAS","MICHAEL","INDY","LIU"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "INDY"; verify_case(1, Arg2, findBoy(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "LILLY"; string Arr1[] = {"PIERRE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "PIERRE"; verify_case(2, Arg2, findBoy(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "MERYLOV"; string Arr1[] = {"JOHN","DAVE","STEVE","JOHN","DAVE"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "DAVE"; verify_case(3, Arg2, findBoy(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "LLOL"; string Arr1[] = {"BVERON","CVERON","AVERON","DVERON"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "AVERON"; verify_case(4, Arg2, findBoy(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "VELYLEOCEVE"; string Arr1[] = {"YVXHOVE","LCOKO","OGWSJVEVEDLE","WGFVSJEL","VLOLUVCBLLQVESWHEEKC"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "VLOLUVCBLLQVESWHEEKC"; verify_case(5, Arg2, findBoy(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    LoveCalculator ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

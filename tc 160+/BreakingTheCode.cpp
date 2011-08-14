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

int ind(const string &s) {
    int x;
    sscanf(s.c_str(), "%d", &x);
    return x-1;
}

char buff[10];
string to_str(int x) {
    sprintf(buff, "%02d", x);
    return string(buff);
}
class BreakingTheCode {
	public:
	string decodingEncoding(string code, string message) {
        string sol;
		if (isdigit(message[0])) {
            for (int i=0; i<(int)message.size(); i+=2) {
                int p = ind(message.substr(i, 2));
                sol += code[p];
            }
        } else {
            for (int i=0; i<(int)message.size(); ++i) {
                int p = (int)code.find(message[i]) + 1;
                sol += to_str(p);
            }
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "abcdefghijklmnopqrstuvwxyz"; string Arg1 = "test"; string Arg2 = "20051920"; verify_case(0, Arg2, decodingEncoding(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "abcdefghijklmnopqrstuvwxyz"; string Arg1 = "20051920"; string Arg2 = "test"; verify_case(1, Arg2, decodingEncoding(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "qesdfvujrockgpthzymbnxawli"; string Arg1 = "mwiizkelza"; string Arg2 = "19242626171202251723"; verify_case(2, Arg2, decodingEncoding(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "faxmswrpnqdbygcthuvkojizle"; string Arg1 = "02170308060416192402"; string Arg2 = "ahxpwmtvza"; verify_case(3, Arg2, decodingEncoding(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    BreakingTheCode ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

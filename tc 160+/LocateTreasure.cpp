#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int f(int x) {
    return (x%9 ? x%9 : 9);
}

int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };
string to_str(int x) {
    ostringstream os;
    os << x;
    return os.str();
}
class LocateTreasure {
	public:
	string location(int K, int multi) {
        multi = f(multi);
        
        if (K >= 12) {
            K %= 12;
            if (K<3) {
                K += 12;
            }
        }
        
        int x = 0;
        int y = 0;
        int k = 1;
        int d = 0;
        while (K--) {
           x += k*dx[d];
           y += k*dy[d];
           d = (d+1) % 4;
           k = f(k*multi);
        }
        
        return to_str(x) + ' ' + to_str(y);
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 2; string Arg2 = "-6 4"; verify_case(0, Arg2, location(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 99; int Arg1 = 1; string Arg2 = "1 0"; verify_case(1, Arg2, location(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 9; string Arg2 = "9 1"; verify_case(2, Arg2, location(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    LocateTreasure ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

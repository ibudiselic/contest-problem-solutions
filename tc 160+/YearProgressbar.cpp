#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string mnthstr[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
int mnthday[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
bool isLeap(int y) {
	return (y%4==0 && (y%100!=0 || y%400==0));
}
class YearProgressbar {
	public:
	double percentage(string currentDate) {
	    int d, y, h, m;
        char M[50];
        sscanf(currentDate.c_str(), "%s %d, %d %d:%d", M, &d, &y, &h, &m);
        string s(M);
        const int total = (365 + isLeap(y))*24*60;

        int i = find(mnthstr, mnthstr+12, s) - mnthstr;
        int days = 0;
        for (int j=0; j<i; ++j) {
            days += mnthday[j];
        }
        if (i > 1) {
            days += isLeap(y);
        }
        days += d - 1;
        int mins = (days*24 + h)*60 + m;

        return double(mins)/total * 100.0;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "January 01, 2008 00:00"; double Arg1 = 0.0; verify_case(0, Arg1, percentage(Arg0)); }
	void test_case_1() { string Arg0 = "December 31, 2007 23:59"; double Arg1 = 99.99980974124807; verify_case(1, Arg1, percentage(Arg0)); }
	void test_case_2() { string Arg0 = "July 02, 2007 12:00"; double Arg1 = 50.0; verify_case(2, Arg1, percentage(Arg0)); }
	void test_case_3() { string Arg0 = "July 02, 2008 00:00"; double Arg1 = 50.0; verify_case(3, Arg1, percentage(Arg0)); }
	void test_case_4() { string Arg0 = "May 10, 1981 00:31"; double Arg1 = 35.348363774733635; verify_case(4, Arg1, percentage(Arg0)); }
	void test_case_5() { string Arg0 = "January 31, 1900 00:47"; double Arg1 = 8.228120243531203; verify_case(5, Arg1, percentage(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    YearProgressbar ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

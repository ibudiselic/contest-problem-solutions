#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

unsigned long long tdig = 10000000000LL;
unsigned long long M = 10000000000000LL;
string to_str(unsigned long long x) {
    ostringstream os;
    os << x;
    return os.str();
}

void mul(unsigned long long &D, long double &start, unsigned long long &end, bool &is_long, int x) {
    if (!is_long) {
        D *= x;
        if (D >= tdig) {
            start = log(D);
            end = D%M;
            is_long = true;
        }
    } else {
        start += log(x);
        end = (end*x) % M;
    }
}
class PrettyPrintingProduct {
	public:
	string prettyPrint(int A, int B) {
		if (B < 12) {
            unsigned long long x = 1;
            for (int i=A; i<=B; ++i) {
                x *= i;
            }
            int E = 0;
            while (x%10 == 0) {
                ++E;
                x /= 10;
            }
            return to_str(x) + " * 10^" + to_str(E);
        } else {
            int E = 0;
            unsigned long long D = 1;
            bool is_long = false;
            long double start = 0;
            unsigned long long end = 0;
            int twos = 0;
            int fives = 0;
            for (int i=A; i<=B; ++i) {
                int x = i;
                while (x%5 == 0) {
                    ++fives;
                    x /= 5;
                }
                while ((x&1) == 0) {
                    x >>= 1;
                    ++twos;
                }
                mul(D, start, end, is_long, x);
            }

            E = min(twos, fives);
            twos -= E;
            fives -= E;

            while (twos--) {
                mul(D, start, end, is_long, 2);
            }
            while (fives--) {
                mul(D, start, end, is_long, 5);
            }

            if (!is_long) {
                return to_str(D) + " * 10^" + to_str(E);
            } else {
                string t = to_str(end);
                if ((int)t.size() < 5) {
                    t = string(5-(int)t.size(), '0') + t;
                }
                start /= log(10.0);
                start -= floor(start);
                start = pow(10.0l, start) * 100000 + 1e-9;
                char buff[20];
                sprintf(buff, "%f", (double)start);

                return string(buff).substr(0, 5) + "..." + t.substr((int)t.size()-5) + " * 10^" + to_str(E);
            }
        }
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 10; string Arg2 = "36288 * 10^2"; verify_case(0, Arg2, prettyPrint(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 7; string Arg2 = "7 * 10^0"; verify_case(1, Arg2, prettyPrint(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 211; int Arg1 = 214; string Arg2 = "2038974024 * 10^0"; verify_case(2, Arg2, prettyPrint(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 411; int Arg1 = 414; string Arg2 = "28952...24024 * 10^0"; verify_case(3, Arg2, prettyPrint(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 412; int Arg1 = 415; string Arg2 = "2923450236 * 10^1"; verify_case(4, Arg2, prettyPrint(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 47; int Arg1 = 4700; string Arg2 = "14806...28928 * 10^1163"; verify_case(5, Arg2, prettyPrint(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 1; int Arg1 = 19; string Arg2 = "12164...08832 * 10^3"; verify_case(6, Arg2, prettyPrint(Arg0, Arg1)); }
	void test_case_7() { int Arg0 = 13; int Arg1 = 25; string Arg2 = "32382...26624 * 10^4"; verify_case(7, Arg2, prettyPrint(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    PrettyPrintingProduct ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

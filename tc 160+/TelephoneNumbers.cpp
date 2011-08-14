#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int SZ = 8388608;
int T[SZ];
const int M = 31;

inline int move_by(int x) {
    int a = x >> 5;
    int b = x & M;

    int t = T[a] >> b;
    int by = 0;
    while (t>0 && (t&1)) {
        ++by;
        t >>= 1;
    }

    if (by == 32-b) {
        while (1) {
            t = T[++a];
            int add = 0;
            while (t>0 && (t&1)) {
                ++add;
                t >>= 1;
            }
            by += add;
            if (add < 32) {
                break;
            }
        } 
    }

    return by;
}
inline int test(int x) {
    const int a = x >> 5;
    const int b = x & M;

    return (T[a]>>b) & 1;
}

inline void mark(int x) {
    const int a = x >> 5;
    const int b = x & M;

    T[a] |= (1 << b);
}

bool valid(int val) {
    int base = 1;
    int offset = 0;
    for (int i=6; i>=0; --i, offset+=4, base<<=4) {
        int x = (val>>offset) & 15;
        int nval = val - x*base;
        for (int y=0; y<16; ++y) {
            if (y != x) {
                if (test(nval + y*base)) {
                   return false;
                } 
            }
        }
    }

    return true;
}
string repr(int x) {
    char buff[20];
    sprintf(buff, "%07x", x);
    return string(buff);
}

class TelephoneNumbers {
	public:
	string kthNumber(int separation, int k) {
        memset(T, 0, sizeof T);
	    if (separation == 1) {
            return repr(k - 1);
        } else if (separation == 2) {
            int t = 0;
            int val = 0;
            while (t < k) {
                int mb = move_by(val);
                if (mb == 0) {
                    ++t;
                    if (t == k) {
                        return repr(val);
                    }
                    mark(val);
                    int base = 1;
                    int offset = 0;
                    for (int i=6; i>=0; --i, offset+=4, base<<=4) {
                        int x = (val>>offset) & 15;
                        int nval = val - x*base;
                        for (int y=0; y<16; ++y) {
                            if (y != x) {
                                mark(nval + y*base);
                            }
                        }
                    }
                    val = (val & ~15) + 16;
                } else {
                    val += mb;
                }
            } 
        } else {
            int t = 0;
            int val = 0;
            while (t < k) {
                int mb = move_by(val);
                if (mb == 0) {
                    if (!valid(val)) {
                        ++val;
                        continue;
                    }
                    ++t;
                    if (t == k) {
                        return repr(val);
                    }
                    mark(val);
                    int base = 1;
                    int offset = 0;
                    for (int i=6; i>=0; --i, offset+=4, base<<=4) {
                        int x = (val>>offset) & 15;
                        int nval = val - x*base;
                        for (int y=0; y<16; ++y) {
                            if (y != x) {
                                mark(nval + y*base);
                            }
                        }
                    }
                    val = (val & ~15) + 16;
                } else {
                    val += mb;
                }
            } 
        }
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 5; string Arg2 = "0000004"; verify_case(0, Arg2, kthNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 17; string Arg2 = "0000101"; verify_case(1, Arg2, kthNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 33; string Arg2 = "0002023"; verify_case(2, Arg2, kthNumber(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    TelephoneNumbers ___test; 
    ___test.run_test(-1); 
    ___test.kthNumber(3, 300000) ;
    } 
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int cnt[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 5 };
int taken[10];
long long up, down, num;
string N;

long long next(long long x) {
    ostringstream os;
    os << x;
    string str = os.str();
    str = string(N.size()-str.size(), '0') + str;

    if (str.size() == 1) {
        return x;
    }

    int p = (int)str.size() - 2;
    while (p>=0 && str[p]>=str[p+1]) {
        --p;
    }

    if (p < 0) {
        return x;
    }

    string res = str.substr(0, p) + str[p+1];
    string rem = str.substr(p, 1) + (p+2<(int)str.size() ? str.substr(p+2) : "");
    sort(rem.begin(), rem.end());

    res += rem;

    istringstream is(res);
    is >> x;
    return x;
}

void upd() {
    long long x = 0;
    bool any = false;
    vector<int> t(taken, taken+10);
    for (int i=0; i<(int)N.size(); ++i) {
        bool ok = false;
        for (int j=(any ? 0 : N[i]-'0'); j<10; ++j) {
            if (t[j] > 0) {
                any = any || (j > (N[i]-'0'));
                x = 10*x + j;
                --t[j];
                ok = true;
                break;
            }
        }
        if (!ok) {
            string s;
            for (int j=0; j<10; ++j) {
                s += string(t[j], '0' + j);
            }
            for (int j=0; j<(int)s.size(); ++j) {
                x = 10*x + s[s.size()-1-j]-'0';
            }
            break;
        }
    }

    bool stuck = false;
    while (x <= num) {
        long long y = next(x);
        if (y == x) {
            if (stuck) {
                break;
            }
            stuck = 1;
        }
        x = y;
    }
    if (x > num) {
        up = min(up, x);
    }

    x = 0;
    t.assign(taken, taken+10);
    for (int i=0; i<(int)N.size(); ++i) {
        for (int j=0; j<10; ++j) {
            if (t[j] > 0) {
                --t[j];
                x = 10*x + j;
                break;
            }
        }
    }
    if (x < num) {
        down = min(down, x);
    }
}

void go(int d, int n, int left) {
    if (n == 0) {
        if (left == 0) {
            upd();
        }
        return;
    }

    if (left == 0) {
        return;
    }

    if (d == 9) {
        if (n*cnt[9] == left) {
            taken[9] = n;
            upd();
            taken[9] = 0;
        }
        return;
    }

    go(d+1, n, left);
    for (int i=1; i<=n && i*cnt[d]<=left; ++i) {
        taken[d] = i;
        go(d+1, n-i, left-i*cnt[d]);
        taken[d] = 0;
    }
}

class DigitalCounter {
	public:
	long long nextEvent(string current) {
	    memset(taken, 0, sizeof taken);
        N = current;
        int sum = 0;
        int n = current.size();
        for (int i=0; i<n; ++i) {
            sum += cnt[current[i]-'0'];
        }

        const long long inf = 12345678901234567LL;
        up = inf;
        down = inf;
        istringstream is(current);
        is >> num;
        go(0, n, sum);

        cerr << up << ' ' << down << ' ' << num << '\n';
        if (up != inf) {
            return up - num;
        }
        long long p10 = 1;
        while (p10 <= num) {
            p10 *= 10;
        }

        if (down != inf) {
            return p10-num + down;
        }

        return p10;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "1"; long long Arg1 = 10LL; verify_case(0, Arg1, nextEvent(Arg0)); }
	void test_case_1() { string Arg0 = "3"; long long Arg1 = 2LL; verify_case(1, Arg1, nextEvent(Arg0)); }
	void test_case_2() { string Arg0 = "9"; long long Arg1 = 3LL; verify_case(2, Arg1, nextEvent(Arg0)); }
	void test_case_3() { string Arg0 = "99"; long long Arg1 = 5LL; verify_case(3, Arg1, nextEvent(Arg0)); }
	void test_case_4() { string Arg0 = "654371"; long long Arg1 = 43LL; verify_case(4, Arg1, nextEvent(Arg0)); }
	void test_case_5() { string Arg0 = "007"; long long Arg1 = 11LL; verify_case(5, Arg1, nextEvent(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    DigitalCounter ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

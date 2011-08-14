#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

long long my_abs(long long x) { return (x<0 ? -x : x); }
long long gcd(long long m, long long n) {
    return m==0 ? n : gcd(n%m, m);
}
long long lcm(long long m, long long n) {
    return m/gcd(m, n)*n;
}
void norm(pair<long long, long long> &p) {
    long long G = gcd(p.first, p.second);
    p.first /= G;
    p.second /= G;
}
long long gcd(const vector< pair<long long, long long> > &v) {
    long long G = v[0].second;
    for (int i=1; i<(int)v.size(); ++i) {
        G = gcd(G, v[i].second);
    }
    return G;
}
long long lcm(const vector< pair<long long, long long> > &v) {
    long long L = v[0].first;
    for (int i=1; i<(int)v.size(); ++i) {
        L = lcm(L, v[i].first);
    }
    return L;
}

vector<int> periods;
int t1, t2;

int bc(int x) {
    int ret = 0;
    while (x > 0) {
        x &= x - 1;
        ++ret;
    }

    return ret;
}
int get_ways(int i) {
    if (bc(i) <= 1) {
        return 0;
    }

    int first = -1;
    vector< pair<long long, long long> > v;
    for (int j=0; j<(int)periods.size(); ++j) {
        if (i & (1<<j)) {
            if (first == -1) {
                first = j;
            } else {
                v.push_back(make_pair(my_abs((long long)periods[j]*periods[first]), 2*my_abs((long long)periods[j]-periods[first])));
                norm(v.back());
            }
        }
    }

    long long L = lcm(v);
    long long G = gcd(v);
    long long D = gcd(L, G);
    L /= D;
    G /= D;

    return t2*G/L - t1*G/L + (t1*G%L == 0);
}

class KPlanetaryAlignment {
	public:
	int number(vector <int> periods, int k, int t1, int t2) {
        ::periods = periods;
        ::t1 = t1;
        ::t2 = t2;
		int n = periods.size();
        int sol = 0;
        vector<int> groups;
        for (int i=3; i<(1<<n); ++i) {
            if (bc(i) == k) {
                groups.push_back(i);
            }
        }

        int m = groups.size();
        for (int i=1; i<(1<<m); ++i) {
            int S = 0;
            for (int j=0; j<m; ++j) {
                if (i & (1<<j)) {
                    S |= groups[j];
                }
            }
            sol += (bc(i)&1 ? +1 : -1) * get_ways(S);
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {8,40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 0; int Arg3 = 20; int Arg4 = 5; verify_case(0, Arg4, number(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {8,24,40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 0; int Arg3 = 20; int Arg4 = 8; verify_case(1, Arg4, number(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {8,24,40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 0; int Arg3 = 100; int Arg4 = 4; verify_case(2, Arg4, number(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {-10,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 26; int Arg4 = 10; verify_case(3, Arg4, number(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {-1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 10000; int Arg3 = 50000; int Arg4 = 53333; verify_case(4, Arg4, number(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {-1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 0; int Arg3 = 50000; int Arg4 = 200001; verify_case(5, Arg4, number(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arr0[] = {-2,91,87,77,71}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 0; int Arg3 = 50000000; int Arg4 = 1471; verify_case(6, Arg4, number(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    KPlanetaryAlignment ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

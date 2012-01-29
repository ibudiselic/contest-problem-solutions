#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// could be made quite a bit faster, but this is fast enough (~1.7s on the slowest systest)

long long lim;
vector<long long> gen(long long a, long long b) {
    vector<long long> ret;
    while (a <= lim) {
        ret.push_back(a);
        long long tmp = a;
        a = b;
        b = a + tmp;
    }
    ret.push_back(a);
    ret.push_back(b);
    
    return ret;
}

vector< vector<long long> > low;
vector<long long> S;
int sec[50][50][50]; // second number in the sequence after S[i] so that S[j] is the k-th number in the sequence (0-based) with k>=2; -1 if impossible

// # of S[a..b> that match a number in v
int eval(int a, int b, vector<long long> v) {
    bool swapped = false;
    if (v[0] > v[1]) {
        swapped = true;
        swap(v[0], v[1]);
    }
    
    int ret = 0;
    int i = a;
    int j = 0;
    int first_second = 0;
    while (i<b && j<(int)v.size()) {
        if (S[i] == v[j]) {
            first_second += (j-1 <= 0);
            ++ret;
            ++i;
            ++j;
        } else if (S[i] < v[j]) {
            ++i;
        } else {
            ++j;
        }
    }
    
    if (swapped && first_second==2) {
        --ret; // must not reorder them when picking the subsequence...
    }
    return ret;
}

inline bool test(long long y, int pos, const vector<long long> &v) {
    return pos<(int)v.size() && v[pos]<=y;
}

// returns the largest second number (after x) in a Fibonacci sequence such that seq[pos] <= y
long long bs(long long x, long long y, int pos) {
    long long lo = 1;
    long long hi = 2;
    while (test(y, pos, gen(x, hi))) {
        hi *= 2;
    }
    while (lo < hi) {
        long long mid = lo + (hi-lo+1)/2;
        if (test(y, pos, gen(x, mid))) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

int go(int i, int j, int a, int b) {
    long long x = S[i];
    long long y = S[j];
    int best = eval(a, b, gen(x, y));
    if (x <= y) { // otherwise y must be the second number (that's the only way it can be smaller)
        int pos = 2;
        while (pos<(int)low[i].size() && y>=low[i][pos]) {
            long long second = sec[i][j][pos];
            if (second != -1) {
                const vector<long long> v = gen(x, second);
                if (pos<(int)v.size() && v[pos]==y) {
                    best = max(best, eval(a, b, v));
                }
            }
            ++pos;
        }
    }
    return best;
}

int calc(int a, int b) {
    if (b-a <= 2) {
        return b - a;
    }
    
    int best = 2;
    for (int i=a; i<b; ++i) {
        for (int j=a; j<b; ++j) {
            if (i == j) {
                continue;
            }
            best = max(best, go(i, j, a, b));
            best = max(best, go(j, i, a, b));
        }
    }
    
    return best;
}
class SubFibonacci {
	public:
	int maxElements(vector <int> S_) {
        sort(S_.begin(), S_.end());
        lim = S_.back();
        
        S.clear();
        copy(S_.begin(), S_.end(), back_inserter(S));
        
        low.clear();
        for (int i=0; i<(int)S.size(); ++i) {
            low.push_back(gen(S[i], 1));
        }

        memset(sec, 0xff, sizeof sec);
        for (int i=0; i<(int)S.size(); ++i) {
            for (int j=i+1; j<(int)S.size(); ++j) {
                const int x = S[i];
                const int y = S[j];
                int pos = 2;
                while (pos<(int)low[i].size() && y>=low[i][pos]) {
                    long long second = bs(S[i], S[j], pos);
                    const vector<long long> v = gen(x, second);
                    if (pos<(int)v.size() && v[pos]==y) {
                        sec[i][j][pos] = int(second);
                    }
                    ++pos;
                }
            }
        }
        
        int sol = 0;
        for (int i=0; i<=(int)S.size(); ++i) {
            sol = max(sol, calc(0, i) + calc(i, S.size()));
        }
        
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {8, 1, 20, 3, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, maxElements(Arg0)); }
	void test_case_1() { int Arr0[] = {19, 47, 50, 58, 77, 99}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, maxElements(Arg0)); }
	void test_case_2() { int Arr0[] = {512}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, maxElements(Arg0)); }
	void test_case_3() { int Arr0[] = {3, 5, 7, 10, 13, 15, 20, 90}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(3, Arg1, maxElements(Arg0)); }
	void test_case_4() { int Arr0[] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(4, Arg1, maxElements(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    SubFibonacci ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

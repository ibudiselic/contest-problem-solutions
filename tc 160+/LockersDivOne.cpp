#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

/*int go(int n, int step) {
    if (n == 1) {
        return 1;
    }
    int destroyed = (n-1)/step + 1;
    int next_res = go(n-destroyed, step+1);
    int next_res_block = (next_res-1)/(step-1);
    int rem = (next_res-1) % (step-1);
    return next_res_block*step + rem + 2;
}*/

class StatTree {
    public:
    StatTree(int limit); // accepts numbers [0, limit>
    int size() const { return cnt_elems; }
    void insert(int x, int times=1) { change_by(x, times); }
    void remove(int x, int times=1) { change_by(x, -times); }
    int rank_of(int x) const; // 0 based (at what rank can x be inserted - like lower_bound)
    int elem_at(int rank) const; // -1 if rank outside [0, cnt_elems>

    private:
    void change_by(int x, int by);

    int cnt_elems;
    int level_lim; // exclusive, levels [0, level_lim>
    vector< vector<int> > T;
};
    
StatTree::StatTree(int limit): cnt_elems(0), level_lim(0) {
    assert(limit > 0);
    int max_val = limit - 1;
    while (max_val > 0) {
        ++level_lim;
        T.push_back(vector<int>(max_val+1, 0));
        max_val >>= 1;
    }
    assert(T.size() == level_lim);
}
void StatTree::change_by(int x, int by) {
    cnt_elems += by;
    assert(cnt_elems >= 0);
    for (int i=0; i<level_lim; ++i) {
        T[i][x] += by;
        assert(T[i][x] >= 0);
        x >>= 1;
    }
}
int StatTree::elem_at(int rank) const {
    if (rank<0 || rank>=cnt_elems) {
        return -1;
    }
    int elem = 0;
    for (int i=level_lim-1; i>=0; --i) {
        elem <<= 1;
        if (rank >= T[i][elem]) {
            rank -= T[i][elem];
            ++elem;
        }
    }
    return elem;
}
int StatTree::rank_of(int x) const {
    if (elem_at(cnt_elems-1) < x) {
        return cnt_elems;
    }
    int lo = 0;
    int hi = cnt_elems-1;
    while (lo < hi) {
        int mid = lo + (hi-lo)/2;
        if (x <= elem_at(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

class LockersDivOne {
	public:
	int lastOpened(int N) {
	    //return go(N, 2);
        StatTree T(N);
        for (int i=0; i<N; ++i) {
            T.insert(i);
        }
        int step = 2;
        while (T.size() > 1) {
            int cnt = (T.size()-1)/step + 1;
            for (int i=(cnt-1)*step; i>=0; i-=step) {
                T.remove(T.elem_at(i));
            }
            ++step;
        }
        return T.elem_at(0) + 1;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 9; int Arg1 = 6; verify_case(0, Arg1, lastOpened(Arg0)); }
	void test_case_1() { int Arg0 = 42; int Arg1 = 42; verify_case(1, Arg1, lastOpened(Arg0)); }
	void test_case_2() { int Arg0 = 314; int Arg1 = 282; verify_case(2, Arg1, lastOpened(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    LockersDivOne ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

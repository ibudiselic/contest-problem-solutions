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

int bestval[1001][1001];
int bestval2[1001][1001];
struct jewel {
    int x, y, v;
    jewel(int x_, int y_, int v_): x(x_), y(y_), v(v_) {}
};
bool operator<(const jewel &a, const jewel &b) {
    if (a.y != b.y) {
        return a.y < b.y;
    } else if (a.x != b.x) {
        return a.x < b.x;
    } else {
        return a.v < b.v;
    }
}

class RunningMaxes { 
    // this structure uses an upper fenwick tree to support
    // O(logn) set_value for insering a value at a position and
    // get_max(from) that returns the maximal value from the interval [from, MAXVAL]
    // using only O(n) space
    public:
        RunningMaxes(int MAXVAL_): MAXVAL(MAXVAL_), M(MAXVAL+1, 0) {} // change 0 with -INF if necessary
        void set_value(int at, int x) {
            M[0] = max(M[0], x);
            while (at > 0) {
                M[at] = max(M[at], x);
                at -= at&-at;
            }
        }
        int get_max(int from) { // get_max(from, MAXVAL)
            if (from == 0) return M[0];
            int ret = 0; // replace with -INF if necessary
            while (from <= MAXVAL) {
                ret = max(ret, M[from]);
                from += from&-from;
            }
            return ret;
        }
    private:
        const int MAXVAL;
        vector<int> M;
};

class RunningMaxes2 { 
    // this structure uses a lower fenwick tree to support
    // O(logn) set_value for insering a value at a position and
    // get_max(to) that returns the maximal value from the interval [0, to]
    // using only O(n) space
    public:
        RunningMaxes2(int MAXVAL_): MAXVAL(MAXVAL_), M(MAXVAL+1, 0) {} // change 0 with -INF if necessary
        void set_value(int at, int x) {
            while (at <= MAXVAL) {
                M[at] = max(M[at], x);
                at |= at+1;
            }
        }
        int get_max(int to) { // get_max(0, to)
            int ret = 0; // replace with -INF if necessary
            while (to >= 0) {
                ret = max(ret, M[to]);
                to = (to & (to+1)) - 1;
            }
            return ret;
        }
    private:
        const int MAXVAL;
        vector<int> M;
};

class SegmentTree {
    // only works for positive values!
    public:
        SegmentTree(int MAXVAL_): MAXVAL(MAXVAL_), M(2*(MAXVAL+1), 0) { init(0, 0, MAXVAL); } 
        void set_value(int at, int x) { set_value(0, 0, MAXVAL, at, x); }
        int get_max(int a, int b) { return get_max(0, 0, MAXVAL, a, b); }
    private:
        int init(int node, int l, int r) {
            while (node >= (int)M.size()) {
                M.push_back(0);
            }
            if (l == r) {
                return (M[node] = 0); // change with -INF if necessary or some A[l] for an array with inital values
            } else {
                int mid = l + (r-l)/2;
                return (M[node] = max(init(2*node + 1, l, mid), init(2*node + 2, mid+1, r)));
            }
        }
        int set_value(int node, int l, int r, int at, int x) {
            if (at<l || r<at) {
                return M[node];
            }
            if (l == r) {
                assert(l == at);
                return (M[node] = max(M[node], x));
            } else {
                int mid = l + (r-l)/2;
                // don't need to check the old value since set_value will 
                // properly recalculate the max for the whole interval
                return (M[node] = max(set_value(2*node + 1, l, mid, at, x),
                                      set_value(2*node + 2, mid+1, r, at, x)));
            }
        }
        int get_max(int node, int l, int r, int a, int b) {
            if (a>r || b<l) {
                return -1;
            }
            a = max(a, l);
            b = min(b, r);
            if (a==l && b==r) {
                return M[node];
            } else {
                int mid = l + (r-l)/2;
                return max(get_max(2*node + 1, l, mid, a, b),
                           get_max(2*node + 2, mid+1, r, a, b));
            }
        }

        const int MAXVAL;
        vector<int> M;
};

class FoxSearchingRuins {
	public:
	long long theMinTime(int W, int H, int n, int LR, int goalValue, int timeX, int timeY, vector <int> seeds) {
        vector<jewel> J;
        J.reserve(n);
        J.push_back(jewel(((long long)seeds[1]*seeds[0] + seeds[2]) % W,
                          ((long long)seeds[4]*seeds[3] + seeds[5]) % H,
                          ((long long)seeds[7]*seeds[6] + seeds[8]) % seeds[9]));
        for (int i=1; i<n; ++i) {
            J.push_back(jewel(((long long)seeds[1]*J.back().x + seeds[2]) % W,
                              ((long long)seeds[4]*J.back().y + seeds[5]) % H,
                              ((long long)seeds[7]*J.back().v + seeds[8]) % seeds[9]));
        }
        
        sort(J.begin(), J.end());
        for (int i=0; i<n-1; ++i) {
            int j = i+1;
            while (j<n && J[i].x==J[j].x && J[i].y==J[j].y) {
                J[i].v += J[j].v;
                J[j].y = H;
                ++j;
            }
            i = j - 1;
        }
        sort(J.begin(), J.end());
        while (J.back().y == H) {
            --n;
            J.pop_back();
        }
        
        vector<int> ys;
        for (int i=0; i<n; ++i) {
            if (ys.size()==0 || J[i].y!=ys.back()) {
                ys.push_back(J[i].y);
            }
        }
        
        /* uncomment this for RuningMaxes with an upper fenwick tree
        vector<RunningMaxes> left(W+LR, RunningMaxes(W-1));
        vector<RunningMaxes> right(W+LR, RunningMaxes(W-1));
        */
        
        /* uncomment this for RunningMaxes2 with a lower fenwick tree
        vector<RunningMaxes2> left(W+LR, RunningMaxes2(W-1));
        vector<RunningMaxes2> right(W+LR, RunningMaxes2(W-1));
        */
        
        vector<SegmentTree> left(W+LR, SegmentTree(W-1));
        vector<SegmentTree> right(W+LR, SegmentTree(W-1));

        long long sol = -1;
        for (int i=0; i<(int)ys.size(); ++i) {
            const int Y = ys[i];
            vector<int> xs, vals;
            for (int j=0; j<n; ++j) {
                if (J[j].y == Y) {
                    while (j<n && J[j].y==Y) {
                        if (xs.size() > 0) {
                            assert(xs.back() < J[j].x);
                        }
                        xs.push_back(J[j].x);
                        vals.push_back(J[j].v);
                        ++j;
                    }
                    break;
                }
            }
            
            /* this uses RunningMaxes with an upper fenwick tree
            
            for (int j=0; j<(int)xs.size(); ++j) {
                for (int lr=0; lr<=LR; ++lr) { // -> amount of LR moves used thus far
                    bestval[j][lr] = bestval2[j][lr] = vals[j] // -> this is the "entry" value to this row (motion within the row is handled later)
                        + max(left[xs[j]+LR-lr].get_max(W-1-xs[j]), // -> the columns further left must have spent less lr so the difference x-lr is constant
                                                                    //    however, since that could be negative, we add LR to it to make it nonegative
                                                                    // -> also, since we are using an upper fenwick tree for a segment tree, only get_max(from, MAXVAL)
                                                                    //    queries are supported (MAXVAL is W-1) - therefore, the values are reversed because we need
                                                                    //    queries get_max(0, to)... note also that a lower fenwick tree would work nicely for this, but
                                                                    //    requires a separate implementation
                              right[xs[j]+lr].get_max(xs[j])); // -> the columns further right must have spent less lr so the sum x+lr is constant
                                                               // -> also, when using an upper fenwick tree for a segment tree, only get_max(from, MAXVAL)
                                                               // queries are supported (MAXVAL here is W-1)
                }
            }
            // now try moving left/right... it is always optimal to do a single sweep left or right
            // this is because we can alwasy not take jewels moving right and then sweep to the left, or vice versa...
            for (int j=1; j<(int)xs.size(); ++j) { // sweep right
                for (int lr=xs[j]-xs[j-1]; lr<=LR; ++lr) {
                    bestval[j][lr] = max(bestval[j][lr], vals[j] + bestval[j-1][lr-(xs[j]-xs[j-1])]);
                }
            }
            for (int j=(int)xs.size()-2; j>=0; --j) { // sweep left
                for (int lr=xs[j+1]-xs[j]; lr<=LR; ++lr) {
                    bestval2[j][lr] = max(bestval2[j][lr], vals[j] + bestval2[j+1][lr-(xs[j+1]-xs[j])]);
                }
            }
            
            for (int j=0; j<(int)xs.size(); ++j) {
                for (int lr=0; lr<=LR; ++lr) {
                    int best = max(bestval[j][lr], bestval2[j][lr]);
                    if (best >= goalValue) {
                        long long t = (long long)Y*timeY + (long long)lr*timeX;
                        if (sol==-1 || t<sol) {
                            sol = t;
                        }
                    }
                    left[xs[j]+LR-lr].set_value(W-1-xs[j], best);
                    right[xs[j]+lr].set_value(xs[j], best);
                }
            } */
            
            /* this uses running maxes with a lower fenwick tree.
            for (int j=0; j<(int)xs.size(); ++j) {
                for (int lr=0; lr<=LR; ++lr) {
                    bestval[j][lr] = bestval2[j][lr] = vals[j]
                        + max(left[xs[j]+LR-lr].get_max(xs[j]), // since this uses a lower fenwick tree, it supports get_max(0, to) queries
                                                                // and that is exactly what is needed for the left hand side
                              right[xs[j]+lr].get_max(W-1-xs[j])); // similarly to the previous solution using RunningMaxes with an upper fenwick tree,
                                                                   // we will reverse the values in 'right' trees so that we can use the get_max call
                                                                   // to simulate (from, MAXVAL) queries
                }
            }
            // this part is the same
            for (int j=1; j<(int)xs.size(); ++j) {
                for (int lr=xs[j]-xs[j-1]; lr<=LR; ++lr) {
                    bestval[j][lr] = max(bestval[j][lr], vals[j] + bestval[j-1][lr-(xs[j]-xs[j-1])]);
                }
            }
            for (int j=(int)xs.size()-2; j>=0; --j) {
                for (int lr=xs[j+1]-xs[j]; lr<=LR; ++lr) {
                    bestval2[j][lr] = max(bestval2[j][lr], vals[j] + bestval2[j+1][lr-(xs[j+1]-xs[j])]);
                }
            }
            for (int j=0; j<(int)xs.size(); ++j) {
                for (int lr=0; lr<=LR; ++lr) {
                    int best = max(bestval[j][lr], bestval2[j][lr]);
                    if (best >= goalValue) {
                        long long t = (long long)Y*timeY + (long long)lr*timeX;
                        if (sol==-1 || t<sol) {
                            sol = t;
                        }
                    }
                    // this is reversed from the previous case... here we are reversing the 'right' trees since we are using a lower fenwick tree
                    left[xs[j]+LR-lr].set_value(xs[j], best);
                    right[xs[j]+lr].set_value(W-1-xs[j], best);
                }
            } */
            
            // this is by far the slowest solution... worst case is about 1.99 secs (or above)
            for (int j=0; j<(int)xs.size(); ++j) {
                for (int lr=0; lr<=LR; ++lr) {
                    bestval[j][lr] = bestval2[j][lr] = vals[j] + max(left[xs[j]+LR-lr].get_max(0, xs[j]), right[xs[j]+lr].get_max(xs[j], W-1));
                }
            }
            for (int j=1; j<(int)xs.size(); ++j) {
                for (int lr=xs[j]-xs[j-1]; lr<=LR; ++lr) {
                    bestval[j][lr] = max(bestval[j][lr], vals[j] + bestval[j-1][lr-(xs[j]-xs[j-1])]);
                }
            }
            for (int j=(int)xs.size()-2; j>=0; --j) {
                for (int lr=xs[j+1]-xs[j]; lr<=LR; ++lr) {
                    bestval2[j][lr] = max(bestval2[j][lr], vals[j] + bestval2[j+1][lr-(xs[j+1]-xs[j])]);
                }
            }
            for (int j=0; j<(int)xs.size(); ++j) {
                for (int lr=0; lr<=LR; ++lr) {
                    int best = max(bestval[j][lr], bestval2[j][lr]);
                    if (best >= goalValue) {
                        long long t = (long long)Y*timeY + (long long)lr*timeX;
                        if (sol==-1 || t<sol) {
                            sol = t;
                        }
                    }
                    left[xs[j]+LR-lr].set_value(xs[j], best);
                    right[xs[j]+lr].set_value(xs[j], best);
                }
            }
        }
        
        return sol;
	}

        /*
    int L[1000], R[1000];
        O(n^5) ili tako nesto... jako sporo, ali tocno
           
        memset(L, 0xff, sizeof L);
        memset(R, 0xff, sizeof R);
        for (int i=0; i<n; ++i) {
            if (i>0 && J[i-1].y==J[i].y) {
                L[i] = i-1;
            }
            if (i<n-1 && J[i].y==J[i+1].y) {
                R[i] = i+1;
            }
        }
        
        long long sol = -1LL;
        memset(bestval, 0xff, sizeof bestval);
        for (int i=0; i<n; ++i) {
            bestval[i][LR] = J[i].v;
            for (int j=0; J[j].y<J[i].y; ++j) {
                const int dlr = abs(J[j].x - J[i].x);
                for (int lr=dlr; lr<=LR; ++lr) {
                    if (bestval[j][lr] == -1) {
                        continue;
                    }
                    int l = i;
                    int val_l = 0;
                    do {
                        val_l += J[l].v;
                        int r = i;
                        int val_r = 0;
                        do {
                            if (r != i) {
                                val_r += J[r].v;
                            }
                            int lr_cost;
                            lr_cost = abs(J[j].x - J[l].x) + abs(J[r].x - J[l].x) + abs(J[r].x - J[i].x);
                            if (lr_cost <= lr) {
                                bestval[i][lr-lr_cost] = max(bestval[i][lr-lr_cost], bestval[j][lr] + val_l + val_r);
                            }
                            lr_cost = abs(J[j].x - J[r].x) + abs(J[r].x - J[l].x) + abs(J[l].x - J[i].x);
                            if (lr_cost <= lr) {
                                bestval[i][lr-lr_cost] = max(bestval[i][lr-lr_cost], bestval[j][lr] + val_l + val_r);
                            }

                            r = R[r];
                        } while (r != -1);
                        l = L[l];
                    } while (l != -1);
                }
            }
            for (int lr=0; lr<=LR; ++lr) {
                long long t = (long long)J[i].y*timeY + (long long)(LR-lr)*timeX;
                if (bestval[i][lr] >= goalValue) {
                    if (sol==-1 || sol>t) {
                        sol = t;
                    }
                }
            }
        }*/






   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 8; int Arg2 = 5; int Arg3 = 7; int Arg4 = 10; int Arg5 = 3; int Arg6 = 1; int Arr7[] = {979, 777, 878, 646, 441, 545, 789, 896, 987, 10}; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); long long Arg8 = 5LL; verify_case(0, Arg8, theMinTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_1() { int Arg0 = 7; int Arg1 = 8; int Arg2 = 10; int Arg3 = 3; int Arg4 = 10; int Arg5 = 3; int Arg6 = 10; int Arr7[] = {0, 1, 1, 0, 1, 3, 1011, 3033, 2022, 10}; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); long long Arg8 = 29LL; verify_case(1, Arg8, theMinTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 8; int Arg2 = 10; int Arg3 = 3; int Arg4 = 14; int Arg5 = 3; int Arg6 = 10; int Arr7[] = {0, 1, 1, 0, 1, 3, 1011, 3033, 2022, 10}; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); long long Arg8 = 59LL; verify_case(2, Arg8, theMinTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 8; int Arg2 = 10; int Arg3 = 4; int Arg4 = 14; int Arg5 = 3; int Arg6 = 10; int Arr7[] = {0, 1, 1, 0, 1, 3, 1011, 3033, 2022, 10}; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); long long Arg8 = 42LL; verify_case(3, Arg8, theMinTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_4() { int Arg0 = 497; int Arg1 = 503; int Arg2 = 989; int Arg3 = 647; int Arg4 = 100000; int Arg5 = 13; int Arg6 = 14; int Arr7[] = {7613497, 5316789, 1334537, 2217889, 6349551, 978463, 1234567, 2345678, 3456789, 1000}; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); long long Arg8 = -1LL; verify_case(4, Arg8, theMinTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }
	void test_case_5() { int Arg0 = 1000; int Arg1 = 749613275; int Arg2 = 1000; int Arg3 = 1000; int Arg4 = 7500000; int Arg5 = 97; int Arg6 = 6; int Arr7[] = {224284427, 617001937, 294074399, 606566321, 202762619, 419798101, 200613401, 640663967, 417565817, 170000}; vector <int> Arg7(Arr7, Arr7 + (sizeof(Arr7) / sizeof(Arr7[0]))); long long Arg8 = 3780225876LL; verify_case(5, Arg8, theMinTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    FoxSearchingRuins ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

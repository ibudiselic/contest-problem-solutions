#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>
#include <ctime>

using namespace std;

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

int start_time_;
void init_time() {
    start_time_ = clock();
}
const int CLOCK_LIMIT = 1.8 * CLOCKS_PER_SEC;
bool timeout() {
    return clock()-start_time_ > CLOCK_LIMIT;
}
class Sheep {
	public:
	int minCapacity(int numSheep, int maxRuns, vector <string> part1, vector <string> part2, vector <string> part3, vector <string> part4) {
        init_time();
		string s = accumulate(part1.begin(), part1.end(), string()) + accumulate(part2.begin(), part2.end(), string()) +
                   accumulate(part3.begin(), part3.end(), string()) + accumulate(part4.begin(), part4.end(), string());
        istringstream is(s);
        int x;
        vector<int> v;
        int lo = 0;
        int hi = 0;
        StatTree S(2001);
        while (is >> x) {
            v.push_back(x);
            S.insert(x);
            hi += x;
            lo = max(lo, x);
        }
        
        while (lo < hi) {
            int mid = lo + (hi-lo)/2;
            StatTree T = S;
            int cnt = 0;
            bool ok = true;
            while (T.size() > 0) {
                if (++cnt > maxRuns) {
                    ok = false;
                    break;
                }
                int w = mid;
                while (true) {
                    int r = T.rank_of(w);
                    int x = T.elem_at(r);
                    if (x == w) {
                        T.remove(x);
                        break;
                    } else if (r == 0) {
                        break;
                    } else {
                        x = T.elem_at(r-1);
                        w -= x;
                        T.remove(x);
                    }
                }
            }
            
            if (ok) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        
        int sol = lo;
        while (lo>0 && !timeout()) {
            StatTree T = S;
            int cnt = 0;
            bool ok = true;
            while (T.size() > 0) {
                if (++cnt > maxRuns) {
                    ok = false;
                    break;
                }
                int w = lo;
                while (true) {
                    int r = T.rank_of(w);
                    int x = T.elem_at(r);
                    if (x == w) {
                        T.remove(x);
                        break;
                    } else if (r == 0) {
                        break;
                    } else {
                        x = T.elem_at(r-1);
                        w -= x;
                        T.remove(x);
                    }
                }
            }
            if (ok) {
                sol = lo;
            }
            --lo;
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 2; string Arr2[] = { "26 7 10 30 5 4" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = { }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = { }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 42; verify_case(0, Arg6, minCapacity(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 2; string Arr2[] = { "4 8 15 16 23 42" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = { }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = { }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 54; verify_case(1, Arg6, minCapacity(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 4; string Arr2[] = { "666 42 7 13 400 511 600 200 202 111 313 94 280", " 72 42" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = { }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = { }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 896; verify_case(2, Arg6, minCapacity(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { int Arg0 = 7; int Arg1 = 6; string Arr2[] = { "200 2", "01 202 203" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { " 204 " }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = { }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = { "205", " ", "206" }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 401; verify_case(3, Arg6, minCapacity(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { int Arg0 = 200; int Arg1 = 20; string Arr2[] = { "42 468 335 501 1170 1725 1479 1359 963 465 1706",
  " 146 1282 828 1962 492 996 1943 828 1437 392 605",
  " 1903 154 293 383 1422 717 1719 1896 1448 1727",
  " 772 1539 1870 1913 1668 300 1036 1895 704 1812",
  " 1323 334 1674 665 1142 1712 254 869 1548 1645",
  " 663 758 38 860 724 1742 1530 779 317 1036 191",
  " 1843 289 107 1041 943 1265 649 1447 1806 1891",
  " 730 371 1351 1007 1102 394 1549 1630 624 85 1955",
  " 757 1841 967 1377 1932 309 945 440 627 1324 1538",
  " 1539 119 83 930 542 834 1116 640 1659 705 1931",
  " 1978 307 1674 387 1022 746 925 1073 271 1830 778",
  " 1574 1098 513 1987 1291 1162 637 356 768 1656",
  " 1575 32 53 1351 1151 942 1725 1967 1431 1108 192",
  " 8 1338 1458 288 1754 384 946 910 210 1759 222",
  " 589 423 947 1507 1031 414 1169 901 592 763 1656",
  " 1411 360 1625 538 1549 484 1596 42 1603 351 292",
  " 837 1375 1021 597 22 1349 1200 1669 485 282 735",
  " 54 2000 419 1939 901 1789 128 468 1729 894 649",
  " 484 1808 422 311 618 814 1515" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = { }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = { }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); string Arr5[] = { }; vector <string> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arg6 = 9986; verify_case(4, Arg6, minCapacity(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Sheep ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

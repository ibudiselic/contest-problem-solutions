#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
vector<string> cutUp(const string &s, const string &delim=" ") {
	int lastPos = 0, pos = 0;
	vector<string> ret;

	while (pos+delim.size() <= s.size()) {
		if (s.substr(pos, delim.size()) == delim) {
			ret.push_back(s.substr(lastPos, pos-lastPos));

			pos += (int)delim.size()-1;
			lastPos = pos+1;
		}
		++pos;
	}

	if (lastPos < (int)s.size())
		ret.push_back(s.substr(lastPos));

	return ret;
}
struct line {
    int common, l, r;
    line(int common_, int l_, int r_): common(common_), l(l_), r(r_) {}
};
bool operator<(const line &a, const line &b) {
    if (a.common != b.common) {
        return a.common < b.common;
    } else if (a.l != b.l) {
        return a.l < b.l;
    } else {
        return a.r < b.r;
    }
}
void parse(const vector<string> &A, vector<line> &H, vector<line> &V) {
    for (int i=0; i<(int)A.size(); ++i) {
        vector<string> t = cutUp(A[i], ",");
        for (int j=0; j<(int)t.size(); ++j) {
            istringstream is(t[j]);
            int x1, y1, x2, y2;
            is >> x1 >> y1 >> x2 >> y2;
            if (x1 == x2) {
                V.push_back(line(x1, y1, y2));
            } else {
                assert(y1 == y2);
                H.push_back(line(y1, x1, x2));
            }
        }
    }
}
int len(const vector<line> &A) {
    int ret = 0;
    for (int i=0; i<(int)A.size(); ++i) {
        ret += A[i].r - A[i].l;
    }
    return ret;
}
int calc_overlap(const vector<line> &A, const vector<line> &B, int d1, int d2) {
    int i = 0;
    int j = 0;
    int ret = 0;
    while (i<(int)A.size() && j<(int)B.size()) {
        if (A[i].common < B[j].common+d1) {
            ++i;
        } else if (A[i].common > B[j].common+d1) {
            ++j;
        } else {
            while (j<(int)B.size() && A[i].common==B[j].common+d1 && B[j].l+d2<=A[i].l) {
                ret += max(0, min(A[i].r, B[j].r+d2)-A[i].l);
                ++j;
            }
            while (j<(int)B.size() && A[i].common==B[j].common+d1 && B[j].l+d2<=A[i].r) {
                ret += min(A[i].r, B[j].r+d2) - B[j].l - d2;
                ++j;
            }
            ++i;
            if (j > 0) {
                --j;
            }
        }
    }
    return ret;
}
int calc_overlap(const vector<line> &H1, const vector<line> &V1, const vector<line> &H2, const vector<line> &V2, int dx, int dy) {
    return calc_overlap(H1, H2, dy, dx) + calc_overlap(V1, V2, dx, dy);
}
bool done[180][180];
class Hieroglyphs {
	public:
	int minimumVisible(vector <string> hier1, vector <string> hier2) {
	    vector<line> H1, V1, H2, V2;
        parse(hier1, H1, V1);
        parse(hier2, H2, V2);
        sort(H1.begin(), H1.end());
        sort(H2.begin(), H2.end());
        sort(V1.begin(), V1.end());
        sort(V2.begin(), V2.end());
        
        int total = len(H1) + len(V1) + len(H2) + len(V2);
        int sol = total;
        
        const int offset = 80;
        memset(done, 0, sizeof done);
        for (int i=0; i<(int)H1.size(); ++i) {
            for (int j=0; j<(int)H2.size(); ++j) {
                int dy = H1[i].common - H2[j].common;
                int dx0 = H1[i].l - H2[j].l;
                int lim = H1[i].r - H1[i].l;
                assert(lim > 0);
                for (int delta=0; delta<lim; ++delta) {
                    if (!done[dx0+delta+offset][dy+offset]) {
                        done[dx0+delta+offset][dy+offset] = 1;
                        const int overlap = calc_overlap(H1, V1, H2, V2, dx0+delta, dy);
                        assert(overlap > 0);
                        sol = min(sol, total-overlap);
                    }
                }
            }
        }
        
        for (int i=0; i<(int)V1.size(); ++i) {
            for (int j=0; j<(int)V2.size(); ++j) {
                int dx = V1[i].common - V2[j].common;
                int dy0 = V1[i].l - V2[j].l;
                int lim = V1[i].r - V1[i].l;
                assert(lim > 0);
                for (int delta=0; delta<lim; ++delta) {
                    if (!done[dx+offset][dy0+delta+offset]) {
                        done[dx+offset][dy0+delta+offset] = 1;
                        const int overlap = calc_overlap(H1, V1, H2, V2, dx, dy0+delta);
                        assert(overlap > 0);
                        sol = min(sol, total-overlap);
                    }
                }
            }
        }
        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0 0 10 0,10 0 10 3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 1 10 1","5 1 5 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 16; verify_case(0, Arg2, minimumVisible(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"1 1 1 5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"3 2 5 2"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(1, Arg2, minimumVisible(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"0 2 6 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"5 1 6 1,8 1 9 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(2, Arg2, minimumVisible(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"10 20 10 30,15 20 15 30","10 20 15 20,0 30 30 30"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0 5 0 15,5 5 5 25","0 5 5 5,0 15 5 15"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 65; verify_case(3, Arg2, minimumVisible(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"10 10 10 20,10 30 10 40","10 10 20 10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"10 0 10 20,10 27 10 35","10 0 20 0"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 45; verify_case(4, Arg2, minimumVisible(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    Hieroglyphs ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

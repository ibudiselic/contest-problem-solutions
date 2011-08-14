#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

struct Point {
    long long x, y;
    Point(long long x_, long long y_): x(x_), y(y_) {}
    string to_str() const { ostringstream os; os << '(' << x << ", " << y << ')'; return os.str(); }
};
bool operator<(const Point &a, const Point &b) {
    if (a.x != b.x) {
        return a.x < b.x;
    } else {
        return a.y < b.y;
    }
}
bool operator!=(const Point &a, const Point &b) {
    return a<b || b<a;
}

struct Line {
    Point a, b;
    Line(const Point &a_, const Point &b_): a(a_), b(b_) { if (b < a) { swap(a, b); } }
    string to_str() const { return a.to_str() + " -> " + b.to_str(); }
};
bool operator<(const Line &u, const Line &v) {
    if (u.a != v.a) {
        return u.a < v.a;
    } else {
        return u.b < v.b;
    }
}

class WifiPlanet {
	public:
	long long routersNeeded(vector <int> x, vector <int> y, long long denom) {
		vector<Point> v;
        int n = x.size();
        for (int i=0; i<n; ++i) {
            v.push_back(Point(x[i], y[i]));
        }
        vector<Line> l;
        map<int, vector<Line> > xstart, xend, ystart, yend;
        for (int i=1; i<=n; ++i) {
            if (v[i-1].x != v[i%n].x) {
                l.push_back(Line(v[i-1], v[i%n]));
                xstart[l.back().a.x].push_back(l.back());
                xend[l.back().b.x].push_back(l.back());
                ystart[l.back().a.y].push_back(l.back());
                yend[l.back().b.y].push_back(l.back());
            }
        }
        
        long long sol = 0;
        sort(x.begin(), x.end());
        x.erase(unique(x.begin(), x.end()), x.end());
        n = x.size();
        
        vector<Line> active;
        {
        const vector<Line> &t = xstart[x[0]];
        for (int i=0; i<(int)t.size(); ++i) {
            active.push_back(t[i]);
        }
        }
        
        for (int i=0; i<(int)l.size(); ++i) {
            cerr << l[i].to_str() << '\n';
        }
        cerr << '\n';
        long long left = (x[0] + denom - 1) / denom;
        long long right;
        for (int i=1; i<n; ++i) {
            right = x[i] / denom;
            // upd area
            sort(active.begin(), active.end());
            cerr << x[i-1] << ' ' << x[i] << " | " << left << ' ' << right << ' ' << active.size() << '\n';
            for (int j=0; j<(int)active.size(); ++j) {
                cerr << active[j].to_str() << '\n';
            }
            cerr << '\n';
            assert(active.size() % 2 == 0);
            for (int j=1; j<(int)active.size(); j+=2) {
                sol += (right-left+1) * (under(left, right, active[j]) - under(left, right, active[j-1]));
            }
            // upd active set
            vector<Line> next(xstart[x[i]]);
            for (int j=0; j<(int)active.size(); ++j) {
                if (active[j].b.x != x[i]) {
                    assert(active[j].b.x > x[i]);
                    next.push_back(active[j]);
                }
            }
            left = right;
            active.swap(next);
        }

        return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,7,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,3,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; long long Arg3 = 2LL; verify_case(0, Arg3, routersNeeded(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {3,3,4,4,5,6,10,10,11,11,10,10,9,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,2,6,3,8,8,9,9,3,3,2,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; long long Arg3 = 4LL; verify_case(1, Arg3, routersNeeded(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {50,1000050,1000049}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,1000002,1000003}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; long long Arg3 = 0LL; verify_case(2, Arg3, routersNeeded(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {32,32,64,8,15,1000,999}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,10,10,48,48,47,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 16; long long Arg3 = 120LL; verify_case(3, Arg3, routersNeeded(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {1,1000000000,1000000000,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,1000000000,1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; long long Arg3 = 111111110888888889LL; verify_case(4, Arg3, routersNeeded(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    WifiPlanet ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

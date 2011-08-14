#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

template<class T> vector<T> tokenize(string s, const string &delim=" ") {
  vector<T> ret;
  string::size_type i=0;
  string::size_type len = delim.length();
  if (delim != " ")
    while ((i=s.find(delim)) != string::npos)
      s.replace(i, len, " ");

  istringstream is(s);
  T val;
  while (is >> val)
    ret.push_back(val);
  return ret;
}

struct Point {
	int x, y;
	bool operator==(const Point &a) const {
		return x==a.x && y==a.y;
	}
	bool operator!=(const Point &a) const {
		return !(this->operator==(a));
	}
};

vector<Point> poly_line(const string &s) {
	vector<string> p = tokenize<string>(s, "-");
	vector<Point> ret;
	for (int i=0; i<(int)p.size(); ++i) {
		int x, y;
		sscanf(p[i].c_str(), "%d,%d", &x, &y);
		ret.push_back((Point) {x, y});
	}

	return ret;
}

int N;
vector< vector<bool> > G;
vector<int> C;
void dfs(int x, int comp) {
	C[x] = comp;
	for (int i=0; i<N; ++i) {
		if (G[x][i] && C[i]==-1) {
			dfs(i, comp);
		}
	}
}
inline int sgn0(long long t) {
	return (t==0 ? 0 : (t>0 ? 1 : -1));
}
inline int ccw(long long x1, long long y1, long long x2, long long y2) {
	return sgn0(x1*y2 - y1*x2);
}
inline int ccw(const Point &c, const Point &a, const Point &b) {
	return ccw(b.x-a.x, b.y-a.y, c.x-a.x, c.y-a.y);
}
bool is_on_line(const Point &p, const Point &a, const Point &b) {
	int x = min(a.x, b.x);
	int X = max(a.x, b.x);
	int y = min(a.y, b.y);
	int Y = max(a.y, b.y);

	return (x<=p.x && p.x<=X && y<=p.y && p.y<=Y) && ccw(p, a, b)==0;
}
bool is_on(const Point &p, const vector<Point> &v) {
	for (int i=0; i<(int)v.size(); ++i) {
		if (v[i] == p) {
			return true;
		}
	}
	for (int i=1; i<(int)v.size(); ++i) {
		if (v[i] != v[i-1]) {
			if (is_on_line(p, v[i-1], v[i])) {
				return true;
			}
		}
	}
	return false;
}
inline bool clean_intersects(const Point &a, const Point &b, const Point &c, const Point &d) {
	return ccw(c, a, b)*ccw(d, a, b)==-1 && ccw(a, c, d)*ccw(b, c, d)==-1;
}
bool has_common_point(const vector<Point> &a, const vector<Point> &b) {
	for (int i=0; i<(int)a.size(); ++i) {
		if (is_on(a[i], b)) {
			return true;
		}
	}
	for (int i=0; i<(int)b.size(); ++i) {
		if (is_on(b[i], a)) {
			return true;
		}
	}

	for (int i=1; i<(int)a.size(); ++i) {
		if (a[i] != a[i-1]) {
			for (int j=1; j<(int)b.size(); ++j) {
				if (b[j] != b[j-1]) {
					if (clean_intersects(a[i-1], a[i], b[j-1], b[j])) {
						return true;
					}
				}
			}
		}
	}

	return false;
}
class PolylineUnion {
	public:
	int countComponents(vector <string> polylines_) {
		string polylines;
		for (int i=0; i<(int)polylines_.size(); ++i)
			polylines += polylines_[i];

		vector<string> P_ = tokenize<string>(polylines);
		vector< vector<Point> > P;
		for (int i=0; i<(int)P_.size(); ++i) {
			P.push_back(poly_line(P_[i]));
		}

		/*for (int i=0; i<(int)P.size(); ++i) {
			for (int j=0; j<(int)P[i].size(); ++j) {
				cerr << P[i][j].x << ' ' << P[i][j].y << '\n';
			}
			cerr << '\n';
		}*/

		N = P.size();
		G.assign(N, vector<bool>(N, false));

		for (int i=0; i<N; ++i) {
			for (int j=i+1; j<N; ++j) {
				if (has_common_point(P[i], P[j])) {
					G[i][j] = G[j][i] = 1;
				}
			}
		}

		int comp = 0;
		C.assign(N, -1);
		for (int i=0; i<N; ++i) {
			if (C[i] == -1) {
				dfs(i, comp++);
			}
		}

		return comp;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0,0-10,10 0,10-10,0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, countComponents(Arg0)); }
	void test_case_1() { string Arr0[] = {"0,0-10,5 5,0-15,5-10,10-5,5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, countComponents(Arg0)); }
	void test_case_2() { string Arr0[] = {"1","3,0-5,5 4,0-4,20"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, countComponents(Arg0)); }
	void test_case_3() { string Arr0[] = {"10,0-10,1-9,2-9,3-8,4 ","8,2-9,2-10,3 ","12,2-11,2-9,1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(3, Arg1, countComponents(Arg0)); }
	void test_case_4() { string Arr0[] = {"0,0-10,0-0,0 20,0-8,0-20,0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, countComponents(Arg0)); }
	void test_case_5() { string Arr0[] = {"1,1 2,2 3,3 4,4 3,3-4,4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(5, Arg1, countComponents(Arg0)); }
	void test_case_6() { string Arr0[] = {"10,10-20,10 20,10-15,18 15,18-10,10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(6, Arg1, countComponents(Arg0)); }
	void test_case_7() { string Arr0[] = {"1,1 1,1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(7, Arg1, countComponents(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    PolylineUnion ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

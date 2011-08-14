#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <utility>

using namespace std;

template<class T>
string to_str(T x)
{
    string ret;
    ostringstream os(ret);

    os << x;
    return os.str();
}
struct Edge {
	int dest;
	int len;
	Edge(int d, int l): dest(d), len(l) {}
	string print() const {
		return to_str(dest)+':'+to_str(len);
	}
};
bool operator<(const Edge &a, const Edge &b) {
	if (a.dest!=b.dest)
		return a.dest < b.dest;
	else return a.len < b.len;
}
int n, m;
inline bool valid(int i, int j) {
	return (i>=0&&i<m && j>=0&&j<n);
}
const int di[] = { -1, -1, 0, 1, 1,  1,  0, -1 };
const int dj[] = {  0,  1, 1, 1, 0, -1, -1, -1 };

enum {
	EDGE = 250, EMPTY
};
typedef pair<int, int> PII;
PII go(int i, int j, int dir, const vector<vector<int> > &a, int len) {
	assert(valid(i, j) && a[i][j]==EDGE);

	while (valid(i, j) && a[i][j]==EDGE) {
		++len;
		i += di[dir];
		j += dj[dir];
	}
	if (valid(i, j) && a[i][j]<250)
		return make_pair(a[i][j], len);

	int newdir = (dir+1)%8;
	int ii = i-di[dir]+di[newdir];
	int jj = j-dj[dir]+dj[newdir];
	if (valid(ii, jj))
		if (a[ii][jj]==EDGE)
			return go(ii, jj, newdir, a, len);
		else if (a[ii][jj]<250)
			return make_pair(a[ii][jj], len);
	newdir = (dir==0)?7:dir-1;
	ii = i-di[dir]+di[newdir];
	jj = j-dj[dir]+dj[newdir];
	if (valid(ii, jj))
		if (a[ii][jj]==EDGE)
			return go(ii, jj, newdir, a, len);
		else if (a[ii][jj]<250)
			return make_pair(a[ii][jj], len);

	return make_pair(-1, -1);
}
class BitmapToGraph {
	public:
	vector <string> parse(vector <string> bm) {
		int cnt = 0;
		m = bm.size();
		n = bm[0].size();

		vector<vector<int> > bitmap(m, vector<int>(n));
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (bm[i][j]=='N')
					bitmap[i][j] = cnt++;
				else if (bm[i][j]=='E')
					bitmap[i][j] = EDGE;
				else
					bitmap[i][j] = EMPTY;

		vector<list<Edge> > a(cnt);
		vector<bool> self(cnt, false);
		for (int i=0; i<m; ++i)
			for (int j=0; j<n; ++j)
				if (bitmap[i][j]<250) {
					const int start = bitmap[i][j];
					for (int dir=0; dir<8; ++dir) {
						const int ii=i+di[dir];
						const int jj=j+dj[dir];
						if (valid(ii, jj) && bitmap[ii][jj]==EDGE) {
							PII t = go(ii, jj, dir, bitmap, 0);
							const int finish = t.first;
							const int len = t.second;
							assert(finish != -1);
							assert(start<cnt && finish<cnt);
							if (finish==start &&) {
								if (!self[start]) {
									self[start] = true;
									a[start].push_back(Edge(finish, len));
								}
							} else
								a[start].push_back(Edge(finish, len));
						}
					}
				}

		vector<string> sol(cnt);
		for (int i=0; i<cnt; ++i) {
			a[i].sort();
			for (list<Edge>::const_iterator iter=a[i].begin(); iter!=a[i].end(); ++iter) {
				if (iter!=a[i].begin())
					sol[i] += ',';
				sol[i] += iter->print();
			}
		}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] =    {"NEEE.....N",
    "....EEEEE.",
    ".........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "1:8",  "0:8" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, parse(Arg0)); }
	void test_case_1() { string Arr0[] =     {"N.N",
     ".E.",
     "N.N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "3:1",  "2:1",  "1:1",  "0:1" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, parse(Arg0)); }
	void test_case_2() { string Arr0[] =    {"N..N..N",
    ".E.E.E.",
    "..EEE..",
    "NEEEEEN",
    "..EEE..",
    ".E.E.E.",
    "N..N..N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "7:5",  "6:5",  "5:5",  "4:5",  "3:5",  "2:5",  "1:5",  "0:5" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, parse(Arg0)); }
	void test_case_3() { string Arr0[] =    {".NE....NE..N",
    "E..E...E.E..",
    "E..E...E.E.E",
    ".EE....NE..E"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "0:7",  "3:2,3:4",  "",  "1:2,1:4" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, parse(Arg0)); }
	void test_case_4() { string Arr0[] = {".EE....",
 "E..E...",
 "E..E...",
 "NEEEEE.",
 "...E..E",
 "...E..E",
 "...E..E",
 "....EE."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "0:20" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, parse(Arg0)); }
	void test_case_5() { string Arr0[] = {".EE.",
 "N..N",
 ".EE."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "1:2,1:2",  "0:2,0:2" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, parse(Arg0)); }
	void test_case_6() { string Arr0[] =    {"N..N.........",
    ".E.E.........",
    "..EE....EN...",
    "...E.N.E.....",
    "...NEEEEEN...",
    "...E.N.E.....",
    "..EE....EN...",
    ".E.E.........",
    "N..N........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = { "6:4",  "4:3",  "6:3",  "6:1,7:3,8:4",  "1:3,5:5,9:3",  "4:5",  "0:4,2:3,3:1",  "3:3",  "3:4",  "4:3" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(6, Arg1, parse(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BitmapToGraph ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

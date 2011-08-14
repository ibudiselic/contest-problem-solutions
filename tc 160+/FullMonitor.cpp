#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <utility>

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
	int x, y, z;
	Point(int x_, int y_, int z_): x(x_), y(y_), z(z_) {}
};
bool operator<(const Point &a, const Point &b) {
	if (a.x != b.x)
		return a.x < b.x;
	else if (a.y != b.y)
		return a.y < b.y;
	else return a.z < b.z;
}
class FullMonitor {
	public:
	int numLasers(vector <string> pixels) {
		set<Point> activated;
		set<pair<int, int> > xy, yz, zx;
		for (int i=0; i<(int)pixels.size(); ++i) {
			vector<int> t = tokenize<int>(pixels[i], ",");
			xy.insert(make_pair(t[0], t[1]));
			yz.insert(make_pair(t[1], t[2]));
			zx.insert(make_pair(t[2], t[0]));
			activated.insert(Point(t[0], t[1], t[2]));
		}
		for (set<pair<int, int> >::const_iterator i=xy.begin(); i!=xy.end(); ++i)
			for (set<pair<int, int> >::const_iterator j=yz.begin(); j!=yz.end(); ++j)
				for (set<pair<int, int> >::const_iterator k=zx.begin(); k!=zx.end(); ++k)
					if (i->first==k->second && i->second==j->first && j->second==k->first && activated.count(Point(i->first, i->second, j->second))==0)
						return -1;

		return xy.size()+yz.size()+zx.size();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"25,25,25"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, numLasers(Arg0)); }
	void test_case_1() { string Arr0[] = {"25,25,25","25,25,26"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, numLasers(Arg0)); }
	void test_case_2() { string Arr0[] = {"25,25,25","25,25,26","25,26,26","25,26,25"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(2, Arg1, numLasers(Arg0)); }
	void test_case_3() { string Arr0[] = {"1000,1005,20","20,50,20","30,90,10","1005,30,90",
 "90,1000,1005","30,90,20","1000,90,10","40,90,10",
 "1000,1000,1000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, numLasers(Arg0)); }
	void test_case_4() { string Arr0[] = {"1,1,3","1,3,1","3,1,1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, numLasers(Arg0)); }
	void test_case_5() { string Arr0[] = {"1,1,3","1,3,1","3,1,1","1,1,1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(5, Arg1, numLasers(Arg0)); }
	void test_case_6() { string Arr0[] = {"938,134,626","1015,310,957","427,741,13","388,513,56",
"914,169,526","716,540,478","796,461,500","506,886,866",
"44,185,744","474,104,631","557,402,744","992,132,804",
"440,499,122","895,845,612","711,576,984","281,846,475",
"781,620,301","305,632,954","874,659,36","17,978,393",
"765,481,372","612,316,8","902,281,515","272,125,1012",
"413,513,987","595,940,1014","858,1019,100","899,554,613",
"226,995,592","793,939,286","386,41,212","111,899,737",
"339,199,117","1014,710,638","413,187,56","301,691,368",
"387,285,286","546,356,739","366,356,660","877,461,737",
"538,301,629","707,116,7","701,730,70"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(6, Arg1, numLasers(Arg0)); }
	void test_case_7() { string Arr0[] = {"286,596,559","502,325,84","303,56,960","28,678,821",
"542,57,303","233,418,91","13,520,124","645,129,889",
"438,433,951","835,953,56","921,531,943","416,159,446",
"513,426,1018","778,486,254","132,380,822","828,351,787",
"659,531,866","893,140,419","603,721,110","888,144,689",
"861,869,515","632,912,973","435,828,676","526,365,850",
"162,860,173","637,910,701","169,21,311","431,722,798",
"674,663,1012","451,343,584","132,380,1000","184,720,1011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 95; verify_case(7, Arg1, numLasers(Arg0)); }
	void test_case_8() { string Arr0[] = {"1,0,0","4,1,2","0,2,0","0,0,0","4,4,3","2,3,2","0,4,3",
"4,2,3","4,4,1","2,2,0","4,1,1","4,0,1","1,0,2","1,3,2",
"0,2,3","4,0,2","2,2,3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 31; verify_case(8, Arg1, numLasers(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    FullMonitor ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

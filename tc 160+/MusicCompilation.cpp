#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class MusicCompilation {
	public:
	vector <string> makeCompilation(vector <string> artists) {
		vector<string> a, b, c;
		for (int i=0; i<(int)artists.size(); ++i) {
			istringstream is(artists[i]);
			string name;
			int x;
			is >> name >> x;
			if (x == 1) {
				b.push_back(name);
			} else {
				a.push_back(name);
				c.push_back(name);
				x -= 2;
				while (x--)
					b.push_back(name);
			}
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		sort(c.begin(), c.end());
		copy(b.begin(), b.end(), back_inserter(a));
		copy(c.begin(), c.end(), back_inserter(a));
		return a;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"Shakira 1","Jamiroquai 3","Gorillaz 2"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Gorillaz", "Jamiroquai", "Jamiroquai", "Shakira", "Gorillaz", "Jamiroquai" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, makeCompilation(Arg0)); }
	void test_case_1() { string Arr0[] = {"Radiohead 2","Spiderbait 3","LimpBizkit 4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"LimpBizkit", "Radiohead", "Spiderbait", "LimpBizkit", "LimpBizkit", "Spiderbait", "LimpBizkit", "Radiohead", "Spiderbait" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, makeCompilation(Arg0)); }
	void test_case_2() { string Arr0[] = {"Beatles 2","ABBA 1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"Beatles", "ABBA", "Beatles" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, makeCompilation(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MusicCompilation ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

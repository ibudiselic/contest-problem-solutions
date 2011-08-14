#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> sol;
vector<string> w;
int W;
int n;

int cntEndSpaces(const string &s) {
	int ret = 0;
	for (int i=(int)s.size()-1; s[i]==' '; --i, ++ret)
		;

	return ret;
}
bool can(int rows) {
	const int minCols = (n+rows-1)/rows;
	bool canMakeIt = false;
	int rightSpaces = -1;

	for (int cols=minCols; cols<=n && (rows==1 || (rows-1)*(cols-1)+rows<=n); ++cols) {
		const int fullCols = n - (rows-1)*cols;
		assert(fullCols>=1 && fullCols<=cols);

		vector<string> cur(rows, string());
		int i = 0;
		bool ok = true;
		for (int c=0; c<cols; ++c) {
			int largest = 0;
			int howMany = rows-1 + (c<fullCols);

			for (int r=0; r<howMany; ++r) {
				cur[r] += w[i++] + (c<cols-1 ? " " : "");
				largest = max(largest, (int)cur[r].size());
			}
			if (largest > W) {
				ok = false;
				break;
			}

			for (int r=0; r<rows; ++r)
				cur[r] += string(largest-cur[r].size(), ' ');
		}

		if (ok) {
			for (int r=0; r<rows; ++r)
				cur[r] += string(W-cur[r].size(), ' ');

			canMakeIt = true;
			int fewestSpaces = 1234567890;
			for (int r=0; r<rows; ++r)
				fewestSpaces = min(fewestSpaces, cntEndSpaces(cur[r]));

			if (fewestSpaces > rightSpaces) {
				rightSpaces = fewestSpaces;
				sol = cur;
			}
		}
	}

	return canMakeIt;
}

class Lister {
	public:
	vector <string> doList(int pageWidth, vector <string> names) {
		 w = names;
		 W = pageWidth;
		 n = w.size();
		 sort(w.begin(), w.end());

		 for (int rows=1; rows<=n; ++rows)
		 	if (can(rows))
		 		return sol;

		 return vector<string>();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 10; string Arr1[] = {"bob","abernathy","x"}
; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "abernathy ",  "bob       ",  "x         " }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, doList(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 11; string Arr1[] = {"bob","abernathy","x"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "abernathy x",  "bob        " }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, doList(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; string Arr1[] = {"bob","a","x"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "a bob x   " }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, doList(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; string Arr1[] = {"x","teddy","andy"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "andy  x   ",  "teddy     " }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, doList(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 33; string Arr1[] = {"g","babec","bafffebe","bffaf",
 "decdgfgcbc","bacfeddea","g","deecgabcg","c"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "babec     bffaf decdgfgcbc g     ",  "bacfeddea c     deecgabcg  g     ",  "bafffebe                         " }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, doList(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Lister ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

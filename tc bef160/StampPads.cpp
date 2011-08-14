#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template<class T>
vector<T> tokenize(string s, const string &delim=" ")
{
    vector<T> ret_val;
    string::size_type i=0;
    string::size_type len = delim.length();
    if (delim != " ")
        while ((i=s.find(delim)) != string::npos)
            s.replace(i, len, " ");

    istringstream is(s);
    T val;

    while (is >> val)
        ret_val.push_back(val);
    return ret_val;
}
class StampPads {
	public:
	int bestCombo(vector <string> pads, vector <string> wishlist) {
		vector<vector<int> > p(pads.size(), vector<int>());
		for (int i=0; i<(int)wishlist.size(); ++i)
			for (int j=0; j<(int)pads.size(); ++j) {
				vector<string> t = tokenize<string>(pads[j]);
				for (vector<string>::size_type k=0; k<t.size(); ++k)
					if (t[k] == wishlist[i]) {
						p[j].push_back(i);
						break;
					}
			}

		int lim = 1<<pads.size();
		int sol = 100;
		int n = (int)wishlist.size();
		for (int mask=1; mask<lim; ++mask) {
			vector<bool> a(n, false);
			int k = n;
			int cnt = 0;
			for (int i=0; i<(int)p.size() && (1<<i)<=mask; ++i)
				if (mask & (1<<i)) {
					++cnt;
					for (int j=0; j<(int)p[i].size(); ++j)
						if (!a[p[i][j]]) {
							--k;
							a[p[i][j]] = true;
						}
				}
			if (k==0)
				sol = min(sol, cnt);
		}
		return sol!=100 ? sol:-1;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"yellow red purple blue cyan",
 "red green orange magenta yellow",
 "brown black orange yellow tan"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"orange", "yellow", "red", "blue", "magenta", "tan"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(0, Arg2, bestCombo(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"yellow red purple blue cyan",
 "red green orange magenta yellow",
 "brown black orange yellow tan"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"orange", "yellow", "red", "blue", "tan"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, bestCombo(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"yellow black blue green red",
 "yellow brown cyan magenta tan",
 "black grey fire maroon silver",
 "blue white neon tangerine rust",
 "green orange soot turquoise mint",
 "red cream opal chrome sky"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"yellow", "black", "blue", "green", "red",
 "brown", "grey", "white", "orange", "cream"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(2, Arg2, bestCombo(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"red green orange magenta yellow"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"silver"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(3, Arg2, bestCombo(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"a i y d o", "t s k g e", "j u w i k", "u k l s j", "q s a c y",
 "q m d x a", "m s l h r", "s x q l n", "u r j s k", "e w v d p",
 "o l a b q", "f z g a m", "o g k b a", "c h g k t", "z v s n x",
 "z n b w c", "h p o u k", "t z o x m", "a w i v z", "u t v m y"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"x", "b", "u", "c", "h", "j", "t", "v", "d", "g",
 "k", "w", "y", "z", "a", "i", "m", "l", "n", "e"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(4, Arg2, bestCombo(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    StampPads ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

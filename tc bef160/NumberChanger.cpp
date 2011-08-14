#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
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
template<class T>
string to_str(T x)
{
    string ret;
    ostringstream os(ret);

    os << x;
    return os.str();
}

/*** real code starts here ***/

class NumberChanger {
	public:
	int transform(string start, string finish)
	{
		int n = start.length();
		int sol = 2000000000;
		vector<int> pos;
		
		for (int i=0; i<n; ++i) pos.push_back(i);
		do {
			int cnt = 0;
			for (int i=0; i<n; ++i) cnt += abs(finish[i]-start[pos[i]]);
			vector<bool> v(n, 0);
			for (int i=0; i<n; ++i)
				if (!v[i]) {
					v[i] = 1;
					for (int j=pos[i]; j!=i; j=pos[j]) {
						v[j] = 1;
						++cnt;
					}
				}
			sol <?= cnt;
		} while (next_permutation(pos.begin(), pos.end()));
		
		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "01234567"; string Arg1 = "01234567"; int Arg2 = 0; verify_case(0, Arg2, transform(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "11119999"; string Arg1 = "99991111"; int Arg2 = 4; verify_case(1, Arg2, transform(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "55555555"; string Arg1 = "12345678"; int Arg2 = 16; verify_case(2, Arg2, transform(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "77771111"; string Arg1 = "00446688"; int Arg2 = 16; verify_case(3, Arg2, transform(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "12"; string Arg1 = "30"; int Arg2 = 3; verify_case(4, Arg2, transform(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    NumberChanger ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

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
vector<int> d;
template<class T>
T max_of(T a, T b)
{
	return a>b ? a:b;
}
class YahtzeeRoll {
	public:
	void fill_up(vector<int> &a, vector<int> &n, vector<bool> &o)
	{
		for (int i=0; i<(int)a.size(); ++i)
			++n[a[i]];
		for (int i=0; i<6; ++i)
			o[n[i]] = true;
	}
	int best_score(int start, int mask)
	{	         
		int res = 0;
		int i=start;
		for (; i<(int)d.size() && !(mask & (1<<(4-i))); ++i)
			;
		if (i==(int)d.size()) {
			vector<int> number_of(6, 0);
			vector<bool> of_a_kind(6, false);
			fill_up(d, number_of, of_a_kind);
			if (of_a_kind[5]) return 50;
			else if (number_of[0]&&number_of[1]&&number_of[2]&&number_of[3]&&number_of[4]
				  || number_of[1]&&number_of[2]&&number_of[3]&&number_of[4]&&number_of[5])
				return 40;
			else if (number_of[0]&&number_of[1]&&number_of[2]&&number_of[3]
			      || number_of[1]&&number_of[2]&&number_of[3]&&number_of[4]
			      || number_of[2]&&number_of[3]&&number_of[4]&&number_of[5])
			    return 30;
			else if (of_a_kind[2]&&of_a_kind[3])
				return 25;
			else return 0;
		}
		int t=d[i];
		for (int j=0; j<6; ++j) {
			d[i] = j;
			res += best_score(i+1, mask);
		}
		d[i] = t;
		return res;
	}	
	double bestChoice(vector <int> dice) {
		double sol = 0.0;
		for (int i=0; i<(int)dice.size(); ++i)
			--dice[i];
		
		d = dice;
		for (int mask=0; mask<32; ++mask) {
			double t = best_score(0, mask);
			for (int i=0; i<5; ++i)
				if (mask & (1<<(4-i)))
					t /= 6.0;
			sol = max_of(sol, t);
		}
		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 1, 1, 1, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 8.333333333333334; verify_case(0, Arg1, bestChoice(Arg0)); }
	void test_case_1() { int Arr0[] = { 1, 1, 1, 2, 2 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 25.0; verify_case(1, Arg1, bestChoice(Arg0)); }
	void test_case_2() { int Arr0[] = { 2, 3, 4, 5, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 33.333333333333336; verify_case(2, Arg1, bestChoice(Arg0)); }
	void test_case_3() { int Arr0[] = { 2, 2, 3, 4, 4 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 17.77777777777778; verify_case(3, Arg1, bestChoice(Arg0)); }
	void test_case_4() { int Arr0[] = { 6, 1, 3, 5, 5 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 9.722222222222221; verify_case(4, Arg1, bestChoice(Arg0)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    YahtzeeRoll ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

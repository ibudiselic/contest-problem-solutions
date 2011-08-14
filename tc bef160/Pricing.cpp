#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Pricing {
	public:
	int maxSales(vector <int> price) {
		int n = (int)price.size();
		int sol = 0;

		sort(price.begin(), price.end());
		for (int x1=0; x1<=n; ++x1)
			for (int x2=0; x2<=n-x1; ++x2)
				for (int x3=0; x3<=n-x1-x2; ++x3) {
					int x4 = n-x1-x2-x3;
					int t1, t2, t3, t4;
					t1 = t2 = t3 = t4 = 0;
					for (int i=0; i<x1; ++i)
						t1 = ::max(t1, price[i]*(x1-i));
					for (int i=0; i<x2 && x1+i<n; ++i)
						t2 = ::max(t2, price[x1+i]*(x2-i));
					for (int i=0; i<x3 && x1+x2+i<n; ++i)
						t3 = ::max(t3, price[x1+x2+i]*(x3-i));
					for (int i=0; i<x4 && x1+x2+x3+i<n; ++i)
						t4 = ::max(t4, price[x1+x2+x3+i]*(x4-i));
					sol = ::max(sol, t1+t2+t3+t4);
				}
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {9,1,5,5,5,5,4,8,80}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 120; verify_case(0, Arg1, maxSales(Arg0)); }
	void test_case_1() { int Arr0[] = {17,50,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 69; verify_case(1, Arg1, maxSales(Arg0)); }
	void test_case_2() { int Arr0[] = {130,110,90,13,6,5,4,3,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 346; verify_case(2, Arg1, maxSales(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Pricing ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <stack>

using namespace std;

/*input array: h
output array: R (of size n)
j := 0
m := size of h
for i := 0 to n-1
	R[i] := h[j]
	s := (j+1)%m
	h[j] := ( ( h[j] ^ h[s] ) + 13 ) % 835454957
	j := s
*/
vector<int> H;
void input_reformat(vector<int> &v, int n) {
	H.assign(n, 0);
	int j = 0;
	int m = v.size();
	for (int i=0; i<n; ++i) {
		H[i] = v[j];
		int s = (j+1)%m;
		v[j] = ((v[j]^v[s])+13) % 835454957;
		j = s;
	}
}
int l[100000], r[100000];
class BuildingAdvertise {
	public:
	long long getMaxArea(vector <int> h, int n) {
		input_reformat(h, n);

		/* ovo radi... samo probavam drugi nacin */
		/*l[0] = -1;
		for (int i=1; i<n; ++i)
			if (H[i] > H[i-1]) {
				l[i] = i-1;
			} else { // H[i] <= H[i-1]
				int j = i-1;
				while (j!=-1 && H[i]<=H[j])
					j = l[j];
				l[i] = j;
			}

		r[n-1] = n;
		for (int i=n-2; i>=0; --i)
			if (H[i] > H[i+1]) {
				r[i] = i+1;
			} else { // H[i] <= H[i+1]
				int j = i+1;
				while (j!=n && H[i]<=H[j])
					j = r[j];
				r[i] = j;
			}

		long long sol = 0;
		for (int i=0; i<n; ++i)
			sol = max(sol, ((long long)r[i]-l[i]-1)*H[i]);

		return sol;*/

		H.push_back(0);
		stack<long long> pos, hight;

		long long sol = 0;
		for (int i=0; i<=n; ++i) {
			int reach = i;
			while (!hight.empty() && hight.top()>=H[i]) {
				sol = max(sol, hight.top()*(i-pos.top()));
				reach = pos.top();
				hight.pop();
				pos.pop();
			}
			hight.push(H[i]);
			pos.push(reach);
		}

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,6,5,6,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; long long Arg2 = 15LL; verify_case(0, Arg2, getMaxArea(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {5,0,7,0,2,6,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; long long Arg2 = 7LL; verify_case(1, Arg2, getMaxArea(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1048589,2097165}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100000; long long Arg2 = 104858900000LL; verify_case(2, Arg2, getMaxArea(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,7,2,5,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; long long Arg2 = 8LL; verify_case(3, Arg2, getMaxArea(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BuildingAdvertise ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>
using namespace std;

bool done[1<<25];
int pos[26];
int ind[26];
int n;
string o;
string x;
string sol;
unsigned target;

bool go(unsigned mask) {
	if (mask == target)
		return true;
	if (done[mask])
		return false;
	done[mask] = true;

	for (int i=0; i<n; ++i)
		if ((mask & (1u<<i)) == 0) {
			const int p = pos[x[i]-'a'];
			int d = 1;
			while (1) {
				if (isupper(o[p-d]) && tolower(o[p-d])==x[i])
					break; /* car i can get to the final position */
				const int t = ind[tolower(o[p-d]) - 'a'];
				if ( ((mask>>t) & 1)==1 && isupper(o[p-d]) || ((mask>>t) & 1)==0 && islower(o[p-d]) )
					break; /* car i can't get to the final position in this direction */
				++d;
			}
			bool ok = isupper(o[p-d]) && tolower(o[p-d])==x[i];
			if (!ok) {
				d = 1;
				while (1) {
					if (isupper(o[p+d]) && tolower(o[p+d])==x[i])
						break; /* car i can get to the final position */
					const int t = ind[tolower(o[p+d]) - 'a'];
					if ( ((mask>>t) & 1)==1 && isupper(o[p+d]) || ((mask>>t) & 1)==0 && islower(o[p+d]) )
						break; /* car i can't get to the final position in this direction */
					++d;
				}
				ok = isupper(o[p+d]) && tolower(o[p+d])==x[i];
			}
			if (ok) {
				if (go(mask | (1u<<i))) {
					sol += x[i];
					return true;
				}
			}
		}
	return false;
}

class CircleOrder {
	public:
	string firstOrder(string circle) {
		n = circle.size() / 2;
		target = (1u<<n) - 1;

		o = circle + circle + circle;

		x = circle;
		sort(x.begin(), x.end());
		x = x.substr(n);
		memset(ind, 0, sizeof ind);
		for (int i=0; i<n; ++i)
			ind[x[i]-'a'] = i;

		memset(pos, 0, sizeof pos);
		for (int i=2*n; i<4*n; ++i)
			if (islower(o[i]))
				pos[o[i]-'a'] = i;

		memset(done, 0, sizeof done);
		sol.clear();
		go(0);
		if (sol.size() == 0)
			return "NONE";
		else {
			reverse(sol.begin(), sol.end());
			return sol;
		}
		return "gg";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BACacb"; string Arg1 = "abc"; verify_case(0, Arg1, firstOrder(Arg0)); }
	void test_case_1() { string Arg0 = "ABCacb"; string Arg1 = "NONE"; verify_case(1, Arg1, firstOrder(Arg0)); }
	void test_case_2() { string Arg0 = "XYxPyp"; string Arg1 = "xyp"; verify_case(2, Arg1, firstOrder(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    CircleOrder ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

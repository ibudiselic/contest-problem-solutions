#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

class MatchNumbersHard {
	public:
	vector <string> maxNumber(vector <string> matches, string n) {
		vector<long long> C(matches.size(), 0);
		for (int i=0; i<(int)matches.size(); ++i)
			istringstream(matches[i]) >> C[i];
		long long N;
		istringstream(n) >> N;

		/* corner cases */
		bool zero_digits = true;
		for (int i=0; i<(int)C.size(); ++i)
			if (C[i] <= N) {
				zero_digits = false;
				break;
			}
		if (zero_digits) {
			vector<string> sol;
			sol.push_back("0");
			sol.push_back("");
			sol.push_back("");
			return sol;
		}

		bool only_zero = (C[0] <= N);
		for (int i=1; i<(int)C.size(); ++i)
			if (C[i] <= N) {
				only_zero = false;
				break;
			}
		if (only_zero) {
			vector<string> sol;
			sol.push_back("1");
			sol.push_back("0");
			sol.push_back("0");
			return sol;
		}

		/* core algorithm */
		vector<long long> num(C.size(), 0);
		int best_digit = 0;

		for (int i=1; i<(int)C.size(); ++i)
			if (C[i] <= C[best_digit])
				best_digit = i;

		//cerr << best_digit << ' ' << N << ' ' << C[best_digit] << '\n';

		num[best_digit] = N/C[best_digit];
		//cerr << num[best_digit] << '\n';
		N -= num[best_digit] * C[best_digit];
		//cerr << "ostatak nakon prvog oduzimanja N = " << N << '\n';
		/* special case for 0 */
		if (best_digit == 0) {
			/* cheapest non-zero digit */
			const long long min_cost = *min_element(C.begin()+1, C.end());
			const long long rem_cnt = (min_cost-N + C[0]-1)/C[0];
			//cerr << "specijalni slucaj 0: " << min_cost << ' ' << rem_cnt << '\n';
			num[0] -= rem_cnt;
			assert(num[0] >= 0);
			N += rem_cnt * C[0];
			//cerr << "novi N: " << N << '\n';
			/* find largest non-zero digit creatable with remaining N */
			int best_new = C.size()-1;
			while (C[best_new] > N)
				--best_new;
			++num[best_new];
			N -= C[best_new];
		}
		/* back to general case */
		/* try to change for better digits */
		//cerr << N << '\n';
		for (int change=0; change<(int)C.size()-1; ++change) {
			bool repeat = (num[change] > 0);
			while (repeat) {
				repeat = false;
				/* find better candidate */
				int better;
				for (better=(int)C.size()-1; better>change; --better) {
					const long long cnt_change = min(num[change], max(0ll, N/(C[better]-C[change])));
					if (cnt_change > 0) {
						//cerr << "zamjena " << change << ' ' << better << ' ' << N;
						N -= cnt_change * (C[better]-C[change]);
						//cerr << ' ' << N << '\n';
						num[change] -= cnt_change;
						num[better] += cnt_change;;
						repeat = true;
						break;
					}
				}
				repeat &= (num[change] > 0);
			}
		}

		/* create output */
		vector<string> sol;
		long long cnt = accumulate(num.begin(), num.end(), 0ll);
		ostringstream os;
		os << cnt;
		sol.push_back(os.str());

		string left;
		vector<long long> t = num;
		long long x = 0;
		while (x<cnt && x<50) {
			for (int i=(int)t.size()-1; i>=0; --i)
				if (t[i] > 0) {
					--t[i];
					left += char(i+'0');
					break;
				}
			++x;
		}
		sol.push_back(left);

		string right;
		x = 0;
		while (x<cnt && x<50) {
			for (int i=0; i<(int)num.size(); ++i)
				if (num[i] > 0) {
					--num[i];
					right = char(i+'0') + right;
					break;
				}
			++x;
		}
		sol.push_back(right);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"6","7","8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "21"; string Arr2[] = {"3", "210", "210" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"1","7","8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "21"; string Arr2[] = {"15", "100000000000000", "100000000000000" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"1","1","1","1","1","1","1","1","1","1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "923372036854775807"; string Arr2[] = {"923372036854775807", "99999999999999999999999999999999999999999999999999", "99999999999999999999999999999999999999999999999999" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"1","923372036854775807"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "923372036854775807"; string Arr2[] = {"1", "1", "1" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"1","923372036854775806"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "923372036854775807"; string Arr2[] = {"2", "10", "10" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"1","5","10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "10"; string Arr2[] = {"6", "100000", "100000" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {"1","923372036854775807"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "923372036854775806"; string Arr2[] = {"1", "0", "0" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(6, Arg2, maxNumber(Arg0, Arg1)); }
	void test_case_7() { string Arr0[] = {"1", "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "1000000"; string Arr2[] = {"999991", "10000000000000000000000000000000000000000000000000", "00000000000000000000000000000000000000000000000000" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(7, Arg2, maxNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    MatchNumbersHard ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

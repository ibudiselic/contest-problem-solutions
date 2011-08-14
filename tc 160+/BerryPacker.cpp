#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

unsigned mask[100001];
class BerryPacker {
	public:
	double bestPacking(vector <int> first, vector <int> period, int berries) {
		int n = first.size();
		memset(mask, 0, sizeof mask); // mask for the inspectors that see box i
		vector<int> sees(n); // num of boxes inspector i sees
		vector<int> num(1<<n); // number of boxes that the given mask of inspectors sees
		double sol = 0.0;

		for (int boxes=1; boxes<=berries; ++boxes) {
			++num[0]; // no inspectors initially see this box
			for (int i=0; i<n; ++i)
				while (first[i] < boxes) {
					--num[mask[first[i]]];
					mask[first[i]] |= 1<<i;
					++num[mask[first[i]]];
					++sees[i];
					first[i] += period[i];
				}

			vector<double> val(1<<n);
			for (int m=0; m<(1<<n); ++m)
				for (int i=0; i<n; ++i)
					if (m & (1<<i))
						if (sees[i] > 0)
							val[m] += double(boxes)/sees[i];

			vector< pair<double, int> > v(1<<n);
			for (int m=0; m<(1<<n); ++m) {
				v[m].first = val[m];
				v[m].second = num[m];
			}
			sort(v.begin(), v.end());
			reverse(v.begin(), v.end());
			double cur = 0.0;
			int left = berries - boxes;
			for (int m=0; m<(1<<n); ++m) {
				int add = min(left, v[m].second*8);
				left -= add;
				cur += v[m].first*(v[m].second+add);
			}
			sol = max(sol, cur);
		}
		return sol/n;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {500}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; double Arg3 = 12.0; verify_case(0, Arg3, bestPacking(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; double Arg3 = 9.0; verify_case(1, Arg3, bestPacking(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {2,5,9,25}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,11,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; double Arg3 = 251.50649350649354; verify_case(2, Arg3, bestPacking(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BerryPacker ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

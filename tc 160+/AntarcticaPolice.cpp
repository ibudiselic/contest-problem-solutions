#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;
int comp[50];
bool taken[50];
class AntarcticaPolice {
	public:
	double minAverageCost(vector <int> costs, vector <string> roads) {
		const int n = roads.size();
		for (int k=0; k<n; ++k)
			for (int i=0; i<n; ++i)
				for (int j=0; j<n; ++j)
					if (roads[i][k]=='Y' && roads[k][j]=='Y')
						roads[i][j] = 'Y';

		memset(comp, 0xff, sizeof comp);
		int ncomp = 0;
		for (int i=0; i<n; ++i) {
			for (int j=0; j<i; ++j)
				if (roads[i][j]=='Y' && roads[j][i]=='Y') {
					comp[i] = comp[j];
					break;
				}
			if (comp[i] == -1)
				comp[i] = ncomp++;
		}

		memset(taken, 0, sizeof taken);
		int sum=0, cnt=0;
		for (int c=0; c<ncomp; ++c) {
			bool root = true;
			int besti = -1;
			for (int i=0; i<n; ++i)
				if (comp[i] == c) {
					if (besti==-1 || costs[i]<costs[besti])
						besti = i;
				} else {
					for (int j=0; j<n; ++j)
						if (comp[j]==c && roads[i][j]=='Y') {
							root = false;
							break;
						}
				}
			if (root) {
				sum += costs[besti];
				taken[besti] = 1;
				++cnt;
			}
		}

		vector<int> t;
		for (int i=0; i<n; ++i)
			if (!taken[i])
				t.push_back(costs[i]);

		sort(t.begin(), t.end());
		for (int i=0; i<(int)t.size(); ++i)
			if (sum*(cnt+1) > (sum + t[i])*cnt) {
				sum += t[i];
				++cnt;
			}

		return double(sum)/cnt;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNN","NNYN","NNNY","YNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(0, Arg2, minAverageCost(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNN","NNYN","NNNY","NYNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(1, Arg2, minAverageCost(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {5,6,7,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNN","YNNN","NNNY", "NNYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 6.0; verify_case(2, Arg2, minAverageCost(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {10,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NY","NN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 7.5; verify_case(3, Arg2, minAverageCost(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {34,22,25,43,12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNNY","YNNYN","NNNYY","NNNNN","NNNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 19.666666666666668; verify_case(4, Arg2, minAverageCost(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    AntarcticaPolice ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

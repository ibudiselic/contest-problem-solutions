#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

struct elim {
	double time;
	string name;
	elim(double t_, const string &n_): time(t_), name(n_) {}
};
bool operator<(const elim &a, const elim &b) {
	if (fabs(a.time - b.time) > 1e-9)
		return a.time < b.time;
	else
		return a.name < b.name;
}
class BikeRace {
	public:
	vector <string> eliminated(int track, vector <string> name, vector <int> start, vector <int> speed) {
		int n = name.size();
		vector<elim> v;
		vector<bool> eliminated(n, 0);

		while (1) {
			double mintime = 1e32;
			int ind = -1;
			for (int i=0; i<n; ++i)
				if (!eliminated[i])
					for (int j=0; j<n; ++j)
						if (i!=j && !eliminated[j]) {
							if (start[i] > start[j]) {
								if ((start[i]-start[j])*speed[j] >= track) {
									if (start[j] + double(track)/speed[j] < mintime) {
										mintime = start[j] + double(track)/speed[j];
										ind = i;
									}
								} else if (speed[j] > speed[i]) {
									int pos = (start[i]-start[j])*speed[j];
									if (start[i] + (track-pos)/double(speed[j]-speed[i]) < mintime) {
										mintime = start[i] + (track-pos)/double(speed[j]-speed[i]);
										ind = i;
									}
								}
							} else {
								if ((start[j]-start[i])*speed[i] >= track)
									continue;
								if (speed[j] > speed[i]) {
									int pos = (start[j]-start[i])*speed[i];
									if (start[j] + pos/double(speed[j]-speed[i]) < mintime) {
										mintime = start[j] + pos/double(speed[j]-speed[i]);
										ind = i;
									}
								}
							}
						}
			if (ind == -1)
				break;
			eliminated[ind] = 1;
			v.push_back(elim(mintime, name[ind]));
		}

		sort(v.begin(), v.end());
		vector<string> sol;
		for (int i=0; i<(int)v.size(); ++i)
			sol.push_back(v[i].name);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 4800; string Arr1[] = {"A","B","C"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 0, 100,180} ; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {30, 30, 30} ; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = { "C" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, eliminated(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3000; string Arr1[] = {"BO","JO", "AL"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = { 10,  0,    15 } ; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = { 12,  2,    10 } ; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = { "JO",  "AL" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, eliminated(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3000; string Arr1[] = {"BOBO","JOHNNY","ANNA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {67,0,15}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {50,45,3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = { "BOBO",  "ANNA" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, eliminated(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 3000; string Arr1[] = {"B","J","A"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {66,0,15}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {50,45,3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = { "A",  "J" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, eliminated(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 5000; string Arr1[] = {"TOM","TOMMY","BILL","SPEEDY","JIMMY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100,120,110,0,1000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {50,50,50,50,50}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = { "BILL",  "JIMMY",  "TOM",  "TOMMY" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(4, Arg4, eliminated(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BikeRace ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

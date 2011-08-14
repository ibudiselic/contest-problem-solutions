#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Station {
	int dist, price;
	Station(int d = 0, int p = 0): dist(d), price(p) {}
};
bool operator<(const Station &a, const Station &b) {
	return a.dist < b.dist;
}

class GasStations {
	public:
	double tripCost(vector <int> d, vector <int> p, int mpg, int tank_sz, int trip_len) {
		int max_range = tank_sz*mpg;
		double cur_gas = tank_sz;

		vector<Station> a;
		a.push_back(Station(0, 20001));
		for (vector<int>::size_type i=0; i<d.size(); ++i)
			a.push_back(Station(d[i], p[i]));
		a.push_back(Station(trip_len, 0));

		sort(a.begin(), a.end());
		vector<double> spent(a.size());
		spent[0] = 0.0;

		for (vector<Station>::size_type i=0; i<a.size()-1; ++i) {
			vector<Station>::size_type next = i;
			for (vector<Station>::size_type j=i+1; j<a.size() && a[j].dist-a[i].dist<=max_range; ++j)
				if (a[j].price<a[i].price) {
					next = j;
					break;
				}
			if (next == i) {
				spent[i+1] = spent[i] + (tank_sz-cur_gas)*a[i].price;
				cur_gas = tank_sz - (double)(a[i+1].dist-a[i].dist)/mpg;
			} else {
				spent[next] = spent[i] + ::max(((double)(a[next].dist-a[i].dist)/mpg - cur_gas) * a[i].price, 0.0);
				cur_gas = ::max(cur_gas - (double)(a[next].dist-a[i].dist)/mpg, 0.0);
				i = next-1;
			}
		}
		return spent[spent.size()-1];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {100,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000,1500}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; int Arg3 = 10; int Arg4 = 300; double Arg5 = 5000.0; verify_case(0, Arg5, tripCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arr0[] = {300,450,525}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1659,1529,1439}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; int Arg3 = 20; int Arg4 = 600; double Arg5 = 15277.5; verify_case(1, Arg5, tripCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arr0[] = {300,450,525}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1659,1439,1529}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; int Arg3 = 20; int Arg4 = 600; double Arg5 = 14940.0; verify_case(2, Arg5, tripCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arr0[] = {300,125,450,525}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1659,1729,1439,1529}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; int Arg3 = 20; int Arg4 = 600; double Arg5 = 14940.0; verify_case(3, Arg5, tripCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arr0[] = {200}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; int Arg3 = 20; int Arg4 = 400; double Arg5 = 0.0; verify_case(4, Arg5, tripCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arr0[] = {100,400}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1549,1649}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 25; int Arg3 = 16; int Arg4 = 600; double Arg5 = 12792.0; verify_case(5, Arg5, tripCost(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    GasStations ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

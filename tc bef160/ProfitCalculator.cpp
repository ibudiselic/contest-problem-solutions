#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class ProfitCalculator {
	public:
	int percent(vector <string> items) {
		double cost, price;
		cost = price = 0.0;
		for (vector<string>::size_type i=0; i<items.size(); ++i) {
			istringstream is(items[i]);
			double a, b;
			is >> a >> b;
			cost += a;
			price += b;
		}
		return (int)((cost-price)/cost*100.0);
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"012.99 008.73","099.99 050.00","123.45 101.07"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32; verify_case(0, Arg1, percent(Arg0)); }
	void test_case_1() { string Arr0[] = {"000.00 049.99","999.99 936.22","033.99 025.64","249.99 211.87"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, percent(Arg0)); }
	void test_case_2() { string Arr0[] = {"822.77 704.86","829.42 355.45","887.18 949.38"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; verify_case(2, Arg1, percent(Arg0)); }
	void test_case_3() { string Arr0[] = {"612.72 941.34","576.46 182.66","787.41 524.70","637.96 333.23","345.01 219.69",
 "567.22 104.77","673.02 885.77"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 23; verify_case(3, Arg1, percent(Arg0)); }
	void test_case_4() { string Arr0[] = {"811.22 275.32","433.89 006.48","141.28 967.41","344.47 786.23","897.47 860.61",
 "007.42 559.29","255.72 460.00","419.35 931.19","419.25 490.52","199.78 114.44",
 "505.63 276.58","720.96 735.00","719.90 824.46","816.58 195.94","498.68 453.05",
 "399.48 921.39","930.88 017.63","422.20 075.39","380.22 917.27","630.83 995.87",
 "821.07 126.87","715.73 985.62","246.23 134.64","168.28 550.33","707.28 046.72",
 "117.76 281.87","595.43 410.45","345.28 532.42","554.24 264.34","195.73 814.87",
 "131.98 041.28","595.13 939.47","576.04 107.70","716.00 404.75","524.24 029.96",
 "673.49 070.97","288.09 849.43","616.34 236.34","401.96 316.33","371.18 014.27",
 "809.63 508.33","375.68 290.84","334.66 477.89","689.54 526.35","084.77 316.51",
 "304.76 015.91","460.63 636.56","357.84 436.20","752.24 047.64","922.10 573.12"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(4, Arg1, percent(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    ProfitCalculator ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

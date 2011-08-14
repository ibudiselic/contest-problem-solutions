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
struct Point {
	int x, y;
	Point(int x_, int y_): x(x_), y(y_) {}
	Point(const string &s) { istringstream(s) >> x >> y; }
};
Point operator-(const Point &a, const Point &b) { return Point(a.x-b.x, a.y-b.y); }
int operator*(const Point &a, const Point &b) { return a.x*b.x + a.y*b.y; }
int operator^(const Point &a, const Point &b) { return a.x*b.y - a.y*b.x; }
bool operator==(const Point &a, const Point &b) { return a.x==b.x && a.y==b.y; }
double norm(const Point &a) { return sqrt(a*a); }
double area(const Point &a, const Point &b, const Point &c) { return fabs((a-c)^(b-c))/2.0; }
double dist(const Point &a, const Point &b, const Point &c) { if (a == b) return norm(b-c); else return 2*area(a, b, c)/norm(a-b); }
bool in_ribbon(const Point &a, const Point &b, const Point &c) { return (b-a)*(c-b)<=0 && (a-b)*(c-a)<=0; }
vector<Point> A, B;
double get_dr_factor(const Point &a, const Point &b) {
	double ret = 1.0;

	for (int i=0; i<(int)B.size(); ++i)
		if (in_ribbon(a, b, B[i])) {
			const double d = dist(a, b, B[i]);
			ret = min(ret, d/(d+1.0));
		}
	return ret;
}
class BasketballStrategy {
	public:
	double scoreProbability(vector <string> team, vector <string> rivals, double Cp, double Cs) {
		A.clear();
		B.clear();
		for (int i=0; i<(int)team.size(); ++i) A.push_back(Point(team[i]));
		for (int i=0; i<(int)rivals.size(); ++i) B.push_back(Point(rivals[i]));

		Point basket(50, 0);
		vector<double> shotp(A.size());
		for (int i=0; i<(int)A.size(); ++i)
			shotp[i] = pow(Cs*get_dr_factor(A[i], basket), log(norm(A[i]-basket)));

		vector< vector<double> > passp(A.size(), vector<double> (A.size()));
		for (int i=0; i<(int)A.size(); ++i)
			for (int j=0; j<(int)A.size(); ++j)
				if (i == j) {
					passp[i][i] = 1.0;
				} else {
					const double ls = norm(A[i]-A[j]);
					passp[i][j] = Cp*(1-(ls/150)*(ls/150))*get_dr_factor(A[i], A[j]);
				}

		for (int n=0; n<(int)A.size(); ++n)
			for (int i=0; i<(int)A.size(); ++i)
				for (int j=0; j<(int)A.size(); ++j)
					shotp[i] = max(shotp[i], passp[i][j]*shotp[j]);

		return shotp[0];
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"50 50","35 60","70 15"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"75 5","72 25","45 17"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1; double Arg3 = 1; double Arg4 = 0.6100612919616956; verify_case(0, Arg4, scoreProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"50 4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"50 5"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.99; double Arg3 = 0.5; double Arg4 = 0.3825461314703953; verify_case(1, Arg4, scoreProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"50 4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"50 3"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.5; double Arg3 = 0.5; double Arg4 = 0.0; verify_case(2, Arg4, scoreProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"50 50","40 50","40 40","40 30","50 20"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"50 41","44 29","48 27","45 41","48 64"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.999999; double Arg3 = 0.8; double Arg4 = 0.25546407305110735; verify_case(3, Arg4, scoreProbability(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = {"50 50","50 25"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"40 40","60 20"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1; double Arg3 = 0.7; double Arg4 = 0.20631213370921644; verify_case(4, Arg4, scoreProbability(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    BasketballStrategy ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

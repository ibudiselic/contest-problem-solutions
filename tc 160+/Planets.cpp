#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
template<class T>
vector<T> tokenize(string s, const string &delim=" ")
{
    vector<T> ret_val;
    string::size_type i=0;
    string::size_type len = delim.length();
    if (delim != " ")
        while ((i=s.find(delim)) != string::npos)
            s.replace(i, len, " ");

    istringstream is(s);
    T val;

    while (is >> val)
        ret_val.push_back(val);
    return ret_val;
}
double sqr(double x) {
	return x*x;
}
struct Vec {
	double i, j, k;
	double mod() { return sqrt(sqr(i)+sqr(j)+sqr(k)); }
	Vec(double ii=0, double jj=0, double kk=0): i(ii), j(jj), k(kk) {}
	Vec &operator+=(const Vec &v) { i+=v.i; j+=v.j; k+=v.k; return *this; }
};
const Vec operator+(const Vec &v1, const Vec &v2) {
	Vec t(v1);
	return t+=v2;
}
string doit(double d) {
	static char buffer[20];
	if (fabs(d) < 1.0)
		sprintf(buffer, "%.3fE00", d);
	else
		sprintf(buffer, "%.3E", d);

	string s(buffer);
	string::size_type t = s.find('+');
	if (t!=string::npos) s.erase(t, 1);
	t = s.find("E0");
	if (t!=string::npos) s.erase(t+1, 1);
	return s=="-0.000E0" ? "0.000E0" : s;
}
struct Planet {
	Vec pos, v;
	double mass;
	Planet(const vector<double> &a): pos(a[0], a[1], a[2]), v(a[3], a[4], a[5]), mass(a[6]) {}
	string ispisi() { return doit(pos.i)+' '+doit(pos.j)+' '+doit(pos.k); }
};
const Vec operator*(double d, const Vec &v) {
	return Vec(v.i*d, v.j*d, v.k*d);
}
double dist(const Planet &a, const Planet &b) {
	return sqrt(sqr(a.pos.i-b.pos.i)+sqr(a.pos.j-b.pos.j)+sqr(a.pos.k-b.pos.k));
}
const Vec unit_vector(const Vec &a, const Vec &b) {
	Vec t(a.i-b.i, a.j-b.j, a.k-b.k);
	return 1/t.mod() * t;
}
const double grav_const = 6.673e-11;
class Planets {
	public:
	vector <string> locations(vector <string> planets, int time) {
		vector<Planet> p;
		for (int i=0; i<(int)planets.size(); ++i) {
			vector<double> t = tokenize<double>(planets[i]);
			assert(t.size()==7);
			p.push_back(Planet(t));
		}
		const int n = (int)p.size();
		while (time--) {
			for (int i=0; i<n; ++i) {
				Vec force;
				for (int j=0; j<n; ++j)
					if (i != j) {
						const double d = dist(p[i], p[j]);
						force += p[i].mass*p[j].mass/d/d*grav_const * unit_vector(p[j].pos, p[i].pos);
					}
				p[i].v += 3600/p[i].mass * force;
			}
			for (int i=0; i<n; ++i)
				p[i].pos += 3600*p[i].v;
		}
		vector<string> sol;
		for (int i=0; i<n; ++i)
			sol.push_back(p[i].ispisi());
		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"0 0 0 0 0 0 1.98892E30","1.496E11 0 0 0 29785.391801 0 5.972E24"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; string Arr2[] = { "1.165E3 2.756E1 0.000E0",  "1.492E11 1.071E10 0.000E0" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, locations(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"0 0 -.00000001 0 0 0 1.98892E30","1.496E11 0 0 0 29785.391801 0 5.972E24"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; string Arr2[] = { "0.231E0 0.000E0 0.000E0",  "1.496E11 1.072E8 0.000E0" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, locations(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"0 000E0000 .0000 0 0 0 1.98892E30","1.496E8 0 0 0 0 0 5.972E24"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; string Arr2[] = { "2.308E5 0.000E0 0.000E0",  "-7.671E10 0.000E0 0.000E0" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, locations(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"0 0 0.0000 0 0 0 1.98892E30","1.496E11 0 0 0 0 0 5.972E24"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; string Arr2[] = { "2.943E2 0.000E0 0.000E0",  "1.495E11 0.000E0 0.000E0" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, locations(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"5.05E9 -5.45E9 7.43E9 63.36 -66.61 37.53 4.43E49",
 "3.25E9 -3.34E9 -2.64E9 -93.91 85.61 -34.32 7.90E49",
 "4.97E8 -4.78E9 4.70E9 -2.032 -46.67 66.06 1.74E49",
 "3.31E9 -2.58E9 4.98E9 26.73 -40.55 -64.62 4.10E48",
 "1.66E9 2.34E9 2.2E9 -90.23 92.23 -53.40 4.23E49"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; string Arr2[] = { "-7.660E28 6.211E28 -1.186E29",  "-1.518E28 3.601E28 1.015E29",  "1.823E29 7.816E28 -4.915E28",  "-2.968E28 -1.486E29 -4.411E28",  "3.647E28 -1.500E29 -4.098E28" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, locations(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"0 0 0 0 0 0 1000","500 500 866.02540378443864676372317 0 0 0 1000","1000 1000 0 0 0 0 1000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; string Arr2[] = { "0.003E0 0.003E0 0.003E0",  "5.000E2 5.000E2 8.660E2",  "1.000E3 1.000E3 0.003E0" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, locations(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Planets ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

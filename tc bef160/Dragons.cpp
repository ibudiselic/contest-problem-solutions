#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
typedef unsigned long long llint;

llint gcd(llint a, llint b) {
	if (b == 0)
		return a;
	else return gcd(b, a%b);
}
llint lcm(llint a, llint b) {
	return ::min(a, b)/gcd(a, b)*::max(a, b);
}
struct Frac {
	llint nom, denom;
	Frac() { nom = 0; denom = 1; }
	Frac(llint nom_, llint denom_) { nom=nom_; denom=denom_; }
};
void reduce(Frac &a) {
	llint t = gcd(a.nom, a.denom);

	a.nom /= t;
	a.denom /= t;
}
Frac operator+(const Frac &a, const Frac &b) {
	Frac t;

	t.denom = lcm(a.denom, b.denom);
	t.nom = a.nom * (t.denom/a.denom) + b.nom * (t.denom/b.denom);
	reduce(t);

	return t;
}
Frac operator/(const Frac &a, const int d) {
	Frac t;
	t.nom = a.nom; t.denom = a.denom * d;
	reduce(t);

	return t;
}
int a[][6] = {
							{ 0, 0, 1, 1, 1, 1 },
							{ 1, 1, 0, 0, 1, 1 },
							{ 1, 1, 1, 1, 0, 0 }
						 };

class Dragons {
	public:
	string snaug(vector <int> initialFood, int rounds) {
		Frac x[6];
		Frac y[6];
		Frac *staro, *novo, *t;

		for (int i=0; i<6; ++i)
			x[i] = Frac(initialFood[i], 1);
		staro = x;
		novo = y;

		for (int i=0; i<rounds; ++i) {
			for (int j=0; j<6; ++j) {
				novo[j].nom = 0;
				novo[j].denom = 1;
			}
			for (int j=0; j<6; ++j) {
				for (int k=0; k<6; ++k)
					if (a[j/2][k])
						novo[j] = novo[j] + staro[k]/4;
			}
			t = novo; novo = staro; staro = t;
		}
		ostringstream os;
		os << staro[2].nom;
		if (staro[2].denom!=1)
			os << '/' << staro[2].denom;
		return os.str();
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 0, 4, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "1"; verify_case(0, Arg2, snaug(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 0, 4, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; string Arg2 = "1/2"; verify_case(1, Arg2, snaug(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1000, 1000, 1000, 1000, 1000, 1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 45; string Arg2 = "1000"; verify_case(2, Arg2, snaug(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1, 2, 3, 4, 5, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 45; string Arg2 = "7/2"; verify_case(3, Arg2, snaug(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    Dragons ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

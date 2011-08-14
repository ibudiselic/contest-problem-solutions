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

int lim[2001];
int mLim[2001];
int A, D;
double sol;

bool ok(double speed, int pos) {
	if (pos == D+1)
		return true;
	if (speed > mLim[pos]+1e-9 || speed > lim[pos]+1e-9)
		return false;

	return ok(speed - A, pos+1);
}
void go(double speed, int pos) {
	sol = max(sol, speed);
	if (pos == D)
		return;

	double lo = max(0.0, speed - A);
	double hi = min((double)lim[pos], speed + A);

	for (int i=0; i<150; ++i) {
		double mid = lo + (hi-lo)/2;
		if (ok(mid, pos+1))
			lo = mid;
		else
			hi = mid;
	}

	const double ns = (lo+hi)/2;

	sol = max(sol, min(double(lim[pos]), (speed + ns + A)/2));

	go(ns, pos+1);
}

class TestingCar {
	public:
	double maximalSpeed(vector <string> restrictions, int duration, int acceleration) {
		for (int i=0; i<2001; ++i)
			mLim[i] = lim[i] = 25*1000 + 1;
		D = duration;
		A = acceleration;

		for (int i=0; i<(int)restrictions.size(); ++i) {
			int l, s, t;
			sscanf(restrictions[i].c_str(), "%d %d %d", &l, &s, &t);
			for (int j=0; j<t; ++j)
				lim[s+j] = min(lim[s+j], l);
			if (t == 0)
				mLim[s] = l;
		}

		sol = 0.0;
		go(0, 0);

		return sol;
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"30 0 200"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 25; double Arg3 = 30.0; verify_case(0, Arg3, maximalSpeed(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"30 0 200"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 5; double Arg3 = 20.0; verify_case(1, Arg3, maximalSpeed(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"50 0 40", "50 60 50"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 10; double Arg3 = 150.0; verify_case(2, Arg3, maximalSpeed(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"50 30 10", "50 60 50"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 10; double Arg3 = 175.0; verify_case(3, Arg3, maximalSpeed(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"0 0 100", "0 200 100", "0 400 100", "0 600 100", "0 800 100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 20; double Arg3 = 2000.0; verify_case(4, Arg3, maximalSpeed(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"0 0 100", "0 200 100", "0 400 100", "0 600 100", "0 800 100", "0 1000 100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 20; double Arg3 = 1000.0; verify_case(5, Arg3, maximalSpeed(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arr0[] = {"44 422 129", "45 1 29", "72 290 80", "2 1 331", "76 445 16",
"76 204 429", "8 372 737", "21 159 538", "71 266 707", "99 73 933",
 "38 457 879", "42 24 299", "54 349 882", "6 352 909", "26 419 428",
 "51 327 311", "10 52 898", "75 10 702", "54 263 762", "75 404 223",
 "43 383 127", "86 433 521", "58 394 306", "33 379 514", "58 239 973",
 "89 301 765", "47 235 777", "75 355 190", "52 425 38", "59 140 347",
 "89 220 810", "47 72 724", "3 398 283", "0 224 266", "88 222 615",
 "25 149 85", "59 221 838", "14 87 86", "44 227 252", "73 330 936",
 "71 198 138", "54 186 141", "6 128 454", "5 123 719", "7 442 930",
 "59 174 505", "37 0 581", "9 198 168", "40 391 692", "49 320 419"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 462; int Arg2 = 13; double Arg3 = 7.5; verify_case(6, Arg3, maximalSpeed(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    TestingCar ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

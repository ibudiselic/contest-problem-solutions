#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct point {
	int x, y;
	point(int x_, int y_): x(x_), y(y_) {}
};
struct llpoint {
	long long x, y;
	llpoint(long long x_, long long y_): x(x_), y(y_) {}
};

vector<point> R1, R2, S1, S2;
int area(int i) {
	return (R2[i].x-R1[i].x) * (R2[i].y-R1[i].y);
}
bool contains(int i, const point &p) {
	return R1[i].x<p.x && p.x<R2[i].x && R1[i].y<p.y && p.y<R2[i].y;
}
bool contains(int i) {
	for (int j=0; j<(int)S1.size(); ++j) {
		if (contains(i, S1[j]) || contains(i, S2[j])) {
			return true;
		}
	}
	return false;
}

long long ccw(const llpoint &a, const llpoint &b) {
	return a.x*b.y - a.y*b.x;
}
long long ccw(const point &a, const point &b, const point &c) {
	return ccw(llpoint(b.x-a.x, b.y-a.y), llpoint(c.x-a.x, c.y-a.y));
}
bool on_line(const point &c, const point &a, const point &b) {
	if (ccw(a, b, c)) {
		return false;
	}
	int X = max(a.x, b.x);
	int x = min(a.x, b.x);
	int Y = max(a.y, b.y);
	int y = min(a.y, b.y);
	return x<=c.x && c.x<=X && y<=c.y && c.y<=Y;
}
bool intersects(const point &a, const point &b, const point &c, const point &d) {
	long long u = ccw(a, b, c);
	long long v = ccw(a, b, d);
	if (u==0 && v==0) {
		return on_line(a, c, d) || on_line(b, c, d) || on_line(c, a, b) || on_line(d, a, b);
	}
	if (u*v > 0) {
		return false;
	}
	u = ccw(c, d, a);
	v = ccw(c, d, b);
	assert(u!=0 || v!=0);
	return u*v <= 0;
}
bool intersected_by(int i, int j) {
	return intersects(R1[i], point(R2[i].x, R1[i].y), S1[j], S2[j]) ||
		   intersects(point(R2[i].x, R1[i].y), R2[i], S1[j], S2[j]) ||
		   intersects(R2[i], point(R1[i].x, R2[i].y), S1[j], S2[j]) ||
		   intersects(point(R1[i].x, R2[i].y), R1[i], S1[j], S2[j]);
}
bool intersected(int i) {
	for (int j=0; j<(int)S1.size(); ++j) {
		if (intersected_by(i, j)) {
			return true;
		}
	}
	return false;
}
class RectangleCrossings {
	public:
	vector <int> countAreas(vector <string> rectangles, vector <string> segments) {
		R1.clear();
		R2.clear();
		S1.clear();
		S2.clear();
		for (int i=0; i<(int)rectangles.size(); ++i) {
			int x1, y1, x2, y2;
			istringstream is(rectangles[i]);
			is >> x1 >> y1 >> x2 >> y2;
			R1.push_back(point(x1, y1));
			R2.push_back(point(x2, y2));
		}

		for (int i=0; i<(int)segments.size(); ++i) {
			int x1, y1, x2, y2;
			istringstream is(segments[i]);
			is >> x1 >> y1 >> x2 >> y2;
			S1.push_back(point(x1, y1));
			S2.push_back(point(x2, y2));
		}

		vector<int> status(R1.size(), 0);
		for (int i=0; i<(int)R1.size(); ++i) {
			if (contains(i)) {
				status[i] = 1;
			}
		}

		for (int i=0; i<(int)R1.size(); ++i) {
			if (status[i]==0 && intersected(i)) {
				status[i] = 2;
			}
		}

		vector<int> sol(2, 0);
		for (int i=0; i<(int)status.size(); ++i) {
			if (status[i] != 0) {
				sol[status[i]-1] += area(i);
			}
		}

		return sol;
	}







   
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"-1000 -1000 1000 1000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"-525 245 222 243"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4000000, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, countAreas(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"1 1 2 2", "1 4 2 5", "5 5 6 7", "7 7 9 9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"1 2 1 5"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 2 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, countAreas(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"1 1 3 3", "4 4 5 5", "6 6 7 7", "8 8 9 9", "51 22 344 352", "-124 -235 -12 -1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"-100 -2 300 300"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {122898, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, countAreas(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"1 1 3 3", "4 4 5 5", "6 6 7 7", "8 8 9 9", "51 22 344 352", "-124 -235 -12 -1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"-104 -103 202 201"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {122898, 7 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, countAreas(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"-891 -869 -853 -842", "-857 -399 -744 -231", "-910 -55 -856 36", "-844 287 -749 548", "-809 627 -782 954",
"-704 -803 -641 -663", "-684 -330 -558 -268", "-702 -40 -545 98", "-660 386 -528 586", "-697 855 -571 962",
"-414 -678 -168 -648", "-401 -559 -383 -441", "-387 5 -263 51", "-389 220 -194 448", "-361 673 -175 753",
"68 -912 95 -742", "-24 -521 24 -227", "30 -70 38 -2", "-111 297 14 356", "7 797 27 809", "368 -709 418 -614",
"247 -453 344 -251", "385 -111 417 -33", "275 202 290 421", "265 604 278 921", "524 -861 655 -640",
"555 -336 576 -305", "429 28 578 35", "480 324 704 520", "444 632 665 842", "932 -954 981 -931",
"930 -537 939 -455", "735 -81 787 192", "830 316 869 589", "808 629 971 666"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"-898 -383 126 12", "283 -716 545 -918", "-299 333 54 138", "-901 129 706 488", "-8 690 -290 955",
"-590 -771 476 257", "-528 -518 651 -139", "-984 -848 -380 459", "-358 924 31 -617", "817 -904 -208 -401",
"-657 -211 275 -407", "-427 -699 -460 876", "403 -612 -675 563", "-782 -197 845 816", "-492 -771 -342 -83",
"-650 -208 393 -614", "-67 -290 135 -610", "68 650 -366 560", "-482 608 -525 516", "548 460 -95 -436",
"461 -457 -491 -846", "-672 728 -764 548", "-301 633 -613 278", "-496 126 940 576", "-350 -378 -671 1000",
"148 82 275 211", "815 872 -810 -362", "160 -367 -754 569", "-721 941 -405 -57", "-792 582 804 563",
"-934 -115 -641 -737"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {126942, 241757 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, countAreas(Arg0, Arg1)); }

// END CUT HERE
 
};

// BEGIN CUT HERE 
int main()
    {
    RectangleCrossings ___test; 
    ___test.run_test(-1); 
    } 
// END CUT HERE

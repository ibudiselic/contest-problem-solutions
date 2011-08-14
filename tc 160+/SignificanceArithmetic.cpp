#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

vector<string> cutUp(const string &s, const string &delim=" ") {
	int lastPos = 0, pos = 0;
	vector<string> ret;

	while (pos+delim.size() <= s.size()) {
		if (s.substr(pos, delim.size()) == delim) {
			ret.push_back(s.substr(lastPos, pos-lastPos));

			pos += (int)delim.size()-1;
			lastPos = pos+1;
		}
		++pos;
	}

	if (lastPos < (int)s.size())
		ret.push_back(s.substr(lastPos));

	return ret;
}
string str(int x) {
	ostringstream os;
	os << x;
	return os.str();
}
class SignificanceArithmetic {
	public:
	string evaluate(string expression) {
		vector<string> t = cutUp(expression, "+");
		vector<string> x = cutUp(t[0], ".");
		vector<string> y = cutUp(t[1], ".");

		int a, b, c, d;
		int afterSig = 1234567890;
		sscanf(x[0].c_str(), "%d", &a);
		if (x.size() == 1) {
			b = 0;
			afterSig = 0;
		} else {
			sscanf(x[1].c_str(), "%d", &b);
			afterSig = min(afterSig, (int)x[1].size());
		}

		sscanf(y[0].c_str(), "%d", &c);
		if (y.size() == 1) {
			d = 0;
			afterSig = 0;
		} else {
			sscanf(y[1].c_str(), "%d", &d);
			afterSig = min(afterSig, (int)y[1].size());
		}

		string endPart;
		if (afterSig == 0) {
			if (x.size()==2 && y.size()==1)
				y.push_back(string());
			if (y.size()==2 && x.size()==1)
				x.push_back(string());
		}

		bool haveUnitCarry = false;
		if (x.size() == 2) {
			while (x[1].size() > y[1].size())
				y[1] += '0';
			while (y[1].size() > x[1].size())
				x[1] += '0';

			endPart.assign(x[1].size(), ' ');
			bool haveCarry = 0;
			for (int pos=(int)endPart.size()-1; pos>=0; --pos) {
				int d = x[1][pos]+y[1][pos] + haveCarry - 2*int('0');
				haveCarry = (d>9);
				endPart[pos] = d%10 + '0';
			}
			haveUnitCarry = haveCarry;
		}
		int front = a+c+haveUnitCarry;
		if (afterSig == 0) {
			if (endPart.size() == 0) {
				return str(front);
			} else {
				if (endPart[0] < '5')
					return str(front);
				else if (endPart[0] > '5')
					return str(front+1);
				else {
					bool hasNonzero = false;
					for (int i=1; i<(int)endPart.size(); ++i)
						hasNonzero |= (endPart[i]!='0');
					if (hasNonzero || (front+1)%2==0)
						return str(front+1);
					else
						return str(front);
				}
			}
		} else {
			if (afterSig == (int)endPart.size())
				return str(front) + '.' + endPart;
			if (endPart[afterSig] < '5') {
				return str(front) + '.' + endPart.substr(0, afterSig);
			} else if (endPart[afterSig] > '5') {
				bool haveCarry = true;
				for (int i=afterSig-1; i>=0; --i) {
					int d = (endPart[i]-'0' + haveCarry);
					haveCarry = (d>9);
					endPart[i] = d%10 + '0';
				}
				return str(front+haveCarry) + '.' + endPart.substr(0, afterSig);
			} else {
				bool hasNonzero = false;
				for (int i=afterSig+1; i<(int)endPart.size(); ++i)
					hasNonzero |= (endPart[i]!='0');
				if (hasNonzero || endPart[afterSig-1]%2==1) {
					bool haveCarry = true;
					for (int i=afterSig-1; i>=0; --i) {
						int d = (endPart[i]-'0' + haveCarry);
						haveCarry = (d>9);
						endPart[i] = d%10 + '0';
					}
					return str(front+haveCarry) + '.' + endPart.substr(0, afterSig);
				} else {
					return str(front) + '.' + endPart.substr(0, afterSig);
				}
			}
		}
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "2+2"; string Arg1 = "4"; verify_case(0, Arg1, evaluate(Arg0)); }
	void test_case_1() { string Arg0 = "1.234+0.000"; string Arg1 = "1.234"; verify_case(1, Arg1, evaluate(Arg0)); }
	void test_case_2() { string Arg0 = "1.234+0.006"; string Arg1 = "1.240"; verify_case(2, Arg1, evaluate(Arg0)); }
	void test_case_3() { string Arg0 = "12.57+2.6"; string Arg1 = "15.2"; verify_case(3, Arg1, evaluate(Arg0)); }
	void test_case_4() { string Arg0 = "5.50005+0"; string Arg1 = "6"; verify_case(4, Arg1, evaluate(Arg0)); }
	void test_case_5() { string Arg0 = "2.5+2"; string Arg1 = "4"; verify_case(5, Arg1, evaluate(Arg0)); }
	void test_case_6() { string Arg0 = "0.00+000"; string Arg1 = "0"; verify_case(6, Arg1, evaluate(Arg0)); }
	void test_case_7() { string Arg0 = "983.17+76.8"; string Arg1 = "1060.0"; verify_case(7, Arg1, evaluate(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    SignificanceArithmetic ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

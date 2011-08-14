#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

template<class T>
string to_str(T x)
{
    string ret;
    ostringstream os(ret);

    os << x;
    return os.str();
}

vector<int> stack(80001, 0);
class QuiningTopCoder {
	public:
	int get(const vector<int> &a, int &sp) {
		if (sp==0)
			return 0;
		else return a[--sp];
	}
	string testCode(string s) {
		string res;
		int ip, sp, d, clock, m, a, b;
		int n = (int)s.size();
		bool multd = false;
		ip = sp = 0;
		d = 1;
		m = 0;

		for (clock=0; clock<=80000; ++clock) {
			if (multd)
				d /= 2;
			multd = false;
			if (isdigit(s[ip]))
				stack[sp++] = s[ip]-'0';
			else
				switch (s[ip]) {
					case '$':
						sp = (sp==0) ? (0):(sp-1);
						break;
					case ':':
						a = get(stack, sp);
						stack[sp++] = a; stack[sp++] = a;
						break;
					case 'W':
						a = get(stack, sp); b = get(stack, sp);
						stack[sp++] = a; stack[sp++] = b;
						break;
					case ',':
						a = get(stack, sp);
						res += s[abs(a)%n];
						++m;
						if (res[m-1] != s[m-1])
							return "MISMATCH "+to_str<int>(clock);
						else if (n==m)
							return "QUINES "+to_str<int>(clock);
						break;
					case '+':
						a = get(stack, sp); b = get(stack, sp);
						if (abs(a+b) > 1000000000)
							return "OVERFLOW "+to_str<int>(clock);
						else
							stack[sp++] = a+b;
						break;
					case '-':
						a = get(stack, sp); b = get(stack, sp);
						if (abs(a-b) > 1000000000)
							return "OVERFLOW "+to_str<int>(clock);
						else
							stack[sp++] = a-b;
						break;
					case '#':
						d *= 2;
						multd = true;
						break;
					case 'R':
						d *= -1;
						break;
					case 'S':
						a = get(stack, sp);
						if (a>0) stack[sp++] = 1;
						else stack[sp++] = -1;
						break;
					case '_':
						a = get(stack, sp);
						d = a%n;
						break;
					case 'J':
						a = get(stack, sp);
						ip = abs(a)%n;
						continue;
						break;
					case '@':
						return "BADEND "+to_str<int>(clock);
						break;
				}
			ip = (3*n+ip+d)%n;
		}
		return "TIMEOUT";
	}








// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = ","; string Arg1 = "QUINES 0"; verify_case(0, Arg1, testCode(Arg0)); }
	void test_case_1() { string Arg0 = "_"; string Arg1 = "TIMEOUT"; verify_case(1, Arg1, testCode(Arg0)); }
	void test_case_2() { string Arg0 = "1:+:1J"; string Arg1 = "OVERFLOW 147"; verify_case(2, Arg1, testCode(Arg0)); }
	void test_case_3() { string Arg0 = "0,1+:#@:$1J"; string Arg1 = "QUINES 91"; verify_case(3, Arg1, testCode(Arg0)); }
	void test_case_4() { string Arg0 = "0,1+::9W-9W-S1W1W:+2_J_@_@"; string Arg1 = "BADEND 437"; verify_case(4, Arg1, testCode(Arg0)); }
	void test_case_5() { string Arg0 = "#R,#:+1+:#,R#"; string Arg1 = "QUINES 97"; verify_case(5, Arg1, testCode(Arg0)); }
	void test_case_6() { string Arg0 = "R,#1+1:"; string Arg1 = "MISMATCH 7"; verify_case(6, Arg1, testCode(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
    {
    QuiningTopCoder ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

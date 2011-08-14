#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class HowEasy {
	public:
	int pointVal(string str) {
		int cnt = 0;
		int tot = 0;
		string s;

		istringstream is(str);

		while (is >> s) {
			bool word = true;
			int len = 0;
			for (int i=0; i<(int)s.size()-1; ++i, ++len)
				if (!isalpha(s[i])) {
					word = false;
					break;
				}
			if (s[s.size()-1]!='.') ++len;
			if (s.size()==1 && len==0) word = false;
			if (word) {
				tot += len;
				++cnt;
			}
		}
		if (cnt == 0) return 250;
		switch (tot/cnt) {
			case 0: case 1: case 2: case 3: return 250; break;
			case 4: case 5: return 500; break;
			default: return 1000; break;
		}
		return -1;
	}







   // *** WARNING *** No test cases defined for this problem
};

// BEGIN CUT HERE
int main()
    {
    HowEasy ___test;
    ___test.run_test(-1);
    }
// END CUT HERE

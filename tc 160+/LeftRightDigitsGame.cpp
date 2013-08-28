#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class LeftRightDigitsGame {
public:
    string minNumber(string digits) {
        int n = digits.size();
        string sol(n, ' ');
        int left = n;
        int right = n-1;
        int i = 0;
        while (left != 0) {
            for (int d=(i==0); d<10; ++d) {
                for (int pos=left-1; pos>=0; --pos) {
                    if (digits[pos]-'0' == d) {
                        sol[i] = digits[pos];
                        for (int j=left-1; j>pos; --j) {
                            sol[right--] = digits[j];
                        }
                        left = pos;
                        ++i;
                        goto NEXT;
                    }
                }
            }
            NEXT:;
        }

        return sol;
    }
};

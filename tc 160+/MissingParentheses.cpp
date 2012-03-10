#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class MissingParentheses {
public:
    int countCorrections(string par) {
        int bc = 0;
        int sol = 0;
        for (int i=0; i<(int)par.size(); ++i) {
            bc += (par[i]=='(') - (par[i]==')');
            if (bc < 0) {
                ++sol;
                bc = 0;
            }
        }
        return sol + bc;
    }
};

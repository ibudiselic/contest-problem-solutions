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

class PikachuEasy {
public:
    string check(string word) {
        int n = word.size();
        int at = 0;
        while (at < n) {
            if (word[at] == 'p') {
                if (at+1==n || word[at+1]!='i') {
                    return "NO";
                }
                at += 2;
            } else if (word[at] == 'k') {
                if (at+1==n || word[at+1]!='a') {
                    return "NO";
                }
                at += 2;
            } else {
                if (at+2>=n || word[at]!='c' || word[at+1]!='h' || word[at+2]!='u') {
                    return "NO";
                }
                at += 3;
            }
        }
        return "YES";
    }
};

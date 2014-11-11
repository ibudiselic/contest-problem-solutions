//# implementation, dates
//# => trivial
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool is_leap(int y) {
    return (y%4==0 && y%100!=0) || y%400==0;
}

int ndays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string invalid = "Invalid";
const string male = "Male";
const string female = "Female";
class IDNumberVerification {
public:
    string verify(string id, vector <string> regionCodes) {
        if (find(begin(regionCodes), end(regionCodes), id.substr(0, 6)) == end(regionCodes)) return invalid;
        int y, m, d;
        sscanf(id.substr(6, 8).c_str(), "%4d%2d%2d", &y, &m, &d);
        if (m<1 || m>12) return invalid;
        int maxday = ndays[m-1];
        if (m==2 && is_leap(y)) maxday = 29;
        if (d<1 || d>maxday) return invalid;
        if (y<1900 || y>2011) return invalid;

        int code;
        sscanf(id.substr(14, 3).c_str(), "%3d", &code);
        if (code == 0) return invalid;

        int hash = 0;
        int p2 = 2;
        for (int i=16; i>=0; --i) {
            hash = (hash+(id[i]-'0')*p2)%11;
            p2 = p2*2%11;
        }
        hash = (12-hash)%11;
        if (hash==10 && id[17]!='X') return invalid;
        if (hash!=10 && id[17]!=char('0'+hash)) return invalid;

        return code%2==0 ? female : male;
    }
};

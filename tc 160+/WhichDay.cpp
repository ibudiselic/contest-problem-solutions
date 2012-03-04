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
#include <set>

using namespace std;

string days[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
class WhichDay {
public:
    string getDay(vector <string> notOnThisDay) {
        set<string> n(notOnThisDay.begin(), notOnThisDay.end());
        set<string> d(days, days+7);
        vector<string> v;
        
        set_difference(d.begin(), d.end(), n.begin(), n.end(), back_inserter(v));
        return v[0];
    }
};

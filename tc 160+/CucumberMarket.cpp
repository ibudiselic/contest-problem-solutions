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

class CucumberMarket {
public:
    string check(vector <int> price, int budget, int k) {
        sort(price.begin(), price.end(), greater<int>());
        return accumulate(price.begin(), price.begin()+k, 0) <= budget ? "YES" : "NO";
    }
};

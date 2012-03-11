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

class RowAndManyCoins {
public:
    string getWinner(string cells) {
        if (cells[0]=='A' || cells[cells.size()-1]=='A') {
            return "Alice";
        } else {
            return "Bob";
        }
    }
};

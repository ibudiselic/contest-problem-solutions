//# case
//# => work small cases on paper
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

class KnightCircuit2 {
public:
    int maxSize(int w, int h) {
        if (w > h) {
            swap(w, h);
        }
        if (w==1 || h<=2) return 1;
        if (w == 2) return (h+1)/2;
        if (w==3 && h==3) return 8;
        return h*w;
    }
};

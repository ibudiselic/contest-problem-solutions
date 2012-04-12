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

class EllysDirectoryListing {
public:
    vector <string> getFiles(vector <string> files) {
        int n = files.size();
        if (files[n-1]=="." && files[n-2]==".." ||
            files[n-2]=="." && files[n-1]=="..") {
            return files;
        }
        int p = find(files.begin(), files.end(), string(1, '.')) - files.begin();
        int q = find(files.begin(), files.end(), string(2, '.')) - files.begin();
        swap(files[min(p, q)], files.back());
        if (files[n-1]=="." && files[n-2]==".." ||
            files[n-2]=="." && files[n-1]=="..") {
            return files;
        }
        p = find(files.begin(), files.end(), string(1, '.')) - files.begin();
        q = find(files.begin(), files.end(), string(2, '.')) - files.begin();
        swap(files[min(p, q)], files[n-2]);
        return files;
    }
};

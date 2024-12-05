#include "iostream"
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <map>
#include <ostream>
#include <sched.h>
#include <sstream>
#include <string>
#include <vector>

bool descending(int x, int j) { return x > j; }

using namespace std;

int main()
{
    map<int, vector<int>> levels;

    fstream input("input.txt");

    int lineNum = 0;
    string line;
    while (getline(input, line)) {
        stringstream ss(line);
        int number;
        while (ss >> number) {
            levels[lineNum].push_back(number);
        }
        lineNum++;
    }
    map<int, vector<int>> safes = levels;
    for (pair pair : levels) {
        vector<int> sector = pair.second;
        vector<int> rev_sector = pair.second;
        vector<int>& original = pair.second;
        int key = pair.first;
        sort(sector.begin(), sector.end());
        sort(rev_sector.begin(), rev_sector.end(), descending);
        int sim_asc = 0;
        int sim_des = 0;
        bool tolerated = false;
        for (int num : original) {
            cout << num;
        }
        cout << endl;
        for (int i = 0; i < original.size(); i++) {
            if (original.at(i) == sector.at(i)) {
                sim_asc++;
            }
            if (original.at(i) == rev_sector.at(i)) {
                sim_des++;
            }
        }
        cout << sim_asc << " " << sim_des << endl;
        if ((original.size() == sim_asc || original.size() == sim_des)) {
            for (int i = 0; i < original.size() - 1; i++) {
                int difference = abs(original[i] - original[i + 1]);
                if (difference > 3 || difference == 0) {
                    safes.erase(key);
                    break;
                }
            }
        } else {
            safes.erase(key);
        }
    }
    long validCount = 0;
    for (pair pair : safes) {
        vector<int>& original = pair.second;
        validCount++;
    }

    cout << endl
         << validCount;
    return 0;
}

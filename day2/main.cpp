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

void checkNumber(pair<int, vector<int>>& values, map<int, vector<int>>& safes, bool tolerated = false)
{
    vector<int> sector = values.second;
    vector<int> rev_sector = values.second;
    vector<int>& original = values.second;

    const int key = values.first;

    sort(sector.begin(), sector.end());
    sort(rev_sector.begin(), rev_sector.end(), descending);

    int sim_asc = 0;
    int sim_des = 0;

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

    bool prefAsc = false;
    if (sim_asc > sim_des) {
        prefAsc = true;
    }

    cout << sim_asc << " " << sim_des << endl;
    if ((original.size() == sim_asc || original.size() == sim_des)) {
        for (int i = 0; i < original.size() - 1; i++) {
            int difference = abs(original[i] - original[i + 1]);
            if (difference > 3 || difference == 0) {
                /*if (tolerated)*/
                safes.erase(key);
                /*else {*/
                /*cout << "difference case, tolerated and deleted : " << original[i] << endl;*/
                /*    original.erase(original.begin() + i);*/
                /*    tolerated = true;*/
                /*    checkNumber(values, safes, tolerated);*/
                /*}*/
                break;
            }
        }
        /*} else if ((sim_asc == original.size() - 2 || sim_des == original.size() - 2)) {*/
        /*    tolerated = true;*/
        /*    for (int i = 0; i < original.size(); i++) {*/
        /*        if (prefAsc) {*/
        /*            if (original.at(i) != sector.at(i)) {*/
        /*                cout << "sorting case, tolerated and deleted : " << original[i] << endl;*/
        /*                original.erase(original.begin() + i);*/
        /*                checkNumber(values, safes, tolerated);*/
        /*                break;*/
        /*            }*/
        /*        } else {*/
        /*            if (original.at(i) != rev_sector.at(i)) {*/
        /*                cout << "sorting case, tolerated and deleted : " << original[i] << endl;*/
        /*                original.erase(original.begin() + i);*/
        /*                checkNumber(values, safes, tolerated);*/
        /*                break;*/
        /*            }*/
        /*        }*/
        /*    }*/

    } else {
        safes.erase(key);
    }
}

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
    for (pair<int, vector<int>> values : levels) {
        checkNumber(values, safes);
    }

    long validCount = 0;
    for (pair pair : safes) {
        cout << endl;

        for (int num : pair.second) {
            cout << num;
        }

        cout << endl;
        validCount++;
    }

    cout << endl
         << validCount;
    return 0;
}

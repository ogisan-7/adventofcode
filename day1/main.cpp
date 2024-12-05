#include <algorithm>
#include <cstddef>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {

  const int N = 1000;
  vector<int> a, b;
  map<int, int> frequency;

  int x, y;
  for (int i = 0; i < N; i++) {

    cin >> x >> y;

    a.push_back(x);
    b.push_back(y);
  }

  for (int num : b) {

    if (find(a.begin(), a.end(), num) != a.end()) {
      pair<map<int, int>::iterator, bool> ret;
      ret = frequency.insert(pair<int, int>(num, 1));

      if (ret.second == false) {
        frequency[num]++;
      }
    }
  }

  for (pair pair : frequency) {
    cout << pair.first << ' ' << pair.second << "\n";
  }

  long long sum = 0;
  for (int num : a) {
    if (frequency.find(num) != frequency.end()) {
      cout << num << "*" << frequency[num] << "\n";

      sum += num * frequency[num];
    }
  }

  cout << "The number is \n " << sum << "\n";

  // sort(a.begin(), a.end());
  // sort(b.begin(), b.end());

  return 0;
}

#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <regex>
#include <string>

bool _DEMO = false;

using namespace std;

int main()
{
    fstream inputFile;
    cout << "working on it" << endl;

    if (_DEMO)
        inputFile.open("demo_input.txt");
    else
        inputFile.open("input.txt");

    string input_str, tempstr;

    while (getline(inputFile, tempstr)) {
        input_str.append(tempstr);
    }

    smatch sm;

    regex expression("mul[(](\\d+),(\\d+)[)]");
    regex do_exp("(do[(][)])");
    regex dont_exp("(don't[(][)])");

    string rev_string(input_str.rbegin(), input_str.rend());

    size_t last_mul_pos = 0;
    int sum = 0;

    bool allowed = true;

    for (int i = 0; i < input_str.length(); i++) {
        char curr_char = input_str[i];

        if (curr_char == 'd') {
            if ((regex_search(input_str.cbegin() + i, input_str.cbegin() + i + 4, sm, do_exp))) {
                cout << sm.str() << endl;
                allowed = true;
            } else if ((regex_search(input_str.cbegin() + i, input_str.cbegin() + i + 7, sm, dont_exp))) {
                cout << sm.str() << endl;
                allowed = false;
            }
        }

        if (curr_char == 'm') {
            if ((regex_search(input_str.cbegin() + i, input_str.cbegin() + i + 12, sm, expression)) && allowed) {
                cout << sm.str() << endl;
                sum += stoi(sm[1]) * stoi(sm[2]);
            }
        }
    }

    cout << sum << endl;
    return 0;
}

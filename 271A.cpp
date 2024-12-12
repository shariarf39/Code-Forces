#include<iostream>
#include<set>
#include<string>
using namespace std;

bool hasDistinctDigits(int year) {
    string yearStr = to_string(year);
    set<char> digits(yearStr.begin(), yearStr.end());
    return digits.size() == yearStr.size();
}

int nextDistinctYear(int year) {
    while (true) {
        year++;
        if (hasDistinctDigits(year)) {
            return year;
        }
    }
}

int main() {
    int y;
    cin >> y;
    cout << nextDistinctYear(y) << endl;
    return 0;
}
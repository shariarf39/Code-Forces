#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> levels;

    int a, b;
    cin >> a;
    for (int i = 0; i < a; i++) {
        int level;
        cin >> level;
        levels.insert(level);
    }

    cin >> b;
    for (int i = 0; i < b; i++) {
        int level;
        cin >> level;
        levels.insert(level);
    }

    // Check if all levels (1 to n) are in the set
    if ((int)levels.size() == n) {
        cout << "I become the guy." << endl;
    } else {
        cout << "Oh, my keyboard!" << endl;
    }

    return 0;
}

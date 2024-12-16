#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> groups(n);
    for (int i = 0; i < n; ++i) {
        cin >> groups[i];
    }

    int count[5] = {0};
    for (int i = 0; i < n; ++i) {
        count[groups[i]]++;
    }

    int taxis = count[4]; 

   
    int minThreeOne = min(count[3], count[1]);
    taxis += minThreeOne;
    count[3] -= minThreeOne;
    count[1] -= minThreeOne;

 
    taxis += count[3];


    taxis += count[2] / 2;
    count[2] %= 2;

 
    if (count[2] > 0) {
        taxis++;
        count[1] -= min(2, count[1]);
    }

    taxis += (count[1] + 3) / 4;

    cout << taxis << endl;

    return 0;
}
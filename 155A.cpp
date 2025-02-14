#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> points(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> points[i];
    }
    
    int amazingCount = 0;
    int maxPoints = points[0];
    int minPoints = points[0];
    
    for (int i = 1; i < n; ++i) {
        if (points[i] > maxPoints) {
            amazingCount++;
            maxPoints = points[i];
        } else if (points[i] < minPoints) {
            amazingCount++;
            minPoints = points[i];
        }
    }
    
    cout << amazingCount << endl;
    return 0;
}
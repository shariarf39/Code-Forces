#include <iostream>
#include <algorithm>

int main() {
    int x1, x2, x3;
    std::cin >> x1 >> x2 >> x3;

    // Sort the coordinates
    int arr[3] = {x1, x2, x3};
    std::sort(arr, arr + 3);

    // The optimal meeting point is the middle point after sorting
    int meeting_point = arr[1];

    // Calculate the total distance
    int total_distance = (arr[2] - meeting_point) + (meeting_point - arr[0]);

    std::cout << total_distance << std::endl;

    return 0;
}
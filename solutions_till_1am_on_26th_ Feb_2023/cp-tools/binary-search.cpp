#include <iostream>
#include <vector>
#include <algorithm>

int bS(std::vector<int>& vect, int target) {
    int left = 0;
    int right = vect.size() - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (vect[mid] == target) {
            return mid;
        }

        if (vect[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if(left < vect.size())
        return left;
    
    return left - 1;
}

int main() {
    std::vector<int> vec = {1, 3, 5, 7, 8, 11, 13};
    int target = 1;
    std::sort(vec.begin(), vec.end()); // Make sure the vector is sorted

    int index = bS(vec, target);
    std::cout << "Index of closest greater value: " << index << std::endl;

    return 0;
}

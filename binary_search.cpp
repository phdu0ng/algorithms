#include <iostream>
#include <vector>

int binary_search(const std::vector<int>& v, int target) {
    int low = 0;
    int high = static_cast<int>(v.size()) - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (v[mid] == target) {
            return mid;
        } else if (v[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    std::vector<int> values{1, 2, 2, 2, 3, 5, 8};

    std::cout << "target 2: " << binary_search(values, 2) << '\n';
    std::cout << "target 5: " << binary_search(values, 5) << '\n';
    std::cout << "target 4: " << binary_search(values, 4) << '\n';
    std::cout << "empty: " << binary_search({}, 2) << '\n';

    return 0;
}

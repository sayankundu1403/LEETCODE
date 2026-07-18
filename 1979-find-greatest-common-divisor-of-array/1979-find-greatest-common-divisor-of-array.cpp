#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int findGCD(std::vector<int>& nums) {
        // Find the minimum and maximum elements in the vector
        auto [min_it, max_it] = std::minmax_element(nums.begin(), nums.end());
        
        // Compute and return the Greatest Common Divisor
        return std::gcd(*min_it, *max_it);
    }
};

class Solution {
public:
    int minMoves(vector<int>& nums) {
        // Calculate the sum of all elements and find the minimum element
        int sum = 0;
        int minValue = INT_MAX;  // Initialize with maximum integer value
      
        // Iterate through all numbers to find sum and minimum
        for (int num : nums) {
            sum += num;
            minValue = min(minValue, num);
        }
      
        // The minimum moves needed is the difference between:
        // - current sum of all elements
        // - sum if all elements were equal to the minimum value
        // This equals: sum - (minValue * n)
        return sum - minValue * nums.size();
    }
};

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        const int INF = INT_MAX;
        int minSum = INF;
      
        // Iterate through all possible starting positions
        for (int start = 0; start < n; ++start) {
            int currentSum = 0;
          
            // Extend the subarray from the current starting position
            for (int end = start; end < n; ++end) {
                currentSum += nums[end];
                int subarrayLength = end - start + 1;
              
                // Check if the subarray meets the criteria:
                // 1. Length is within the range [l, r]
                // 2. Sum is positive
                if (subarrayLength >= l && subarrayLength <= r && currentSum > 0) {
                    minSum = min(minSum, currentSum);
                }
            }
        }
      
        // Return -1 if no valid subarray was found, otherwise return the minimum sum
        return minSum == INF ? -1 : minSum;
    }
};

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // Sort the array to find the median
        sort(nums.begin(), nums.end());
      
        // Get the median element (middle element for odd size, upper middle for even size)
        int median = nums[nums.size() / 2];
      
        // Calculate the total number of moves needed
        int totalMoves = 0;
      
        // Sum up the absolute differences between each element and the median
        for (int& num : nums) {
            totalMoves += abs(num - median);
        }
      
        return totalMoves;
    }
};

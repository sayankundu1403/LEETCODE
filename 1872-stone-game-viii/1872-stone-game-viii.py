class Solution:
    def stoneGameVIII(self, stones: list[int]) -> int:
        n = len(stones)
        
        # 1. Compute the prefix sums correctly
        pref = [0] * n
        pref[0] = stones[0]
        for i in range(1, n):
            pref[i] = pref[i-1] + stones[i]
            
        # 2. Base case: If forced to take all stones up to index n-1, 
        # the next player gets 0 points. Net difference = pref[-1] - 0
        dp = pref[-1]
        
        # 3. Iterate backwards from index n-2 down to index 1 (since x >= 2 stones)
        for i in range(n - 2, 0, -1):
            dp = max(dp, pref[i] - dp)
            
        return dp

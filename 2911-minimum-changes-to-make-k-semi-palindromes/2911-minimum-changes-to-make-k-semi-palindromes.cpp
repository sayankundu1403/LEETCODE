class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
      
        // minChanges[i][j] = minimum changes to make substring s[i-1...j-1] a semi-palindrome
        // A semi-palindrome is a string that becomes palindromic when read with period d
        int minChanges[n + 1][n + 1];
      
        // dp[i][j] = minimum changes to partition s[0...i-1] into j semi-palindromes
        int dp[n + 1][k + 1];
      
        // Initialize with large values (infinity)
        memset(minChanges, 0x3f, sizeof(minChanges));
        memset(dp, 0x3f, sizeof(dp));
      
        // Base case: empty string with 0 partitions needs 0 changes
        dp[0][0] = 0;
      
        // Precompute minimum changes for all substrings to become semi-palindromes
        for (int start = 1; start <= n; ++start) {
            for (int end = start; end <= n; ++end) {
                int length = end - start + 1;
              
                // Try all possible divisors of length as the period
                for (int period = 1; period < length; ++period) {
                    if (length % period == 0) {
                        int changesNeeded = 0;
                      
                        // Check pairs of characters that should be equal in a semi-palindrome
                        // with the given period
                        for (int leftIdx = 0; leftIdx < length; ++leftIdx) {
                            // Calculate corresponding right index for semi-palindrome check
                            int rightIdx = (length / period - 1 - leftIdx / period) * period + leftIdx % period;
                          
                            // Only check each pair once (avoid double counting)
                            if (leftIdx >= rightIdx) {
                                break;
                            }
                          
                            // Count mismatches that need to be changed
                            if (s[start - 1 + leftIdx] != s[start - 1 + rightIdx]) {
                                ++changesNeeded;
                            }
                        }
                      
                        // Update minimum changes for this substring
                        minChanges[start][end] = min(minChanges[start][end], changesNeeded);
                    }
                }
            }
        }
      
        // Dynamic programming to find minimum changes for k partitions
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                // Try all possible positions for the (j-1)th partition endpoint
                for (int prevEnd = 0; prevEnd < i - 1; ++prevEnd) {
                    // dp[i][j] = min(previous j-1 partitions + cost of jth partition)
                    dp[i][j] = min(dp[i][j], dp[prevEnd][j - 1] + minChanges[prevEnd + 1][i]);
                }
            }
        }
      
        // Return minimum changes to partition entire string into k semi-palindromes
        return dp[n][k];
    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
        int sourceLen = s.size();
        int targetLen = t.size();
      
        // dp[i][j] represents the number of distinct subsequences of s[0...i-1] that equals t[0...j-1]
        // Using unsigned long long to handle potential overflow for large results
        unsigned long long dp[sourceLen + 1][targetLen + 1];
        memset(dp, 0, sizeof(dp));
      
        // Base case: empty target string can be matched by any source string in exactly one way (delete all characters)
        for (int i = 0; i <= sourceLen; ++i) {
            dp[i][0] = 1;
        }
      
        // Fill the dp table
        for (int i = 1; i <= sourceLen; ++i) {
            for (int j = 1; j <= targetLen; ++j) {
                // Case 1: Skip the current character in source string
                // The number of ways remains the same as without this character
                dp[i][j] = dp[i - 1][j];
              
                // Case 2: If characters match, we can also use this character
                // Add the number of ways when both strings exclude current characters
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }
      
        // Return the number of distinct subsequences of entire s that equals entire t
        return dp[sourceLen][targetLen];
    }
};

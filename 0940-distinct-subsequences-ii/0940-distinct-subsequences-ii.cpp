class Solution {
public:
    const int MOD = 1e9 + 7;

    int distinctSubseqII(string s) {
        // dp[i] stores the number of distinct subsequences ending with character ('a' + i)
        vector<long> dp(26, 0);
      
        // Process each character in the string
        for (char& ch : s) {
            int charIndex = ch - 'a';
          
            // When we add current character to all existing subsequences:
            // - We can append it to all existing subsequences (sum of all dp values)
            // - We can also create a new subsequence with just this character (hence +1)
            // This gives us the new count of subsequences ending with current character
            dp[charIndex] = accumulate(dp.begin(), dp.end(), 1L) % MOD;
        }
      
        // Return the total count of all distinct subsequences
        // Sum up all subsequences ending with each character
        return accumulate(dp.begin(), dp.end(), 0L) % MOD;
    }
};

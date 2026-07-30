class Solution {
public:
    int minimumPushes(string word) {
        int pushes = 0;
        int n = word.length();
        
        for (int i = 0; i < n; i++) {
            // (i / 8) + 1 calculates the cost multiplier for the current letter
            pushes += (i / 8) + 1;
        }
        
        return pushes;
    }
};
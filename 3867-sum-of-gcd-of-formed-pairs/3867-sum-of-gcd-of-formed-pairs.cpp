class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref;
        pref.reserve(n);

        int mx = 0;
        for (int x : nums) {
            mx = max(mx, x);
            pref.push_back(gcd(x, mx));
        }

        sort(pref.begin(), pref.end());

        long long ans = 0;
        for (int i = 0; i < n / 2; i++) {
            ans += gcd(pref[i], pref[n - 1 - i]);
        }

        return ans;
    }
};
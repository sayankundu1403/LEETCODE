class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);

        for (int x : nums)
            freq[x]++;

        // cnt[i] = numbers divisible by i
        vector<long long> cnt(mx + 1, 0);

        for (int i = 1; i <= mx; i++)
            for (int j = i; j <= mx; j += i)
                cnt[i] += freq[j];

        // exact gcd count
        vector<long long> exact(mx + 1, 0);

        for (int i = mx; i >= 1; i--) {

            exact[i] = cnt[i] * (cnt[i] - 1) / 2;

            for (int j = i * 2; j <= mx; j += i)
                exact[i] -= exact[j];
        }

        // prefix
        vector<long long> pref(mx + 1, 0);

        for (int i = 1; i <= mx; i++)
            pref[i] = pref[i - 1] + exact[i];

        vector<int> ans;

        for (long long q : queries) {

            int g = lower_bound(pref.begin() + 1, pref.end(), q + 1) - pref.begin();

            ans.push_back(g);
        }

        return ans;
    }
};
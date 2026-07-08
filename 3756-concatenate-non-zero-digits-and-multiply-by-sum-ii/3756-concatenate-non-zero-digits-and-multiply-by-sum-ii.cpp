class Solution {
public:
    static const int MOD = 1000000007;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size();

        vector<int> digits;
        vector<int> pos;

        vector<int> first(n), last(n);

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                digits.push_back(s[i] - '0');
                pos.push_back(i);
            }
        }

        int m = digits.size();

        if (m == 0)
            return vector<int>(queries.size(), 0);

        vector<int> idx(n, -1);

        for (int i = 0; i < m; i++)
            idx[pos[i]] = i;

        // first non-zero at or after i
        int cur = m;
        for (int i = n - 1; i >= 0; i--) {
            if (idx[i] != -1)
                cur = idx[i];
            first[i] = cur;
        }

        // last non-zero at or before i
        cur = -1;
        for (int i = 0; i < n; i++) {
            if (idx[i] != -1)
                cur = idx[i];
            last[i] = cur;
        }

        vector<long long> pow10(m + 1), invPow10(m + 1);

        pow10[0] = 1;
        for (int i = 1; i <= m; i++)
            pow10[i] = pow10[i - 1] * 10 % MOD;

        long long inv10 = modPow(10, MOD - 2);

        invPow10[0] = 1;
        for (int i = 1; i <= m; i++)
            invPow10[i] = invPow10[i - 1] * inv10 % MOD;

        vector<long long> prefNum(m + 1, 0);
        vector<int> prefSum(m + 1, 0);

        for (int i = 0; i < m; i++) {
            prefNum[i + 1] = (prefNum[i] * 10 + digits[i]) % MOD;
            prefSum[i + 1] = prefSum[i] + digits[i];
        }

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            int L = first[l];

            if (L == m) {
                ans.push_back(0);
                continue;
            }

            int R = last[r];

            if (R < L) {
                ans.push_back(0);
                continue;
            }

            int len = R - L + 1;

            long long x =
                (prefNum[R + 1] -
                 prefNum[L] * pow10[len] % MOD +
                 MOD) % MOD;

            long long sum = prefSum[R + 1] - prefSum[L];

            ans.push_back(x * sum % MOD);
        }

        return ans;
    }
};
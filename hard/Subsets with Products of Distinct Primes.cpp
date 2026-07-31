class Solution {
public:
    using ll = long long;
    static const int MOD = 1e9 + 7;

    vector<vector<int>> pfactors;
    vector<int> pos;
    vector<int> issafe;
    vector<vector<int>> dp;

    ll mod_pow(ll a, ll b, ll m) {
        ll res = 1;
        while (b > 0) {
            if (b & 1) res = (res * a) % m;
            a = (a * a) % m;
            b >>= 1;
        }
        return res;
    }

    int helper(int in, int mask, vector<int> &freq) {
        if (in >= 31) return 1;

        if (dp[in][mask] != -1) return dp[in][mask];

        ll op1 = helper(in + 1, mask, freq);
        ll op2 = 0;

        if (freq[in] && issafe[in]) {
            int nmask = mask;
            bool flag = 0;

            for (auto x : pfactors[in]) {
                if (mask & (1 << pos[x])) {
                    flag = 1;
                    break;
                }
                nmask |= (1 << pos[x]);
            }

            if (!flag) {
                op2 = 1LL * freq[in] * helper(in + 1, nmask, freq);
                op2 %= MOD;
            }
        }

        return dp[in][mask] = (op1 + op2) % MOD;
    }

    int countSubsets(vector<int> &arr) {
        int mx = 31;
        pfactors = vector<vector<int>>(mx);
        vector<int> prime;

        for (int i = 2; i < mx; i++) {
            if (pfactors[i].empty()) {
                prime.push_back(i);
                for (int j = i; j < mx; j += i)
                    pfactors[j].push_back(i);
            }
        }

        pos = vector<int>(mx, -1);
        for (int i = 0; i < prime.size(); i++)
            pos[prime[i]] = i;

        issafe = vector<int>(mx, 1);
        for (int i = 2; i < mx; i++) {
            for (auto x : pfactors[i]) {
                if (i % (x * x) == 0) {
                    issafe[i] = 0;
                    break;
                }
            }
        }

        vector<int> freq(mx, 0);
        for (auto x : arr) freq[x]++;

        dp = vector<vector<int>>(31, vector<int>(1 << prime.size(), -1));

        ll ans = helper(2, 0, freq);
        ans = (ans - 1 + MOD) % MOD;
        ans = (ans * mod_pow(2, freq[1], MOD)) % MOD;

        return ans;
    }
};

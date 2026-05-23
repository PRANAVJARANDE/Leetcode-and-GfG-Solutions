class Solution {
public:
    int minChanges(vector<int>& nums, int k) 
    {
        const int MAXX = 1024;
        const int INF = 1e9;

        int n = nums.size();

        vector<int> dp(MAXX, INF);
        dp[0] = 0;

        for(int g = 0; g < k; g++)
        {
            unordered_map<int,int> freq;
            int cnt = 0;

            for(int i = g; i < n; i += k)
            {
                freq[nums[i]]++;
                cnt++;
            }

            int mn = *min_element(dp.begin(), dp.end());

            vector<int> ndp(MAXX, mn + cnt);

            for(auto &[val, f] : freq)
            {
                int cost = cnt - f;

                for(int xr = 0; xr < MAXX; xr++)
                {
                    ndp[xr ^ val] =min(ndp[xr ^ val],dp[xr]+ cost);
                }
            }
            dp = ndp;
        }
        return dp[0];
    }
};

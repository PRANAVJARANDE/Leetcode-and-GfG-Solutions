class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) 
    {
        int ans=0;
        sort(costs.begin(),costs.end());
        for(auto x:costs)
        {
            if(x<=coins)
            {
                coins-=x;
                ans++;
            }
            else break;
        }
        return ans;
    }
};

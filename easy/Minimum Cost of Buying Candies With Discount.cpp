class Solution {
public:

    int minimumCost(vector<int>& cost) 
    {
        sort(cost.begin(),cost.end(),greater<int>());
        int ans=0;
        int n=cost.size();
        for(int i=0;i<n;i+=3)
        {
            ans+=cost[i];
            if(i+1<n)ans+=cost[i+1];
        }
        return ans;
    }
};

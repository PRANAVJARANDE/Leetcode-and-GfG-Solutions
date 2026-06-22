class Solution {
  public:
    int maxArea(vector<int> &height) 
    {
        int n=height.size();
        
        vector<vector<int>>v1(n,vector<int>(2,0));
        for(int i=0;i<n;i++)
        {
            v1[i][0]=height[i];
            v1[i][1]=i;
        }
        
        sort(v1.begin(),v1.end(),greater<vector<int>>());
        int ans=0;
        int maxi=INT_MIN,mini=INT_MAX;
        for(auto x:v1)
        {
            if(maxi!=INT_MIN)
            {
                int d1=abs(x[1]-mini)-1;
                int d2=abs(x[1]-maxi)-1;
                ans=max(ans,max(d1,d2)*x[0]);
            }
            maxi=max(maxi,x[1]);
            mini=min(mini,x[1]);
        }
        return ans;
    }
};

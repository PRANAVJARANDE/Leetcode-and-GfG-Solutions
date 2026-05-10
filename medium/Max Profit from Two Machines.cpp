class Solution {
  public:
  
    int maxProfit(int x, int y, vector<int> &a, vector<int> &b) 
    {
        int n=a.size();
        int ans=0;
        vector<vector<int>>v1,v2;
        for(int i=0;i<n;i++)
        {
            int diff=a[i]-b[i];
            if(diff==0)ans+=a[i];
            else
            {
                if(diff>0)v1.push_back({diff,a[i],b[i]});
                else v2.push_back({-diff,a[i],b[i]});
            }
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        
        while(!v1.empty())
        {
            auto temp=v1.back();
            v1.pop_back();
            if(x>0)
            {
                ans+=temp[1];
                x--;
            }
            else ans+=temp[2];
        }
        
        while(!v2.empty())
        {
            auto temp=v2.back();
            v2.pop_back();
            if(y>0)
            {
                ans+=temp[2];
                y--;
            }
            else ans+=temp[1];
        }
        return ans;
    }
};

class Solution {
  public:
    
    unordered_map<int,int> helper(vector<int>&v1)
    {
        int n=v1.size();
        unordered_map<int,int>m;
        for(int i=0;i<(1<<n);i++)
        {
            int cs=0;
            for(int j=0;j<n;j++)
            {
                if(i & (1<<j))
                {
                    cs+=v1[j];
                }
            }
            m[cs]++;
        }
        return m;
    }
    
  
    int countSubset(vector<int> &a, int k) 
    {
        int n=a.size();
        vector<int>v1,v2;
        int mid=n/2;
        for(int i=0;i<mid;i++)v1.push_back(a[i]);
        for(int i=mid;i<n;i++)v2.push_back(a[i]);
        
        unordered_map<int,int>m1=helper(v1);
        unordered_map<int,int>m2=helper(v2);
        
        int ans=0;
        for(auto x:m1)
        {
            int left=x.second;
            int req=k-x.first;
            ans+=left*m2[req];
        }
        return ans;
    }
};

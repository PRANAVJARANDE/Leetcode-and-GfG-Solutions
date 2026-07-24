class Solution {
  public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) 
    {
        int n=arr.size();
        vector<int>cnt(n,0);
        for(int i=1;i<n-1;i++)
        {
            if(arr[i-1]>arr[i] && arr[i]<arr[i+1])cnt[i]=1;
        }
        
        for(int i=1;i<n;i++)cnt[i]+=cnt[i-1];
        
        vector<bool>ans;
        for(auto x:queries)
        {
            int l=x[0]+1,r=x[1]-1;
            
            if(l>r)ans.push_back(1);
            else
            {
                int dips=cnt[r]-cnt[l-1];
                if(dips==0)ans.push_back(1);
                else ans.push_back(0);
            }
        }
        return ans;
    
        
    }
};

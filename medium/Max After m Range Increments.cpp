class Solution {
  public:
  
    /*
        
        n - 8
        arr : 0 0 0 0 0 0 0 0 
        
        op1 : 1 2 5
        
        arr : 0 5 5 0 0 0 0 0
        
        diff: 0 5 0 -5 0 0 0 0
        
        
        in the end
        psum-diff 0 5 5 0 0 0 0
        
        
    */
  
  
  
  
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) 
    {
        vector<int>diff(n+1,0);
        for(int i=0;i<a.size();i++)
        {
            diff[a[i]]+=k[i];
            diff[b[i]+1]-=k[i];
        }
        
        int ans=diff[0];
        for(int i=1;i<n+1;i++)
        {
            diff[i]+=diff[i-1];
            ans=max(ans,diff[i]);
        }
        return ans;
    }
};

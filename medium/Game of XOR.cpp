class Solution {
  public:
    
    int subarrayXor(vector<int>&a) 
    {
        int n=a.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int cnt=(i+1)*(n-i);
            if(cnt%2)ans=ans^a[i];
        }
        return ans;
    }
};

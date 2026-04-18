class Solution {
  public:
  
    // 0 0 1 1 0 1 0 1 1 0 0 1 1 1 0 1
  
    int maxOnes(vector<int>& a) 
    {
        int n=a.size();
        int oc=0;
        for(auto x:a)oc+=x;
        
        int ans=oc;
        
        int mini=0;
        int sum=0;
        for(int r=0;r<n;r++)
        {
            if(a[r]==0)sum++;
            else sum--;
            if(sum<0)sum=0;
            ans=max(ans,oc+sum);
        }
        return ans;
    }
};

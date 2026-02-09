class Solution {
  public:
    int maxProduct(vector<int> &a) 
    {
        int ans=a[0];
        int maxi=a[0];
        int mini=a[0];

        for(int i=1;i<a.size();i++)
        {
            if(a[i]<0)swap(maxi,mini);
            maxi=max(a[i],a[i]*maxi);
            mini=min(a[i],a[i]*mini);
            ans=max(ans,maxi);
        }
        return ans;
    }
};

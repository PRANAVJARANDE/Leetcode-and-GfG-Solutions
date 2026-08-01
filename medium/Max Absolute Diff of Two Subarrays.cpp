class Solution {
  public:
    
    int helper(vector<int>&a)
    {
        // maxi - mini
        
        int n=a.size();
        vector<int>maxi(n,0);
        vector<int>mini(n,0);
        
        int cs=0;
        bool pos=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]>0)pos=1;
            cs+=a[i];
            if(cs<0)cs=0;
            maxi[i]=a[i];
            if(pos==1)maxi[i]=max(maxi[i],cs);
            if(i-1>=0)maxi[i]=max(maxi[i],maxi[i-1]);
        }
        
        bool neg=0;
        cs=0;
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]<0)neg=1;
            cs+=a[i];
            if(cs>0)cs=0;
            mini[i]=a[i];
            if(neg==1)mini[i]=min(mini[i],cs);
            if(i+1<n)mini[i]=min(mini[i],mini[i+1]);
        }
        
        
        int ans=INT_MIN;
        for(int i=0;i<n-1;i++)
        {
            int res=maxi[i]-mini[i+1];
            ans=max(ans,res);
        }
        return ans;
    }
  
    int maxDiffSubArrays(vector<int>& arr) 
    {
        int ans1=helper(arr);
        reverse(arr.begin(),arr.end());
        int ans2=helper(arr);
        return max(ans1,ans2);
    }
};

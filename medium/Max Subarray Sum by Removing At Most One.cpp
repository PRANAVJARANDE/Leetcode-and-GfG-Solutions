class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) 
    {
        int ans=0;
        int sum=0;
        bool flag=0;
        int maxi=INT_MIN;
        for(auto x:arr)
        {
            if(x>=0)flag=1;
            maxi=max(maxi,x);
            sum+=x;
            if(sum<0)sum=0;
            ans=max(ans,sum);
        }
        if(flag==0)return maxi;
        int n=arr.size();
        vector<int>psum(n,0),nsum(n,0);
        
        for(int i=0;i<n;i++)
        {
            psum[i]=arr[i];
            if(i-1>=0)psum[i]+=psum[i-1];
            psum[i]=max(0,psum[i]);
        }
        
        for(int i=n-1;i>=0;i--)
        {
            nsum[i]=arr[i];
            if(i+1<n)nsum[i]+=nsum[i+1];
            nsum[i]=max(0,nsum[i]);
        }
        
        for(int i=0;i<n-2;i++)
        {
            ans=max(ans,psum[i]+nsum[i+2]);
        }
        return ans;
        
        
    }
};

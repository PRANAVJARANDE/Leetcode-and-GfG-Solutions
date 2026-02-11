class Solution {
public:
  
    bool check(long long mid, vector<int>& a, long long k, int w)
    {
        int n=a.size();
        vector<long long>extra(n+1,0);
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=extra[i];
            long long val=a[i]+sum;
            if(val<mid)
            {
                long long need=mid-val;
                k-=need;
                if(k<0)return 0;   
                sum+=need;
                if(i+w<n)extra[i+w]-=need;
            }
        }
        return 1;
    }
  
    int maxMinHeight(vector<int> &a, int k, int w) 
    {
        long long l=*min_element(a.begin(),a.end());
        long long r=l+k;
        long long ans=l;
        while(l<=r)
        {
            long long mid=l+(r-l)/2;
            if(check(mid,a,k,w))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return (int)ans;
    }
};

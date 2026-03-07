#define ll long long
class Solution {
public:

    ll getsum(ll l,ll r,vector<ll>&v1)
    {
        if(l>r)return 0;
        ll sum=v1[r];
        if(l-1>=0)sum-=v1[l-1];
        return sum;
    }

    int minMoves(vector<int>& nums, int k) 
    {
        if(k==1)return 0;
        vector<ll>v1;
        for(int i=0;i<nums.size();i++)if(nums[i]==1)v1.push_back(i);
        for(int i=1;i<v1.size();i++)v1[i]+=v1[i-1];
        
        ll ans=INT_MAX;
        for(int i=k-1;i<v1.size();i++)
        {
            ll r=i;
            ll l=i-k+1;
            ll mid=l+(r-l)/2;

            int val=getsum(mid,mid,v1);
            
            ll psum=getsum(l,mid-1,v1);
            ll pcnt=max(0ll,mid-l);
            ll nsum=getsum(mid+1,r,v1);
            ll ncnt=max(0ll,r-mid);

            ll res1=(pcnt*val)-psum-((pcnt*(pcnt+1))/2);
            ll res2=nsum-(ncnt*val)-((ncnt*(ncnt+1))/2);
            ll res=res1+res2;
            ans=min(ans,res);
        }
        return ans;    
    }
};

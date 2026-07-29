#define ll long long
class Solution {
public:

    ll ncr(ll n,ll r,ll lim) 
    {
        r=min(r,n-r);
        ll ans=1;
        for(int i=1;i<=r;i++) 
        {
            ans=ans*(n-r+i)/i;
            if(ans>lim)return lim+1;
        }
        return ans;
    }

    ll help(vector<int>&cnt,int rem,int k)
    {
        ll ans=1;
        for(auto x:cnt)
        {
            if(x!=0)
            {
                ans*=ncr(rem,x,k);
                if(ans>k)return k+1;
                rem-=x;
            }
        }
        return ans;
    }

    string smallestPalindrome(string s, int k) 
    {
        int n=s.size(),mid=n/2;
        vector<int>cnt(26,0);
        for(auto x:s)cnt[x-'a']++;
        string ans(n,' ');
        for(int i=0;i<26;i++)
        {
            if(cnt[i]%2)ans[mid]=i+'a';
            cnt[i]/=2;
        }
        
        if(help(cnt,mid,k)<k)return "";


        for(int i=0;i<mid;i++)
        {
            for(int c=0;c<26;c++)
            {
                if(cnt[c]!=0)
                {
                    cnt[c]--;
                    ll temp=help(cnt,mid-i-1,k);
                    if(temp>=k)
                    {
                        ans[i]=c+'a';
                        ans[n-i-1]=ans[i];
                        break;
                    }
                    k-=temp;
                    cnt[c]++;
                }
            }
        }
        return ans;
    }
};

#define ll long long
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) 
    {
        vector<ll>free(n,0);
        vector<ll>cnt(n,0);
        sort(meetings.begin(),meetings.end());
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q1;
        for(auto x:meetings)
        {
            ll st=x[0],en=x[1];
            while(!q1.empty() && q1.top().first<=st)
            {
                free[q1.top().second]=0;
                q1.pop();
            }
            // find next room 
            ll in=0;
            while(in<n && free[in]==1)in++;

            if(in==n)
            {
                auto tp=q1.top();
                q1.pop();
                cnt[tp.second]++;
                q1.push({tp.first+en-st,tp.second});
            }
            else
            {
                //got a free room
                free[in]=1;
                q1.push({en,in});
                cnt[in]++;
            }
        }
        ll ans=0;
        for(ll i=1;i<n;i++)
        {
            if(cnt[i]>cnt[ans])
            {
                ans=i;
            }
        }
        return ans;
    }
};

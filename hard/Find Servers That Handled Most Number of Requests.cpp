class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) 
    {
        int rsz=arrival.size();
        vector<int>cnt(k,0);
        
        set<int>free_servers;
        for(int i=0;i<k;i++)free_servers.insert(i);
        
        // finish time , server  -> asc
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>busy;

        for(int i=0;i<rsz;i++)
        {   
            int at=arrival[i];
            while(!busy.empty() && busy.top().first<=at)
            {
                free_servers.insert(busy.top().second);
                busy.pop();
            }
            int bt=load[i];
            if(free_servers.empty())continue;
            int requested_server=(i%k);
            auto itr=free_servers.lower_bound(requested_server);
            int went_to=*free_servers.begin();
            if(itr!=free_servers.end())went_to=*itr;
            cnt[went_to]++;
            busy.push({at+bt,went_to});
            free_servers.erase(went_to);
        }
        
        vector<int>ans;
        int maxi=0;
        for(int i=0;i<k;i++)
        {
            if(cnt[i]>maxi)
            {
                ans.clear();
                ans.push_back(i);
                maxi=cnt[i];
            }
            else if(cnt[i]==maxi)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

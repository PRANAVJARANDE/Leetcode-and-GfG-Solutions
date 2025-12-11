class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) 
    {
        map<int,vector<int>>mx,my;
        for(auto x:buildings)
        {
            mx[x[0]].push_back(x[1]);
            my[x[1]].push_back(x[0]);
        }
        map<pair<int,int>,int>cnt;
        for(auto x:mx)
        {
            sort(x.second.begin(),x.second.end());
            for(int i=1;i<x.second.size()-1;i++)
            {
                cnt[{x.first,x.second[i]}]++;
            }
        }
        for(auto x:my)
        {
            sort(x.second.begin(),x.second.end());
            for(int i=1;i<x.second.size()-1;i++)
            {
                cnt[{x.second[i],x.first}]++;
            }
        }
        int ans=0;
        for(auto x:cnt)
        {
            if(x.second==2)ans++;
        }
        return ans;
    }
};

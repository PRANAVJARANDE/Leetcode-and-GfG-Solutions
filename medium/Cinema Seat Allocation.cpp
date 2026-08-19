class Solution {
public:

    vector<vector<int>>valid={{2,3,4,5},{4,5,6,7},{6,7,8,9}};
    int maxNumberOfFamilies(int n, vector<vector<int>>& r) 
    {
        map<int,set<int>>v1;
        for(auto x:r)v1[x[0]].insert(x[1]);
        int ans=(n-v1.size())*2;
        for(auto x:v1)
        {
            for(auto t:valid)
            {
                bool flag=1;
                for(auto ch:t)
                {
                    if(x.second.find(ch)!=x.second.end())
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag)
                {
                    ans++;
                    for(auto ch:t)x.second.insert(ch);
                }
            }
            
        }
        return ans;
    }
};

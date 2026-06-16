class Solution {
public:
    bool isTransformable(string s, string t) 
    {
        int n=s.size();
        vector<deque<int>>v1(10);
        for(int i=0;i<n;i++)v1[s[i]-'0'].push_back(i);
        
        for(int i=0;i<n;i++)
        {
            int tar=t[i]-'0';
            if(v1[tar].empty())return 0;
            
            int index=v1[tar].front();
            v1[tar].pop_front();

            for(int z=0;z<tar;z++)
            {
                if(!v1[z].empty())
                {
                    if(v1[z].front()<index)return 0;
                }
            }
        }
        return 1;
    }
};

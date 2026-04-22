class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) 
    {
        int qs=queries.size();
        int ds=dictionary.size();
        vector<string>ans;
        for(auto q:queries)
        {
            for(auto s:dictionary)
            {
                int cnt=0;
                for(int i=0;i<q.size();i++)
                {
                    if(q[i]!=s[i])cnt++;
                    if(cnt>2)break;
                }
                if(cnt<=2)
                {
                    ans.push_back(q);
                    break;
                }
            }
        }
        return ans;
    }
};

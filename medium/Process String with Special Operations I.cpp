class Solution {
public:
    string processStr(string s) 
    {
        string res;
        for(auto x:s)
        {
            if(x=='*')
            {
                if(!res.empty())res.pop_back();
            }
            else if(x=='#')res=res+res;
            else if(x=='%')
            {
                reverse(res.begin(),res.end());
            }
            else res+=x;
        }
        return res;
    }
};

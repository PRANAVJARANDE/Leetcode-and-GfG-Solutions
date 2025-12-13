class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n=code.size();
        map<string,vector<string>>valid;
        for(int i=0;i<n;i++)
        {
            if(isActive[i] && code[i]!="" && (businessLine[i]=="electronics" || businessLine[i]=="grocery" || businessLine[i]=="pharmacy" || businessLine[i]=="restaurant"))
            {
                //check validity of code
                bool flag=1;
                for(auto x:code[i])
                {
                    if(!(('a'<=x && x<='z') || ('A'<=x && x<='Z') || ('0'<=x && x<='9') || (x=='_')))
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag)valid[businessLine[i]].push_back(code[i]);
            }
        }
        vector<string>ans;
        for(auto x:valid)
        {
            sort(x.second.begin(),x.second.end());
            for(auto z:x.second)ans.push_back(z);
        }
        return ans;
    }
};

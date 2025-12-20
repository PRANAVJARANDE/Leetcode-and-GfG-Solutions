class Solution {
public:
    int minDeletionSize(vector<string>& strs) 
    {
        int ans=0;
        int sz=strs[0].size();
        for(int i=0;i<sz;i++)
        {
            bool flag=1;
            for(int j=1;j<strs.size();j++)
            {
                if(strs[j-1][i]>strs[j][i])
                {
                    flag=0;
                    break;
                }
            }
            if(flag==0)ans++;
        }
        return ans;
    }
};

class Solution {
  public:
    vector<string> graycode(int n) {
        vector<string>ans;
        for(int i=0;i<(1<<n);i++)
        {
            int val=i ^ (i>>1);
            string s;
            for(int j=n-1;j>=0;j--)
            {
                s.push_back(((val & (1<<j))? '1':'0'));
            }
            ans.push_back(s);
        }
        return ans;
    }
};

class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        int n=s1.size();
        int m=s2.size();
        
        int st=-1;
        int en=1e6;
        for(int i=0;i<n;i++)
        {
            int in=0;
            for(int j=i;j<n;j++)
            {
                if(s1[j]==s2[in])
                {
                    in++;
                    if(in==m)
                    {
                        int sz=j-i+1;
                        if(sz<en-st+1)
                        {
                            st=i;
                            en=j;
                        }
                        break;
                    }
                }
            }
        }
        //cout<<st<<" "<<en<<endl;
        if(st==-1)return "";
        return s1.substr(st,en-st+1);
    }
};

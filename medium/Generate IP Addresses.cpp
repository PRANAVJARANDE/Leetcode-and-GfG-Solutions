class Solution {
  public:
    vector<string> generateIp(string &s) 
    {
        vector<string>ans;
        int n=s.size();
 
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    string s1=s.substr(0,i);
                    string s2=s.substr(i,j-i);
                    string s3=s.substr(j,k-j);
                    string s4=s.substr(k);
                    
                    if(s1.size()>=2 && s1[0]=='0')continue;
                    if(s2.size()>=2 && s2[0]=='0')continue;
                    if(s3.size()>=2 && s3[0]=='0')continue;
                    if(s4.size()>=2 && s4[0]=='0')continue;
                    
                    if(s1.size()>=4 || s2.size()>=4 || s3.size()>=4 || s4.size()>=4)continue;
                    
                    if(s1=="" || s2=="" || s3=="" || s4=="")continue;
                    int n1=stoi(s1);
                    int n2=stoi(s2);
                    int n3=stoi(s3);
                    int n4=stoi(s4);
                    if(n1>=0 && n2>=0 && n3>=0 && n4>=0 && n1<=255 && n2<=255 && n3<=255 && n4<=255)
                    {
                        string res=s1+"."+s2+"."+s3+"."+s4;
                        ans.push_back(res);
                    }
                }
            }
        }
        return ans;
    }
};

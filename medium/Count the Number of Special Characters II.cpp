class Solution {
public:
    int numberOfSpecialChars(string word) 
    {
        int ans=0;
        for(int i=0;i<26;i++)
        {
            char l='a'+i,u='A'+i;
            bool fans=1;
            bool flag1=0,flag2=0;
            for(auto x:word)
            {   
                if(x==l)
                {
                    if(flag2==1)
                    {
                        fans=0;
                        break;
                    }
                    else
                    {
                        flag1=1;
                    }
                }
                else if(x==u)
                {
                    if(flag2==0)flag2=1;
                }
            }  
            if(flag1 && flag2 && fans)ans++;
        }
        return ans;
        
    }
};

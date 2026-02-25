class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) 
    {
        vector<int>m1(26,-1),m2(26,-1);
        for(int i=0;i<s1.size();i++)
        {
            if(m1[s1[i]-'a']==-1)m1[s1[i]-'a']=s2[i]-'a';
            else if(m1[s1[i]-'a']!=s2[i]-'a')return 0;
            if(m2[s2[i]-'a']==-1)m2[s2[i]-'a']=s1[i]-'a';
            else if(m2[s2[i]-'a']!=s1[i]-'a')return 0;
        }
        return 1;
    }
};

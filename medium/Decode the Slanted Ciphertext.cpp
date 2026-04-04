class Solution {
public:
    string decodeCiphertext(string s, int rows) 
    {
        int n=s.size();
        int cs=n/rows;

        vector<int>ptr(rows,0);
        for(int i=0;i<rows;i++)ptr[i]=i;

        string ans;
        while(ptr[0]<cs)
        {
            for(int i=0;i<rows;i++)
            {
                if(cs*i+ptr[i]<n)ans.push_back(s[cs*i + ptr[i]]);
                ptr[i]++;
            }
        }
        while(!ans.empty() && ans.back()==' ')ans.pop_back();
        return ans;
    }
};

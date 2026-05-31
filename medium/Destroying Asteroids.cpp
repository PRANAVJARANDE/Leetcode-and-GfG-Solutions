class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) 
    {
        long long m=mass;
        sort(a.begin(),a.end());
        for(auto x:a)
        {
            if(m>=x)m+=x;
            else return 0;
        }
        return 1;
    }
};

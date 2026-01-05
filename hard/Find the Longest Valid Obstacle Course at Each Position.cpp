class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& a) 
    {
        vector<int>ans;
        vector<int>res;
        for(auto x:a)
        {   
            int in=upper_bound(res.begin(),res.end(),x)-res.begin();
            if(in==res.size())
            {
                res.push_back(x);
                ans.push_back(res.size());
            }
            else 
            {
                res[in]=x;
                ans.push_back(in+1);
            }
        }
        return ans;
    }
};

class Solution {
  public:
    bool canAttend(vector<vector<int>> &a) {
        sort(a.begin(),a.end());
        for(int i=0;i<a.size()-1;i++)
        {
            if(a[i][1]>a[i+1][0])return 0;
        }
        return 1;
    }
};

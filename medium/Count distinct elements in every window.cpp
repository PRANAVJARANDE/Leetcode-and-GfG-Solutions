class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        map<int,int>m;
        for(int i=0;i<k;i++)m[arr[i]]++;
        vector<int>ans;
        ans.push_back(m.size());
        for(int i=k;i<arr.size();i++)
        {
            m[arr[i]]++;
            m[arr[i-k]]--;
            if(m[arr[i-k]]==0)m.erase(arr[i-k]);
            ans.push_back((int)m.size());
        }
        return ans;
    }
};

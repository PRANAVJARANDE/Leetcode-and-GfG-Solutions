// Time Complexity : O(n)
// Space Complexity : O(k)

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int>ans;
        deque<int>q1;
        for(int i=0;i<k;i++)
        {
            while(!q1.empty() && arr[i]>=arr[q1.back()])q1.pop_back();
            q1.push_back(i);
        }
        ans.push_back(arr[q1.front()]);
        for(int i=k;i<arr.size();i++)
        {
            while(!q1.empty() && q1.front()<=i-k)q1.pop_front();
            while(!q1.empty() && arr[i]>=arr[q1.back()])q1.pop_back();
            q1.push_back(i);
            ans.push_back(arr[q1.front()]);
        }
        return ans;
    }
};

// ------------------------------------------------------------------------------------------------------------------

// Time Complexity : O(nlogn)
// Space Complexity : O(n)
class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int>ans;
        priority_queue<pair<int,int>>q1;
        for(int i=0;i<k;i++)q1.push({arr[i],i});
        ans.push_back(q1.top().first);
        for(int i=k;i<arr.size();i++)
        {
            q1.push({arr[i],i});
            while(!q1.empty() && q1.top().second<=i-k)q1.pop();
            ans.push_back(q1.top().first);
        }
        return ans;
    }
};

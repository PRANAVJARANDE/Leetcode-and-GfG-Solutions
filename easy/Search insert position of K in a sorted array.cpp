class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        return lower_bound(arr.begin(),arr.end(),k)-arr.begin();
    }
};

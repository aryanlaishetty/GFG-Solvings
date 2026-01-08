class Solution {
  public:
    int countDistinct(const vector<int>& arr) {
        // code here
        unordered_set<int> s;

        for(int i=0; i<arr.size(); i++) {
            s.insert(arr[i]);
        }
    
        return s.size();
    }
};
class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int> s;
        
        for(int el : a) {
            s.insert(el);
        }
        
        for(int el : b) {
            s.insert(el);
        }
        
        vector<int> result(s.begin(), s.end());
      
        return result;
    }
};
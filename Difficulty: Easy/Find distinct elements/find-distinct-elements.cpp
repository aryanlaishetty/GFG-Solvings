// User function Template for C++
int distinct(vector<int>& arr) {
    // Your code here
    unordered_set<int> s;

    for(int i=0; i<arr.size(); i++) {
        s.insert(arr[i]);
    }

    return s.size();
}
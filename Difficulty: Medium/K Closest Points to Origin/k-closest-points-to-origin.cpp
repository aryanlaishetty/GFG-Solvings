class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
        vector<vector<int>> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  //<distSq, i>

        for(int i=0; i<points.size(); i++) {    //O(n)
            vector<int> temp = points[i];
            int distSq = temp[0]*temp[0] + temp[1]*temp[1];
            pq.push(make_pair(distSq, i));
        }

        for(int i=0; i<k; i++) {    //O(k * log n) ; worst case k=n, //O(nlogn)
            int idx = pq.top().second;
            ans.push_back(points[idx]);
            pq.pop();   //O(log n)
        }
        
        return ans;
    }
};
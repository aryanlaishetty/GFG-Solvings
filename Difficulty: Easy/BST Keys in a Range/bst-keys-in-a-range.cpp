class Solution {
  public:
    vector<int> helper(Node *root, int low, int high, vector<int> &arr) {
        if(root == NULL) {
            return arr;
        }
        
        if(low <= root->data && root->data <= high) {
            helper(root->left, low, high, arr);
            arr.push_back(root->data);
            helper(root->right, low, high, arr);
        } else if(root->data < low) {
            helper(root->right, low, high, arr);
        } else {
            helper(root->left, low, high, arr);
        }
        
        return arr;
    }
  
    vector<int> printNearNodes(Node *root, int low, int high) {
        // code here
        vector<int> arr;
        return helper(root, low, high, arr);
    }
};
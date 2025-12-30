/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* LCA(Node* root, int n1, int n2) {    //TC=O(n), SC=O(1)
        if(root == NULL) {
            return NULL;
        }
    
        if(root->data == n1 || root->data == n2) {
            return root;
        }
    
        Node* leftLCA = LCA(root->left, n1, n2);
        Node* rightLCA = LCA(root->right, n1, n2);
    
        if(leftLCA != NULL && rightLCA != NULL) {
            return root;
        }
    
        return leftLCA == NULL ? rightLCA : leftLCA;
    }
    
    int dist(Node* root, int n) {
        if(root == NULL) {
            return -1;
        }
        
        if(root->data == n) {
            return 0;
        }
        
        int leftDist = dist(root->left, n);
        if(leftDist != -1) {
            return leftDist + 1;
        }
        
        int rightDist = dist(root->right, n);
        if(rightDist != -1) {
            return rightDist + 1;
        }
        
        return -1;
    }
    
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* lca = LCA(root, a, b);
        
        int dist1 = dist(lca, a);
        int dist2 = dist(lca, b);
        
        return dist1 + dist2;
    }
};
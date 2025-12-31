/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:

    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int toSumTree(Node *node) {
        // Your code here
        if(node == NULL) {
            return 0;
        }
    
        int leftOld = toSumTree(node->left);
        int rightOld = toSumTree(node->right);
        int currOld = node->data;
    
        node->data = leftOld + rightOld;
    
        if(node->left != NULL) {
            node->data += node->left->data;
        }
        
        if(node->right != NULL) {
            node->data += node->right->data;
        }
    
        return currOld;
    }
};
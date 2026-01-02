/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool validateHelper(Node* root, Node* min, Node* max) {
        if(root == NULL) {
            return true;
        }
    
        if(min != NULL && root->data < min->data) {
            return false;
        }
    
        if(max != NULL && root->data > max->data) {
            return false;
        }
    
        return validateHelper(root->left, min, root) && validateHelper(root->right, root, max);
    }
    
    bool isBST(Node* root) {
        // code here
        return validateHelper(root, NULL, NULL);
    }
};
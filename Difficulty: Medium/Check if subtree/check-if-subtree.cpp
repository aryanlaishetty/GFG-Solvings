/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    bool isIdentical(Node* root1, Node* root2) {
        if(root1 == NULL && root2 == NULL) {
            return true;
        } else if(root1 == NULL || root2 == NULL) {
            return false;
        }

        if(root1->data != root2->data) {
            return false;
        }

        return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
    }
  
    // Function to check if S is a subtree of tree T.
    bool isSubTree(Node* root, Node* subRoot) {
        // Your code here
        if(root == NULL && subRoot == NULL) {
            return true;
        } else if(root == NULL || subRoot == NULL) {
            return false;
        }
 
        if(root->data == subRoot->data) {
            if(isIdentical(root, subRoot)) {
                return true;
            }
        }

        bool isLeftSubtree = isSubTree(root->left, subRoot); 

        if(!isLeftSubtree) {
            return isSubTree(root->right, subRoot); 
        }

        return true;
    }
};
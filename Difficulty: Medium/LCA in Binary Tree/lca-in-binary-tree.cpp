/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    bool rootToNodePath(Node* root, int r, vector<int> &path) {
        if(root == NULL) {
            return false;
        }

        path.push_back(root->data);
        if(root->data == r) {
            return true;
        }

        bool isLeft = rootToNodePath(root->left, r, path); 
        bool isRight = rootToNodePath(root->right, r, path); 

        if(isLeft || isRight) {
            return true;
        }

        path.pop_back();
        return false;
    }

    Node* findNode(Node* root, int lca) {
        if(!root) {
            return NULL;
        }

        if(root->data == lca) {
            return root;
        }

        Node* left = findNode(root->left, lca);

        if(left) {
            return left;
        }

        return findNode(root->right, lca);
    }

    Node* lca(Node* root, int n1, int n2) {
        //  code here
        vector<int> path1;
        vector<int> path2;

        rootToNodePath(root, n1, path1);
        rootToNodePath(root, n2, path2);

        int lca = -1;

        for(int i=0, j=0; i<path1.size() && j<path2.size(); i++,j++) {
            if(path1[i] != path2[j]) {
                break;
            }
            lca = path1[i];
        }
        
        return findNode(root, lca);
    }
};
class Node {
public: 
    unordered_map<char, Node*> children;    //this map will store char and node pointer of children of current node
    bool endOfWord; //T - a word ends here, F - word does not end

    Node() {
        endOfWord = false;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string key) {   //O(L)  
        Node* temp = root;

        for(int i=0; i<key.size(); i++) {
            if(temp->children.count(key[i]) == 0) {     //agar trie mai wo character exist nahi karta 
                temp->children[key[i]] = new Node();    //insert
            }
            temp = temp->children[key[i]];
        }

        temp->endOfWord = true;
    }

    int countHelper(Node* root) {
        int ans = 0;

        for(pair<char, Node*> child : root->children) { 
            ans += countHelper(child.second);
        }

        return ans + 1;
    }

    int countNodes() {
        return countHelper(root);
    }

};


class Solution {
  public:
    int countSubs(string& s) {
        // code here
        Trie trie;

        //find suffix
        for(int i=0; i<s.size(); i++) {
            string suffix = s.substr(i);
            trie.insert(suffix);
        }
    
        return trie.countNodes()-1;
    }
};
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

    void longestHelper(Node* root, string &ans, string temp) {
        for(pair<char, Node*> child : root->children) {
            if(child.second->endOfWord) {
                temp += child.first;

                if((temp.size() == ans.size() && temp < ans) || (temp.size() > ans.size())) {
                    ans = temp;
                }

                longestHelper(child.second, ans, temp);
                temp = temp.substr(0, temp.size()-1);
            }
        }
    }

    string longestStringWithEOW() {
        string ans = "";
        longestHelper(root, ans, "");

        return ans;
    }
};

class Solution {
public:
    string longestValidWord(vector<string>& words) {
        // code here
        Trie trie;

        for(int i=0; i<words.size(); i++) {
            trie.insert(words[i]);
        }
    
        return trie.longestStringWithEOW();
    }
};

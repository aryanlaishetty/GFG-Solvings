// User function template for C++
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
        // implement Trie
        root = new Node();
    }

    void insert(string &word) {
        // insert word into Trie
        Node* temp = root;

        for(int i=0; i<word.size(); i++) {
            if(temp->children.count(word[i]) == 0) {     //agar trie mai wo character exist nahi karta 
                temp->children[word[i]] = new Node();    //insert
            }
            temp = temp->children[word[i]];
        }

        temp->endOfWord = true;
    }

    bool search(string &word) {
        // search word in the Trie
        Node* temp = root;

        for(int i=0; i<word.size(); i++) {
            if(temp->children.count(word[i])) {  //exists
                temp = temp->children[word[i]];
            } else {    //does not exists
                return false;
            }
        }

        return temp->endOfWord; //T-if exists
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        Node* temp = root;

        for(int i=0; i<word.size(); i++) {
            if(temp->children.count(word[i])) {
                temp = temp->children[word[i]];
            } else {
                return false;
            }
        }

        return true;
    }
};

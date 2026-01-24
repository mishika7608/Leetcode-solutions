class Node{
    public:
    Node* list[26]={NULL};
    bool flag=false;
    bool check_filled(char ch){
        return list[ch-'a']!=NULL;
    }
    void put(char ch, Node* node){
        list[ch-'a'] = node;
    }
    Node* get(char ch){
        return list[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag==true;
    }

};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if (!node->check_filled(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for (int i=0;i<word.size();i++){
            if (!node->check_filled(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for (int i=0;i<prefix.size();i++){
            if (!node->check_filled(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
struct node{
    vector<node*>v{26,nullptr};
    bool flag;
    bool ispresent(char c){
        return v[c-'a']!=NULL;
    }
    void put(char c,node* node){
        v[c-'a']=node;
    }
    node* next(char c){
        return v[c-'a'];
    }
    void setend(){
        flag=true;
    }
    bool isend(){
        return flag;
    }
};
class Trie {
public:
    node* root;
    Trie() {
        root=new node();
    }
    void insert(string word) {
        node* temp=root;
        for(int i=0;i<word.size();i++){
            if(!temp->ispresent(word[i])){
                temp->put(word[i],new node());
            }
            temp=temp->next(word[i]);
        }
        temp->setend();
    }
    
    bool search(string word) {
        node* temp=root;
        for(int i=0;i<word.size();i++){
            if(!temp->ispresent(word[i])){
                return false;
            }
            temp=temp->next(word[i]);
        }
        return temp->isend();
    }
    
    bool startsWith(string prefix) {
        node* temp=root;
        for(int i=0;i<prefix.size();i++){
            if(!temp->ispresent(prefix[i])){
                return false;
            }
            temp=temp->next(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
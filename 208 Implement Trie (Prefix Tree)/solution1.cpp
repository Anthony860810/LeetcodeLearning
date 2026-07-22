class Trie {
    private:
        unordered_set<string> trie1;
        unordered_set<string> trie2;
    public:
        Trie() {
            
        }
        
        void insert(string word) {
            string tmp = "";
            for (int idx = 0; idx < word.size(); idx++) {
                tmp.push_back(word[idx]);
                trie2.insert(tmp);
            }
            trie1.insert(word);
        }
        
        bool search(string word) {
            return trie1.find(word) != trie1.end();
        }
        
        bool startsWith(string prefix) {
            return trie2.find(prefix) != trie2.end();
        }
    };
    
    /**
     * Your Trie object will be instantiated and called as such:
     * Trie* obj = new Trie();
     * obj->insert(word);
     * bool param_2 = obj->search(word);
     * bool param_3 = obj->startsWith(prefix);
     */
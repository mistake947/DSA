class TrieNode {
public:
  bool Terminal;
  TrieNode *children[26];
  // Intilize trie
  TrieNode() {
    Terminal = false;
    for (int i = 0; i < 26; i++) {
      children[i] = NULL;
    }
  }
  // insert word in trie
  void insert(string word) {
    TrieNode *curr = root;
    for (int i = 0; i < word.size(); i++) {
      int k = word[i] - 'a';
      if (curr->children[k] == NULL) {
        curr->children[k] = new TrieNode();
      }
      curr = curr->children[k];
    }
    curr->Terminal = true;
  }
  // search word in trie
  bool search(string word) {
    TrieNode *curr = root;
    for (int i = 0; i < word.size(); i++) {
      int k = word[i] - 'a';
      curr = curr->children[k];
      if (curr == NULL)
        return false;
    }
    return curr->Terminal;
  }
  // search prefix
  bool startsWith(string prefix) {
    TrieNode *curr = root;
    for (int i = 0; i < prefix.size(); i++) {
      int k = prefix[i] - 'a';
      curr = curr->children[k];
      if (curr == NULL)
        return false;
    }
    return true;
  }
};

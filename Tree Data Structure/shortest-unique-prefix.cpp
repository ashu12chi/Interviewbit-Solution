struct trie
{
    struct trie* children[26]; // structure for trie node contains array for children and
    int count;                 // count of insertion using that character
};
struct trie* newNode()
{
    struct trie* temp = new trie(); // function to make a new trie node
    for(int i=0;i<26;i++)
        temp->children[i] = NULL;
    temp->count = 0;
    return temp;
}
void insert(struct trie* root,string& key) // insert keys in trie
{
    for(int i=0;i<key.size();i++)
    {
        if(!root->children[key[i]-'a'])
        {
            root->children[key[i]-'a'] = newNode();
        }
        root = root->children[key[i]-'a'];
        root->count++; //increase count for every character
    }
}
string search(struct trie* root,string& key) // while seraching any string in trie to get
{                                            // unique prefix to represent it, select the
    string temp = "";                        // first character where count is 1.
    for(int i=0;i<key.size();i++)
    {
        root = root->children[key[i]-'a'];
        temp += key[i];
        if(root->count == 1)
            return temp; // return prefix string.
    }
    return temp;
}
vector<string> Solution::prefix(vector<string> &A) {
    struct trie* root = newNode();
    for(int i=0;i<A.size();i++)
        insert(root,A[i]);  // insert keys in trie
    vector<string> ans;
    for(int i=0;i<A.size();i++)
    {
        string temp = search(root,A[i]); // search for unique prefixes.
        ans.emplace_back(temp);
    }
    return ans;
}

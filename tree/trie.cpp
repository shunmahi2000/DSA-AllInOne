#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, e) for (ll i = 0; i < e; i++)

class TrieNode
{
public:
    bool isEnd;
    TrieNode *children[26];

    TrieNode()
    {
        this->isEnd = false;
        for (int i = 0; i < 26; i++)
        {
            this->children[i] = NULL;
        }
    }
};
void insert(TrieNode *root, string s)
{

    for (int i = 0; i < s.size(); i++)
    {
        if (root->children[s[i] - 'a'] == NULL)
        {
            root->children[s[i] - 'a'] = new TrieNode();
        }
        root = root->children[s[i] - 'a'];
        if (i + 1 == s.size())
            root->isEnd = true;
    }
}
bool search(TrieNode *root, string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (root->children[s[i] - 'a'] == NULL)
            return false;
        root = root->children[s[i] - 'a'];
    }
    return root->isEnd;
}
int main()
{
    TrieNode *root = new TrieNode();

    insert(root, "apple");
    insert(root, "app");

    cout << search(root, "apple") << endl; // ✅ Should print 1 (true)
    cout << search(root, "app") << endl;   // ✅ Should print 1 (true)
    cout << search(root, "appl") << endl;  // ✅ Should print 0 (false)

    return 0;
}
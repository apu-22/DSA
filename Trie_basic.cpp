#include <bits/stdc++.h>
using namespace std;

struct Trienode
{
    struct Trienode *children[26];
    bool isEndofWord;
    int childCnt;
    int prefixCnt;
};

struct Trienode *getnode()
{
    struct Trienode *newnode = new Trienode;
    newnode->isEndofWord = false;
    newnode->childCnt = 0;
    newnode->prefixCnt = 0;

    for (int i = 0; i < 26; i++)
    {
        newnode->children[i] = NULL;
    }

    return newnode;
}

void insert(struct Trienode *root, string key)
{
    struct Trienode *current = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (current->children[index] == NULL)
        {
            current->children[index] = getnode();
            current->childCnt++;
        }

        current = current->children[index];
        current->prefixCnt++;
    }
    current->isEndofWord = true;
}

void search(struct Trienode *root, string key)
{
    struct Trienode *current = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (current->children[index] == NULL)
        {
            cout << key << ": is not found\n";
            return;
        }
        current = current->children[index];
    }

    if (current->isEndofWord)
        cout << key << ": is found\n";
    else
        cout << key << ": is not found\n";
}

// Helper function to check if a node has any children
bool isEmpty(Trienode *root)
{
    for (int i = 0; i < 26; i++)
    {
        if (root->children[i] != NULL)
            return false;
    }
    return true;
}

void deleteWord(Trienode *&root, string key, int depth = 0)
{
    if (root == NULL)
        return;

    if (depth == key.size())
    {
        if (root->isEndofWord)
            root->isEndofWord = false;

        if (isEmpty(root))
        {
            delete root;
            root = NULL;
        }
        return;
    }

    int index = key[depth] - 'a';
    deleteWord(root->children[index], key, depth + 1);

    if (isEmpty(root) && !root->isEndofWord)
    {
        delete root;
        root = NULL;
    }
}

string LCP(struct Trienode *root)
{
    string prefix = "";
    struct Trienode *current = root;

    while (current && current->childCnt == 1 && !current->isEndofWord)
    {
        for (int i = 0; i < 26; i++)
        {
            if (current->children[i] != NULL)
            {
                prefix += (char)(i + 'a');
                current = current->children[i];
                break;
            }
        }
    }
    return prefix;
}

int countWordWithPrefix(struct Trienode *root, string prefix)
{
    struct Trienode *current = root;
    for (char ch : prefix)
    {
        int index = ch - 'a';
        if (current->children[index] == NULL)
        {
            return 0;
        }
        current = current->children[index];
    }
    return current->prefixCnt;
}

int main()
{
    string key[] = {"coding", "codezen", "codingninja", "coders"};

    int n = sizeof(key) / sizeof(key[0]);

    struct Trienode *root = getnode();

    for (int i = 0; i < n; i++)
    {
        insert(root, key[i]);
    }

    search(root, "coding");
    search(root, "lb");
    search(root, "codezen");
    search(root, "furie");
    search(root, "coders");

    cout << "\nThe common largest prefix is:\n";
    cout << LCP(root) << "\n";

    cout<<"\nThe number of word is started with this 'code' word is: ";
    cout<<countWordWithPrefix(root, "code")<<"\n";

    cout << "\nDeleting 'thanos' from Trie...\n";
    deleteWord(root, "coders");

    search(root, "coders");
}

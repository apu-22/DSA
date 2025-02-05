#include <bits/stdc++.h>
using namespace std;

struct Trienode
{
    struct Trienode *children[26];
    bool isEndofWord;
};

struct Trienode *getnode()
{
    struct Trienode *newnode = new Trienode;
    newnode->isEndofWord = false;

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
            current->children[index] = getnode();

        current = current->children[index];
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
            cout << key << ": is not found" << "\n";
            return;
        }
        current = current->children[index];
    }

    if (current->isEndofWord)
        cout << key << ": is found" << "\n";
    else
        cout << key << ": is not found" << "\n";
}

int main()
{
    string key[] = {"thanos", "apu", "lb", "a", "blackpanther"};

    int n = sizeof(key) / sizeof(key[0]);

    struct Trienode *root = getnode();

    for (int i = 0; i < n; i++)
    {
        insert(root, key[i]);
    }

    search(root, "thanos");
    search(root, "lb");
    search(root, "blackpanther");
    search(root, "furie");
    search(root, "bccd");
}
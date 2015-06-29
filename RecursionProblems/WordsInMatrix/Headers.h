#include <iostream>
#include <memory>
#include <vector>
#include <set>
#include <unordered_map>
#include <utility>
using namespace std;

class Dictionary
{
public:
    Dictionary()
    {
        m_root = make_shared<Node>('!');
    }

    void insert(string word)
    {
        int index = 0;
        int wordLen = word.length();
        shared_ptr<Node> parent = nullptr;
        shared_ptr<Node> curr = m_root;
        while (curr && index < wordLen)
        {
            char ch = word.at(index);
            parent = curr;
            curr = curr->children[ch];
            index++;
        }

        if (!curr)
        {
            index--;
            curr = parent;
        }

        for (; index < wordLen; index++)
        {
            char ch = word.at(index);
            auto node = make_shared<Node>(ch);
            curr->children[ch] = node;
            curr = node;
        }

        curr->word = word;
    }

    bool IsWordPresent(string word)
    {
        int index = 0;
        int wordLen = word.length();
        shared_ptr<Node> curr = m_root;
        while (curr && index < wordLen)
        {
            char ch = word.at(index);
            curr = curr->children[ch];
            index++;
        }

        return (curr && (0 == curr->word.compare(word))) ? true : false;
    }

    bool IsPrefixPresent(string prefix)
    {
        int index = 0;
        int prefixLen = prefix.length();
        shared_ptr<Node> curr = m_root;
        while (curr && index < prefixLen)
        {
            char ch = prefix.at(index);
            curr = curr->children[ch];
            index++;
        }

        return curr == nullptr ? false : true;
    }

private:
    struct Node
    {
        Node(char ch)
        {
            letter = ch;
        }
        char letter;
        string word;
        unordered_map<char, shared_ptr<Node>> children;
    };

    shared_ptr<Node> m_root;
};
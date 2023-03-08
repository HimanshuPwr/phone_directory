#pragma once
#include <bits/stdc++.h>
namespace Trietree
{
    class TrieNode
    {
    public:
        bool istermi;
        TrieNode *children[36];
        std::vector<long long> keys;

        TrieNode()
        {
            istermi = false;
            keys = {};
            for (int i = 0; i < 36; i++)
            {
                children[i] = nullptr;
            }
        }
    };

    class TrieTree : private TrieNode
    {
    public:
        TrieNode *root;

        void insert_node(std::string word, TrieNode *node, long long key);
        void DFS(std::vector<long long> &matches, TrieNode *node);
        std::vector<long long> full_search(std::string target, TrieNode *node);
        std::vector<long long> part_search(std::string target, TrieNode *node);

        TrieTree()
        {
            root = new TrieNode();
        }
    };

    void TrieTree::insert_node(std::string word, TrieNode *node, long long key)
    {
        int index;
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (word[0] == '+')
            word[0] = '0';
        if (word[0] >= 48 && word[0] <= 57)
            index = 22;
        else
            index = 97;

        for (int i = 0; i < word.size(); i++)
        {
            if (node->children[word[i] - index] == nullptr)
                node->children[word[i] - index] = new TrieNode();

            node = node->children[word[i] - index];
        }
        node->istermi = true;
        node->keys.push_back(key);
    }

    std::vector<long long> TrieTree::full_search(std::string target, TrieNode *node)
    {
        int index;
        std::vector<long long> res;
        if (target[0] == '+')
            target[0] = '0';
        if (target[0] >= 48 && target[0] <= 57)
            index = 22;
        else
            index = 97;

        for (int i = 0; i < target.size(); i++)
        {
            if (node->children[target[i] - index] == nullptr)
                return res;
            node = node->children[target[i] - index];
        }
        if (node->istermi == true)
            return node->keys;
        else
            return res;
    }

    void TrieTree::DFS(std::vector<long long> &matches, TrieNode *node)
    {
        if (node->istermi == true)
        {
            for (int i = 0; i < node->keys.size(); i++)
                matches.push_back(node->keys[i]);
        }
        for (int i = 0; i < 36; i++)
        {
            if (node->children[i] != nullptr)
                DFS(matches, node->children[i]);
        }
    }

    std::vector<long long> TrieTree::part_search(std::string target, TrieNode *node)
    {
        int index;
        std::vector<long long> matches;
        if (target[0] == '+')
            target[0] = '0';
        if (target[0] >= 48 && target[0] <= 57)
            index = 22;
        else
            index = 97;

        for (int i = 0; i < target.size(); i++)
        {
            if (node->children[target[i] - index] == nullptr)
                return matches;
            node = node->children[target[i] - index];
        }

        DFS(matches, node);

        return matches;
    }

}

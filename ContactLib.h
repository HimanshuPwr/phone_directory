#pragma once
#include <bits/stdc++.h>
using namespace std;
namespace ContactLib
{
    class TrieNode
    {
    public:
        bool istermi;
        TrieNode *children[36];
        vector<string> tel_num;

        TrieNode()
        {
            istermi = false;
            for (int i = 0; i < 36; i++)
                children[i] = nullptr;
        }
    };

    class TrieTree
    {
    public:
        TrieNode *root;
        TrieTree()
        {
            root = new TrieNode();
        }

        void insert_node(string word, TrieNode *node, string number)
        {
            int index;
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
            node->tel_num.push_back(number);
        }

        vector<string> full_search(string target, TrieNode *node)
        {
            int index;
            vector<string> res;
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
                return node->tel_num;
            else
                return res;
        }

        void DFS(vector<string> &matches, TrieNode *node)
        {
            if (node->istermi == true)
            {
                for (int i = 0; i < node->tel_num.size(); i++)
                    matches.push_back(node->tel_num[i]);
            }
            for (int i = 0; i < 36; i++)
            {
                if (node->children[i] != nullptr)
                    DFS(matches, node->children[i]);
            }
        }

        vector<string> part_search(string target, TrieNode *node)
        {
            int index;
            vector<string> matches;
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
    };

    class Contact_Management
    {
    public:
        TrieTree first, last, numbers;
        unordered_map<string, pair<string, string>> mp;

        void insert_details(string f, string l, string n)
        {
            mp[n] = {f, l};
            first.insert_node(f, first.root, n);
            last.insert_node(l, last.root, n);
            numbers.insert_node(n, numbers.root, n);
        }

        vector<vector<string>> search_first(string target, int type)
        {
            vector<vector<string>> ans;
            vector<string> res;
            if (type == 1)
            {
                res = first.full_search(target, first.root);
            }
            else // if(type==2)
            {
                res = first.part_search(target, first.root);
            }

            if (res.empty() == true)
                return ans;
            else
            {
                for (int i = 0; i < res.size(); i++)
                {
                    vector<string> temp;
                    temp.push_back(mp[res[i]].first);
                    temp.push_back(mp[res[i]].second);
                    temp.push_back(res[i]);
                    ans.push_back(temp);
                }
            }
            return ans;
        }

        vector<vector<string>> search_last(string target, int type)
        {
            vector<vector<string>> ans;
            vector<string> res;
            if (type == 1)
            {
                res = last.full_search(target, last.root);
            }
            else // if(type==2)
            {
                res = last.part_search(target, last.root);
            }

            if (res.empty() == true)
                return ans;
            else
            {
                for (int i = 0; i < res.size(); i++)
                {
                    vector<string> temp;
                    temp.push_back(mp[res[i]].first);
                    temp.push_back(mp[res[i]].second);
                    temp.push_back(res[i]);
                    ans.push_back(temp);
                }
            }
            return ans;
        }

        vector<vector<string>> search_numbers(string target, int type)
        {
            vector<vector<string>> ans;
            vector<string> res;
            if (type == 1)
            {
                res = numbers.full_search(target, numbers.root);
            }
            else // if(type==2)
            {
                res = numbers.part_search(target, numbers.root);
            }

            if (res.empty() == true)
                return ans;
            else
            {
                for (int i = 0; i < res.size(); i++)
                {
                    vector<string> temp;
                    temp.push_back(mp[res[i]].first);
                    temp.push_back(mp[res[i]].second);
                    temp.push_back(res[i]);
                    ans.push_back(temp);
                }
            }
            return ans;
        }
    };
}
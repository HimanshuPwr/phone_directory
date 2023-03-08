#pragma once
#include <bits/stdc++.h>
#include "Trietree.h"
using namespace Trietree;

namespace ContactLib
{

    class Contact_Management
    {
        TrieTree first, last, numbers;
        std::vector<long long> line_keys;

    public:
        void insert_details(std::string f, std::string l, std::string n, long long pos, long long line_no);
        std::vector<long long> search_first(std::string target, int type);
        std::vector<long long> search_last(std::string target, int type);
        std::vector<long long> search_numbers(std::string target, int type);
    };

    void Contact_Management::insert_details(std::string f, std::string l, std::string n, long long pos, long long line_no)
    {
        line_keys.push_back(pos);
        first.insert_node(f, first.root, line_no);
        last.insert_node(l, last.root, line_no);
        numbers.insert_node(n, numbers.root, line_no);
    }

    std::vector<long long> Contact_Management::search_first(std::string target, int type)
    {
        std::vector<long long> res;
        std::vector<long long> ans = {};
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
                ans.push_back(line_keys[res[i]]);
            }
        }
        return ans;
    }

    std::vector<long long> Contact_Management::search_last(std::string target, int type)
    {
        std::vector<long long> ans;
        std::vector<long long> res;
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
                ans.push_back(line_keys[res[i]]);
            }
        }
        return ans;
    }

    std::vector<long long> Contact_Management::search_numbers(std::string target, int type)
    {
        std::vector<long long> ans;
        std::vector<long long> res;
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
                ans.push_back(line_keys[res[i]]);
            }
        }
        return ans;
    }
}

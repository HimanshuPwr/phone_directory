#include <bits/stdc++.h>
#include "ContactLib.h"
using namespace std;

using namespace ContactLib;

signed main()
{
    bool flag = true;
    Contact_Management obj;
    clock_t tstart = clock();

    fstream f;
    f.open("data.csv", ios::in);
    string line, word;
    vector<string> w_line;
    if (f.is_open())
    {
        while (getline(f, line))
        {
            w_line.clear();
            stringstream s(line);
            while (getline(s, word, ','))
            {

                w_line.push_back(word);
            }
            obj.insert_details(w_line[0], w_line[1], w_line[2]);
        }
    }
    else
    {
        cout << "Unable to open file!";
    }

    tstart = clock() - tstart;
    cout << "Time takken insert: " << (float)tstart / CLOCKS_PER_SEC << "\n";
    tstart = clock();

    f.close();

    string x = "+441234567890";
    transform(x.begin(), x.end(), x.begin(), ::tolower);
    x[0] = toupper(x[0]);
    vector<vector<string>> answer = obj.search_numbers(x, 1);

    if (answer.empty() == true)
        cout << "NOT FOUND!! \n";
    else
    {
        for (int i = 0; i < answer.size(); i++)
        {
            cout << answer[i][0] << " " << answer[i][1] << " " << answer[i][2] << "\n";
        }
    }

    tstart = clock() - tstart;
    cout << "Time takken search: " << (float)tstart / CLOCKS_PER_SEC;
    return 0;
}
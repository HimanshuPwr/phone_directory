#include <bits/stdc++.h>
#include "ContactLib.h"

using namespace ContactLib;
using namespace std;

void process_data(string file_name, Contact_Management &obj)
{
    fstream f;
    f.open(file_name, ios::in);
    string line, word;
    vector<string> w_line;
    long long pos = 0;
    if (f.is_open())
    {
        int line_no = 0;
        while (getline(f, line))
        {
            w_line.clear();
            stringstream s(line);
            while (getline(s, word, ','))
            {

                w_line.push_back(word);
            }
            obj.insert_details(w_line[0], w_line[1], w_line[2], pos, line_no);
            pos = f.tellg();
            line_no++;
        }
    }
    else
    {
        cout << "Unable to open file!"
             << "\n";
    }

    f.close();
}

void display(vector<long long> answer)
{
    if (answer.empty() == true)
        cout << "NOT FOUND!! \n";
    else
    {
        fstream f;
        f.open("data.csv", ios::in);

        cout << "\nCONTACTS MATCHING YOUR SEARCH ARE:"
             << "/n/n";
        for (int i = 0; i < answer.size(); i++)
        {
            f.seekg(answer[i]);
            string line, word;
            getline(f, line);
            stringstream s(line);
            while (getline(s, word, ','))
            {

                cout << word << " ";
            }
            cout << "\n";
        }
        cout << "\nTOTAL NUMBER OF SEARCH RESULTS: " << answer.size();
        f.close();
    }
}

signed main()
{
    bool flag = true;
    Contact_Management obj;
    vector<long long> answer;
    string file_name = "data.csv";

    clock_t tstart = clock();

    process_data(file_name, obj);

    tstart = clock() - tstart;
    cout << "Time taken to process data: " << (float)tstart / CLOCKS_PER_SEC << "\n\n";

    cout << "\n********************** WELCOME TO THE PHONE DIRECTORY **********************\n\n";
    cout << "ENTER THE FIELD YOU WANT TO SEARCH ON:\n";
    cout << "1. FIRST NAME\n";
    cout << "2. LAST NAME\n";
    cout << "3. PHONE NUMBER\n";
    cout << "4. EXIT\n";

    int choice, type;
    string x;
    cin >> choice;

    cout << "ENTER THE TYPE OF SEARCH:\n";
    cout << "1. EXACT or FULL SEARCH\n";
    cout << "2. PARTIAL SEARCH\n";
    cin >> type;

    switch (choice)
    {
    case 1:

        cout << "\nPLEASE ENTER THE FIRST NAME YOU WANT TO SEARCH:\n";
        cin >> x;
        transform(x.begin(), x.end(), x.begin(), ::tolower);
        tstart = clock();
        answer = obj.search_first(x, type);
        tstart = clock() - tstart;
        break;

    case 2:

        cout << "\nPLEASE ENTER THE LAST NAME YOU WANT TO SEARCH:\n";
        cin >> x;
        transform(x.begin(), x.end(), x.begin(), ::tolower);
        tstart = clock();
        answer = obj.search_last(x, type);
        tstart = clock() - tstart;
        break;

    case 3:

        cout << "\nPLEASE ENTER THE PHONE NUMBER YOU WANT TO SEARCH:\n";
        cin >> x;
        transform(x.begin(), x.end(), x.begin(), ::tolower);
        tstart = clock();
        answer = obj.search_numbers(x, type);
        tstart = clock() - tstart;
        break;

    default:
        break;
    }

    display(answer);

    cout << "\nTime taken to search: " << (float)tstart / CLOCKS_PER_SEC;
    return 0;
}

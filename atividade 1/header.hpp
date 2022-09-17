#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> dictionary;

int menu()
{
    int menu_option;

    cout << "-------------------------" << endl;
    cout << "UFxC String Store V.0" << endl;
    cout << "1. Insert string" << endl;
    cout << "2. Print index and string" << endl;
    cout << "3. Search string (literal)" << endl;
    cout << "4. Search substrings" << endl;
    cout << "5. Remove string (by index)" << endl;
    cout << "6. Remove by substrings (all occurrences)" << endl;
    cout << endl;
    cout << "0. Quit" << endl;
    cout << "-------------------------" << endl;

    cin >> menu_option;

    return menu_option;
}

vector<string> insert_string(vector<string> &dictionary)
{
    string result;

    cout << "-------------------------" << endl;
    cout << "type your String to insert" << endl;
    cout << "-------------------------" << endl;

    cin >> result;

    dictionary.push_back(result);

    return dictionary;
}

void show_dictionary(vector<string> &dictionary)
{
    cout << "-------------------------" << endl;
    for (size_t i = 0; i < dictionary.size(); i++)
    {
        cout << "Index: " << i << ". String: " << dictionary.at(i) << endl;
    }
    cout << "-------------------------" << endl;
}

void vizualization_time()
{
    string a;

    cout << "Press Enter to continue" << endl;
    cout << "-------------------------" << endl;

    cin.ignore();
    getline(cin, a);
}

void search_string(vector<string> &dictionary)
{
    string search;
    cout << "-------------------------" << endl;
    cout << "Insert the String that you want to search for:" << endl;
    cout << "-------------------------" << endl;

    cin >> search;

    for (size_t i = 0; i < dictionary.size(); i++)
    {
        if (search == dictionary[i])
        {
            cout << "Index: " << i << ". String: " << dictionary.at(i) << endl;
        }
    }
}

bool match_substring(string &word, string &substring, size_t i, size_t j)
{
    if (word.at(i) == substring.at(j))
    {
        i++;
        j++;
        if (i > word.size())
        {
            return false;
        }
        if (j == substring.size())
        {
            return true;
        }
        else
        {
            match_substring(word, substring, i, j);
        }
    }
    else
    {
        i++;
        j = 0;
        if (i >= word.size())
        {
            return false;
        }
        else
        {
            match_substring(word, substring, i, j);
        }
    }
}

void search_substring(vector<string> &dictionary)
{
    string search;
    cout << "-------------------------" << endl;
    cout << "Insert the susbtring that you want to search for:" << endl;
    cout << "-------------------------" << endl;

    cin >> search;

    for (size_t i = 0; i < dictionary.size(); i++)
    {
        if (match_substring(dictionary.at(i), search, 0, 0) == true)
        {
            cout << "Index: " << i << ". String: " << dictionary.at(i) << endl;
        }
    }
}

void remove_string_by_index(vector<string> &dictionary)
{
    int index;
    cout << "-------------------------" << endl;
    cout << "Insert the index that you want to remove:" << endl;
    cout << "-------------------------" << endl;
    cin >> index;

    dictionary.erase(dictionary.begin() + index);
}

void remove_string_by_substring(vector<string> &dictionary)
{
    string search;
    cout << "-------------------------" << endl;
    cout << "Insert the substring that you want to remove:" << endl;
    cout << "!!! Notice that all strings with that substring will be removed" << endl;
    cout << "-------------------------" << endl;

    cin >> search;
    size_t i = 0;
    while (i < dictionary.size())
    {
        if (match_substring(dictionary.at(i), search, 0, 0) == true)
        {
            dictionary.erase(dictionary.begin() + i);
        }else{
        i++;
        }
    }
}

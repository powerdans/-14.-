#pragma once
#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 26;
struct Tnote
{
    struct Tnote* children[SIZE];
    bool OfWord;
    Tnote();
    ~Tnote();
};
class tree
{
public:
    tree();
    ~tree();
    Tnote* getNewNode();
    void insert(Tnote* root, const string& key);
    Tnote* search(const string& key);
    void dictionary();
    string entPref();
    vector<string> vectorWords(Tnote* pNode, string str, vector<string> vec);
    void prefix(string pref);
private:
    Tnote* root;
};
#include "Header.h"
#include <string>
using namespace std;
Tnote::Tnote() {
    OfWord = false;
    for (int i = 0; i < SIZE; i++)
        children[i] = nullptr;
}
Tnote::~Tnote() {
    for (int i = 0; i < SIZE; i++)
        if (children[i])
            delete children[i];
}
tree::tree() {    
    root = new Tnote();          }
tree::~tree() { 
    if (root)delete root;
}
Tnote* tree::getNewNode() {
    struct Tnote* pNode = new Tnote;
    pNode->OfWord = false;
    for (int i = 0; i < SIZE; i++)
        pNode->children[i] = nullptr;
    return pNode;
}
void tree::insert(Tnote* root, const string& key) {
    Tnote* pINNode = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pINNode->children[index])
        {
            pINNode->children[index] = getNewNode();
        }
        pINNode = pINNode->children[index];
    }
    pINNode->OfWord = true;
}
Tnote* tree::search(  const string& key  ) {
    Tnote* current = root;
    for (size_t i = 0; i < key.size(); i++)
    {
        int index = key[i] - 'a';
        if (current->children[index] && (index < SIZE && index >= 0))
        {
            current = current->children[index];
        }
        else
        {
            current = nullptr; break;
        }
    }
    return current;
}
vector<string> tree::vectorWords(Tnote* pNode, string str, vector<string> vec) {
    if (pNode->OfWord && str.size())
    {
        vec.push_back(str);
    }

    for (int i = 0; i < SIZE; i++)
    {
        string curr = str;
        if (pNode->children[i])
        {
            curr += i + 'a';
            vec = vectorWords(pNode->children[i], curr, vec);
        }
    }
    return vec;
}
void tree::prefix(string stroka) {
    setlocale(LC_ALL, "");
    vector<string> temp;
    Tnote* current = search(stroka);
    if (current == nullptr || current == root)
    {
        return;
    }
    vector<string> vec = vectorWords(current, stroka, temp);
    if (vec.empty())
    {
        cout << "мер якнб: " << stroka << endl;
        return;
    }
    else
    {
        cout << " KLIC Enter :  " << stroka << endl << endl;
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i];
            cout << endl << endl;
            int put = cin.get();
            cout << endl << endl;
            if (put == 13)
            {
                cout << vec[i]; break;
            }
        }
    }
}
string tree::entPref() {
    setlocale(LC_ALL, "");
    cout << "ббедхре опет: ";
    string str;
    cin >> str;
    cout << endl;
    for (int i = 0; i < str.size(); i++)
        str[i] = tolower(str[i]);
    return str;
}
void tree::dictionary()
{
    insert(root, "test");
}
#include"Header.h"
#include <string>
using namespace std;

int main()
{
    tree trie;
    trie.dictionary(); cout << endl << endl;
    cout << "dfdtrdv" << endl << endl << endl;
    trie.prefix("te");
    cout << "" << endl << endl;
    string pref = trie.entPref(); trie.prefix(pref);
    cout << "asassaas" << endl << endl;
    return 0;
}

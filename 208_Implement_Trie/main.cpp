#include "header3.h"

int main(char** args, int argc)
{
    Trie* obj = new Trie();
    obj->insert("word");
    obj->insert("hello");
    obj->insert("world");
    bool param_2 = obj->search("word");
    bool param_3 = obj->startsWith("wo");

    return 0;
}
#include "header2.h"

int main(char** args, int argc)
{

    //"addWord", "addWord", "addWord", "addWord", "search", "search", "addWord", "search", "search", "search", "search", "search", "search"]
    //["at"],     ["and"],   ["an"],    ["add"],   ["a"],    [".at"],  ["bat"],   [".at"],   ["an."], ["a.d."], ["b."],   ["a.d"],  ["."]]
    
    WordDictionary* obj = new WordDictionary();
    obj->addWord("at");
    obj->addWord("and");
    obj->addWord("an");
    obj->addWord("add");
    bool param_2 = obj->search("a");
    param_2 = obj->search(".at");
    obj->addWord("bat");
    param_2 = obj->search(".at");
    param_2 = obj->search("an.");
    param_2 = obj->search("a.d.");
    param_2 = obj->search("b.");
    param_2 = obj->search("a.d");
    param_2 = obj->search(".");

    return 0;
}
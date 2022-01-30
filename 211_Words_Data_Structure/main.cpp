#include "revisit.h"

int main(char** args, int argc)
{
    WordDictionary* obj = new WordDictionary();

    // Test1
    //"addWord", "addWord", "addWord", "addWord", "search", "search", "addWord", "search", "search", "search", "search", "search", "search"]
    //["at"],     ["and"],   ["an"],    ["add"],   ["a"],    [".at"],  ["bat"],   [".at"],   ["an."], ["a.d."], ["b."],   ["a.d"],  ["."]]

    //obj->addWord("at");
    //obj->addWord("and");
    //obj->addWord("an");
    //obj->addWord("add");
    //bool param_2 = obj->search("a");
    //param_2 = obj->search(".at");
    //obj->addWord("bat");
    //param_2 = obj->search(".at");
    //param_2 = obj->search("an.");
    //param_2 = obj->search("a.d.");
    //param_2 = obj->search("b.");
    //param_2 = obj->search("a.d");
    //param_2 = obj->search(".");

    // Test2
    //obj->addWord("a");
    //obj->addWord("a");
    //bool param_2 = obj->search(".");
    //param_2 = obj->search("a");
    //param_2 = obj->search("aa");
    //
    //param_2 = obj->search("a");
    //param_2 = obj->search(".a");
    //param_2 = obj->search("a.");

// Test 3
    //["WordDictionary", "addWord", "addWord", "addWord", "search", "search", "search", "search"]
    //[[], ["bad"], ["dad"], ["mad"], ["pad"], ["bad"], [".ad"], ["b.."]]

    obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");
    bool param_2 = obj->search("pad");
    param_2 = obj->search("bad");
    param_2 = obj->search(".ad");
    param_2 = obj->search("b..");

    return 0;
}
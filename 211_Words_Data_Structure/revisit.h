#include "..\common\common.h"

class WordDictionary {

    struct LetterNode
    {
        bool isWord;
        LetterNode* next;

        LetterNode()
        {
            isWord = false;
            next = nullptr;
        }
    };

public:
    WordDictionary()
    {
        dictionary = new LetterNode[26];
    }

    void addWord(string word) {
        LetterNode* letters = dictionary;
        for (int i = 0; i < word.length(); i++)
        {
            if (letters[word[i] - 'a'].next == nullptr)
            {
                letters[word[i] - 'a'].next = new LetterNode[26];
            }

            if (i == word.length() - 1)
            {
                letters[word[i] - 'a'].isWord = true;
            }

            letters = letters[word[i] - 'a'].next;
        }

    }

    bool search(string word)
    {
        return IsWord(dictionary, word, 0);
    }

private:

    bool IsWord(LetterNode* letters, string& word, int pos)
    {
        for (int i = pos; i < word.length(); i++)
        {
            if (letters == nullptr)
            {
                return false;
            }

            if (word[i] == '.')
            {
                for (int j = 0; j < 26; j++)
                {
                    if (i == word.length() - 1)
                    {
                        if (letters[j].isWord)
                        {
                            return true;
                        }
                    }

                    if (IsWord(letters[j].next, word, i + 1))
                    {
                        return true;
                    }
                }

                return false;
            }
            else
            {
                if (i == word.length() - 1)
                {
                    if (letters[word[i] - 'a'].isWord)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                letters = letters[word[i] - 'a'].next;
            }
        }
        return false;
    }

    LetterNode* dictionary;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
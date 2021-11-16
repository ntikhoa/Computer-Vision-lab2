#include "StringHelper.h"

vector<String> split(String cmd) {
    char space_char = ' ';
    vector<string> words{};

    stringstream sstream(cmd);
    string word;
    while (std::getline(sstream, word, space_char)) {
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        words.push_back(word);
    }

    return words;
}
#include "StringHelper.h"

vector<String> split(String cmd) {
    vector<String> words;

    String c = "";
    for (int i = 0; i < cmd.size(); i++) {
        if (cmd[i] != ' ') {
            c += cmd[i];
        }
        else {
            words.push_back(c);
            c = "";
        }
    }
    words.push_back(c);
    return words;
}
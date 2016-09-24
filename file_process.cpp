//
// Created by 廖建国 on 15/10/17.
//


#include <sstream>
#include "file_process.h"


map<string, string> build_map(ifstream &map_file) {
    map<string, string> trans_map;
    string key, value;
    while(map_file >> key && getline(map_file, value)){
        if(value.size() > 1)    trans_map[key] = value.substr(1);
        else
            throw runtime_error("no rule for " + key);
    }
    return trans_map;
}

const string &transform(const string &s, const map<string, string> &m) {
    auto map_it = m.find(s);
    if(map_it != m.end())  return map_it->second;// 不能用m[s]???
    else    return s;
}

void word_transform(ifstream &map_file, ifstream &input) {
    auto trans_map = build_map(map_file);
    string string1;

    while (getline(input , string1)){
        istringstream str(string1);
        string word;
        cout << word << endl;
        while (str >> word)     cout << transform(word,trans_map) << " ";
        cout << endl;
    }

}

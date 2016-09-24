//
// Created by 廖建国 on 15/10/17.
//


#ifndef LEARNALGORITHM_FILE_PROCESS_H
#define LEARNALGORITHM_FILE_PROCESS_H

#include <fstream>
#include <iostream>
#include <map>

using namespace std;  //原来漏了这一行呀

void word_transform(ifstream &map_file, ifstream &input);
map<string, string> build_map(ifstream &map_file);
const string &transform(const string &s, const map<string, string> &m);

#endif //LEARNALGORITHM_FILE_PROCESS_H

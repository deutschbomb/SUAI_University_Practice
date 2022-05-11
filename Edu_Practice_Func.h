#ifndef EDU_PRACTICE_FUNC_H_
#define EDU_PRACTICE_FUNC_H_

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

void read_text(int __text_num, string& main_text);
void write_result(int __text_num, vector <string> Words, vector <int>& WordsOnLetter_Count);
void write_analyze(int __text_num, string main_text, int words_count, int sort_time, vector <int> WordsOnLetter_Count);
vector <string> separate_words(string S);
void bubble_sort(vector <string>& __Words, int& __sort_time);
char __tolower(char SYM);

#endif
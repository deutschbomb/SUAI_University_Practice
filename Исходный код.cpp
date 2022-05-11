/*--------------------------------------------------------------------------------------------------|
|	����� 0: "������ ����������, ������ �� ������"													|
|	����� 1: "������ ����������, ���� ����������"													|
|	����� 2: "������ ��������, ������ � ���������"													|
|	����� 3: "��� �������, ������ ������ ���"														|
|	����� 4: "������ ����������, ������ ���� �����"													|
|	����� 5: "��������� ������, ������ �������"														|
|	����� 6: "��������� ������, ������ � ������ � �����"											|
|	����� 7: "��������� ������, ������� ������"														|
|	����� 8: "������ ���������, ����� ������ �������"												|
|	����� 9: "������ ����������, ����� � Ҹ���� ����"												|
|---------------------------------------------------------------------------------------------------|*/

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

#include "Edu_Practice_Func.h" // ����������� ����� � ������������ ���������

using namespace std;

void main() {
	SetConsoleOutputCP(1251);	// ��������� ��������� � ������� (�����)
	SetConsoleCP(1251);			// ��������� ��������� � ������� (����)

	int text_num, sort_time;
	string main_text;
	vector<int> WordsOnLetter_Count(33);
			
	cout << "������� ����� ������ (�� 0 �� 9): "; cin >> text_num;
	read_text(text_num, main_text);
	vector <string> Words = separate_words(main_text);
	bubble_sort(Words, sort_time);
	int words_count = Words.size();

	write_result(text_num, Words, WordsOnLetter_Count);
	write_analyze(text_num, main_text, words_count, sort_time, WordsOnLetter_Count);

}
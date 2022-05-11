#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

#include "Edu_Practice_Func.h"

using namespace std;

void read_text(int __text_num, string& main_text) {
	fstream fin; // ���������� ��� ������ � ������
	switch (__text_num) // ����������� switch/case ��� �������� ���������� ������
	{
	case 0:
		fin.open("Texts/Text_0.txt", ios_base::in);
		break;
	case 1:
		fin.open("Texts/Text_1.txt", ios_base::in);
		break;
	case 2:
		fin.open("Texts/Text_2.txt", ios_base::in);
		break;
	case 3:
		fin.open("Texts/Text_3.txt", ios_base::in);
		break;
	case 4:
		fin.open("Texts/Text_4.txt", ios_base::in);
		break;
	case 5:
		fin.open("Texts/Text_5.txt", ios_base::in);
		break;
	case 6:
		fin.open("Texts/Text_6.txt", ios_base::in);
		break;
	case 7:
		fin.open("Texts/Text_7.txt", ios_base::in);
		break;
	case 8:
		fin.open("Texts/Text_8.txt", ios_base::in);
		break;
	case 9:
		fin.open("Texts/Text_9.txt", ios_base::in);
		break;
	default:
		cout << " ������ ������ ���." << endl;
		break;
	}
	while (!fin.eof()) {
		main_text += fin.get(); // ������������ ������ ��������� ������
	}
	main_text.erase(main_text.length() - 1); // �������� ���������� ������� ������� � ������
	fin.close(); // �������� ����� � ��������� �������
}	// ������� ��� �������� � ������ ������� ������

void write_result(int __text_num, vector <string> __Words, vector <int>& WordsOnLetter_Count) {
	fstream fout; // ���������� ��� ������ � ������
	int first_sym = -33, letter = 0;
	switch (__text_num) // ����������� switch/case ��� �������� ���������� ������
	{
	case 0:
		fout.open("Results/Result_Text_0.txt", ios_base::out);
		break;
	case 1:
		fout.open("Results/Result_Text_1.txt", ios_base::out);
		break;
	case 2:
		fout.open("Results/Result_Text_2.txt", ios_base::out);
		break;
	case 3:
		fout.open("Results/Result_Text_3.txt", ios_base::out);
		break;
	case 4:
		fout.open("Results/Result_Text_4.txt", ios_base::out);
		break;
	case 5:
		fout.open("Results/Result_Text_5.txt", ios_base::out);
		break;
	case 6:
		fout.open("Results/Result_Text_6.txt", ios_base::out);
		break;
	case 7:
		fout.open("Results/Result_Text_7.txt", ios_base::out);
		break;
	case 8:
		fout.open("Results/Result_Text_8.txt", ios_base::out);
		break;
	case 9:
		fout.open("Results/Result_Text_9.txt", ios_base::out);
		break;
	default:
		cout << " ������ ������ ���." << endl;
		break;
	}
	while (first_sym != -1) { // ���� ��� ������ ��������������� ���� � ����
		first_sym++; // ������� �� ��������� ����� ��������
		int _words_count = 0; // ������� ���������� ����, ������������ �� ����������� �����
		for (int i = 0; i < __Words.size(); i++) { // ���� ������� �� ������� ����
			if (__tolower(__Words[i][0]) == (char)first_sym) {	// ���� ����� ���������� � �������� �����,
				fout << ' ' << __Words[i];						// �� ������� ����� � ����
				_words_count++;									// � ��������� ������� ����
			}
		}
		WordsOnLetter_Count[letter] = _words_count; // �������� � ������ ���������� ����, ������������ �� ����������� �����
		if (_words_count > 0) { // ���� �������� ���� �� ���� �����,
			fout << endl;		// �� ������� � ����� �� ��������� ������
		}
		if ((char)first_sym == '�') { // ���� ��� ������� ������������� ����� "�",
			first_sym = (int)'�' - 1; // �� �������� ��� ������� �� ���������� ����� "�"
		}
		if ((char)first_sym == '�') { // ���� ��� ������� ������������� ����� "�",
			first_sym = (int)'�' - 1; // �� �������� ��� ������� �� ���������� ����� "�"
		}
		letter++; // ������� �� ��������� ����� � �������
	}
}	// ������� ��� ������ ����������

void write_analyze(int __text_num, string main_text, int words_count, int sort_time, vector <int> WordsOnLetter_Count) {
	fstream fout; // ���������� ��� ������ � ������
	int first_sym = -32;
	switch (__text_num) // ����������� switch/case ��� �������� ���������� ������
	{
	case 0:
		fout.open("Analyzes/Analyze_Text_0.txt", ios_base::out);
		break;
	case 1:
		fout.open("Analyzes/Analyze_Text_1.txt", ios_base::out);
		break;
	case 2:
		fout.open("Analyzes/Analyze_Text_2.txt", ios_base::out);
		break;
	case 3:
		fout.open("Analyzes/Analyze_Text_3.txt", ios_base::out);
		break;
	case 4:
		fout.open("Analyzes/Analyze_Text_4.txt", ios_base::out);
		break;
	case 5:
		fout.open("Analyzes/Analyze_Text_5.txt", ios_base::out);
		break;
	case 6:
		fout.open("Analyzes/Analyze_Text_6.txt", ios_base::out);
		break;
	case 7:
		fout.open("Analyzes/Analyze_Text_7.txt", ios_base::out);
		break;
	case 8:
		fout.open("Analyzes/Analyze_Text_8.txt", ios_base::out);
		break;
	case 9:
		fout.open("Analyzes/Analyze_Text_9.txt", ios_base::out);
		break;
	default:
		cout << " ������ ������ ���." << endl;
		break;
	}
	fout << " �������� �����:" << endl;
	fout << main_text << "\n\n";
	fout << "������� 13: ���������, �� ��������, �� �����������, ������������ �����, ���������� ���������" << endl;
	fout << "���������� ����: " << words_count << endl;
	fout << "����� ����������: " << sort_time << " ���" << endl;
	fout << "���������� (���������� ���� �� ������ ����� ��������):" << endl;
	for (int i = 0; i < WordsOnLetter_Count.size(); i++) { // ���� ������� �� ������� � ����������� ����, ������������ �� ����������� �����
		fout << (char)first_sym << " - " << WordsOnLetter_Count[i] << endl; /* ����� ����� �������� � ���������������� ���������� ����,
																			������������ �� ����������� ����� */
		if (first_sym == -27) {												// ���� ��� ������� ������������� ����� "�",
			i++;															// �� ��������� ��������
			fout << (char)-72 << " - " << WordsOnLetter_Count[i] << endl;	// � ������� ���������� ����, ������������ �� ����� "�"
		}
		first_sym++; // ������� �� ��������� ����� ��������
	}
}	// ������� ��� ������ �������

vector <string> separate_words(string S) {
	vector <string> Words;
	string word;
	for (int i = 0; i < S.length() - 1; i++) { // ���� ������� �� ������������ ������
		char letter = S[i]; // ������ ������ �� ������
		while (letter == '�' || letter == '�' || (letter >= -64 && letter <= -1)) { // ���� ������ ������ �������� ������ �������� ��������,
			word += S[i];															// �� �������� ����� � ������,
			i++;																	// ��������� ��������,
			letter = S[i];															// � ����� ������ �� ���� ���������
			if (i != S.length()) {				// ���� �������� �� ������� �� ������� ������,
				char next_letter = S[i + 1];	// �� ����� ��������� ������ ��� ��������
				if (S[i] == '-' && (next_letter == '�' || next_letter == '�' || (next_letter >= -64 && next_letter <= -1))) {
									// ���� ������ �������� �������, � ������ ��� �����,
					word += S[i];	// �� �������� ������ � ������
					i++;			// ��������� ��������,
					letter = S[i];	// � ����� ������ �� ���� ���������
				}
			}
		}
		if (word.size() > 0) {		// ���� ������ �� ������,
			Words.push_back(word);	// �� �������� � � ������� ����
			word.clear();			// � �������� ������
		}
	}
	return Words; // ������� ������ ���������� ����
}	// ������� ���������� ������ �� �����

void bubble_sort(vector <string>& Words, int& sort_time) {
	int i = -1;
	bool Flag;
	int start_sort = clock(); // ����� ������ ����������
	do {
		i++; // ���������� ���������
		Flag = false; // ���������� ����� �������� "False"
		for (int j = Words.size() - 1; j > i; j--) { // ���� ������� �� ������� ��������������� ����
			if (Words[j - 1] > Words[j]) {		// ���� ������ �������� ����� ����� ����� � �������� ������, ��� ����� ���������� �����,
				swap(Words[j - 1], Words[j]);	// �� �������� ������� �����,
				Flag = true;					// � ��������� ����� �������� "True"
			}
		}
	} while (Flag == true); // ��������� ���� ���� ���� �� ����� ����� �������� "True"
	int stop_sort = clock(); // ����� ��������� ����������
	sort_time = (stop_sort - start_sort) / 1000; // ���������� ������� ���������� � ��������
}	// ������� ���������� ���������

char __tolower(char SYM) {
	int code; // �������� ���������� ��� ���� �������

	if ((int)SYM == -88) // ���� �������� ����� - "�", �� ������������ ������ - "�"
		code = -72;

	else if ((int)SYM >= -64 && (int)SYM <= -33)	// ���� �������� ������ - ����� ��������� �������� ��������,
		code = (int)SYM + 32;						// �� ��� ������������� ������� - ��������������� ����� ������� ��������

	else code = (int)SYM; // ���� ����� � ������ ��������, �� ������� � ��� ���������

	return (char)code; // ����������� �������� ���������� �������
}	// �������, ����������� ����� � ������ �������
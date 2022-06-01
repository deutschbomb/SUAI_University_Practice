#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

#include "Edu_Practice_Func.h"

using namespace std;

int read_text(int __text_num, string& main_text) {
	fstream fin; // переменная для работы с файлом
	switch (__text_num) // конструкция switch/case для открытия выбранного текста
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
		cout << " Такого текста нет." << endl;
		break;
	}
	if (!fin.is_open()) {
		cout << "Ошибка! Файл не существует." << endl;
		return 0;
	} // проверка, открылся ли необходимый файл
	while (!fin.eof()) {
		main_text += fin.get(); // посимвольное чтение открытого текста
	}
	main_text.erase(main_text.length() - 1); // удаление последнего пустого символа в тексте
	fin.close(); // закрытие файла с выбранным текстом
}	// функция для открытия и чтения нужного текста

void write_result(int __text_num, vector <string> __Words, vector <int>& WordsOnLetter_Count) {
	fstream fout; // переменная для работы с файлом
	int first_sym = -33, letter = 0;
	switch (__text_num) // конструкция switch/case для открытия выбранного текста
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
		cout << " Такого текста нет." << endl;
		break;
	}
	while (first_sym != -1) { // цикл для вывода отсортированных слов в файл
		first_sym++; // переход на следующую букву алфавита
		int _words_count = 0; // счётчик количества слов, начинающихся на определённую букву
		for (int i = 0; i < __Words.size(); i++) { // цикл прохода по массиву слов
			if (__tolower(__Words[i][0]) == (char)first_sym) {	// если слово начинается с заданной буквы,
				fout << ' ' << __Words[i];						// то вывести слово в файл
				_words_count++;									// и увеличить счётчик слов
			}
		}
		WordsOnLetter_Count[letter] = _words_count; // добавить в массив количество слов, начинающихся на определённую букву
		if (_words_count > 0) { // если выведено хотя бы одно слово,
			fout << endl;		// то перейти в файле на следующую строку
		}
		if ((char)first_sym == 'е') { // если код символа соответствует букве "е",
			first_sym = (int)'ё' - 1; // то заменить код символа на предыдущий букве "ё"
		}
		if ((char)first_sym == 'ё') { // если код символа соответствует букве "ё",
			first_sym = (int)'ж' - 1; // то заменить код символа на предыдущий букве "ж"
		}
		letter++; // переход на следующую букву в массиве
	}
}	// функция для вывода результата

void write_analyze(int __text_num, string main_text, int words_count, int sort_time, vector <int> WordsOnLetter_Count) {
	fstream fout; // переменная для работы с файлом
	int first_sym = -32;
	switch (__text_num) // конструкция switch/case для открытия выбранного текста
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
		cout << " Такого текста нет." << endl;
		break;
	}
	fout
		<< " Введённый текст:" << endl
		<< main_text << endl << endl
		<< "Вариант 13: кириллица, по алфавиту, по возрастанию, игнорировать числа, сортировка пузырьком" << endl
		<< "Количество слов: " << words_count << endl
		<< "Время сортировки: " << sort_time << " мс" << endl
		<< "Статистика (количество слов на каждую букву алфавита):" << endl;
	for (int i = 0; i < WordsOnLetter_Count.size(); i++) { // цикл прохода по массиву с количеством слов, начинающихся на определённую букву
		fout << (char)first_sym << " - " << WordsOnLetter_Count[i] << endl; /* вывод буквы алфавита и соответствующего количества слов,
																			начинающихся на определённую букву */
		if (first_sym == -27) {												// если код символа соответствует букве "е",
			i++;															// то увеличить итератор
			fout << (char)-72 << " - " << WordsOnLetter_Count[i] << endl;	// и вывести количество слов, начинающихся на букву "ё"
		}
		first_sym++; // переход на следующую букву алфавита
	}
}	// функция для вывода анализа

vector <string> separate_words(string S) {
	vector <string> Words;
	string word;
	for (int i = 0; i < S.length() - 1; i++) { // цикл прохода по прочитанному тексту
		char letter = S[i]; // взятый символ из текста
		while (letter == 'Ё' || letter == 'ё' || (letter >= -64 && letter <= -1)) { // пока взятый символ является буквой русского алфавита,
			word += S[i];															// то добавить букву в строку,
			i++;																	// увеличить итератор,
			letter = S[i];															// и взять символ на этом итераторе
			if (i != S.length()) {				// если итератор не выходит за пределы текста,
				char next_letter = S[i + 1];	// то взять следующий символ для проверки
				if (S[i] == '-' && (next_letter == 'Ё' || next_letter == 'ё' || (next_letter >= -64 && next_letter <= -1))) {
									// если символ является дефисом, а следом идёт буква,
					word += S[i];	// то добавить символ к строке
					i++;			// увеличить итератор,
					letter = S[i];	// и взять символ на этом итераторе
				}
			}
		}
		if (word.size() > 0) {		// если строка не пустая,
			Words.push_back(word);	// то добавить её к массиву слов
			word.clear();			// и очистить строку
		}
	}
	return Words; // вернуть массив разделённых слов
}	// функция разделения текста на слова

void bubble_sort(vector <string>& Words, int& sort_time) {
	int i = -1;
	bool Flag = true;
	int start_sort = clock(); // время начала сортировки
	while (Flag == true) {	// выполнять цикл пока флаг не будет равен значению "True"
		i++; // увеличение итератора
		Flag = false; // присвоение флагу значения "False"
		for (int j = Words.size() - 1; j > i; j--) { // цикл прохода по массиву несортированных слов
			if (Words[j - 1] > Words[j]) {		// если первая отличная буква слова стоит в алфавите дальше, чем буква следующего слова,
				swap(Words[j - 1], Words[j]);	// то поменять местами слова,
				Flag = true;					// и присвоить флагу значение "True"
			}
		}
	}
	int stop_sort = clock(); // время окончания сортировки
	sort_time = (stop_sort - start_sort)/* / 1000*/; // вычисление времени сортировки в миллисекундах
}	// функция сортировки Пузырьком

char __tolower(char SYM) {
	int code; // создание переменной для кода символа

	if ((int)SYM == -88) // если введённая буква - "Ё", то возвращаемый символ - "ё"
		code = -72;

	else if ((int)SYM >= -64 && (int)SYM <= -33)	// если введённый символ - буква кириллицы верхнего регистра,
		code = (int)SYM + 32;						// то код возвращаемого символа - соответствующая буква нижнего регистра

	else code = (int)SYM; // если буква в нижнем регистре, то вернуть её без изменений

	return (char)code; // возвращение функцией изменённого символа
}	// функция, переводящая букву в нижний регистр
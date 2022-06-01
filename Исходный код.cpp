/*--------------------------------------------------------------------------------------------------|
|	Текст 0: "Братья Стругацкие, Улитка на склоне"													|
|	Текст 1: "Братья Стругацкие, Град обреченный"													|
|	Текст 2: "Михаил Булгаков, Мастер и Маргарита"													|
|	Текст 3: "Кир Булычёв, Умение кидать мяч"														|
|	Текст 4: "Братья Стругацкие, Трудно быть богом"													|
|	Текст 5: "Александр Пушкин, Медный всадник"														|
|	Текст 6: "Александр Пушкин, Сказка о рыбаке и рыбке"											|
|	Текст 7: "Александр Пушкин, Евгений Онегин"														|
|	Текст 8: "Михаил Лермонтов, Герой нашего времени"												|
|	Текст 9: "Сергей Лукьяненко, Поезд в Тёплый Край"												|
|---------------------------------------------------------------------------------------------------|*/

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>


#include "Edu_Practice_Func.h" // подключение файла с собственными функциями

using namespace std;

int main() {
	SetConsoleOutputCP(1251);	// поддержка кириллицы в консоли (вывод)
	SetConsoleCP(1251);			// поддержка кириллицы в консоли (ввод)

	int text_num, sort_time;
	string main_text;
	vector<int> WordsOnLetter_Count(33);
			
	cout << "Введите номер текста (от 0 до 9): "; cin >> text_num;
	if (read_text(text_num, main_text) == 0) {
		cout << "Не удалось открыть файл с выбранным текстом. Проверьте входной файл." << endl;
		return 0;
	}
	vector <string> Words = separate_words(main_text);
	bubble_sort(Words, sort_time);
	int words_count = Words.size();

	write_result(text_num, Words, WordsOnLetter_Count);
	write_analyze(text_num, main_text, words_count, sort_time, WordsOnLetter_Count);

	cout
		<< " Вариант 13: кириллица, по алфавиту, по возрастанию, игнорировать числа,\n сортировка пузырьком" << endl
		<< " Количество слов: " << words_count << endl
		<< " Время сортировки: " << sort_time << " мс" << endl
		<< " Статистика (количество слов на каждую букву алфавита):" << endl;
	for (int i = 0; i < 6; i++) {
		cout << (char)(-32 + i) << " - " << WordsOnLetter_Count[i] << endl;
	}
	cout << (char)(-72) << " - " << WordsOnLetter_Count[6] << endl;
	for (int i = 7; i < WordsOnLetter_Count.size(); i++) {
		cout << (char)(-33 + i) << " - " << WordsOnLetter_Count[i] << endl;
	}
}
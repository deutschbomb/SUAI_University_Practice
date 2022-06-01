# Учебная Практика
### ГУАП, первый курс - II семестр, 2022 г.
________________________________________________________________________________________________________________________________________________________________

В рамках учебной практики необходимо закрепить полученные знания по `C++` на дисциплине ***«Основы программирования»*** и в соответствии с вариантом задания написать программу для сортировки и анализа текстовых данных.
#### Параметры варианта задания:
- символы кириллицы;
- сортировка слов по алфавиту, по возрастанию;
- игнорировать числа;
- сортировка `пузырьком`.

#### Блок-схема основного файла программы:
![Блок-схема](https://user-images.githubusercontent.com/102412482/171272306-14746abf-c5c4-4456-8092-9c1279a79687.png "Блок-схема")

<details>
  <summary>ПРИМЕРЫ КОДА</summary>

#### Пример реализованного алгоритма сортировки пузырьком:
```c++
void bubble_sort(vector <string>& Words, int& sort_time) {
	int i = -1;
	bool Flag;
	int start_sort = clock();
	do {
		i++;
		Flag = false;
		for (int j = Words.size() - 1; j > i; j--) {
			if (Words[j - 1] > Words[j]) {
				swap(Words[j - 1], Words[j]);
				Flag = true;
			}
		}
	} while (Flag == true);
	int stop_sort = clock();
	sort_time = (stop_sort - start_sort)/* / 1000*/;
}
```

#### Пример реализованного алгоритма разделения текста на слова:
```c++
vector <string> separate_words(string S) {
	vector <string> Words;
	string word;
	for (int i = 0; i < S.length() - 1; i++) {
		char letter = S[i];
		while (letter == 'Ё' || letter == 'ё' || (letter >= -64 && letter <= -1)) {
			word += S[i];
			i++;
			letter = S[i];
			if (i != S.length()) {
				char next_letter = S[i + 1];
				if (S[i] == '-' && (next_letter == 'Ё' || next_letter == 'ё' || (next_letter >= -64 && next_letter <= -1))) {
					word += S[i];
					i++;
					letter = S[i];
				}
			}
		}
		if (word.size() > 0) {
			Words.push_back(word);
			word.clear();
		}
	}
	return Words;
}
```
</details>

<details>
  <summary>ПРИМЕРЫ ФАЙЛОВ</summary>

#### Пример файла "result.txt":
![result.txt](https://user-images.githubusercontent.com/102412482/171374781-326350e3-4211-4ef4-a1dd-a2097721575f.png "result.txt")

#### Пример файла "analysis.txt":
![analysis.txt](https://user-images.githubusercontent.com/102412482/171375020-1651a58b-2d48-446b-aa86-dc631536201d.png "analysis.txt")

</details>

#### Несколько результатов работы программы с разными текстами:
| **Время сортировки, мс** | **Количество слов** |
|:------------------------:|:-------------------:|
|            ~90           |         651         |
|           ~113           |         721         |
|           ~195           |         943         |
|           ~357           |        1290         |
|           ~593           |        1643         |
|          ~1188           |        2342         |

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)

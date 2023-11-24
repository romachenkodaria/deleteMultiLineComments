#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <fstream>
#include "CodeString.h"
#include "Code.h"




int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Russian");
	if (argc < 2) {
		std::cout << "Недостаточно аргументов. Использование: " << argv[0] << " <имя_входного_файла>.txt имя_выходного_файла>.txt" << std::endl;
		return 1;
	}

	std::ifstream inputFile(argv[1]);
	std::vector<std::string> lines;

	if (inputFile.is_open()) {

		std::string line;

		// Чтение каждой строки из файла и добавление ее в вектор
		while (std::getline(inputFile, line)) {
			lines.push_back(line);
			if (line.size() > 255)
			{
				std::cout << "Строка под номером " + std::to_string(lines.size()) + " превышает допустимый лимит в 255 символов" << std::endl;
				return 1;
			}
		}

		// Закрытие файла после чтения
		inputFile.close();

		std::vector<std::string> lines1 = {
			"This is a line with // a single-line comment",
			"Another \"line /* \"with a multi-line",
			"comment /*and a  */string/*  literal \"inside\"",
			"No comments or strings */here"
		};

		Code code(lines);
		code.removeMultiLineComments();

		std::ofstream outputFile(argv[2]);

		// Проверка, открыт ли файл успешно
		if (outputFile.is_open())
		{
			// Запись каждой строки вектора в файл
			for (const auto& codeString : code.codeStrings)
			{
				outputFile << codeString.text << std::endl;
			}

			// Закрытие файла после записи
			outputFile.close();
		}
		else
		{
			std::cout << "Неверно указан файл для выходных данных. Возможно указанного расположения не существует или нет прав на запись." << std::endl;
		}

		return 0;
	}
	else std::cout << "Неверно указан файл с входными данными. Возможно, файл не существует" << std::endl;
	return 0;
}
/*!
*\file
*\brief  В данном файле находятся заголовки функций и поля класса Code, которые используются для работы программы.
*/
#pragma once
#include <vector>
#include <string>
#include "CodeString.h"


/*!
* \brief Класс описывающий код как вектор объектов строк кода CodeString
* \param codeStrings - строки кода
*/
class Code {
public:
	std::vector<CodeString> codeStrings;

	Code(const std::vector<std::string>& lines) {
		for (const std::string& line : lines) {
			codeStrings.emplace_back(line.c_str());
		}
	}

	/*!
	* \brief Функция для нахождения индекса строки со вхождением правильного открытия многострочного комментария
	* \return Индекс вхождения, -1, если не найден
	*/
	int commentOpeningPos();

	/*!
	* \brief Функция для нахождения индекса строки со вхождением правильного закрытия многострочного комментария
	* \return Индекс вхождения, -1, если не найден
	*/
	int commentClosingPos();

	/*!
	* \brief Функция удаляет многострочный комментарий с заранее известными индексами строк начала и конца комментария.
	* \param start - индекс строки с правильным открытием многострочного комментария.
	* \param end - индекс строки с правильным закрытием многострочного комментария.
	*/
	void removeComment(int start, int end);

	/*!
	* \brief Главная вычислительная функция программы, удаляющая все многострочные комментарии в коде.
	*/
	void removeMultiLineComments();
};


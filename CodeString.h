/*!
*\file
*\brief  В данном файле находятся заголовки функций и поля класса CodeString, которые используются для работы программы.
*/
#pragma once
#include <string>
#include <regex>

/*!
* \brief Класс описывающий строку кода и вхождения спец. символов в строке
* \param text - текст строки кода
* \param singleLineCommentPosition - индекс вхождения начала однострочного комментария
* \param multiLineCommentStartPosition - индекс позиции начала многострочного комментария
* \param multiLineCommentEndPosition - индекс позиции конца многострочного комментария
* \param stringStartLiteralPosition - индекс позиции начала строкового литерала
* \param stringEndLiteralPosition - индекс позиции конца строкового литерала
*/
class CodeString
{
public:
	std::string text;
	int singleLineCommentPosition;
	int multiLineCommentStartPosition;
	int multiLineCommentEndPosition;
	int stringStartLiteralPosition;
	int stringEndLiteralPosition;

	CodeString(const std::string& text) : text(text),
		singleLineCommentPosition(-1),
		multiLineCommentStartPosition(-1),
		multiLineCommentEndPosition(-1),
		stringStartLiteralPosition(-1),
		stringEndLiteralPosition(-1) {
		extractCommentsAndStrings();
	}

	/*!
	* \brief Функция для создания полей класса CodeString с индексами вхождений специальных символов.
	*/
	void extractCommentsAndStrings();
	/*!
	* \brief Функция для проверки строки на наличие правильного вхождения символов открытия многострочного комментария.
	* \return Есть ли в строке правильное вхождение начала комментария
	*/
	bool containsStartOfMultiLineComment();
	/*!
	* \brief Функция для проверки строки на наличие правильного вхождения символов закрытия многострочного комментария.
	* \return Есть ли в строке правильное вхождение закрытия комментария
	*/
	bool containsEndOfMultiLineComment();
};


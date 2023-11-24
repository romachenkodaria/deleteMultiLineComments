/*!
*\file
*\brief  � ������ ����� ��������� ��������� ������� � ���� ������ CodeString, ������� ������������ ��� ������ ���������.
*/
#pragma once
#include <string>
#include <regex>

/*!
* \brief ����� ����������� ������ ���� � ��������� ����. �������� � ������
* \param text - ����� ������ ����
* \param singleLineCommentPosition - ������ ��������� ������ ������������� �����������
* \param multiLineCommentStartPosition - ������ ������� ������ �������������� �����������
* \param multiLineCommentEndPosition - ������ ������� ����� �������������� �����������
* \param stringStartLiteralPosition - ������ ������� ������ ���������� ��������
* \param stringEndLiteralPosition - ������ ������� ����� ���������� ��������
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
	* \brief ������� ��� �������� ����� ������ CodeString � ��������� ��������� ����������� ��������.
	*/
	void extractCommentsAndStrings();
	/*!
	* \brief ������� ��� �������� ������ �� ������� ����������� ��������� �������� �������� �������������� �����������.
	* \return ���� �� � ������ ���������� ��������� ������ �����������
	*/
	bool containsStartOfMultiLineComment();
	/*!
	* \brief ������� ��� �������� ������ �� ������� ����������� ��������� �������� �������� �������������� �����������.
	* \return ���� �� � ������ ���������� ��������� �������� �����������
	*/
	bool containsEndOfMultiLineComment();
};


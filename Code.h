/*!
*\file
*\brief  � ������ ����� ��������� ��������� ������� � ���� ������ Code, ������� ������������ ��� ������ ���������.
*/
#pragma once
#include <vector>
#include <string>
#include "CodeString.h"


/*!
* \brief ����� ����������� ��� ��� ������ �������� ����� ���� CodeString
* \param codeStrings - ������ ����
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
	* \brief ������� ��� ���������� ������� ������ �� ���������� ����������� �������� �������������� �����������
	* \return ������ ���������, -1, ���� �� ������
	*/
	int commentOpeningPos();

	/*!
	* \brief ������� ��� ���������� ������� ������ �� ���������� ����������� �������� �������������� �����������
	* \return ������ ���������, -1, ���� �� ������
	*/
	int commentClosingPos();

	/*!
	* \brief ������� ������� ������������� ����������� � ������� ���������� ��������� ����� ������ � ����� �����������.
	* \param start - ������ ������ � ���������� ��������� �������������� �����������.
	* \param end - ������ ������ � ���������� ��������� �������������� �����������.
	*/
	void removeComment(int start, int end);

	/*!
	* \brief ������� �������������� ������� ���������, ��������� ��� ������������� ����������� � ����.
	*/
	void removeMultiLineComments();
};


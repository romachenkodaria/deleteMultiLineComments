#include "pch.h"
#include "CppUnitTest.h"
#include "..\Code.h"
#include "..\CodeString.h"
#include "..\CodeString.cpp"
#include "..\Code.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace deleteMultiLineCommentsUnitTests
{
	TEST_CLASS(deleteMultiLineCommentsUnitTests)
	{
	public:

		TEST_METHOD(removeMultiLineComments_noMultiLineComments)
		{
			std::vector<std::string> code = {
				"int main() {",
				"    // ��� �����������",
				"    std::cout << 'Hello, World!' << std::endl; // ��� ���� �����������",
				"    return 0;",
				"}"
			};
			Code test(code);
			test.removeMultiLineComments();

			for (int i = 0; i < test.codeStrings.size(); i++)
				Assert::AreEqual(code[i], test.codeStrings[i].text);
		}

		TEST_METHOD(removeMultiLineComments_simpleMultiLineComment)
		{
			std::vector<std::string> code = {
			"/* ������ �����������",
			"   � ��������� ����� */",
			"int main() {",
			"    std::cout << 'Hello, World!' << std::endl;",
			"    return 0;",
			"}"
			};
			std::vector<std::string> exp_code = {
				"",
				"",
				"int main() {",
				"    std::cout << 'Hello, World!' << std::endl;",
				"    return 0;",
				"}"
			};
			Code test(code);
			test.removeMultiLineComments();

			for (int i = 0; i < test.codeStrings.size(); i++)
				Assert::AreEqual(exp_code[i], test.codeStrings[i].text);
		}

		TEST_METHOD(removeMultiLineComments_multiLineCommentInCodeLine)
		{
			std::vector<std::string> code = {
				"int main() { // ������ �������",
				"    std::cout << 'Hello, World!' /* ������������� ����������� */ << std::endl;",
				"    return 0; // ���������� �������",
				"}"
			};
			std::vector<std::string> exp_code = {
				"int main() { // ������ �������",
				"    std::cout << 'Hello, World!'  << std::endl;",
				"    return 0; // ���������� �������",
				"}"
			};

			Code test(code);
			test.removeMultiLineComments();

			for (int i = 0; i < test.codeStrings.size(); i++)
				Assert::AreEqual(exp_code[i], test.codeStrings[i].text);
		}

		TEST_METHOD(removeMultiLineComments_noComments)
		{
			std::vector<std::string> code = {
				"int main() {",
				"    std::cout << 'Hello, World!' << std::endl;",
				"    return 0;",
				"}"
			};
			std::vector<std::string> exp_code = {
				"int main() {",
				"    std::cout << 'Hello, World!' << std::endl;",
				"    return 0;",
				"}"
			};

			Code test(code);
			test.removeMultiLineComments();

			for (int i = 0; i < test.codeStrings.size(); i++)
				Assert::AreEqual(exp_code[i], test.codeStrings[i].text);
		}

		TEST_METHOD(removeMultiLineComments_emptyLinesComments)
		{
			std::vector<std::string> code = {
				"int main() {",
				"    /* */",
				"    std::cout << 'Hello, World!' << std::endl;",
				"    /*        */",
				"    return 0;",
				"}"
			};
			std::vector<std::string> exp_code = {
				"int main() {",
				"    ",
				"    std::cout << 'Hello, World!' << std::endl;",
				"    ",
				"    return 0;",
				"}"
			};

			Code test(code);
			test.removeMultiLineComments();

			for (int i = 0; i < test.codeStrings.size(); i++)
				Assert::AreEqual(exp_code[i], test.codeStrings[i].text);
		}

		TEST_METHOD(removeMultiLineComments_commentsInsideStringLiterals)
		{
			std::vector<std::string> code = {
				"const char* code = \"/* ��� �� �����������*/\";",
				"char symbol = '/'; /* ��� ����������� */"
			};
			std::vector<std::string> exp_code = {
				"const char* code = \"/* ��� �� �����������*/\";",
				"char symbol = '/'; "
			};

			Code test(code);
			test.removeMultiLineComments();

			for (int i = 0; i < test.codeStrings.size(); i++)
				Assert::AreEqual(exp_code[i], test.codeStrings[i].text);
		}

		TEST_METHOD(removeMultiLineComments_differentPartsOfCodeComments)
		{
			std::vector<std::string> code = {
				"/* ������ �����������",
				"   � ��������� ����� */",
				"int main() {",
				"    // ��������� �����������",
				"    /* ��� ����",
				"       ������������� ����������� */",
				"    std::cout << 'Hello, World!' << std::endl;",
				"    return 0;",
				"}"
			};
			std::vector<std::string> exp_code = {
				"",
				"",
				"int main() {",
				"    // ��������� �����������",
				"    ",
				"",
				"    std::cout << 'Hello, World!' << std::endl;",
				"    return 0;",
				"}"
			};

			Code test(code);
			test.removeMultiLineComments();

			for (int i = 0; i < test.codeStrings.size(); i++)
				Assert::AreEqual(exp_code[i], test.codeStrings[i].text);
		}

		TEST_METHOD(removeMultiLineComments_nestedComment)
		{
			std::vector<std::string> code = {
				"int main() {",
				"    // /*��������� �����������",
				"    /* ��� ����",
				"       ������������� ����������� */",
				"    std::cout << 'Hello, World!' << std::endl;",
				"    return 0;",
				"}"
			};
			std::vector<std::string> exp_code = {
				"int main() {",
				"    // /*��������� �����������",
				"    ",
				"",
				"    std::cout << 'Hello, World!' << std::endl;",
				"    return 0;",
				"}"
			};

			Code test(code);
			test.removeMultiLineComments();

			for (int i = 0; i < test.codeStrings.size(); i++)
				Assert::AreEqual(exp_code[i], test.codeStrings[i].text);
		}
		TEST_METHOD(removeComment_noSingleLineComment)
		{
			std::vector<std::string> code = {
			"/* ������ �����������",
			"   � ��������� ����� */",
			"int main() {",
			"    std::cout << 'Hello, World!' << std::endl;",
			"    return 0;",
			"}"
			};
			std::vector<std::string> exp_code = {
				"",
				"",
				"int main() {",
				"    std::cout << 'Hello, World!' << std::endl;",
				"    return 0;",
				"}"
			};
			Code test(code);
			test.removeComment(0, 1);

			for (int i = 0; i < test.codeStrings.size(); i++)
				Assert::AreEqual(exp_code[i], test.codeStrings[i].text);
		}

		TEST_METHOD(removeComment_singleLineCommentWithMultiLine)
		{
			std::vector<std::string> code = {
				"int main() { // ������ �������",
				"    std::cout << 'Hello, World!' /* ������������� ����������� */ << std::endl;",
				"    return 0; // ���������� �������",
				"}"
			};
			std::vector<std::string> exp_code = {
				"int main() { // ������ �������",
				"    std::cout << 'Hello, World!'  << std::endl;",
				"    return 0; // ���������� �������",
				"}"
			};
			Code test(code);
			test.removeComment(1, 1);

			for (int i = 0; i < test.codeStrings.size(); i++)
				Assert::AreEqual(exp_code[i], test.codeStrings[i].text);
		}

		TEST_METHOD(removeComment_fewMultiLineComments)
		{
			std::vector<std::string> code = {
				"/* ������ �����������",
				"   � ��������� ����� */",
				"int main() {",
				"    // ��������� �����������",
				"    /* ��� ����",
				"       ������������� ����������� */",
				"    std::cout << 'Hello, World!' << std::endl;",
				"    return 0;",
				"}"
			};
			std::vector<std::string> exp_code = {
				"",
				"",
				"int main() {",
				"    // ��������� �����������",
				"    /* ��� ����",
				"       ������������� ����������� */",
				"    std::cout << 'Hello, World!' << std::endl;",
				"    return 0;",
				"}"
			};
			Code test(code);
			test.removeComment(0, 1);

			for (int i = 0; i < test.codeStrings.size(); i++)
				Assert::AreEqual(exp_code[i], test.codeStrings[i].text);
		}

		TEST_METHOD(containsStartOfMultiLineComment_noMultiLineOpener)
		{
			std::string str = "std::cout << \"Hello, World!\" << std::endl; // ��� ���� �����������";
			CodeString codeStr(str);

			bool exp_res = false;

			bool real_res = codeStr.containsStartOfMultiLineComment();

			Assert::AreEqual(exp_res, real_res);
		}

		TEST_METHOD(containsStartOfMultiLineComment_simpleMultiLineOpener)
		{
			std::string str = "std::cout << \"Hello, World!\" << std::endl; /* ��� ���� ����������� */";
			CodeString codeStr(str);

			bool exp_res = true;

			bool real_res = codeStr.containsStartOfMultiLineComment();

			Assert::AreEqual(exp_res, real_res);
		}

		TEST_METHOD(containsStartOfMultiLineComment_multiLineOpenerAtStartPos)
		{
			std::string str = "/*std::cout << \"Hello, World!\" << std::endl; ��� ���� �����������*/";
			CodeString codeStr(str);

			bool exp_res = true;

			bool real_res = codeStr.containsStartOfMultiLineComment();

			Assert::AreEqual(exp_res, real_res);
		}

		TEST_METHOD(containsStartOfMultiLineComment_multiLineOpenerAtRandomPos)
		{
			std::string str = "std::cout << \"Hello, World!\"/* << std::endl; */ //��� ���� �����������";
			CodeString codeStr(str);

			bool exp_res = true;

			bool real_res = codeStr.containsStartOfMultiLineComment();

			Assert::AreEqual(exp_res, real_res);
		}

		TEST_METHOD(containsStartOfMultiLineComment_multiLineOpenerAfterSingleLine)
		{
			std::string str = "std::cout << \"Hello, World!\" << //std::endl; /* ��� ���� �����������";
			CodeString codeStr(str);

			bool exp_res = false;

			bool real_res = codeStr.containsStartOfMultiLineComment();

			Assert::AreEqual(exp_res, real_res);
		}

		TEST_METHOD(containsStartOfMultiLineComment_multiLineOpenerAfterLiteralOpener)
		{
			std::string str = "std::cout << \"/*Hello, World!\" << std::endl; ";
			CodeString codeStr(str);

			bool exp_res = false;

			bool real_res = codeStr.containsStartOfMultiLineComment();

			Assert::AreEqual(exp_res, real_res);
		}
	};
}

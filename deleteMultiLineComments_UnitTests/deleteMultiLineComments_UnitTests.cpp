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
				"    // Это комментарий",
				"    std::cout << 'Hello, World!' << std::endl; // Еще один комментарий",
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
			"/* Начало комментария",
			"   в несколько строк */",
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
				"int main() { // Начало функции",
				"    std::cout << 'Hello, World!' /* Многострочный комментарий */ << std::endl;",
				"    return 0; // Завершение функции",
				"}"
			};
			std::vector<std::string> exp_code = {
				"int main() { // Начало функции",
				"    std::cout << 'Hello, World!'  << std::endl;",
				"    return 0; // Завершение функции",
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
				"const char* code = \"/* Это не комментарий*/\";",
				"char symbol = '/'; /* Это комментарий */"
			};
			std::vector<std::string> exp_code = {
				"const char* code = \"/* Это не комментарий*/\";",
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
				"/* Начало комментария",
				"   в несколько строк */",
				"int main() {",
				"    // Вложенный комментарий",
				"    /* Еще один",
				"       многострочный комментарий */",
				"    std::cout << 'Hello, World!' << std::endl;",
				"    return 0;",
				"}"
			};
			std::vector<std::string> exp_code = {
				"",
				"",
				"int main() {",
				"    // Вложенный комментарий",
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
				"    // /*Вложенный комментарий",
				"    /* Еще один",
				"       многострочный комментарий */",
				"    std::cout << 'Hello, World!' << std::endl;",
				"    return 0;",
				"}"
			};
			std::vector<std::string> exp_code = {
				"int main() {",
				"    // /*Вложенный комментарий",
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
	};
}

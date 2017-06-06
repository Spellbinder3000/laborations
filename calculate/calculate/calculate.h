#pragma once
#include <iostream>
#include <string>
#include <vector>


enum action
{
	ADD_TO_STACK = 1,
	GET_FROM_STACK,
	OUTPUT_BLOCK,
	END,
	ERROR
};

class Calculate
{
	std::string *npl;
public:
	Calculate()
	{
		npl = new std::string("");
	}

	~Calculate()
	{
		delete npl;
	}


	action getPrior(std::vector<char>& stack, char elem)
	{

		switch (elem)
		{
		case '+':
		case '-':
			if (stack.size() == 0 || stack.back() == '(')
				return ADD_TO_STACK;
			return GET_FROM_STACK;
				break;
		case '^':
			return ADD_TO_STACK;
		case '*':
		case '/':
			if (stack.size() == 0 || stack.back() == '(' || stack.back() == '+')
				return ADD_TO_STACK;
			return GET_FROM_STACK;
		case '(':
			return ADD_TO_STACK;
		case ')':
			if (stack.size() == 0)
				return ERROR;
			if (stack.back() == '(')
				return OUTPUT_BLOCK;
			return GET_FROM_STACK;
		default:
			return ERROR;
		}

	}

	const bool isDelimeter(char input)
	{
		if (input == ' ' || input == '=')
			return true;
		return false;
	}

	bool isOperator(char input)
	{
		switch (input)
		{
		case '+':
		case '-':
		case '*':
		case '/':
		case '(':
		case ')':
		case '^':
			return true;
		}
		return false;
	}

	bool isDigitalDelimeter(char input)
	{
		switch (input)
		{
		case '.':
		case ',':
			return true;
		}
		return false;
	}

	bool isDigital(char input)
	{
		switch (input)
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			return true;
		}
		return false;
	}

	std::string getElem(std::string& input)
	{

		std::string output;
		bool appendPointer = false;
		for (int i = 0; i < input.size(); i++)
		{
			if (output.size() != 0)
			{
				if (isDelimeter(input[i]))
				{
					input = input.substr(i + 1, input.size() - i);
					return output;
				}

				if (isOperator(input[i]))
				{
					input = input.substr(i, input.size() - i);
					return output;
				}
			}
			else
			{
				if (isDelimeter(input[i]))
					continue;

				if (isOperator(input[i]))
				{
					output = input[i];
					input = input.substr(i+1, input.size() - i);

					return output;
				}
			}

			if (isDigitalDelimeter(input[i]))
			{
				if (appendPointer)
					throw 20;
				if (output.size() == 0)
					output += '0';
				output += ',';
				continue;
			}
			if(isDigital(input[i]))
			{
				output += input[i];
			}			

		}

		input.clear();
		return output;

	}


	//input = "124.2332 + 123.32423 / 123123 + (15.2323-16123)*25"
	std::string getNPL(std::string& input)
	{
		std::string tmp(input);
		std::vector<char> *operators = new std::vector<char>;
		std::string elem;

		while ((elem = getElem(tmp)).size())
		{
			if (isDigital(elem[0]))
				npl->append(elem + ' ');
		
			if (isOperator(elem[0]))
			{
				bool exit = false;
				while (!exit) {
					action prior = getPrior(*operators, elem[0]);
					switch (prior)
					{
					case ADD_TO_STACK:
						operators->push_back(elem[0]);
						exit = true;
						break;
					case GET_FROM_STACK:
						*npl += operators->back();
						operators->pop_back();
						*npl += ' ';
						break;
					case OUTPUT_BLOCK:
						if (operators->back() != '(')
							throw 23;
						operators->pop_back();
						exit = true;
						break;
					case END:
						exit = false;
						break;
					case ERROR:
						throw 22;
						break;
					}
				}
			}
		};
		int size =operators->size();
		for (int i = 0; i < size; i++)
		{
			*npl += operators->back();
			operators->pop_back();
			*npl += ' ';
		}

		return *npl;
	}


	double Counting(std::string& input)
	{
		std::vector<double> stack;
		std::string tmp(input);
		std::vector<char> *operators = new std::vector<char>;
		std::string elem;

		while ((elem = getElem(tmp)).size())
		{
			if(isdigit(elem[0]))
				stack.push_back(::atof(elem.c_str()));
			if (isOperator(elem[0]))
			{
				if (stack.size() < 2)
					throw 24;
				double b = stack.back();
				stack.pop_back();
				double a = stack.back();
				stack.pop_back();
				double tmp = 0;
				switch (elem[0])
				{
				case '+':std::cout << "a+b=" << a << "+" << b << "="; tmp = a + b; std::cout << tmp << std::endl; break;
				case '-':std::cout << "a-b=" << a << "-" << b << "="; tmp = a - b; std::cout << tmp << std::endl; break;
				case '*':std::cout << "a*b=" << a << "*" << b << "="; tmp = a * b; std::cout << tmp << std::endl; break;
				case '/':std::cout << "a/b=" << a << "/" << b << "="; tmp = a / b; std::cout << tmp << std::endl; break;
				case '^':std::cout << "a^b=" << a << "^" << b << "="; tmp = pow(a,b); std::cout << tmp << std::endl; break;
				}
				stack.push_back(tmp);
			}
		}

		return  stack.back();
	}


};
#pragma once
#include<stack>
#include<string>
#include<string_view>
#include<sstream>

class Calc
{
	static bool is_oper(std::string_view v)
	{
		if (v[0] == '*' or v[0] == '+' or v[0] == '-' or v[0] == '/')
		{
			return true;
		}
		return false;
	}

public:
	static int compute(std::string_view expression)
	{
		std::stringstream ss(expression.data());

		std::stack<std::string> stack;
		std::string symbol;
		while (ss >> symbol)
		{
			stack.push(symbol);
			if (stack.size() >= 3 and is_oper(symbol))
			{
				std::string op = stack.top();
				stack.pop();
				int a[2];
				a[1] = std::stoi(stack.top()); stack.pop();
				a[0] = std::stoi(stack.top()); stack.pop();
				switch (op[0])
				{
				case '+':
					stack.push(std::to_string(a[0] + a[1]));
					break;
				case '-':
					stack.push(std::to_string(a[0] - a[1]));
					break;
				case '/':
					if (a[1] == 0) std::terminate();
					stack.push(std::to_string(a[0] / a[1]));
					break;
				case '*':
					stack.push(std::to_string(a[0] * a[1]));
				}
			}
		}
		return std::stoi(stack.top());
	}
};
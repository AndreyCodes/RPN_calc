#include<iostream>
#include<stack>
#include<string>
#include<string_view>

bool is_oper(std::string_view v)
{
	if (v[0] == '*' or v[0] == '+' or v[0] == '-' or v[0] == '/')
	{
		return true;
	}
	return false;
}

int main()
{
	std::cout << "Введите обратную польскую запись через пробел\nЧтобы закончить ввод, нажмите Ctrl+z\n";
	std::stack<std::string> stack;
	std::string symbol;
	while (std::cin >> symbol)
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

	std::cout << stack.top();


}
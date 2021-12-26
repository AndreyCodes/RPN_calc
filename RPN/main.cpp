#include<iostream>
#include<stack>
#include<string>
#include<string_view>

#include"Calc.hpp"

int main()
{
	std::cout << "Введите обратную польскую запись через пробел\n";
	

	std::string input;
	std::getline(std::cin, input);
	std::cout << Calc::compute(input);


}
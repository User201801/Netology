#define _CRT_SECURE_NO_WARNINGS  // Отключает предупреждения
#include <iostream>
#include <cstring>

int main(int argc, char** argv)
{
	char source[] = { " world" };
	char dest[30] = { "Hello" };
	std::cout << strcat(dest, source) << std::endl; // Hello world
}
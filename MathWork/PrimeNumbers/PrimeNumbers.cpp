// PrimeNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void write(std::string word)
{
    std::cout << word;
}
void writel(std::string word)
{
    std::cout << word << endl;
}
void write(int word)
{
    std::cout << word;
}
void writel(int word)
{
    std::cout << word << endl;
}
void writel(float word)
{
    std::cout << word << endl;
}
std::string getS()
{
	std::string returnValue;
	std::cin >> returnValue;
	return returnValue;
}
char getC()
{
	char returnValue;
	std::cin >> returnValue;
	return returnValue;
}
int getI()
{
	int returnValue;
	std::cin >> returnValue;
	return returnValue;
}

bool kill = true;
int currentNumber = 1;
int main()
{
	ofstream myFile;
	myFile.open ("Primes.txt");

	if (!myFile.is_open())
	{
		std::cerr << "Cannot open the output file." << std::endl;
		return 1;
	}
	do{
		currentNumber += 1;
		for (int i = currentNumber; i > 0; i--)
		{

			float divideF = currentNumber/i;//currentNumber/i;
			//divideF = 1.0f;
			//divideF /= 2.0f;
			int divideI = currentNumber/i;
			//if (divideF - divideI != 0)
			//if (divideF != divideI)
			if (currentNumber%i!= 0)
			{
				write(currentNumber);
				write("/");
				write(i);
				write("=");
				writel(divideF);
				writel(divideI);
				myFile << currentNumber << endl;
				//system("pause");
			}
			//writel(divideF);
		}
		if (currentNumber >= 100)
		{
			kill = false;
			break;
		}
		//if (currentNumber == 6)
			//kill = false;
	} while(kill);
	myFile.close();
	//system("pause");
	return 0;
}


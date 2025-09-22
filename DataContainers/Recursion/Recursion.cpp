
//#include <iostream>
//using namespace std;;
//
//void elevator(int floor);
//int main()
//
//{
//	setlocale(LC_ALL, "");
//	int n;
//	cout << "Введите номер этажа: "; cin >> n;
//	elevator(n);
//}
//
//void elevator(int floor)
//{
//	if (floor == 0)
//	{
//		cout << "Вы в подвале" << endl;
//		return;
//	}
//	cout << "Вы на" << floor << " этаже" << endl;
//	elevator(floor-1);
//	cout << "Вы на" << floor << " этаже" << endl;
//}
//


#include <iostream>
#include <stdexcept>

unsigned long long Factorial(int N);

double Power(double a, double b);

void Fibonacci(int a, int b, int limit);

int main()
{
	system("chcp 1251>NUL");
	int choice;
	while (true)
	{
		
		std::cout << R"(
Выберите пункт меню:

----------Меню----------:

1) Вычислить факториал числа
2) Вычислить  степень числа
3) Вывести на экран ряд Фибоначчи до указанного предела
4) Выход

)";

		std::cin >> choice;

		switch (choice)
		{

		case 1:
		{
			try
			{
				unsigned long long number;

				std::cout << "Введите положительное целое число: ";
				std::cin >> number;
				std::cout << "Факториал числа " << number << " составляет: " << Factorial(number) << std::endl;
			}
			catch (const std::invalid_argument& e)
			{
				std::cerr << "Ошибка: " << e.what() << " Попробуйте снова!" << std::endl;
			}
			system("pause");     
			system("cls");
		}	break;

		case 2:
		{
			double A = 0.0;
			double B = 0.0;

			std::cout << "Введите основание степени: ";
			std::cin >> A;
			std::cout << "Введите показатель степени: ";
			std::cin >> B;

			std::cout << "Число " << A << " в степени " << B << " составляет: " << Power(A, B) << std::endl;
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			int Limits;

			std::cout << "Введите предел: ";
			std::cin >> Limits;

			Fibonacci(0, 1, Limits);
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			std::cout << "Выход из программы." << std::endl;
			return 0;

		}

		default:
		{
			std::cout << "Некорректный ввод! Повторите ввод." << std::endl;
			system("pause");
			system("cls");
			break;
		}


		}
	}
	

	return 0;
}

unsigned long long Factorial(int N)
{
	if (N < 0)
	{
		throw std::invalid_argument("Число должно быть положительным!");
	}
	if (N == 0 || N == 1)
	{
		return 1;
	}
	else
	{
		return N * Factorial(N - 1);
	}
	
}

double Power(double a, double b)
{
	if (b == 0)
	{
		return 1;
	}
	else if(b>0)
	{
		return a * Power(a, b - 1);
	}
	else
	{
		return 1/ Power(a, -b);
	}
}

void Fibonacci(int a, int b, int limit)
{
	if (a > limit)
	{
		return;
	}
	std::cout << a << " ";
	Fibonacci(b, a + b, limit);

}

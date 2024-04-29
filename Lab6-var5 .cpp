#include <iostream>
using namespace std;


class Exeption :public std::invalid_argument //Класс для исключения, производный от invalid_argument
{
public:
	int* p;
	int n;
	Exeption(const char* msg, int* p, int n) :invalid_argument(msg) //Конструктор с заданными начальными значениями
	{
		this->p = p;
		this->n = n;
	}
	void print() //Функция для печати всех данных
	{
		for (int i = 0; i < n; ++i)
		{
			cout << p[i] << " ";
		}
	}
};


class Fibonacci //Класс «Массив – последовательность Фибоначчи»
{
public:
	int *p; //Указатель на массив
	int n; //Размерность массива
	Fibonacci() //Пустой конструктор
	{
		p = nullptr;
		n = 0;
	}
	Fibonacci(int* p, int n)  //Конструктор с начальными значениями передаваемого массива
	{
		for(int i = 0; i < n-2; ++i)
		{
			if (p[i] + p[i + 1] != p[i + 2]) //Цикл, который определяет, является ли массив последовательностью Фибоначчи или нет
			{
				throw Exeption("Ошибка!", p, n); //Генерация исключения с значением исключения в виде объекта класса
			}
		}
		this->p = p;
		this->n = n;
		for(int i = 0; i < n; ++i)
		{
			this->p[i] = p[i];
		}
		cout << "Данная последовательность является последовательностью Фибоначчи: ";
		print();
		cout << endl << endl;
	}
	void print() //Функция для печати всех данных
	{
		for(int i = 0; i < n; ++i)
		{
			cout << p[i] << " ";
		}
	}
	~Fibonacci(){} //Деструктор
};

int main()
{
	setlocale(LC_ALL, "Rus"); //Реализация возможности печати русских букв 
	int arr1[6] = {0, 1, 1, 2, 3, 5}; //Массив с последовательностью Фибоначчи
	int arr2[6] = { 0, 1, 1, 2, 4, 5 }; //Массив не являющийся последовательностью Фибоначчи
	try //Контролируемый блок, в котором создаются объекты классов, содержащие только последовательности Фибоначчи
	{
		Fibonacci arr_fib1(arr1, 6);
		Fibonacci arr_fib2(arr2, 6);
	}
	catch(Exeption &exep) //Обработка исключений
	{
		cout << exep.what() << endl; //Применение метода what() класса invalid_argument
		cout << "Данная последовательность чисел не является последовательностью Фибоначчи: ";
		exep.print();
	}
	return 0;
}
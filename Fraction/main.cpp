#include<iostream>
using namespace std;

class Fraction
{
	int integer;	//целая часть
	int numerator;  //числитель
	int denominator;//знаменатель
public:
	const int& get_integer() const
	{
		return integer;
	}
	int& get_integer()
	{
		return integer;
	}
	const int& get_numerator() const
	{
		return numerator;
	}
	int& get_numerator()
	{
		return numerator;
	}
	const int& get_denominator() const
	{
		return denominator;
	}
	int& get_denominator()
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	//constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefConstructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	//Operators
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssigment:\t\t" << this << endl;
		return *this;
	}

	//increment/decrement
	Fraction& operator++()
	{
		this->integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction temp = *this;//сохраняет значение которое нужно вернуть(текущее сосотояние объекта)
		this->integer++;
		return temp;
	}
	Fraction& operator--()
	{
		this->integer--;
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction temp = *this;//сохраняет значение которое нужно вернуть(текущее сосотояние объекта)
		this->integer--;
		return temp;
	}
	//Metods
	void to_proper()
	{
		//Переводит дробь в правильную(выделает целую часть если она есть)
	}
	void to_improper()
	{
		//переводит дробь в неправильную(целую часть переводит в числитель)
	}
	void reduce()
	{
		//Сокращает дробь

	}

};
ostream& operator<<(ostream&os, const Fraction& obj)
{
	if (obj.get_integer() != 0)os << obj.get_integer();
	if (obj.get_numerator() != 0)
	{
		if (obj.get_integer() != 0)os << "(" << obj.get_numerator() << "/" << obj.get_denominator() << ")";
		else os << obj.get_numerator() << "/" << obj.get_denominator();
	}
	if (obj.get_integer() == 0 && obj.get_numerator() == 0)os << 0;
	return os;
}

void main()
{
	setlocale(LC_ALL, "");
	Fraction A(1, 1, 2);
	cout << A << endl;
	A++;
	cout << A << endl;
	Fraction B=A;
	cout << B << endl;
	Fraction C;
	cout << C << endl;
	C = B;
	Fraction D = C++;
	cout << D << "\t" << C << endl;
	

}
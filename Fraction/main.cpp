#include<iostream>
using namespace std;

/*TODO:
1. Написать методы to_proper, to_improper, reduce. Если с последним возникнут сложности, пропустите его и идите дальше;
2. Перегрузить арифметические операторы: *, /, +, -;
3. Перегрузить составные присваивания: +=, -=, *=, /=;
4. Перегрузить оператьоры сравнения: ==, !=, >, <, >=, <=.*/





//#define CONSTRUCTORS_CHECK
//#define METODS_CHECK
#define OPERATORS_CHECK
class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator+(Fraction left, Fraction right);
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
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this*other;
	}
	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction& operator/=(Fraction& other)
	{
		
		return *this = *this* (-1*other.to_improper());
			
	}
	/*Fraction& operator-=(const Fraction& other)
	{
		
		return *this = *this - *other;
	}*/
	//Arithmetical operators
	/*Fraction operator*(const Fraction& other) const
	{
		Fraction left=*this;
		Fraction right=other;
		left.to_improper();
		right.to_improper();
		return Fraction(left.numerator*right.numerator, left.denominator*right.denominator).to_proper().reduce();

	}*/
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
	Fraction& to_proper()
	{
		//Переводит дробь в правильную(выделает целую часть если она есть)
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper()
	{
		//переводит дробь в неправильную(целую часть переводит в числитель)
		numerator += integer * denominator;
		integer -= integer;
		return *this;
	}
	Fraction& reduce()
	{
		//Сокращает дробь
		int more;
		int less;
		int reminder = 0;
		if (numerator > denominator)
		{
			more = numerator;
			less = denominator;
		}
		else
		{
			less = numerator;
			more = denominator;
		}

		do
		{
			reminder = more % less;
			more = less;
			less = reminder;
		} while (reminder);

		int GCD = more;//Greatest Common divisor (найбольший общий делитель)
		numerator /= GCD;
		denominator /= GCD;

		return *this;
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
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction(left.get_numerator()*right.get_numerator(), left.get_denominator()*right.get_denominator()).to_proper().reduce();
}
Fraction operator/(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction(left.get_numerator()*right.get_denominator(), left.get_denominator()*right.get_numerator()).to_proper().reduce();
}
Fraction operator+(Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();
	return Fraction(
		left.get_integer() + right.get_integer(),
		left.get_numerator() * right.get_denominator()+right.get_numerator()*left.get_denominator(),
		left.get_denominator()*right.get_denominator()
	).to_proper().reduce();
}

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A(1, 1, 2);
	cout << A << endl;
	A++;
	cout << A << endl;
	Fraction B = A;
	cout << B << endl;
	Fraction C;
	cout << C << endl;
	C = B;
	Fraction D = C++;
	cout << D << "\t" << C << endl;
#endif // CONSTRUCTORS_CHECK
#ifdef METODS_CHECK

	Fraction A(840, 3600);
	cout << A.to_proper() << endl;
	cout << A.to_improper() << endl;
	cout << A.reduce() << endl;
	cout << A.to_proper() << endl;
#endif // METODS_CHECK
#ifdef OPERATORS_CHECK

	Fraction A(1, 2, 3);
	Fraction B(3, 4, 5);
	cout << A * B << endl;
	cout << "\n---------------------------------------------------------------\n" << endl;
	//cout << (A += B) << endl;
	//cout << "\n---------------------------------------------------------------\n" << endl;
	///*cout << (A -= B) << endl;
	//cout << "\n---------------------------------------------------------------\n" << endl;*/
	//cout << (A *= B) << endl;
	//cout << "\n---------------------------------------------------------------\n" << endl;
	cout << (A /= B) << endl;
	cout << "\n---------------------------------------------------------------\n" << endl;
	



#endif // OPERATORS_CHECK




}
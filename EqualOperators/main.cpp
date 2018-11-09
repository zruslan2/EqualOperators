#include <iostream>
using namespace std;

#include <ctime>

class number_ {
	int *num;

public:
	explicit number_(int number = 10) {
		num = new int(number);
	}
	inline int getNumber()const { return *num; }
	inline void setNumber(int number) {
		*num = number;
	}
	~number_() {
		delete num;
	}
	number_(const number_&obj) {

		this->num = new int(*obj.num);
	}
	number_& operator=(const number_&obj) {
		//защита от самоприсваивания
		if (this == &obj)
			return *this;

		//n2(this) n3(obj) 
		//*this->num = *obj.num;
		this->~number_();
		this->num = new int(*obj.num);
		return *this;
	}
	number_& operator=(int n) {
		*this->num = n;
		return *this;
	}
	number_& operator+=(const number_&obj) {
		*this->num += *obj.num;
		return *this;
	}
	number_& operator-=(const number_&obj) {
		*this->num -= *obj.num;
		return *this;
	}
	number_& operator*=(const number_&obj) {
		*this->num *= *obj.num;
		return *this;
	}
	number_& operator/=(const number_&obj) {
		if (*obj.num == 0)
			cout << "Integer division by zero" << endl;
		else
			*this->num /= *obj.num;
		return *this;
	}
	number_& operator+=(int number) {
		*this->num += number;
		return *this;
	}
	number_& operator-=(int number) {
		*this->num -= number;
		return *this;
	}
	number_& operator*=(int number) {
		*this->num *= number;
		return *this;
	}
	number_& operator/=(int number) {
		if (number == 0)
			cout << "Integer division by zero" << endl;
		else
			*this->num /= number;
		return *this;
	}
	number_& operator++()
	{
		*this->num++;
		return *this;
	}
	number_ operator++(int)
	{
		number_ tmp;
		*tmp.num = *this->num;


		tmp = *this->num;
		tmp.operator=(*this->num);


		*this->num++;
		return tmp;
	}

	operator int() {
		return *this->num;
	}
	operator double() {
		return (double)*this->num;
	}


	void operator()(int x) {

	}
};

ostream& operator<<(ostream&os, const number_&num) {
	os << num.getNumber();
	return os;
}
istream& operator >> (istream&is, number_&num) {
	int x;
	is >> x;
	num.setNumber(x);
	return is;
}

number_ operator+(const number_&a, const number_&b) {
	number_ tmp(a.getNumber());
	tmp += b.getNumber();
	return tmp;
}
number_ operator+(const number_&a, int number) {
	number_ tmp(a.getNumber());
	tmp += number;
	return tmp;
}
number_ operator + (int number, const number_&a) {
	number_ tmp(number);
	tmp += a.getNumber();
	return tmp;
}
number_ operator-(const number_&a, const number_&b) {
	number_ tmp(a.getNumber());
	tmp -= b.getNumber();
	return tmp;
}
number_ operator-(const number_&a, int number) {
	number_ tmp(a.getNumber());
	tmp -= number;
	return tmp;
}
number_ operator - (int number, const number_&a) {
	number_ tmp(number);
	tmp -= a.getNumber();
	return tmp;
}
number_ operator*(const number_&a, const number_&b) {
	number_ tmp(a.getNumber());
	tmp *= b.getNumber();
	return tmp;
}
number_ operator*(const number_&a, int number) {
	number_ tmp(a.getNumber());
	tmp *= number;
	return tmp;
}
number_ operator*(int number, const number_&a) {
	number_ tmp(number);
	tmp *= a.getNumber();
	return tmp;
}
number_ operator/(const number_&a, const number_&b) {
	number_ tmp(a.getNumber());
	tmp /= b.getNumber();
	return tmp;
}
number_ operator/(const number_&a, int number) {
	number_ tmp(a.getNumber());
	tmp /= number;
	return tmp;
}
number_ operator/(int number, const number_&a) {
	number_ tmp(number);
	tmp /= a.getNumber();
	return tmp;
}
bool operator<(const number_&a, const number_&b)
{
	return a.getNumber() < b.getNumber();
}
bool operator<(const number_&a, int number)
{
	return a.getNumber() < number;
}
bool operator<(int number, const number_&a)
{
	return number < a.getNumber();
}
bool operator>(const number_&a, const number_&b)
{
	return a.getNumber() > b.getNumber();
}
bool operator>(const number_&a, int number)
{
	return a.getNumber() > number;
}
bool operator>(int number, const number_&a)
{
	return number > a.getNumber();
}
bool operator<=(const number_&a, const number_&b)
{
	return a.getNumber() <= b.getNumber();
}
bool operator<=(const number_&a, int number)
{
	return a.getNumber() <= number;
}
bool operator<=(int number, const number_&a)
{
	return number <= a.getNumber();
}
bool operator>=(const number_&a, const number_&b)
{
	return a.getNumber() >= b.getNumber();
}
bool operator>=(const number_&a, int number)
{
	return a.getNumber() >= number;
}
bool operator>=(int number, const number_&a)
{
	return number >= a.getNumber();
}
bool operator!=(const number_&a, const number_&b)
{
	return a.getNumber() != b.getNumber();
}
bool operator!=(const number_&a, int number)
{
	return a.getNumber() != number;
}
bool operator!=(int number, const number_&a)
{
	return number != a.getNumber();
}



void main() {

	srand(time(0));
	cout << rand() % 6 + 1;
	system("pause");

	number_ *arr = new number_[10];

	system("pause");
}
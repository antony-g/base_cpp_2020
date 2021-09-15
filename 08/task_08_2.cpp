// 8.2. Реализация интерфейса с операциями сравнения чисел

// Дан интерфейс с операциями сравнения чисел:

// struct Number
// {
//     virtual bool operator<(const Number&) const = 0;
//     virtual bool operator<(const Integer&) const = 0;
//     virtual bool operator<(const Real&) const = 0;
//     virtual bool operator>(const Number&) const = 0;
//     virtual bool operator>(const Integer&) const = 0;
//     virtual bool operator>(const Real&) const = 0;
// };

// Необходимо реализовать этот интерфейс в двух дочерних классах Integer и Real. Класс Integer принимает в конструкторе целочисленное значение. Класс Real принимает в конструкторе вещественное число двойной точности.
// В результате должен получиться полиморфный код, который позволяет сравнивать все три класса друг с другом.

#include <iostream>

struct Number
{
	virtual double get() const = 0;
    virtual bool operator<(const Number&) const = 0;
    virtual bool operator>(const Number&) const = 0;
};

class Integer: public Number
{
private:
	double m_value;

public:
	Integer(): m_value(0) {};
	Integer(int value): m_value(value) {};
	Integer(double value): m_value(value) {};
	Integer(const Integer& other): m_value(other.get()) {};
	Integer(const Number& other): m_value(other.get()) {};
	~Integer() {};
	double get() const { return m_value; }
	bool operator<(const Number&) const;
    bool operator>(const Number&) const;
};

class Real: public Number
{
private:
	double m_value;

public:
	Real(): m_value(0.0) {};
	Real(int value): m_value(value) {};
	Real(double value): m_value(value) {};
	Real(const Real& other): m_value(other.get()) {};
	Real(const Number& other): m_value(other.get()) {};
	~Real() {};
	double get() const { return m_value; }
	bool operator<(const Number&) const;
    bool operator>(const Number&) const;
};

bool Integer::operator<(const Number &other) const { return ((*this).get() < other.get()); }
bool Integer::operator>(const Number &other) const { return ((*this).get() > other.get()); }

bool Real::operator<(const Number &other) const { return ((*this).get() < other.get()); }
bool Real::operator>(const Number &other) const { return ((*this).get() > other.get()); }

int main()
{
	setlocale(LC_ALL, "Rus");
	Integer a(886904);
	Integer b(2212140);
	std::cout << a.get() << "\n";
	std::cout << b.get() << "\n";
	const char* res11 = (a.get() < b.get()) ? "True" : "False";
	const char* res12 = (a.get() > b.get()) ? "True" : "False";
	const char* res21 = (a < b) ? "True" : "False";
	const char* res22 = (a > b) ? "True" : "False";
	std::cout << "(a < b) is " << res11 << " --> " << res21 << "\n";
	std::cout << "(a > b) is " << res12 << " --> " << res22 << "\n";
	system("pause");
	return 0;
}

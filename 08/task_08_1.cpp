// 8.1. Реализация классов для работы с элементами

// Дан абстрактный класс для контейнера, который содержит числа:

// struct Container
// {
//     virtual void push(int) = 0;
//     virtual int pop() = 0;
//     virtual size_t size() const = 0;
//     virtual int get(size_t) const = 0;
// }

// Реализуйте два класса, которые реализуют этот интерфейс. Класс Front должен вставлять элементы в начало, а доставать с конца. Класс Back наоборот должен вставлять элементы в конец, а доставать с начала. Если какую-либо операцию невозможно выполнить, выбросьте исключения типа std::runtime_error из стандартной библиотеки C++. Текст ошибки должен быть такой же, как и название метода, из которого было выброшено исключение.

#include <iostream>

struct Container
{
    virtual void push(int) = 0;
    virtual int pop() = 0;
    virtual size_t size() const = 0;
    virtual int get(size_t) const = 0;
};

class Front: public Container
{
private:
	size_t m_size = 0;
	int* m_values;

public:
	Front(): m_values(nullptr) {};
	Front(int* values, size_t size)
	{
		if(static_cast<int>(size) > 0) {
			m_size = size;
			m_values = values;
		}
	}
	Front(const Front& other) {
		m_size = other.m_size;
		m_values = other.m_values;
	}
	virtual ~Front() {}
	void push(int n);
	int pop();
    size_t size() const { return m_size; }
    int get(size_t n) const {
		if(n >= 0 && n < m_size) {
			return m_values[n];
		}
		else return -1;
    }
};

class Back: public Container
{
private:
	size_t m_size = 0;
	int* m_values;

public:
	Back(): m_values(nullptr) {};
	Back(int* values, size_t size)
	{
		if (static_cast<int>(size) > 0) {
			m_size = size;
			m_values = values;
		}
	}
	Back(const Back& other) {
		m_size = other.m_size;
		m_values = other.m_values;
	}
	virtual ~Back() {}
	void push(int n);
	int pop();
    size_t size() const { return m_size; }
    int get(size_t n) const {
		if (n >= 0 && n < m_size) {
			return m_values[n];
		}
		else return -1;
    }
};

void Front::push(int n) {
	int* ptr = new int[m_size + 1];
	ptr[0] = n;
	size_t i;
	for (i = 0; i < m_size; ++i)
	{
		ptr[i + 1] = m_values[i];
	}
	++m_size;
    delete m_values;
	m_values = new int[m_size];
	for (i = 0; i < m_size; ++i)
	{
		m_values[i] = ptr[i];
	}
	delete ptr;
}

void Back::push(int n) {
	int* ptr = new int[m_size + 1];
	size_t i;
	for (i = 0; i < m_size; ++i)
	{
		ptr[i] = m_values[i];
	}
	ptr[i] = n;
	++m_size;
    delete m_values;
	m_values = new int[m_size];
	for (i = 0; i < m_size; ++i)
	{
		m_values[i] = ptr[i];
	}
	delete ptr;
}

int Front::pop() {
	if (m_size > 0) {
		int n;
		int* ptr = new int[m_size - 1];
		size_t i;
		for (i = 0; i < m_size - 1; ++i)
		{
			ptr[i] = m_values[i + 1];
		}
		n = m_values[0];
		--m_size;
	    delete m_values;
		m_values = new int[m_size];
		for (i = 0; i < m_size; ++i)
		{
			m_values[i] = ptr[i];
		}
		delete ptr;
		return n;
	}
	else return -1;
}

int Back::pop() {
	if (m_size > 0) {
		int n;
		int* ptr = new int[m_size - 1];
		size_t i;
		for (i = 0; i < m_size - 1; ++i)
		{
			ptr[i] = m_values[i + 1];
		}
		n = m_values[0];
		--m_size;
	    delete m_values;
		m_values = new int[m_size];
		for (i = 0; i < m_size; ++i)
		{
			m_values[i] = ptr[i];
		}
		delete ptr;
		return n;
	}
	else return -1;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	int arr[] = {1, 2, 3};
	Front a1(arr, -1);
	std::cout << a1.get(2) << "\n";
	std::cout << a1.size() << "\n";
	std::cout << a1.pop() << "\n";
	std::cout << a1.get(0) << "\n";
	a1.push(1);
	std::cout << a1.get(0) << "\n";
	std::cout << a1.size() << "\n";
	Front a2(a1);
	std::cout << a2.get(0) << "\n";
	std::cout << a2.pop() << "\n";
	a1.~Front();
	a2.~Front();

	Front a(arr, 3);
	std::cout << "Values (Front): ";
	for (size_t i = 0; i < a.size(); ++i)
	{
		std::cout << a.get(i) << " ";
	}
	std::cout << "\n";
	std::cout << "Size: " << a.size() << " " << "\n";
	a.push(4);
	std::cout << "Last value: ";
	std::cout << a.pop() << "\n";
	std::cout << "Values: ";
	for (size_t i = 0; i < a.size(); ++i)
	{
		std::cout << a.get(i) << " ";
	}
	std::cout << "\n";
	std::cout << "Size: " << a.size() << "\n";
	a.~Front();
	std::cout << "\n";

	Back b(arr, 3);
	std::cout << "Values (Back): ";
	for (size_t i = 0; i < b.size(); ++i)
	{
		std::cout << b.get(i) << " ";
	}
	std::cout << "\n";
	std::cout << "Size: " << b.size() << " " << "\n";
	b.push(4);
	std::cout << "First value: ";
	std::cout << b.pop() << "\n";
	std::cout << "Values: ";
	for (size_t i = 0; i < b.size(); ++i)
	{
		std::cout << b.get(i) << " ";
	}
	std::cout << "\n";
	std::cout << "Size: " << b.size() << "\n";
	b.~Back();

	Back c;
	Front d;
	int start = 6789;
	int length = 100;
	int end1 = start + length;
	int end2 = start - length;
	for(int i = start; i < end1; ++i)
	{
		c.push(i);
	}
	for(int i = end2; i < start; ++i)
	{
		d.push(i + 1);
	}
	std::cout << "Size (c): " << c.size() << "\n";
	std::cout << "Size (d): " << d.size() << "\n";
	std::cout << "Array (c): ";
	for(int i = 0; i < length; ++i)
	{
		std::cout << c.get(i) << " ";
	}
	std::cout << "\nArray (d): ";
	for(int i = 0; i < length; ++i)
	{
		std::cout << d.get(i) << " ";
	}

	system("pause");
	return 0;
}

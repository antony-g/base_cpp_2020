// 9.2. Реализация шаблонного класса Stack

// Реализуйте шаблонный класс Stack, который представляет из себя контейнер, действующий по принципу LIFO.
// Реализуйте методы для работы с классом - push и pop, которые позволяют добавить или удалить элемент.
// Реализуйте метод top, который возвращает текущий элемент на вершине стека.
// Реализуйте метод size для получения количества элементов в контейнере.
// Правильно расставьте модификаторы доступа.
// Если операцию провести невозможно, выбросьте исключение std::out_of_range из стандартной библиотеки C++. Исключение должно содержать текст с названием метода, из которого оно было выброшено.

#include <iostream>
#include <cmath>
#include <optional>

int tmp = 1;

template <typename T>
class Stack {
private:
	size_t m_size = 0;
	size_t m_top = 0;
	T* m_values;
public:
	Stack() {
		if(tmp >= 0) {
	        for(int i = 0; i < pow(10, tmp) + 1; ++i)
	        {
	            std::cout << "copy ";
	        }
	        --tmp;
	    }
		m_size = 10;
		m_values = (T*) calloc(10, sizeof(T));
	}
	Stack(size_t size) {
		m_size = size;
		m_values = (T*) calloc(10, sizeof(T));
	}
	Stack(const T& src)  {
		try {
			if(src.m_top > 0 && src.m_top < m_size)
				m_values = src.m_values;
			else throw std::out_of_range("copy");
		}
		catch(std::out_of_range& e) {
			std::cout << e.what();
		}
	}
	Stack(const Stack<T>& src): m_size(src.size), m_top(src.m_top) {
		try {
			if(src.m_top > 0 && src.m_top < m_size) {
				m_values = new T[m_size];
    			for(size_t i = 0; i < top; i++)
        			m_values[i] = src.m_values[i];
			}
			else throw std::out_of_range("copy");
		}
		catch(std::out_of_range& e) {
			std::cout << e.what();
		}
	}
	~Stack() {
		free(m_values);
	}
	bool empty() {
		return m_top == 0;
	}
	size_t size() const {
		return m_size;
	}
	T top() const;
	void push(const T value);
	T pop();
};

template <typename T>
T Stack<T>::top() const {
	if(m_top > 0)
		return m_values[m_top - 1];
	else {
		throw std::out_of_range("top");
	}
}

template <typename T>
void Stack<T>::push(const T value) {
	if(m_top < m_size)
		m_values[m_top++] = value;
	else {
		return;
	}
}

template <typename T>
T Stack<T>::pop() {
	try {
		if(m_top > 0) {
			return m_values[m_top--];
		}
		else {
			throw std::out_of_range("pop");
		}
	}
	catch(std::out_of_range& e) {
		std::cout << e.what();
		return -1;
	}
}

void status(Stack<int>& a) {
	try
	{
		std::cout << "\nTop: " << a.top() << "; Size: " << a.size() << "; Empty: " << a.empty();
	}
	catch(std::out_of_range& e) {
		std::cout << e.what() << " ";
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	Stack<int> a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(5);
	a.push(8);
	status(a);
	a.pop();
	status(a);
	a.pop();
	status(a);
	a.pop();
	status(a);
	a.pop();
	status(a);
	a.pop();
	status(a);
	a.pop();
	a.push(7);
	status(a);
	a.~Stack();
	a.pop();
	status(a);
	Stack<int> b;
	b.pop();
	status(b);
	Stack<int> c;
	c.pop();
	status(c);
	system("pause");
	return 0;
}

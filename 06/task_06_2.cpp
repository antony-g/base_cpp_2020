// 6.1. Вычисление и хранение дистанции

// Реализуйте класс IntArray, который представляет собой массив типа int. Реализуйте методы, указанные в примере. Конструктор инициализирует массив определенного размера, заполненный значениями по-умолчанию. Метод push_back добавляет в конец массива новый элемент. Метод erase удаляет элемент, находящийся по индексу массива. Методы get и set представляют собой геттер и сеттер. Определите спецификаторы доступа для методов и полей класса. Реализуйте конструктор копирования и деструктор.

#include <iostream>
#include "IntArray.h"
using namespace std;

class IntArray
{
private:
	size_t m_size;
	int* m_values;

public:
	IntArray(size_t size, int defaultValue = 0): m_size(size)
	{
		m_values = new int[m_size];
		if(m_values == NULL)
		{
			cout << "error: malloc" << endl;
			return;
		}
		for(size_t i = 0; i < m_size; ++i)
			m_values[i] = defaultValue;
	}
	IntArray(const IntArray& other): m_size(other.m_size)
	{
		m_values = new int[m_size];
		if(m_values == NULL)
		{
			return;
		}
		for(size_t i = 0; i < m_size; ++i)
			m_values[i] = other.m_values[i];
	}

	~IntArray() {
		delete(m_values);
	}

	void push_back(int value) {
		realloc(m_values, (m_size + 1)*sizeof(int));
		m_values[m_size] = value;
		++m_size;
	}

    void erase(size_t position) {
    	if(position >= m_size) {
    		cout << "error: erase" << endl;
    		return;
    	}
    	else {
    		while(position++ < m_size)
    		m_values[position - 1] = m_values[position];
    	realloc(m_values, (m_size - 1)*sizeof(int));
		--m_size;
    	}
    }

    int get(size_t position) {
    	if(position >= m_size) {
    		cout << "error: get";
    		return 0;
    	}
    	else
    		return m_values[position];
    }

    void set(size_t position, int value) {
    	m_values[position] = value;
    }

    size_t size() {
    	return m_size;
    }
};


int main()
{
	setlocale(LC_ALL, "Rus");

	// Инициплизация массива
	size_t n = 16;
	IntArray a(n, 1);
	cout << "Массив из единиц: ";
	for(size_t i = 0; i < a.size(); ++i){
		cout << a.get(i) << " ";
	}
	cout << "размер: " << a.size() << endl;
	
	// Задание значений массива
	int arr[] = {120,50,60,92,16,20,796,53,14,679,5000,2000,497,123,15,78};
	for(size_t i = 0; i < a.size(); ++i){
		a.set(i, arr[i]) ;
	}
	cout << "Новый массив: ";
	for(size_t i = 0; i < a.size(); ++i){
		cout << a.get(i) << " ";
	}
	cout << "размер: " << a.size() << endl;

	// Получение значения элемента массива
	int i = 100;
	cout << "Элемент № " << i << ":" << a.get(i) << endl;

	// Добавление элемента к массиву
	a.push_back(255);
	cout << "Новый массив: ";
	for(size_t i = 0; i < a.size(); ++i){
		cout << a.get(i) << " ";
	}
	cout << "размер: " << a.size() << endl;

	// Удаление элемента из массива по индексу
	a.erase(100);
	cout << "Новый массив: ";
	for(size_t i = 0; i < a.size(); ++i){
		cout << a.get(i) << " ";
	}
	cout << "размер: " << a.size() << endl;

	// Удаление экземпляра класса
	delete &a;
	cout << "Массив удален." << endl;

	// Создание экземпляра массива критической длины
	IntArray b(100000000, 0);
	cout << "Элемент № 50000000: " << b.get(50000000) << endl;
	cout << "Длина массива: " << b.size() << endl;
	cout << "Массив создан." << endl;

	system("pause");
	return 0;
}

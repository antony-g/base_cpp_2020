// 10.2. Обращение к элементам контейнера

// Реализуйте шаблонный класс Iterator, который позволяет обращаться к элементам абстрактного контейнера. Подразумевается, что контейнер содержит элементы в неразрывном блоке памяти. Класс итератора принимает шаблонным параметром тип данных, на который он указывает, и хранит указатель на место в памяти, из которого можно получить данные. Объект класса принимает указатель через конструктор, важно учесть, что принимаемый указатель может быть любого типа данных.
// Реализуйте класс согласно контракту RandomAccessIterator, который означает, что итератор может изменить свой значение за константное время.
// Убедитесь, что итератор работает для алгоритмов из стандартной библиотеки C++, например std::advance, std::sort.

// #include <bits/stdc++.h> // Подключает все библиотеки C++

#include <iostream>
#include <memory>
#include <algorithm>
#include <cassert>
using size_type = std::size_t;
using difference_type = std::ptrdiff_t;

template <typename T>
class Iterator: public std::iterator<std::random_access_iterator_tag, T>
{
private:
	T* m_ptr;
public:
	Iterator() noexcept: m_ptr(nullptr) {}
	Iterator(T* ptr): m_ptr(ptr) {}
	Iterator(const Iterator& other): m_ptr(other.m_ptr) {}
	Iterator(T value) {
		*m_ptr = value;
	}
	~Iterator() {}
	typename Iterator<T>::reference operator*() const {
		return *m_ptr;
	}
	typename Iterator<T>::pointer operator->() {
		return m_ptr;
	}
	void operator()(T* value) {
		 m_ptr = value;
	}
	bool operator>(const T &other) const {
		return (*m_ptr > other);
	}
	bool operator<(const T &other) const {
		return (*m_ptr < other);
	}
	bool operator<(const Iterator<T>& other) {
		return (m_ptr < other.m_ptr);
	}
	bool operator<=(const Iterator<T>& other) {
		return (m_ptr <= other.m_ptr);
	}
	bool operator>(const Iterator<T>& other) {
		return (m_ptr > other.m_ptr);
	}
	bool operator>=(const Iterator<T>& other) {
		return (m_ptr >= other.m_ptr);
	}
	bool operator==(const Iterator<T>& other) const {
		return (m_ptr == other.m_ptr);
	}
	bool operator!=(const Iterator<T>& other) const {
		return (m_ptr != other.m_ptr);
	}
	Iterator& operator=(const T& other) {
		*m_ptr = other;
		return *this;
	}
	Iterator& operator=(const Iterator<T>& other) {
		m_ptr = other.m_ptr;
		return *this;
	}
	Iterator<T>& operator++() {
		++m_ptr;
		return *this;
	}
	Iterator<T>& operator--() {
		--m_ptr;
		return *this;
	}
	Iterator operator++(T) {
		Iterator tmp = *this;
		++*this;
		return tmp;
	}
	Iterator operator--(T) {
		Iterator tmp = *this;
		--*this;
		return tmp;
	}
	T operator-(const Iterator<T>& other) const
    {
        return m_ptr - other.m_ptr;
    }
	Iterator operator+(T other) const
    {
        return Iterator(m_ptr + other);
    }
    Iterator operator-(T other) const
    {
        return Iterator(m_ptr - other);
    }
	Iterator operator+(const T &other) {
		m_ptr += other;
		return *this;
	}
	Iterator operator-(const T &other) {
		m_ptr -= other;
		return *this;
	}
	Iterator operator+=(const T& other) {
		m_ptr += other;
		return *this;
	}
	Iterator operator-=(const T& other) {
		m_ptr -= other;
		return *this;
	}
	Iterator operator[](T other) {
		T tmp = {};
		if (this->m_ptr + other)
		{
			return this->m_ptr + other;
		}
		else return Iterator(&tmp);
	}
	template <typename m_T>
	friend Iterator<m_T> operator+(const m_T& src, const Iterator<m_T>& other);
	template <typename m_T>
	friend std::ostream &operator<<(std::ostream &os, const Iterator<m_T>& src);
};

template <typename T>
Iterator<T> operator+(const T& src, const Iterator<T>& other) {
	Iterator<T> tmp(src + other.m_ptr);
	return tmp;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Iterator<T>& src) {
	os << *src.m_ptr;
	return os;
}

template <typename T>
constexpr bool isIteratorRandom = std::is_same_v<typename std::iterator_traits<Iterator<T>>::iterator_category, std::random_access_iterator_tag>;


#define SIZE 10

int main()
{
	setlocale(LC_ALL, "Rus");
	static_assert(isIteratorRandom<int>, "iterator tag error");
	auto arr = std::make_unique<int[]>(SIZE);
	for (int i = 0; i < SIZE; ++i)
	{
		arr[i] = i;
	}
	Iterator<int> begin(&arr.get()[0]);
	Iterator<int> end(&arr.get()[SIZE]);
	int i = 0;
	auto it = begin;
	for (it = begin; it != end; ++it, ++i) {
		std::cout << *it << " ";
	}
	std::cout << "\n";
	std::sort(begin, end, std::greater<int>{});
	for (auto it = begin; it != end; ++it) {
		std::cout << *it << " ";
	}
	std::cout << "\n";
	it = begin;
	std::advance(it, 2);
	for (; it != end; ++it) {
		std::cout << *it << " ";
	}
	for (it = begin; it != end; ++it) {
		*it = i;
	}
	std::cout << "\n";
	for (; it < begin + (end - begin) / 2; it = 4 + it){
		std::cout << " It: "  << it << " Begin: " << begin << " End: " << end - 1 << " Res: " << begin + (end - begin) / 2 << "\n";
	}
	it = it - 2;
	it = it + 7;
	--it;
	it = it--;
	std::cout << "it[17]: " << it[17] << " " << "\n";
	std::cout << "(it > end): " << ((it > end) ? "True" : "False") << "\n";
	std::cout << "!(it >= it): " << (!(it >= it) ? "True (fail!)" : "False") << "\n";
	std::cout << "!(it <= it): " << (!(it <= it) ? "True (fail!)" : "False") << "\n";
	std::cout << "(it < begin): " << ((it < begin) ? "True (fail!)" : "False") << "\n";
	std::cout << "(it != it): " << ((it != it) ? "True (fail!)" : "False") << "\n";
	std::cout << "(begin == end): " << ((begin == end) ? "True (fail!)" : "False") << "\n";
	system("pause");
	return 0;
}

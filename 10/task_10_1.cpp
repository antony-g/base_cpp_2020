// 10.1. Реализуйте шаблонный класс Triple

// Реализуйте шаблонный класс Triple с тремя параметрами - первый тип данных в тройке, второй и третий. Класс должен хранить три поля этих типов и принимать их значения через конструктор.
// Реализуйте операторы сдвига из потока ввода и в поток вывода для этого класса.
// Элементы выводятся друг за другом через пробел.
// Определите шаблонную функцию process, которая считывает из стандартного потока ввода массив троек, специализированных шаблонными параметрами этой функции, в класс std::vector из библиотеки C++, затем сортирует его в порядке возрастания и выводит в стандартный поток вывода через пробел.
// Для сортировки используйте алгоритм std::sort из библиотеки C++. 
// Для сравнения классов определите шаблонный функциональный объект сравнения, который лексикографически сравнивает объект по его полям, и передайте его в std::sort.

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

template <typename A, typename B, typename C>
class Triple {
private:
	A m_value_a = {};
	B m_value_b = {};
	C m_value_c = {};
public:
	Triple() {}
	Triple(A value_a, B value_b, C value_c): m_value_a(value_a), m_value_b(value_b), m_value_c(value_c) {}
	Triple(const Triple<A, B, C>& src): m_value_a(src.m_value_a), m_value_b(src.m_value_b), m_value_c(src.m_value_c) {}
	~Triple() {}
	A get_a() {
		return m_value_a;
	}
	B get_b() {
		return m_value_b;
	}
	C get_c() {
		return m_value_c;
	}
	template <typename m_A, typename m_B, typename m_C>
	friend void process(Triple<m_A, m_B, m_C>& obj);
	template <typename m_A, typename m_B, typename m_C>
	friend std::ostream& operator<<(std::ostream& os, Triple<m_A, m_B, m_C>& obj);
	template <typename m_A, typename m_B, typename m_C>
	friend std::istream& operator>>(std::istream& os, Triple<m_A, m_B, m_C>& obj);
};

template <typename A, typename B, typename C>
std::ostream &operator<<(std::ostream& os, Triple<A, B, C>& obj) {
	os << obj.m_value_a << " " << obj.m_value_b << " " << obj.m_value_c;
	return os;
}

template <typename A, typename B, typename C>
std::istream &operator>>(std::istream& is, Triple<A, B, C>& obj) {
	is >> obj.m_value_a >> obj.m_value_b >> obj.m_value_c;
	return is;
}

template <typename A, typename B, typename C>
void process() {
	std::vector<std::tuple<A, B, C>> v;
	Triple<A, B, C> obj;
	while(std::cin >> obj)
	{
		v.push_back(std::make_tuple(obj.get_a(), obj.get_b(), obj.get_c()));
	}
	std::sort(v.begin(), v.end());
	for(const auto &i : v)
    {
    	std::cout << std::get<0>(i) << " " << std::get<1>(i) << " " << std::get<2>(i) << " ";
    }
}

int main()
{
	setlocale(LC_ALL, "Rus");
	Triple<int, float, long long int> a(1, 3.141592, 1E15+1E13);
	process<long, double, std::string>();
	system("pause");
	return 0;
}

// 9.1. �������� ���� ��������� ��������� ��������

// ���������� ��������� �������

// template <class T>
// T sum(const T* val, size_t size);

// ������� ������ ���������� ��� �������� ��������� �������� � ���������� ���������.

// ���������� ������������� ������� ��� ������ String. ������� ������ ���������� ������ � ���������� ��� ��������� ����� ���������. ����� ��������� � ������������ ������ � �������� � �� ������. � ������ ������� ����� data ��� ������� � ������.

#include <iostream>
#include <vector>

template <class T>
T sum(const T* val, size_t size) {
	T res = {};
	for (size_t i = 0; i < size; ++i)
	{
		res = res + val[i];
	}
	return res;
}

class String {
private:
	std::string m_value;
public:
	String() {}
	String(const std::string &val): m_value(val) {}
	~String() {}
	std::string data() const {
		return m_value;
	}
	String operator+(const String& other);
	String& operator=(const String &src);
};

String& String::operator=(const String& other) {
	m_value = other.m_value;
	return *this;
}

String String::operator+(const String& other) {
	std::string res = m_value + other.m_value;
	String tmp(res);
	return tmp;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	// �������������� ����������
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	float b[10] = {.1, .2, .3, .4, .5, .6, .7, .8, .9, 1.};
	int res1 = sum<int>(a, 10);
	std::cout << "����� 1: " << res1 << "\n";
	float res2 = sum<float>(b, 10);
	std::cout << "����� 2: " << res2 << "\n";

	// ��������� �������
	std::vector<std::string> strs;
	strs.reserve(2);
	strs.emplace_back("ab");
	strs.emplace_back("cd");
	strs.emplace_back("ef");
	std::vector<std::string> strs2 = {"a", "b", "c"};

	// ����� ���� ��������� ������� �����:
	std::cout << "������ 1: ";
	for(const auto& it: strs2) {
		std::cout << it;
	}
	std::cout << "\n";
	std::cout << "������ 2: ";
	size_t n = strs2.size();
	for(size_t i = 0; i < n; ++i) {
		std::cout << strs2.at(i);
	}
	std::cout << "\n";


	std::vector<String> strs3;
	strs3.reserve(3);
	strs3.emplace_back("ab");
	strs3.emplace_back("cd");
	strs3.emplace_back("ef");
	std::cout << "������ String: ";
	for(const auto& it: strs3) {
		std::cout << it.data() << " ";
	}
	std::cout << "\n";
	std::cout << "����� String: ";
	std::cout << sum(strs3.data(), strs3.size()).data() << "\n";

	std::string tmp = "Lol";
	std::cout << "����� data: " << tmp.data() << "\n";

	system("pause");
	return 0;
}

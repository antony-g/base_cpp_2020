// 7.1. ���������� ������-������� File

// ���������� �����-������� File ��� ��������� �� ����������� ���������� ����� C FILE. ������� ������ ����� ��������� ���� � ������������ � ��������� ��� � �����������. ����������� ���������. ���������� ������ write � read ��� ���������� ����������� �������� � FILE.

// ���� �����-���� �������� ���������� ���������, ��������� ���������� ���� std::runtime_error �� ����������� ���������� C++. ����� ������ ������ ���� ����� ��, ��� � �������� ������, �� �������� ���� ��������� ����������, ���� ��� ����������� - �ctr�.

#include <iostream>

class File
{
private:
	const char* m_path;
	const char* m_mode;
	FILE* m_fp;

public:
	File(const char* path, const char* mode): m_path(path), m_mode(mode), m_fp(std::fopen(m_path, m_mode))
	{
		try {
			if(!m_fp)
				throw std::runtime_error("ctr");
				// throw std::runtime_error("File opening failed");
		}
		catch (std::runtime_error& e) {
			std::cout << e.what() << "\n";
			// exit(1);
		}
	}
	File(const File& other)
	{
		return;
	}
	~File() {
		try {
			if(m_fp != NULL)
			{
				if(std::fclose(m_fp) == EOF)
				{
					throw std::runtime_error("~ctr");
					// throw std::runtime_error("File closing failed");
				}
			}
		}
		catch (std::runtime_error& e) {
			std::cout << e.what() << "\n";
		}
	}
	void read(char* buffer, size_t count, size_t size) {
		try {
			std::fread(buffer, size, count, m_fp);
			if(m_fp < 0)
				throw std::runtime_error("read");
				// throw std::runtime_error("File reading failed");
		}
		catch (std::runtime_error& e) {
			std::cout << e.what() << "\n";
		}
	}
	void write(const char* buffer, size_t count, size_t size) {
		try {
			// size_t count = static_cast<size_t>(strlen(buffer));
			size_t bytes_written = fwrite(buffer, size, count, m_fp);
			if(bytes_written != count)
				throw std::runtime_error("write");
				// throw std::runtime_error("File writing failed");
		}
		catch (std::runtime_error& e) {
			std::cout << e.what() << "\n";
		}
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	const char* path = "test.txt";
	std::cout << "���� � �����: " << path << "\n";

	File a(path, "r");
	std::cout << "���� ������" << "\n";
	a.read(buf, 99, 1);
	std::cout << "���� ��������" << "\n";
	std::cout << "���������� �����: " << buf << "\n";
	a.write("111");
	std::cout << "���� �������" << "\n";
	a.~File();
	std::cout << "���� ������" << "\n";

	system("pause");
	return 0;
}

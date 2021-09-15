// 7.1. Реализация класса-обертки File

// Реализуйте класс-обертку File для структуры из стандартной библиотеки языка C FILE. Обертка должна уметь открывать файл в конструкторе и закрывать его в деструкторе. Копирование запрещено. Реализуйте методы write и read для выполнения аналогичных операций с FILE.

// Если какую-либо операцию невозможно выполнить, выбросьте исключения типа std::runtime_error из стандартной библиотеки C++. Текст ошибки должен быть такой же, как и название метода, из которого было выброшено исключение, если это конструктор - “ctr”.

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
	std::cout << "Путь к файлу: " << path << "\n";

	File a(path, "r");
	std::cout << "Файл открыт" << "\n";
	a.read(buf, 99, 1);
	std::cout << "Файл прочитан" << "\n";
	std::cout << "Содержимое файла: " << buf << "\n";
	a.write("111");
	std::cout << "Файл записан" << "\n";
	a.~File();
	std::cout << "Файл закрыт" << "\n";

	system("pause");
	return 0;
}

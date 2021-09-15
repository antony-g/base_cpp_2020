// 7.2. ���������� ����� Parser � ������������� ��������� ������� �����

// ���������� ����� Parser � �������� ������������ ���������. ����� ��������� � ������������ ��������� �� ��������� FILE, �� ������� �� ��������� ����� ����� ����� ������. ���������� ����������� � ������� ������ run � ������������ �� ��� ���, ���� �� ����� ������ �����. � ������ �������� ���������� ��� ��������� �� ������� � ������� ��������:

// void (*numberCallback) (int)

// void (*progressCallback) (size_t)

// ������� numberCallback ���������� ��� ���������� ���������� ����� �� ������ � �������� ��� ����� ��� ��������. ������� progressCallback ���������� ��� ���������� ������������� ����������� ������ ����� ��� ����������. �������� �������� � ������� ������ setProgressInterval, �.�. ���� ������ �������� 100, ����� ������ 100 ����� ����� ������� ��� ������� � ������� ���������� �������. �������� �� ��������� ����� �������.

#include <iostream>

class Parser
{
private:
	FILE* m_fp;
	size_t m_interval;
	void (*m_numberCallback)(int n){};
	void (*m_progressCallback)(size_t i){};
	static void lambda1(int){ return; };
	static void lambda2(size_t){ return; };

public:
	Parser(FILE* fp): m_fp(fp), m_interval(1), m_numberCallback(&lambda1), m_progressCallback(&lambda2)
	{
		try {
			if(m_fp < 0)
				throw std::runtime_error("ctr");
		}
		catch (std::runtime_error& e) {
			std::cout << e.what() << "\n";
			return;
		}
	}
	Parser(const Parser& other) {}
	~Parser() {}

	void setProgressInterval(size_t interval) {
		if(interval <= 0)
			m_interval = 1;
		else
			m_interval = interval;
	}
	void run();
	void setNumberCallback(void (*numberCallback)(int));
	void setProgressCallback(void (*progressCallback)(size_t));
};

void Parser::setNumberCallback(void (*numberCallback)(int)) {
	m_numberCallback = numberCallback;
}
void Parser::setProgressCallback(void (*progressCallback)(size_t)) {
	m_progressCallback = progressCallback;
}

void Parser::run() {
	try {
		long long int a;
		int i = 0, n = 0;
		char* str = (char*) calloc(22, sizeof(char));
		char *p;
		if(str == NULL)
		{
			throw std::runtime_error("run");
		}
		std::cout << "\n�����:\n";
		while( (n = std::fscanf(m_fp, "%21s", str)) != EOF)
		{
			a = std::strtoll(str, &p, 10);
			// std::cout << "(" << p << ") ";
			if(a != 0 && p[0] == '\0') {
            	m_numberCallback(a);
            	if((i + 1) % m_interval == 0)
					m_progressCallback(i + 1);
            	++i;
            }
		}
		free(str);
		std::cout << "\n\n";
	}
	catch (std::runtime_error& e) {
		std::cout << e.what() << "\n";
		return;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	int interval = 1;

	// 1. ��������� ������������ ������� �� 16 ����� � ����� � 4.
	std:: cout << "1. ��������� ������������ ������� �� 16 ��������� � ����� � 4.\n";
	FILE* fp = std::fopen("task_07_2_input_1", "r");
	Parser p(fp);
	p.setNumberCallback([](int n) {
		std::cout << n << " ";
	});
	p.setProgressCallback([](size_t i) {
		std::cout << "(������� - " << i << " �����)\n";
		std::cout << "p:" << i << " ";
	});
	p.setProgressInterval(4);
	p.run();

	// 2. ������� ������ �� 200 ����� ���� short int.
	std:: cout << "2. ������� ������ �� 200 ����� ���� short int.\n";
	fp = std::fopen("task_07_2_input_2", "r");
	p = {fp};
	p.setNumberCallback([](int n) {
		std::cout << n << " ";
	});
	p.setProgressCallback([](size_t i) {
		std::cout << "(������� - " << i << " ����������)\n";
	});
	p.setProgressInterval(interval);
	p.run();

	// 3. ������ �� 50 ��������� � ������� long long int.
	std:: cout << "3. ������ �� 50 ��������� � ������� long long int.\n";
	fp = std::fopen("task_07_2_input_3", "r");
	p = {fp};
	p.setNumberCallback([](int n) {
		std::cout << n << " ";
	});
	p.setProgressCallback([](size_t i) {
		// std::cout << "(������� - " << i << "�����)\n";
		std::cout << "p:" << i << " ";
	});
	p.setProgressInterval(interval);
	p.run();

	// 4. ������ �� 10 ��������� � �������, �������������� long long int.
	std:: cout << "4. ������ �� 10 ��������� � �������, �������������� long long int.\n";
	fp = std::fopen("task_07_2_input_4", "r");
	p = {fp};
	p.setNumberCallback([](int n) {
		std::cout << n << " ";
	});
	p.setProgressCallback([](size_t i) {
		std::cout << "(������� - " << i << " ����������)\n";
	});
	p.setProgressInterval(interval);
	p.run();

	// 5. �������� ����� �� ���� � ����.
	std:: cout << "5. �������� ����� �� ���� � ����.\n";
	fp = std::fopen("task_07_2_input_5", "r");
	p = {fp};
	p.setNumberCallback([](int n) {
		std::cout << n << " ";
	});
	p.setProgressCallback([](size_t i) {
		std::cout << "(������� - " << i << " ����������)\n";
	});
	p.setProgressInterval(interval);
	p.run();

	std::cout << "1. ���� � 1.\n";
	fp = std::fopen("task_07_2_test_1", "r");
	p = {fp};
	p.setNumberCallback([](int n) {
		std::cout << n << " ";
	});
	p.setProgressCallback([](size_t i) {
		std::cout << "p:" << i << " ";
	});
	p.setProgressInterval(21);
	p.run();

	std::cout << "2. ���� � 2.\n";
	fp = std::fopen("task_07_2_test_2", "r");
	p = {fp};
	p.setNumberCallback([](int n) {
		std::cout << n << " ";
	});
	p.setProgressCallback([](size_t i) {
		std::cout << "p:" << i << " ";
	});
	p.setProgressInterval(8);
	p.run();

	std::cout << "3. ���� � 3.\n";
	fp = std::fopen("task_07_2_test_3", "r");
	p = {fp};
	p.setNumberCallback([](int n) {
		std::cout << n << " ";
	});
	p.setProgressCallback([](size_t i) {
		std::cout << "p:" << i << " ";
	});
	p.setProgressInterval(33);
	p.run();

	std::cout << "4. ���� � 4.\n";
	fp = std::fopen("task_07_2_test_4", "r");
	p = {fp};
	p.setNumberCallback([](int n) {
		std::cout << n << " ";
	});
	p.setProgressCallback([](size_t i) {
		std::cout << "p:" << i << " ";
	});
	p.setProgressInterval(0);
	p.run();


	std::cout << "5. ���� � 5.\n";
	fp = std::fopen("task_07_2_test_5", "r");
	p = {fp};
	p.setNumberCallback([](int n) {
		std::cout << n << " ";
	});
	p.setProgressCallback([](size_t i) {
		// std::cout << "p:" << i << " ";
	});
	p.setProgressInterval(42);
	p.run();

	std::cout << "6. ���� � 6.\n";
	fp = std::fopen("task_07_2_test_6", "r");
	p = {fp};
	p.setNumberCallback([](int n) {
		// std::cout << n << " ";
	});
	p.setProgressCallback([](size_t i) {
		std::cout << "p:" << i << " ";
	});
	p.setProgressInterval(1);
	p.run();

	std::cout << "7. ���� � 7.\n";
	fp = std::fopen("1task_07_2_test_7", "r");
	p = {fp};
	p.setNumberCallback([](int n) {
		// std::cout << n << " ";
	});
	p.setProgressCallback([](size_t i) {
		std::cout << "p:" << i << " ";
	});
	p.setProgressInterval(87);
	p.run();


	std::cout << "8. ���� � 8.\n";
	fp = std::fopen("task_07_2_test_8", "r");
	p = {fp};
	p.setNumberCallback([](int n) {
		// std::cout << n << " ";
	});
	p.setProgressCallback([](size_t i) {
		std::cout << "p:" << i << " ";
	});
	p.setProgressInterval(121);
	p.run();


	std::cout << "9. ���� � 9.\n";
	fp = std::fopen("task_07_2_test_9", "r");
	p = {fp};
	p.setNumberCallback([](int n) {
		std::cout << n << " ";
	});
	p.setProgressCallback([](size_t i) {
		std::cout << "p:" << i << " ";
	});
	p.setProgressInterval(4);
	p.run();

	system("pause");
	return 0;
}

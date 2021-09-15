// 6.1. Вычисление и хранение дистанции

// Реализуйте класс Distance, который хранит в себе информацию о дистанции в двух целочисленных полях - метрах и километрах. По умолчанию класс хранит в себе нулевые значения. Реализуйте геттеры getMeters и getKilometers для обоих полей, реализуйте аналогичные сеттеры. Реализуйте методы add и sub, которые позволяют сложить или вычесть дистанции и получить новую дистанцию. Количество метров может лежать в диапазоне от 0 до 999 включительно. Расставьте правильно модификаторы доступа.

#include <iostream>
using namespace std;

class Distance
{
private:
	long long int m_km;
	int m_m;

public:
	Distance(long long int km = 0, int m = 0): m_km(km), m_m(m) {
		if(m_m >= 1000){
			m_km += m_m / 1000;
			m_m %= 1000;
		}
		else if(m_m < 0){
			m_km += (m_m / 1000 - 1);
			m_m %= 1000;
			m_m += 1000;
		}
		if(m_km < 0){
			m_km = 0;
			m_m = 0;
		}
	}
	~Distance() { }
	int getKiloMeters() { return m_km; }
	void setKiloMeters(long long int km) { m_km = km; }
	int getMeters() { return m_m; }
	void setMeters(int m) { m_m = m; }

	Distance add(Distance other) {
		return Distance(m_km + other.m_km, m_m + other.m_m);
	}
	Distance sub(Distance other) {
		return Distance(m_km - other.m_km, m_m - other.m_m);
	}
};


int main()
{
	setlocale(LC_ALL, "Rus");
	int i = 1;
	Distance d1(1, 500);
	Distance d2(3, 250);
	Distance res = d1.add(d2);

	cout << "Distance 'd1': " << d1.getKiloMeters() << " km " << d1.getMeters() << " m." << endl;
	cout << "Distance 'd2': " << d2.getKiloMeters() << " km " << d2.getMeters() << " m." << endl;
	cout << "Distance 'res': " << res.getKiloMeters() << " km " << res.getMeters() << " m." << endl << endl;

	d1.setKiloMeters(5);
	d1.setMeters(200);
	d2.setKiloMeters(5);
	d2.setMeters(400);
	res = d1.sub(d2);
	cout << i << ". " << res.getKiloMeters() << " km " << res.getMeters() << " m." << endl;
	++i;

	d1.setKiloMeters(2);
	d1.setMeters(1200);
	d2.setKiloMeters(6);
	d2.setMeters(800);
	res = d1.add(d2);
	cout << i << ". " << res.getKiloMeters() << " km " << res.getMeters() << " m." << endl;
	++i;

	d1.setKiloMeters(6);
	d1.setMeters(1500);
	d2.setKiloMeters(5);
	d2.setMeters(2300);
	res = d1.sub(d2);
	cout << i << ". " << res.getKiloMeters() << " km " << res.getMeters() << " m." << endl;
	++i;

	d1.setKiloMeters(0);
	d1.setMeters(2700);
	d2.setKiloMeters(0);
	d2.setMeters(8000);
	res = d1.sub(d2);
	cout << i << ". " << res.getKiloMeters() << " km " << res.getMeters() << " m." << endl;
	++i;

	system("pause");
	return 0;
}

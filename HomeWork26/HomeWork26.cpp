//Шаблон проэкта
#include <iostream>
#include <string>
struct movies {
	std::string title ;
	int year = 2022;
	std::string genre ;
	unsigned int duration{};
	unsigned int price{};
}
movie1{ "Невезучие", 2003, "Камедия",85,355 },
movie2{"Мадагаскар",2005,"мультфильм",86,280},
movie3{"Достучаться до небес",1997,"Драмма",82,415};
void show_movie(movies M);
movies expensive(movies &m1, movies& m2, movies& m3);
void update_info(movies& M);
int main() {
	setlocale(LC_ALL, "Russian");
	std::cout << "Домашняя работа\n\tЗадача 1\n";
	show_movie(movie1);
	std::cout << "\n\tЗадача 2\n";
	std::cout << "Фильм с наибольшей ценной: \n";
	show_movie(expensive(movie1, movie2, movie3));
	std::cout << "\n\tЗадача 3\n";
	show_movie(movie2);
	update_info(movie2);
	show_movie(movie2);
}
//выводит информацию о фильме
void show_movie(movies M) {
	std::cout << "Название фильма:   " << M.title << '\n';
	std::cout << "Год выхода:        " << M.year << '\n';
	std::cout << "Жанр:              " << M.genre << '\n';
	std::cout << "Продолжительность: " << M.duration << '\n';
	std::cout << "Цена за диск:      " << M.price << std::endl;
}
//возвращает один фильм из трех, с наибольшей ценой
movies expensive(movies &m1, movies& m2, movies &m3) {
	if (m1.price >= m2.price && m1.price >= m3.price)
		return movie1;
	if (m2.price >= m1.price && m2.price >= m3.price)
		return movie2;
	return movie3;
}
//изменяет пораметры выбраного фильма
void update_info(movies& M) {
	unsigned int n;
	std::cout << "Выберите какую информацию о фильме надо обновить:\n";
	std::cout << "1. Название;\n2. Год выхода;\n3. Жанр;\n4. Продолжительность;\n5. Цена за диск;\n";
	std::cin >> n;
	switch (n){
	case 1: {
		std::cout << "Введите новое название -> ";
		std::cin.ignore();
		getline(std::cin, M.title); break;
	}
	case 2: {
		std::cout << "Введите год выхода фильма -> ";
		std::cin >> M.year; break;
	}
	case 3: {
		std::cout << "Введите жанр фильма -> ";
		std::cin.ignore();
		getline(std::cin, M.genre); break;
	}
	case 4: {
		std::cout << "Введите продолжительность фильма -> ";
		std::cin >> M.year; break;
	}
	case 5: {
		std::cout << "Введите новую цену диска -> ";
		std::cin >> M.price; break;
	}
	default:
		std::cout << "Выбран неверный параметр!\n";
		update_info(M);
	}
} 
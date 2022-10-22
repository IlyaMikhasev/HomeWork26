//������ �������
#include <iostream>
#include <string>
struct movies {
	std::string title ;
	int year = 2022;
	std::string genre ;
	unsigned int duration{};
	unsigned int price{};
}
movie1{ "���������", 2003, "�������",85,355 },
movie2{"����������",2005,"����������",86,280},
movie3{"����������� �� �����",1997,"������",82,415};
void show_movie(movies M);
movies expensive(movies &m1, movies& m2, movies& m3);
void update_info(movies& M);
int main() {
	setlocale(LC_ALL, "Russian");
	std::cout << "�������� ������\n\t������ 1\n";
	show_movie(movie1);
	std::cout << "\n\t������ 2\n";
	std::cout << "����� � ���������� ������: \n";
	show_movie(expensive(movie1, movie2, movie3));
	std::cout << "\n\t������ 3\n";
	show_movie(movie2);
	update_info(movie2);
	show_movie(movie2);
}
//������� ���������� � ������
void show_movie(movies M) {
	std::cout << "�������� ������:   " << M.title << '\n';
	std::cout << "��� ������:        " << M.year << '\n';
	std::cout << "����:              " << M.genre << '\n';
	std::cout << "�����������������: " << M.duration << '\n';
	std::cout << "���� �� ����:      " << M.price << std::endl;
}
//���������� ���� ����� �� ����, � ���������� �����
movies expensive(movies &m1, movies& m2, movies &m3) {
	if (m1.price >= m2.price && m1.price >= m3.price)
		return movie1;
	if (m2.price >= m1.price && m2.price >= m3.price)
		return movie2;
	return movie3;
}
//�������� ��������� ��������� ������
void update_info(movies& M) {
	unsigned int n;
	std::cout << "�������� ����� ���������� � ������ ���� ��������:\n";
	std::cout << "1. ��������;\n2. ��� ������;\n3. ����;\n4. �����������������;\n5. ���� �� ����;\n";
	std::cin >> n;
	switch (n){
	case 1: {
		std::cout << "������� ����� �������� -> ";
		std::cin.ignore();
		getline(std::cin, M.title); break;
	}
	case 2: {
		std::cout << "������� ��� ������ ������ -> ";
		std::cin >> M.year; break;
	}
	case 3: {
		std::cout << "������� ���� ������ -> ";
		std::cin.ignore();
		getline(std::cin, M.genre); break;
	}
	case 4: {
		std::cout << "������� ����������������� ������ -> ";
		std::cin >> M.year; break;
	}
	case 5: {
		std::cout << "������� ����� ���� ����� -> ";
		std::cin >> M.price; break;
	}
	default:
		std::cout << "������ �������� ��������!\n";
		update_info(M);
	}
} 
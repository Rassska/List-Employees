#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>
#include <string>

struct Employees {
	// Вектора(массивы) людей
	std::vector<std::string>FIO;
	std::vector<std::string>Adress;
	std::vector<std::string>Birthday;
	std::vector<std::string>Education;
	std::vector<std::string>Number;
	std::vector<std::string>Post;
	std::vector<std::string>Skill;

};


void Menu(int &choise) {
	std::cout << "Выберите действие: " << std::endl;
	std::cout << "1) Вывести всех сотрудников, имеющих..." << std::endl;
	std::cout << "2) Вывести количество сотрудников, работающих..." << std::endl;
	std::cout << "3) Добавить человека" << std::endl;
	std::cout << "4) Удалить человека" << std::endl;
	std::cout << "5) Показать всех" << std::endl;
	std::cout << "6) Выход" << std::endl;
	std::cout << "==> "; std::cin >> choise;
}

void ShowEducation(std::string &input, Employees &Employ) {
	system("cls");
	std::cout << "Введите образование: "; std::cin >> input; std::cout << std::endl;

	int AmountPeople = 0;

	for (int i = 0; i < Employ.FIO.size(); i++) {
		if (Employ.Education[i] == input) {
			std::cout << "ФИО: " << Employ.FIO[i] << std::endl;
			std::cout << "Adress: " << Employ.Adress[i] << std::endl;
			std::cout << "Birthday: " << Employ.Birthday[i] << std::endl;
			std::cout << "Education: " << Employ.Education[i] << std::endl;
			std::cout << "Number: " << Employ.Number[i] << std::endl;
			std::cout << "Post: " << Employ.Post[i] << std::endl;
			std::cout << "Skill: " << Employ.Skill[i] << std::endl;
			std::cout << "--------------------------------" << std::endl;
			AmountPeople++;
		}	
	}
	std::cout << "Всего людей: " << AmountPeople << std::endl;
}

void ShowPost(std::string &post, Employees &Employ) {

	system("cls");
	std::cout << "Введите пост: "; std::cin >> post; std::cout << std::endl;

	int AmountPeople = 0;

	for (int i = 0; i < Employ.FIO.size(); i++) {
		if (Employ.Post[i] == post) {
			std::cout << "ФИО: " << Employ.FIO[i] << std::endl;
			std::cout << "Adress: " << Employ.Adress[i] << std::endl;
			std::cout << "Birthday: " << Employ.Birthday[i] << std::endl;
			std::cout << "Education: " << Employ.Education[i] << std::endl;
			std::cout << "Number: " << Employ.Number[i] << std::endl;
			std::cout << "Post: " << Employ.Post[i] << std::endl;
			std::cout << "Skill: " << Employ.Skill[i] << std::endl;
			std::cout << "--------------------------------" << std::endl;
			AmountPeople++;
		}
	}
	std::cout << "Всего людей: " << AmountPeople << std::endl;
	
}

void AddHuman(Employees &Employ) {
	std::string main;

	std::string name;
	std::string lastname;
	std::string Otch;

	std::cout << "Имя: "; std::cin >> name;
	std::cout << "Фамилия: "; std::cin >> lastname;
	std::cout << "Отчество: "; std::cin >> Otch;
	main = name + " " + lastname + " " + Otch;
	Employ.FIO.push_back(main); 

	std::cout << "Adress: "; std::cin >> main; std::cout << std::endl;
	Employ.Adress.push_back(main);
	
	std::cout << "Birthday: "; std::cin >> main; std::cout << std::endl;
	Employ.Birthday.push_back(main);

	std::cout << "Education: "; std::cin >> main; std::cout << std::endl;
	Employ.Education.push_back(main);

	std::cout << "Number: "; std::cin >> main; std::cout << std::endl;
	Employ.Number.push_back(main);

	std::cout << "Post: "; std::cin >> main; std::cout << std::endl;
	Employ.Post.push_back(main);

	std::cout << "Skill: "; std::cin >> main; std::cout << std::endl;
	Employ.Skill.push_back(main);

	system("cls");
	std::cout << "Человек добавлен" << std::endl << std::endl;
}

void ShowAll(Employees &Employ) {
	system("cls");
	int AmountPeople = 0;
	for (int i = 0; i < Employ.Adress.size(); i++) {
		if (Employ.Skill[i] == "") {

		}
		else {
			std::cout << "ФИО: " << Employ.FIO[i] << std::endl;
			std::cout << "Adress: " << Employ.Adress[i] << std::endl;
			std::cout << "Birthday: " << Employ.Birthday[i] << std::endl;
			std::cout << "Education: " << Employ.Education[i] << std::endl;
			std::cout << "Number: " << Employ.Number[i] << std::endl;
			std::cout << "Post: " << Employ.Post[i] << std::endl;
			std::cout << "Skill: " << Employ.Skill[i] << std::endl;
			std::cout << "--------------------------------" << std::endl;
			AmountPeople++;
		}
	}	
	std::cout << "Всего людей: " << AmountPeople; std::cout << std::endl << std::endl;
}

void DeleteHuman(std::string number, Employees &Employ) {
	system("cls");
	std::cout << "Введите номер телефона: "; std::cin >> number; std::cout <<  std::endl;
	system("cls");
	for (int i = 0; i < Employ.Number.size(); i++) {
		if (number == Employ.Number[i]) {
			std::cout << Employ.FIO[i] << " - Удалён из списка" << std::endl << std::endl;
			Employ.Adress.erase(Employ.Adress.begin() + i);
			Employ.FIO.erase(Employ.FIO.begin() + i);
			Employ.Birthday.erase(Employ.Birthday.begin() + i);
			Employ.Education.erase(Employ.Education.begin() + i);
			Employ.Number.erase(Employ.Number.begin() + i);
			Employ.Post.erase(Employ.Post.begin() + i);
			Employ.Skill.erase(Employ.Skill.begin() + i);
		}
	}
	
	
}

void MainExit(Employees &Employ) {

	// Удаляем файлы что бы потом создать новые с новыми данными
	remove("FIO.txt");
	remove("Adress.txt");
	remove("Education.txt");
	remove("Birthday.txt");
	remove("Number.txt");
	remove("Post.txt");
	remove("Skill.txt");
	
	// создаём файлы
	std::ofstream FIO("FIO.txt");
	std::ofstream Adress("Adress.txt");
	std::ofstream Birthday("Birthday.txt");
	std::ofstream Education("Education.txt");
	std::ofstream Number("Number.txt");
	std::ofstream Post("Post.txt");
	std::ofstream Skill("Skill.txt");
	
	// записываем в них данные
	for (int i = 0; i < Employ.Adress.size(); i++) {

		FIO << Employ.FIO[i];
		FIO << std::endl;

		Adress << Employ.Adress[i];
		Adress << std::endl;

		Birthday << Employ.Birthday[i];
		Birthday << std::endl;

		Education << Employ.Education[i];
		Education << std::endl;

		Number << Employ.Number[i];
		Number << std::endl;

		Post << Employ.Post[i];
		Post << std::endl;

		Skill << Employ.Skill[i];
		Skill << std::endl;

	}

	FIO.close();
	Adress.close();
	Birthday.close();
	Education.close();
	Number.close();
	Post.close();
	Skill.close();

}

int main() {

	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Employees Employ; // Объект структуры
	
	std::vector<Employees>Vec; // Вектор(Массив) сотрудников

	std::string path = "FIO.TXT"; // Путь к txt

	std::ifstream fin; // Для проверки, роли не играет
	fin.open(path);

	// Проверка на наличие файлов
	if (fin.is_open()) {
		fin.close();
	}
	else {
		std::cout << "File not found";
	}

	// ------------------------------

	// Открытие файлов
	std::ifstream FIO("FIO.txt");
	std::ifstream Adress("Adress.txt");
	std::ifstream Birthday("Birthday.txt");
	std::ifstream Education("Education.txt");
	std::ifstream Number("Number.txt");
	std::ifstream Post("Post.txt");
	std::ifstream Skill("Skill.txt");

	std::string main; // сюда постают все данные со всех txt

	// проходим по txt файлам и ложим в векторы объекта Employ
	while (!FIO.eof()) {

		std::getline(FIO, main);
		Employ.FIO.push_back(main);
		main = " ";

		std::getline(Adress, main);
		Employ.Adress.push_back(main);
		main = "";

		std::getline(Birthday, main);
		Employ.Birthday.push_back(main);
		main = "";

		std::getline(Education, main);
		Employ.Education.push_back(main);
		main = "";

		std::getline(Number, main);
		Employ.Number.push_back(main);
		main = "";

		std::getline(Post, main);
		Employ.Post.push_back(main);
		main = "";

		std::getline(Skill, main);
		Employ.Skill.push_back(main);
		main = "";

	}

	bool wh = true;

	int choise = 0;

	std::string input_education; // Для ввода образования
	std::string input_post; // Для ввода Поста
	std::string input_number; // Для номера | удаление

	while (wh) {

		Menu(choise);

		switch(choise) {
		case 1:
			ShowEducation(input_education, Employ); // ищем по образовании
		break;

		case 2:
			ShowPost(input_post, Employ); // Ищем по должности
		break;

		case 3:
			AddHuman(Employ); // Добавляем человека
		break;

		case 4:
			DeleteHuman(input_number, Employ); // Удаляем
		break;

		case 5:
			ShowAll(Employ); // Выводим всех
		break;

		case 6:
			// закрымаем, иначе будут проблемы потом при записи
			FIO.close();
			Adress.close();
			Birthday.close();
			Education.close();
			Number.close();
			Post.close();
			Skill.close();

			MainExit(Employ);

			wh = false;
		break;
		}


	}

}
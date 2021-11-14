#include <iostream>
#include <vector>
#include <fstream>
#include <Windows.h>
#include <string>

struct Employees {
	// �������(�������) �����
	std::vector<std::string>FIO;
	std::vector<std::string>Adress;
	std::vector<std::string>Birthday;
	std::vector<std::string>Education;
	std::vector<std::string>Number;
	std::vector<std::string>Post;
	std::vector<std::string>Skill;

};


void Menu(int &choise) {
	std::cout << "�������� ��������: " << std::endl;
	std::cout << "1) ������� ���� �����������, �������..." << std::endl;
	std::cout << "2) ������� ���������� �����������, ����������..." << std::endl;
	std::cout << "3) �������� ��������" << std::endl;
	std::cout << "4) ������� ��������" << std::endl;
	std::cout << "5) �������� ����" << std::endl;
	std::cout << "6) �����" << std::endl;
	std::cout << "==> "; std::cin >> choise;
}

void ShowEducation(std::string &input, Employees &Employ) {
	system("cls");
	std::cout << "������� �����������: "; std::cin >> input; std::cout << std::endl;

	int AmountPeople = 0;

	for (int i = 0; i < Employ.FIO.size(); i++) {
		if (Employ.Education[i] == input) {
			std::cout << "���: " << Employ.FIO[i] << std::endl;
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
	std::cout << "����� �����: " << AmountPeople << std::endl;
}

void ShowPost(std::string &post, Employees &Employ) {

	system("cls");
	std::cout << "������� ����: "; std::cin >> post; std::cout << std::endl;

	int AmountPeople = 0;

	for (int i = 0; i < Employ.FIO.size(); i++) {
		if (Employ.Post[i] == post) {
			std::cout << "���: " << Employ.FIO[i] << std::endl;
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
	std::cout << "����� �����: " << AmountPeople << std::endl;
	
}

void AddHuman(Employees &Employ) {
	std::string main;

	std::string name;
	std::string lastname;
	std::string Otch;

	std::cout << "���: "; std::cin >> name;
	std::cout << "�������: "; std::cin >> lastname;
	std::cout << "��������: "; std::cin >> Otch;
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
	std::cout << "������� ��������" << std::endl << std::endl;
}

void ShowAll(Employees &Employ) {
	system("cls");
	int AmountPeople = 0;
	for (int i = 0; i < Employ.Adress.size(); i++) {
		if (Employ.Skill[i] == "") {

		}
		else {
			std::cout << "���: " << Employ.FIO[i] << std::endl;
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
	std::cout << "����� �����: " << AmountPeople; std::cout << std::endl << std::endl;
}

void DeleteHuman(std::string number, Employees &Employ) {
	system("cls");
	std::cout << "������� ����� ��������: "; std::cin >> number; std::cout <<  std::endl;
	system("cls");
	for (int i = 0; i < Employ.Number.size(); i++) {
		if (number == Employ.Number[i]) {
			std::cout << Employ.FIO[i] << " - ����� �� ������" << std::endl << std::endl;
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

	// ������� ����� ��� �� ����� ������� ����� � ������ �������
	remove("FIO.txt");
	remove("Adress.txt");
	remove("Education.txt");
	remove("Birthday.txt");
	remove("Number.txt");
	remove("Post.txt");
	remove("Skill.txt");
	
	// ������ �����
	std::ofstream FIO("FIO.txt");
	std::ofstream Adress("Adress.txt");
	std::ofstream Birthday("Birthday.txt");
	std::ofstream Education("Education.txt");
	std::ofstream Number("Number.txt");
	std::ofstream Post("Post.txt");
	std::ofstream Skill("Skill.txt");
	
	// ���������� � ��� ������
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

	Employees Employ; // ������ ���������
	
	std::vector<Employees>Vec; // ������(������) �����������

	std::string path = "FIO.TXT"; // ���� � txt

	std::ifstream fin; // ��� ��������, ���� �� ������
	fin.open(path);

	// �������� �� ������� ������
	if (fin.is_open()) {
		fin.close();
	}
	else {
		std::cout << "File not found";
	}

	// ------------------------------

	// �������� ������
	std::ifstream FIO("FIO.txt");
	std::ifstream Adress("Adress.txt");
	std::ifstream Birthday("Birthday.txt");
	std::ifstream Education("Education.txt");
	std::ifstream Number("Number.txt");
	std::ifstream Post("Post.txt");
	std::ifstream Skill("Skill.txt");

	std::string main; // ���� ������� ��� ������ �� ���� txt

	// �������� �� txt ������ � ����� � ������� ������� Employ
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

	std::string input_education; // ��� ����� �����������
	std::string input_post; // ��� ����� �����
	std::string input_number; // ��� ������ | ��������

	while (wh) {

		Menu(choise);

		switch(choise) {
		case 1:
			ShowEducation(input_education, Employ); // ���� �� �����������
		break;

		case 2:
			ShowPost(input_post, Employ); // ���� �� ���������
		break;

		case 3:
			AddHuman(Employ); // ��������� ��������
		break;

		case 4:
			DeleteHuman(input_number, Employ); // �������
		break;

		case 5:
			ShowAll(Employ); // ������� ����
		break;

		case 6:
			// ���������, ����� ����� �������� ����� ��� ������
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
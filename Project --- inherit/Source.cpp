#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
	char* name;
	int age;
public:
	Person() = default;
	Person(const char* n, int a) :age(a) {
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	void Print() {
		cout << "Name: " << name << "\tAge: " << age << endl;
	}
	void Input() {
		char buff[20];
		cout << "Enter name: ";
		cin.getline(buff, sizeof(buff));
		name = new char[strlen(buff) + 1];
		strcpy_s(name, strlen(buff) + 1, buff);
		cout << "Enter age: ";
		cin >> age;
	}
	~Person() {
		delete[] name;
		//cout << "Person Destructor " << endl;
	 }
};

class Student : public Person
{
	char* Univers;
public:
	Student(const char* n, int a, const char* Univer) :Person(n, a) {
		Univers = new char[strlen(Univer) + 1];
		strcpy_s(Univers, strlen(Univer) + 1, Univer);
	}
	~Student() {
		delete[] Univers;
		//cout << "Student destructor" << endl;
	}
	void Print() {
		cout << "Name: " << name << "\tAge: " << age << "\tUniversity: " << Univers << endl << endl;
	}
};

class Teacher : public Person
{
	string School; 
	double salary;
	int subjects[3] = { 'math', 'IT', 'PE'};
public:
	Teacher(const char* n, int a, string school, double sal) :Person(n, a) {
		School = school;
		salary = sal;
	}
	void Print() {
		cout << "Name: " << name << "\tAge: " << age << "\t\tSchool: " << School << "\t\tSalary: " << salary << endl << endl;
	}
	void Input() {
		cout << "Enter school: ";
		getline(cin, School);
		cout << "Enter salary: ";
		cin >> salary;
	}
};

class Doctor : public Person
{
	string speciality;
	int standing;
	bool isFamilyDoctor;
public:
	Doctor(const char* n, int a, string spec, int stand, bool isFamDoc) :Person(n, a) {
		speciality = spec;
		standing = stand;
		isFamilyDoctor = isFamDoc;
	}
	void Input() {
		cout << "Enter speciality: ";
		getline(cin, speciality);
		cout << "Enter standing: ";
		cin >> standing;
		cout << "Familydoctor? (1 - yes, 0 - no): ";
		cin >> isFamilyDoctor;
	}
	void Print() {
		cout << "Name: " << name << "\tAge: " << age << "\t\tSpeciality: " << speciality << "\t\tStanding: " << standing << "\t\tFamily doctor: " << isFamilyDoctor << endl << endl;
	}
};

class Driver : public Person
{
	string carNum;
	string seria_num;
public:
	Driver(const char* n, int a, string Num, string seria) :Person(n, a) {
		carNum = Num;
		seria_num = seria;
	}
	void Input() {
		cout << "Enter car number: ";
		getline(cin, carNum);
		cout << "Enter seria-number of driver license: ";
		getline(cin, seria_num);
	}
	void Print() {
		cout << "Name: " << name << "\tAge: " << age << "\t\tCar number: " << carNum << "\t\tSeria-number of driver license: " << seria_num << endl << endl;
	}
};


int main() {
	Student obj("Irina", 18, "ITstep");

	Teacher a("Alex", 28, "ITstep", 2000);
	a.Print();
	Doctor b("Oleg", 30, "general physician", 10, true);
	b.Print();
	Driver c("Max", 34, "AK2005C", "6245375633");
	c.Print();
}
#include <iostream>
#include <string>
#include <vector>

class Student {
public:
    std::string name;
    std::string surname;
    std::string group;
    int id;

    // Конструктор
    Student(std::string n, std::string sn, std::string g, int i)
        : name(n), surname(sn), group(g), id(i) {}

    // Метод для вывода информации о студенте
    void printInfo() const {
        std::cout << "Name: " << name << ", Surname: " << surname << ", Group: " << group << ", ID: " << id << std::endl;
    }
};

class StudentsList {
private:
    std::vector<Student> students;

public:
    // Функция для добавления студента в список
    void add(const Student& s) {
        students.push_back(s);
    }

    // Функция для вывода всех студентов
    void printAll() const {
        for (const auto& student : students) {
            student.printInfo();
        }
    }

    // Функция для вывода студентов по фамилии
    void printBySurname(const std::string& surname) const {
        for (const auto& student : students) {
            if (student.surname == surname) {
                student.printInfo();
            }
        }
    }

    // Функция для вывода студентов по имени
    void printByName(const std::string& name) const {
        for (const auto& student : students) {
            if (student.name == name) {
                student.printInfo();
            }
        }
    }
};
int main() {
    StudentsList list;

    // Создание 200 студентов
    for (int i = 1; i <= 200; ++i) {
        list.add(Student("Student" + std::to_string(i), "Surname" + std::to_string(i), "Group" + std::to_string(i), i));
    }

    // Вывод всех студентов
    list.printAll();

    // Вывод студентов по фамилии
    list.printBySurname("Surname1");

    // Вывод студентов по имени
    list.printByName("Student1");

    return 0;
}

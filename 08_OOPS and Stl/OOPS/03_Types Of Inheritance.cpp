#include <bits/stdc++.h>
using namespace std;

// Base Class
class Employee {
protected:
    string name;
    int employeeId;

public:
    Employee(string empName, int empId) {
        name = empName;
        employeeId = empId;
    }

    void display() const {
        cout << "Employee: " << name << ", ID: " << employeeId << endl;
    }
};

// ------------------------------
// 1. Single Inheritance
// ------------------------------
class Developer : public Employee {
private:
    string programmingLanguage;

public:
    Developer(string name, int id, string lang)
        : Employee(name, id) {
        programmingLanguage = lang;
    }

    void show() const {
        display();
        cout << "Role: Developer, Language: " << programmingLanguage << endl;
    }
};

// ------------------------------
// 2. Multilevel Inheritance
// ------------------------------
class SeniorDeveloper : public Developer {
private:
    int experience;

public:
    SeniorDeveloper(string name, int id, string lang, int exp)
        : Developer(name, id, lang) {
        experience = exp;
    }

    void showSenior() const {
        show();
        cout << "Experience: " << experience << " years" << endl;
    }
};

// ------------------------------
// 3. Hierarchical Inheritance
// ------------------------------
class Tester : public Employee {
public:
    Tester(string name, int id)
        : Employee(name, id) {}

    void test() const {
        display();
        cout << "Role: Tester" << endl;
    }
};

// ------------------------------
// Supporting Classes for Multiple Inheritance
// ------------------------------
class ProjectManager {
protected:
    string project;

public:
    ProjectManager(string proj) {
        project = proj;
    }

    void manageProject() const {
        cout << "Managing project: " << project << endl;
    }
};

class TeamLead {
protected:
    int teamSize;

public:
    TeamLead(int size) {
        teamSize = size;
    }

    void leadTeam() const {
        cout << "Leading team of size: " << teamSize << endl;
    }
};

// ------------------------------
// 4. Multiple Inheritance
// ------------------------------
class TechLead : public Employee, public ProjectManager, public TeamLead {
public:
    TechLead(string name, int id, string proj, int size)
        : Employee(name, id), ProjectManager(proj), TeamLead(size) {}

    void showTechLead() const {
        display();
        manageProject();
        leadTeam();
        cout << "Role: Tech Lead" << endl;
    }
};

// ------------------------------
// MAIN FUNCTION
// ------------------------------
int main() {

    cout << "----- Single Inheritance -----" << endl;
    Developer d("Shruti", 101, "C++");
    d.show();

    cout << "\n----- Multilevel Inheritance -----" << endl;
    SeniorDeveloper sd("Ram", 102, "Java", 5);
    sd.showSenior();

    cout << "\n----- Hierarchical Inheritance -----" << endl;
    Tester t("Neha", 103);
    t.test();

    cout << "\n----- Multiple Inheritance -----" << endl;
    TechLead tl("gauri", 104, "AI Project", 8);
    tl.showTechLead();

    return 0;
}
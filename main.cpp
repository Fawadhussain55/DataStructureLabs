#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

/* ========= Student Structure ========= */
struct Student {
    int id;
    char name[100];
    char dept[4];
    int semester;
    float cgpa;
    int credits;
    int year;
    Student* next;
};

/* ========= Global Head ========= */
Student* head = nullptr;
int totalStudents = 0;

/* ========= Load Data From File ========= */
void loadStudents() {
    ifstream file("students_data.txt");

    if (!file) {
        cout << "Unable to open students_data.txt\n";
        return;
    }

    file >> totalStudents;

    Student* last = nullptr;

    for (int i = 0; i < totalStudents; i++) {
        Student* s = new Student;

        file >> s->id;
        file.ignore();
        file.getline(s->name, 100);
        file >> s->dept >> s->semester >> s->cgpa >> s->credits >> s->year;

        s->next = nullptr;

        if (!head)
            head = s;
        else
            last->next = s;

        last = s;
    }

    file.close();
}

/* ========= Swap Two Students (Data Only) ========= */
void swapStudent(Student* a, Student* b) {
    Student temp = *a;

    a->id = b->id;
    strcpy(a->name, b->name);
    strcpy(a->dept, b->dept);
    a->semester = b->semester;
    a->cgpa = b->cgpa;
    a->credits = b->credits;
    a->year = b->year;

    b->id = temp.id;
    strcpy(b->name, temp.name);
    strcpy(b->dept, temp.dept);
    b->semester = temp.semester;
    b->cgpa = temp.cgpa;
    b->credits = temp.credits;
    b->year = temp.year;
}

/* ========= Bubble Sort (CGPA Ranking) ========= */
void bubbleSortByCGPA(Student* start) {
    bool swapped;

    do {
        swapped = false;
        Student* current = start;

        while (current->next) {
            if (current->cgpa < current->next->cgpa ||
               (current->cgpa == current->next->cgpa &&
                current->credits < current->next->credits)) {
                swapStudent(current, current->next);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

/* ========= File 1: Ranked by CGPA ========= */
void generateCGPARanking() {
    Student* copyHead = nullptr;
    Student* last = nullptr;

    for (Student* p = head; p; p = p->next) {
        Student* n = new Student(*p);
        n->next = nullptr;

        if (!copyHead)
            copyHead = n;
        else
            last->next = n;

        last = n;
    }

    bubbleSortByCGPA(copyHead);

    ofstream out("ranked_by_cgpa.txt");
    out << "RANK | ID | NAME | DEPT | SEM | CGPA | CREDITS | YEAR\n";

    int rank = 1;
    for (Student* p = copyHead; p; p = p->next) {
        out << setw(3) << rank++ << " | "
            << p->id << " | "
            << p->name << " | "
            << p->dept << " | "
            << p->semester << " | "
            << fixed << setprecision(2) << p->cgpa << " | "
            << p->credits << " | "
            << p->year << endl;
    }

    out.close();

    while (copyHead) {
        Student* temp = copyHead;
        copyHead = copyHead->next;
        delete temp;
    }
}

/* ========= File 2: Sorted by Enrollment Year (Selection Sort) ========= */
void generateEnrollmentReport() {
    Student* copyHead = nullptr;
    Student* last = nullptr;

    for (Student* p = head; p; p = p->next) {
        Student* n = new Student(*p);
        n->next = nullptr;

        if (!copyHead)
            copyHead = n;
        else
            last->next = n;

        last = n;
    }

    for (Student* i = copyHead; i; i = i->next) {
        Student* min = i;
        for (Student* j = i->next; j; j = j->next) {
            if (j->year < min->year ||
               (j->year == min->year && j->id < min->id)) {
                min = j;
            }
        }
        if (min != i)
            swapStudent(i, min);
    }

    ofstream out("sorted_by_enrollment.txt");

    int currentYear = -1;
    float sumCGPA = 0;
    int count = 0;

    for (Student* p = copyHead; p; p = p->next) {
        if (p->year != currentYear) {
            if (count > 0) {
                out << "Average CGPA: "
                    << fixed << setprecision(2)
                    << (sumCGPA / count) << "\n\n";
            }
            currentYear = p->year;
            sumCGPA = 0;
            count = 0;
            out << "YEAR " << currentYear << "\n";
        }

        out << p->id << " " << p->name
            << " CGPA: " << fixed << setprecision(2) << p->cgpa << endl;

        sumCGPA += p->cgpa;
        count++;
    }

    if (count > 0)
        out << "Average CGPA: "
            << fixed << setprecision(2)
            << (sumCGPA / count) << endl;

    out.close();
}

/* ========= Insertion Sort by Name ========= */
void insertByName(Student** list, Student* node) {
    if (!*list || strcmp(node->name, (*list)->name) < 0) {
        node->next = *list;
        *list = node;
        return;
    }

    Student* cur = *list;
    while (cur->next && strcmp(cur->next->name, node->name) < 0)
        cur = cur->next;

    node->next = cur->next;
    cur->next = node;
}

/* ========= File 3: Performance Tiers ========= */
void generatePerformanceTiers() {
    Student *elite=nullptr, *high=nullptr, *good=nullptr, *low=nullptr;
    int e=0,h=0,g=0,l=0;

    for (Student* p = head; p; p = p->next) {
        Student* n = new Student(*p);
        n->next = nullptr;

        if (p->cgpa >= 3.7) insertByName(&elite,n), e++;
        else if (p->cgpa >= 3.3) insertByName(&high,n), h++;
        else if (p->cgpa >= 3.0) insertByName(&good,n), g++;
        else insertByName(&low,n), l++;
    }

    ofstream out("performance_tiers.txt");

    out << "ELITE STUDENTS: " << e << "\n";
    for (Student* p=elite; p; p=p->next) out << p->name << endl;

    out << "\nHIGH ACHIEVERS: " << h << "\n";
    for (Student* p=high; p; p=p->next) out << p->name << endl;

    out << "\nGOOD STANDING: " << g << "\n";
    for (Student* p=good; p; p=p->next) out << p->name << endl;

    out << "\nNEEDS IMPROVEMENT: " << l << "\n";
    for (Student* p=low; p; p=p->next) out << p->name << endl;

    out.close();
}

/* ========= Free Memory ========= */
void freeMemory() {
    while (head) {
        Student* temp = head;
        head = head->next;
        delete temp;
    }
}

/* ========= Main ========= */
int main() {
    loadStudents();

    if (!head) {
        cout << "No student data found\n";
        return 0;
    }

    generateCGPARanking();
    generateEnrollmentReport();
    generatePerformanceTiers();

    freeMemory();

    cout << "All output files created successfully\n";
    return 0;
}

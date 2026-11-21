
#include <stdio.h>
#include <string.h>

struct Date {
    int day, month, year;
};

struct BP {
    int systolic, diastolic;
};

struct Patient {
    char name[50];
    int age;
    char phone[11];
    struct BP bp;
    struct Date visitDate;
};

void addPatient(struct Patient *p, const char name[],
                int age, const char phone[],
                int sys, int dia, int d, int m, int y)
{
    strcpy(p->name, name);
    p->age = age;
    strcpy(p->phone, phone);
    p->bp.systolic = sys;
    p->bp.diastolic = dia;
    p->visitDate.day = d;
    p->visitDate.month = m;
    p->visitDate.year = y;
}

int main()
{
    struct Patient p;

    addPatient(&p, "Arun", 21, "9876543210",
               120, 80, 20, 11, 2026);

    printf("Patient Details\n");
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Phone: %s\n", p.phone);
    printf("Blood Pressure: %d/%d\n",
           p.bp.systolic, p.bp.diastolic);
    printf("Visit Date: %02d/%02d/%d\n",
           p.visitDate.day,
           p.visitDate.month,
           p.visitDate.year);

    return 0;
}


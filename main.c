#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int roll;
    char name[50];
    int age;
    char course[30];
    float marks;
};

void addStudent();
void displayStudent();
void searchStudent();
void updateStudent();
void deleteStudent();

int main()
{
    int choice;

    while (1)
    {
        printf("\n==============================");
        printf("\nSTUDENT MANAGEMENT SYSTEM");
        printf("\n==============================");
        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Search Student");
        printf("\n4. Update Student");
        printf("\n5. Delete Student");
        printf("\n6. Delete All Students");
        printf("\n7. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            displayStudent();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            updateStudent();
            break;
        case 5:
            deleteStudent();
            break;
        case 6:
            remove("students.dat");
            printf("\nAll records deleted successfully!\n");
            break;
        case 7:
            printf("\nThank you!\n");
            exit(0);
        default:
            printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}

void addStudent()
{
    FILE *fp;
    struct Student s;

    fp = fopen("students.dat", "ab");

    printf("\nEnter Roll Number: ");
    scanf("%d", &s.roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Age: ");
    scanf("%d", &s.age);

    printf("Enter Course: ");
    scanf(" %[^\n]", s.course);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);

    fclose(fp);

    printf("\nStudent Added Successfully!\n");
}

void displayStudent()
{
    FILE *fp;
    struct Student s;

    fp = fopen("students.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNo Records Found!\n");
        return;
    }

    printf("\n\nRoll\tName\t\tAge\tCourse\t\tMarks\n");
    printf("----------------------------------------------------------\n");

    while (fread(&s, sizeof(s), 1, fp))
    {
        printf("%d\t%s\t\t%d\t%s\t\t%.2f\n",
               s.roll, s.name, s.age, s.course, s.marks);
    }

    fclose(fp);
}

void searchStudent()
{
    FILE *fp;
    struct Student s;
    int roll, found = 0;

    fp = fopen("students.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNo Records Found!\n");
        return;
    }

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp))
    {
        if (s.roll == roll)
        {
            printf("\nStudent Found\n");
            printf("Roll: %d\n", s.roll);
            printf("Name: %s\n", s.name);
            printf("Age: %d\n", s.age);
            printf("Course: %s\n", s.course);
            printf("Marks: %.2f\n", s.marks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nStudent Not Found!\n");

    fclose(fp);
}

void updateStudent()
{
    printf("\nUpdate feature will be added in the next version.\n");
}

void deleteStudent()
{
    printf("\nDelete feature will be added in the next version.\n");
}

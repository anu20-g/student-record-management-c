/*
 * Student Record Management System
 * Team 1 Implementation
 * Concepts: Structures, Arrays, Functions
 */
#include <stdio.h>
#include <string.h>

#define MAX 50

struct Student {
    int rollNo;
    char name[50];
    char branch[30];
    float marks;
};

struct Student list[MAX];
int count = 0;

void addRecord() {
    if (count >= MAX) {
        printf("Record list is full!\n");
        return;
    }
    printf("\nEnter Roll Number: ");
    scanf("%d", &list[count].rollNo);
    getchar();
    printf("Enter Name: ");
    fgets(list[count].name, sizeof(list[count].name), stdin);
    list[count].name[strcspn(list[count].name, "\n")] = 0;
    printf("Enter Branch: ");
    fgets(list[count].branch, sizeof(list[count].branch), stdin);
    list[count].branch[strcspn(list[count].branch, "\n")] = 0;
    printf("Enter Marks: ");
    scanf("%f", &list[count].marks);
    count++;
    printf("Record inserted successfully.\n");
}

void showRecords() {
    if (count == 0) {
        printf("\nNo student records available.\n");
        return;
    }
    printf("\n---------------- STUDENT LIST ----------------\n");
    printf("%-8s %-22s %-15s %-6s\n", "RollNo", "Name", "Branch", "Marks");
    printf("----------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-8d %-22s %-15s %-6.2f\n", list[i].rollNo, list[i].name, list[i].branch, list[i].marks);
    }
    printf("----------------------------------------------\n");
}

void searchRecord() {
    int r, found = 0;
    printf("\nEnter Roll No to search: ");
    scanf("%d", &r);
    for (int i = 0; i < count; i++) {
        if (list[i].rollNo == r) {
            printf("Found: Roll %d | Name: %s | Branch: %s | Marks: %.2f\n",
                   list[i].rollNo, list[i].name, list[i].branch, list[i].marks);
            found = 1;
            break;
        }
    }
    if (!found) printf("Record with Roll No %d not found.\n", r);
}

void deleteRecord() {
    int r, found = 0;
    printf("\nEnter Roll No to delete: ");
    scanf("%d", &r);
    for (int i = 0; i < count; i++) {
        if (list[i].rollNo == r) {
            for (int j = i; j < count - 1; j++) {
                list[j] = list[j + 1];
            }
            count--;
            printf("Record deleted.\n");
            found = 1;
            break;
        }
    }
    if (!found) printf("Roll No not found.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n=== STUDENT MANAGEMENT ===\n");
        printf("1. Add Student\n2. Display All\n3. Search Student\n4. Delete Student\n5. Exit\n");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) addRecord();
        else if (choice == 2) showRecords();
        else if (choice == 3) searchRecord();
        else if (choice == 4) deleteRecord();
        else if (choice == 5) { printf("Goodbye!\n"); break; }
        else printf("Invalid option.\n");
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define ID_LENGTH 10
#define NAME_LENGTH 20

// Structure to store student information
typedef struct {
    char id[ID_LENGTH + 1];
    char name[NAME_LENGTH + 1];
} Student;

// Binary search function to find student by ID
int binary_search_student(Student* students, int n, char* searchId) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(students[mid].id, searchId);

        if (cmp == 0) {
            return mid;  // Student found
        }
        
        if (cmp < 0) {
            left = mid + 1;  // Search in right half
        } else {
            right = mid - 1;  // Search in left half
        }
    }

    return -1;  // Student not found
}

int main() {
    FILE *inputFile;
    int N, T;  // N: number of students, T: number of test cases
    Student students[MAX_STUDENTS];
    char searchId[ID_LENGTH + 1];

    // Open input file
    inputFile = fopen("testdata.in", "r");
    if (inputFile == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read number of students
    fscanf(inputFile, "%d", &N);
    
    // Read student records
    for (int i = 0; i < N; i++) {
        fscanf(inputFile, "%s %s", students[i].id, students[i].name);
    }

    // Read number of test cases
    fscanf(inputFile, "%d", &T);

    // Process each test case
    for (int caseNum = 1; caseNum <= T; caseNum++) {
        // Read student ID to search
        fscanf(inputFile, "%s", searchId);

        // Find student using binary search
        int index = binary_search_student(students, N, searchId);

        // Output result
        printf("Case #%d: ", caseNum);
        if (index != -1) {
            printf("%s\n", students[index].name);
        } else {
            printf("N/A\n");
        }
    }

    fclose(inputFile);
    return 0;
}
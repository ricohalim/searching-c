#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep()

void visualize_search(int *arr, int n, int current_index, int x) {
    printf("\nArray: ");
    for (int i = 0; i < n; i++) {
        if (i == current_index) {
            printf("[%d] ", arr[i]); // Highlight current element
        } else {
            printf("%d ", arr[i]);
        }
    }
    printf("\nSearching for: %d\n", x);
    if (arr[current_index] == x) {
        printf("-> Match found at index %d\n", current_index);
    } else {
        printf("-> Checking index %d... No match.\n", current_index);
    }
    printf("------------------------------------------------\n");
    sleep(1); // Pause for visualization
}

int linear_search(int *arr, int n, int x) {
    for (int i = 0; i < n; i++) {
        visualize_search(arr, n, i, x); // Visualize each step
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, x;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &x);

    int index = linear_search(arr, n, x);
    if (index != -1) {
        printf("\nElement found at index %d\n", index);
    } else {
        printf("\nElement not found\n");
    }

    free(arr);
    return 0;
}

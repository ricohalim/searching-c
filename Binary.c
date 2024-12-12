#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void visualize_search(int *arr, int left, int right, int mid, int x) {
    printf("\nCurrent Search Space: ");
    for (int i = left; i <= right; i++) {
        if (i == mid) {
            printf("[%d] ", arr[i]); // Highlight the middle element
        } else {
            printf("%d ", arr[i]);
        }
    }
    printf("\nTarget: %d\n", x);
    printf("Boundaries - Left: %d, Mid: %d, Right: %d\n", left, mid, right);

    if (arr[mid] == x) {
        printf("-> Target found at index %d\n", mid);
    } else if (arr[mid] < x) {
        printf("-> Midpoint (%d) less than target, searching right half\n", arr[mid]);
    } else {
        printf("-> Midpoint (%d) greater than target, searching left half\n", arr[mid]);
    }

    printf("------------------------------------------------\n");
    sleep(1); // Half-second pause for visualization
}

int binary_search(int *arr, int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        visualize_search(arr, left, right, mid, x);

        if (arr[mid] == x) {
            return mid; // Target found
        } else if (arr[mid] < x) {
            left = mid + 1; // Narrow to right half
        } else {
            right = mid - 1; // Narrow to left half
        }
    }
    return -1; // Target not found
}

int main() {
    int n;
    printf("Enter the number of elements in the sorted array: ");
    scanf("%d", &n);

    // Dynamically allocate array
    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Input sorted array
    printf("Enter %d sorted elements in ascending order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        
        // Validate sorting
        if (i > 0 && arr[i] < arr[i-1]) {
            printf("Error: Array must be sorted in ascending order.\n");
            free(arr);
            return 1;
        }
    }

    // Print the array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // Input search element
    int x;
    printf("Enter the element to search: ");
    scanf("%d", &x);

    // Perform binary search
    int index = binary_search(arr, n, x);
    
    if (index != -1) {
        printf("\nElement %d found at index %d\n", x, index);
    } else {
        printf("\nElement %d not found in the array\n", x);
    }

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
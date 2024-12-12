#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep()

void visualize_search(int *arr, int left, int right, int pos, int x) {
    printf("\nArray: ");
    for (int i = left; i <= right; i++) {
        if (i == pos) {
            printf("[%d] ", arr[i]); // Highlight the probed position
        } else {
            printf("%d ", arr[i]);
        }
    }
    printf("\nSearching for: %d\n", x);
    printf("Left: %d, Pos: %d, Right: %d\n", left, pos, right);

    if (arr[pos] == x) {
        printf("-> Match found at index %d\n", pos);
    } else if (arr[pos] < x) {
        printf("-> Element greater than %d, narrowing to right half.\n", arr[pos]);
    } else {
        printf("-> Element smaller than %d, narrowing to left half.\n", arr[pos]);
    }

    printf("------------------------------------------------\n");
    sleep(1); // Pause for visualization
}

int interpolation_search(int *arr, int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right && x >= arr[left] && x <= arr[right]) {
        // Calculate the probable position
        int pos = left + ((x - arr[left]) * (right - left)) / (arr[right] - arr[left]);

        visualize_search(arr, left, right, pos, x); // Visualize each step

        if (arr[pos] == x) {
            return pos; // Element found
        } else if (arr[pos] < x) {
            left = pos + 1; // Narrow to right half
        } else {
            right = pos - 1; // Narrow to left half
        }
    }
    return -1; // Element not found
}

int main() {
    int n, x;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &x);

    int index = interpolation_search(arr, n, x);
    if (index != -1) {
        printf("\nElement found at index %d\n", index);
    } else {
        printf("\nElement not found\n");
    }

    free(arr);
    return 0;
}

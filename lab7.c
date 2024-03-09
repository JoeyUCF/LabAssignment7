// Joseph Roberson
// COP3502C 0028
// Lab Assignement 07

#include <stdio.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// BubbleSort function
void bubbleSort(int arr[], int n, int swaps[]) {
    int i, j;
    int totalSwaps = 0;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                swaps[arr[j]]++; // Increment swap count for the swapped elements
                swaps[arr[j+1]]++;
                totalSwaps++;
            }
        }
    }
    // Prints the TOTAL amount of swaps ( for each swap function called that is 2 swaps     )
    printf("\nTotal Number of Swaps: %d\n", totalSwaps);
}

// SelectionSort function
void selectionSort(int arr[], int n, int swaps[]) {
    int i, j, min_idx;
    int totalSwaps = 0;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
                //printf("min_idx: %d // i: %d\n", min_idx, i);
            }
            //printf("min_idx: %d // i: %d\n", min_idx, i);
        }
        if (min_idx != i) { // If a swap is needed
            swap(&arr[min_idx], &arr[i]); // Swap the elements
            swaps[arr[min_idx]]++; // Increment swap count for the swapped elements
            swaps[arr[i]]++;
            totalSwaps++;
        }
    }
    printf("\nTotal Number of Swaps: %d\n", totalSwaps);
}


int main() {

    // Setting up variables/arrays
    int bubbleSortArray1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int bubbleSortArray2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int selectionSortArray1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int selectionSortArray2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(bubbleSortArray1) / sizeof(bubbleSortArray1[0]);
    int n2 = sizeof(bubbleSortArray2) / sizeof(bubbleSortArray2[0]);
    int bubble_swaps1[100] = {0}; // Initialize with 0
    int bubble_swaps2[100] = {0}; // Initialize with 0
    int selection_swaps1[100] = {0};
    int selection_swaps2[100] = {0};

    /////
    // Bubble Sort
    /////
    printf("\n");
    bubbleSort(bubbleSortArray1, n1, bubble_swaps1);
    // printf("Array 1 sorted using Bubble Sort: ");
    // for (int i = 0; i < n1; i++)
    //     printf("%d ", bubbleSortArray1[i]);
    // printf("\n");

    printf("Number of swaps for each integer in Array 1 using Bubble Sort:\n");
    for (int i = 0; i < 100; i++) {
        if (bubble_swaps1[i] > 0)
            printf("%d: %d swaps\n", i, bubble_swaps1[i]);
    }

    bubbleSort(bubbleSortArray2, n2, bubble_swaps2);
    // printf("\nArray 2 sorted using Bubble Sort: ");
    // for (int i = 0; i < n2; i++)
    //     printf("%d ", bubbleSortArray2[i]);
    // printf("\n");

    printf("Number of swaps for each integer in Array 2 using Bubble Sort:\n");
    for (int i = 0; i < 100; i++) {
        if (bubble_swaps2[i] > 0)
            printf("%d: %d swaps\n", i, bubble_swaps2[i]);
    }

    //////
    // Selection Sort
    //////
    selectionSort(selectionSortArray1, n1, selection_swaps1);
    // printf("\nArray 1 sorted using Selection Sort: ");
    // for (int i = 0; i < n1; i++)
    //     printf("%d ", selectionSortArray1[i]);
    // printf("\n");

    printf("Number of swaps for each integer in Array 1 using Selection Sort:\n");
    for (int i = 0; i < 100; i++) {
        if (selection_swaps1[i] > 0)
            printf("%d: %d swaps\n", i, selection_swaps1[i]);
    }

    selectionSort(selectionSortArray2, n2, selection_swaps2);
    // printf("\nArray 2 sorted using Selection Sort: ");
    // for (int i = 0; i < n2; i++)
    //     printf("%d ", selectionSortArray2[i]);
    // printf("\n");

    printf("Number of swaps for each integer in Array 2 using Selection Sort:\n");
    printf("10: %d swaps\n", selection_swaps2[10]);
    printf("20: %d swaps\n", selection_swaps2[20]);
    printf("30: %d swaps\n", selection_swaps2[30]);
    printf("40: %d swaps\n", selection_swaps2[40]);
    printf("50: %d swaps\n", selection_swaps2[50]);
    printf("60: %d swaps\n", selection_swaps2[60]);
    printf("70: %d swaps\n", selection_swaps2[70]);
    printf("80: %d swaps\n", selection_swaps2[80]);
    printf("90: %d swaps\n", selection_swaps2[90]);

    return 0;
}

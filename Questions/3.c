/*3.Write a program of implementation of array where these operation are performed 
– Insertion, Deletion, Sorting , Searching an element , Reversing.
*/
// NAME - ANSHIKA ARJARIYA
#include <stdio.h>

int main() {
    int arr[50], n, choice, pos, item;

    // Input array size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Menu for operations
    printf("\n1. Insert\n2. Delete\n3. Sort\n4. Search\n5. Reverse\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {

    case 1: // Insertion (0-based index)
        printf("Enter index and element: ");
        scanf("%d %d", &pos, &item);

        // Shift elements to the right
        for (int i = n; i > pos; i--)
            arr[i] = arr[i - 1];

        // Insert element
        arr[pos] = item;
        n++;
        break;

    case 2: // Deletion (0-based index)
        printf("Enter index to delete: ");
        scanf("%d", &pos);

        // Shift elements to the left
        for (int i = pos; i < n - 1; i++)
            arr[i] = arr[i + 1];

        n--;
        break;

    case 3: // Sorting (Bubble Sort)
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
        break;

    case 4: // Searching (Linear Search)
        printf("Enter element to search: ");
        scanf("%d", &item);

        for (int i = 0; i < n; i++) {
            if (arr[i] == item) {
                printf("Element found at index %d", i);
                return 0;
            }
        }
        printf("Element not found");
        return 0;

    case 5: // Reverse array
        for (int i = 0; i < n / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[n - i - 1];
            arr[n - i - 1] = temp;
        }
        break;

    default:
        printf("Invalid choice");
        return 0;
    }

    // Print final array
    printf("Resultant Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
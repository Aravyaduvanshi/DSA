#include <stdio.h>

int main() {
    int s, target;

    printf("Enter number of elements: ");
    scanf("%d", &s);

    int arr[s];

    printf("Enter %d elements:\n", s);
    for (int i = 0; i < s; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &target);

    int found = 0;

    for (int i = 0; i < s; i++) {
        if (arr[i] == target) {
            printf("Element found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Element not found\n");
    }

    return 0;
}
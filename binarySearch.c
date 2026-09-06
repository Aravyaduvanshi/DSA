#include <stdio.h>

int main() {
    int n, target;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements in sorted order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &target);

    int low = 0;
   
    int high = n - 1;
   
    int found = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        printf("mid value is %d",mid);
        if (arr[mid] == target) {
            printf("Element found at index %d\n", mid);
            found = 1;
            break;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
            printf("%d \n",low);
        }
        else {
            high = mid - 1;
            printf("%d \n",high);
        }
    }
    if (found == 0) {
        printf("Element not found\n");
    }
    return 0;
}
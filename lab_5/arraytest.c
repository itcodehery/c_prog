#include <stdio.h>

int main() {
    int n = 5;
    int ch, arr[n];

    void readlist() {
    for (int i = 0 ;i < n ; i++) {
        printf("\nEnter element %d:",i+1);
        scanf("%d", &arr[i]);
    }
    }

    int indexofmin(int start_index, int end_index) {
        int res = 0;
        for (int i = start_index ; i < end_index ; i++) {
            if(arr[i] < arr[res]) {
                res = i;
            }
        }
        return res;
    }

    void sorter() {
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0; j < n - 1 -i ; j++) {
                if(arr[j] < arr[j+1]) {
                    int temp = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    void display_list() {
        for(int i = 0 ; i < n ; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    
    int isPrime(int n) {
        if(n <= 1) return 0;
        for(int i = 2 ; i * i <= n ; i++) {
            if(n % i == 0) return 0;
        }
        return 1;
    }

    int printsum() {
        int sum = 0;
        for(int i = 0 ; i < n ; i++) {
            if (isPrime(arr[i])){
                sum += arr[i];
            }
        }
        return sum;
    }
    
    do {
        printf("1. Read list\n");
        printf("2. Sort list\n");
        printf("3. Display list\n");
        printf("4. Print sum\n");
        printf("5. Index of min\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: readlist();
                break;
            case 2: sorter();
                break;
            case 3: display_list();
                break;
            case 4: printf("Sum: %d\n", printsum());
                break;
            case 5: printf("Index of min: %d\n", indexofmin(2, 4));
                break;
            case 6: return 0;
            default: printf("Invalid choice\n");
        }
    } while (ch > 0);
    return 0;
}

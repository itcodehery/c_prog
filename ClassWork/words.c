#include<stdio.h>
#include<string.h>

#define STRLEN 20
// Read a string and print the number of words in it

int main() {
    char str[STRLEN];
    printf("Enter a string: ");
    fgets(str, STRLEN, stdin);
    str[strlen(str) - 1] = '\0';

    char words[STRLEN][10];
    int num_of_words = 0;
    int temp_index = 0;
    char temp_string[10];

    // str = "My name is xyz"
    for (int i = 0; i <= strlen(str); i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            temp_string[temp_index] = '\0';
            strcpy(words[num_of_words], temp_string);
            temp_index = 0;
            num_of_words++;
        } else {
            temp_string[temp_index] = str[i];
            temp_index++;
        }
    }

    printf("\nThe words in the string are:\n");
    for (int i = 0; i < num_of_words; i++) {
        printf("%s\n", words[i]);
    }

void sort_words(char words[][10], int num_of_words) {
    for (int i = 0; i < num_of_words - 1; i++) {
        for (int j = 0; j < num_of_words - i - 1; j++) {
            if (strcmp(words[j], words[j + 1]) > 0) {
                char temp[10];
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]); 
                strcpy(words[j + 1], temp);
            }
        }
    }
}

    sort_words(words, num_of_words);

    printf("\nThe sorted words are:\n");
    for (int i = 0; i < num_of_words; i++) {
        printf("%s\n", words[i]);
    }



    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LENGTH 256

bool is_date_format(int num) {
    // Extract day, month, and year from the number
    int day = num / 10000;
    int month = (num / 100) % 100;
    int year = num % 100;

    // Check if the date is valid
    if (day < 1 || day > 31 || month < 1 || month > 12){
        return false;   // Return false if the date is invalid
    }
    return true;  // Return true if the date is valid
}

int main() {
    char text[MAX_LENGTH + 1]; // +1 for the null terminator
    printf("Enter a text that ends with a dot (max 256 characters): ");
    fgets(text, MAX_LENGTH + 1, stdin);
    text[strcspn(text, ".")] = 0; // remove the dot at the end

    char seq[7]; // 6 digits + null terminator
    for (int i = 0; i < strlen(text) - 5; i++) {
        if (isdigit(text[i]) && isdigit(text[i+1]) && isdigit(text[i+2]) &&
            isdigit(text[i+3]) && isdigit(text[i+4]) && isdigit(text[i+5])) {
            strncpy(seq, text + i, 6);
            seq[6] = 0; // null terminate the sequence
            int num = atoi(seq);
            if (is_date_format(num)) {
                int day = num / 10000;
                int month = (num / 100) % 100;
                int year = num % 100;
                printf("%02d.%02d.%02d\n", day, month, year);
            }
        }
    }

    return 0;
}

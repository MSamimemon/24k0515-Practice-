#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int validateEmail(char* email) {
    if (email == NULL || strlen(email) == 0) {
        return 0;
    }

    int atCount = 0;
    char* atPosition = NULL;

    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            atCount++;
            if (atCount == 1) {
                atPosition = &email[i];
            }
        }
    }

    if (atCount != 1) {
        return 0;
    }

    if (atPosition != NULL) {
        char* dot = strchr(atPosition, '.');
        if (dot != NULL && dot > atPosition + 1 && *(dot + 1) != '\0') {
            return 1;
        }
    }

    return 0;
}

int main() {
    char* email = NULL;
    size_t length = 0;

    printf("Enter an email address:\n");
    if (getline(&email, &length, stdin) == -1) {
        perror("Failed to read input");
        free(email);
        return 1;
    }

    size_t emailLength = strlen(email);
    if (emailLength > 0 && email[emailLength - 1] == '\n') {
        email[emailLength - 1] = '\0';
    }

    if (validateEmail(email)) {
        printf("Valid Email\n");
    } else {
        printf("Invalid Email\n");
    }

    free(email);
    return 0;
}

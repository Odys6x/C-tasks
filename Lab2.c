#include <stdio.h>
#include <ctype.h>
#include <string.h>

int searchPatternInsensitive(char* text, char* pattern) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);

    for (int i = 0; i <= textLength - patternLength; i++) {
        if (strncmp(tolower(text + i), tolower(pattern), patternLength) == 0) {
            return i;
        }
    }

    return -1; // Pattern not found
}

int searchPatternSensitive(char* text, char* pattern) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);

    for (int i = 0; i <= textLength - patternLength; i++) {
        if (strncmp(text + i, pattern, patternLength) == 0) {
            return i;
        }
    }

    return -1; // Pattern not found
}

int searchPattern(char* text, char* pattern, int sensitive) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);

    for (int i = 0; i <= textLength - patternLength; i++) {
        int match = 1;
        for (int j = 0; j < patternLength; j++) {
            if (pattern[j] == '.')
                continue;
            if (pattern[j] == '_') {
                if (!isspace(text[i + j])) {
                    match = 0;
                    break;
                }
            }
            else {
                if (sensitive) {
                    if (text[i + j] != pattern[j]) {
                        match = 0;
                        break;
                    }
                }
                else {
                    if (tolower(text[i + j]) != tolower(pattern[j])) {
                        match = 0;
                        break;
                    }
                }
            }
        }
        if (match) return i;
    }

    return -1; // Pattern not found
}

int main() {
    char text[256];
    char pattern[256];
    int sensitive;

    // Get input from the user
    printf("Enter a line of text (up to 255 characters):\n");
    fgets(text, sizeof(text), stdin);
    printf("Enter a pattern (up to 255 characters):\n");
    fgets(pattern, sizeof(pattern), stdin);
    printf("Case sensitivity (0 for insensitive, 1 for sensitive): ");
    scanf("%d", &sensitive);

    // Remove the newline character at the end of the strings
    text[strcspn(text, "\n")] = '\0';
    pattern[strcspn(pattern, "\n")] = '\0';

    // Search for pattern based on case-sensitivity
    int index;
    if (sensitive) {
        index = searchPatternSensitive(text, pattern);
    }
    else {
        index = searchPattern(text, pattern, sensitive);
    }

    // Output results
    if (index != -1) {
        printf("Matches at position %d.\n", index);
    }
    else {
        printf("No match.\n");
    }

    return 0;
}

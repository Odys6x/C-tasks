<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>


#define MAX_RECORDS 256
#define MAX_LENGTH 256

// Function to open an existing database file or create a new one
void openFile();

// Function to save records to the database file
void saveFile();

// Function to display all records


// Function to insert a new record
void insertRecord();

// Function to query a record


// Function to update a record's value


// Function to delete a record


int main() {
    char filename[30];
    int cmd;
    char data[256][256] = { {0} }; // Initialize data with 0 (NULL)
    int recordCount = 0;

    printf("Please enter a filename: \n");
    scanf("%s", filename);

    openFile(filename, data, &recordCount);

    while (1) {
        printf("Enter a command (0: SHOW ALL ,1: INSERT ,2: QUERY ,3: UPDATE ,4: DELETE ,5: SAVE ,6: EXIT): \n");
        scanf("%d", &cmd);

        if (cmd == 1) {
            insertRecord(data, &recordCount, "sdddds", "1.456");
            saveFile(filename, data, recordCount);
        }
        // Add more cases for other commands as needed
    }

    return 0;
}

void openFile(char* filename, char data[MAX_RECORDS][2][MAX_LENGTH], int* recordCount) {
    FILE* file;
    file = fopen(filename, "r");

    if (file != NULL) {
        printf("File found. Loading database...\n");
        // Read data from the file and update data and recordCount accordingly
        while (fscanf(file, "%s %s", data[*recordCount][0], data[*recordCount][1]) == 2) {
            (*recordCount)++;
        }
        fclose(file);
    }
    else {
        printf("File not found. Creating a new database.\n");
        // Initialize data and recordCount if necessary
        *recordCount = 0;
    }
}

void saveFile(const char* filename, char data[MAX_RECORDS][2][MAX_LENGTH], int recordCount) {
    FILE* file = fopen(filename, "a");

    if (file != NULL) {
        for (int i = 0; i < recordCount; i++) {
            fprintf(file, "%s %s\n", data[i][0], data[i][1]);
        }
        fclose(file);
        printf("Database saved.\n");
    }
    else {
        printf("Error: Unable to open file for writing.\n");
    }
}

void insertRecord(char data[MAX_RECORDS][2][MAX_LENGTH], int* recordCount, const char* key, const char* value) {
    if (*recordCount >= MAX_RECORDS) {
        printf("Error: Maximum record count reached.\n");
        return;
    }

    for (int i = 0; i < *recordCount; i++) {
        if (strcmp(data[i][0], key) == 0) {
            printf("The record with Key=%s already exists in the database.\n", key);
            return;
        }
    }

    strcpy(data[*recordCount][0], key);
    strcpy(data[*recordCount][1], value);

    (*recordCount)++;
    printf("A new record of Key=%s, Value=%s is successfully inserted.\n", key, value);
}



=======
#include <stdio.h>
#include <stdlib.h>

// Function to open an existing database file or create a new one
void openFile();

// Function to save records to the database file
void saveFile();

// Function to display all records


// Function to insert a new record


// Function to query a record


// Function to update a record's value


// Function to delete a record


int main() {
    char filename[30];
    int cmd;
    char data[256][256] = { {NULL} };
    int recordCount = 0;

    printf("Please enter a filename: \n");
    scanf("%s", filename);

    openFile(filename, data, &recordCount);
    saveFile(filename, data, &recordCount);

    while (1)
    {
        printf("Enter a command (0: SHOW ALL ,1: INSERT ,2: QUERY ,3: UPDATE ,4: DELETE ,5: SAVE ,6: EXIT): \n");
        scanf("%d", &cmd);

        if (cmd == 0) {
            // Code for showing all records goes here
        }
        // Add more cases for other commands as needed
    }

    return 0;
}

void openFile(char* filename, char data[][256], int* recordCount) {
	FILE* file;
	file = fopen(filename, "r");

	if (file != NULL) {
		printf("File found. Loading database...\n");
		// Read data from the file and update data and recordCount accordingly
		fclose(file);
	}
	else {
		printf("File not found. Creating a new database.\n");
		// Initialize data and recordCount if necessary
		*recordCount = 0;
	}
}

void saveFile(const char* filename, char data[][256], int recordCount) {
    FILE* file = fopen(filename, "w");

    if (file != NULL) {
        for (int i = 0; i < recordCount; i++) {
            fprintf(file, "%s\n", data[i]);
        }
        fclose(file);
        printf("Database saved.\n");
    }
    else {
        printf("Error: Unable to open file for writing.\n");
    }
}
>>>>>>> b00bd591b25472ab2833e632e4ff93214d288263

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_handler.h"

#define MAX_FILE_SIZE 100000

char* read_txt_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return NULL;

    char *content = (char *)malloc(MAX_FILE_SIZE);
    if (!content) return NULL;

    size_t read_size = fread(content, 1, MAX_FILE_SIZE - 1, file);
    content[read_size] = '\0';

    fclose(file);
    return content;
}

// Future: Implement PDF support
char* read_pdf_file(const char *filename) {
    (void) filename; // Suppress unused parameter warning
    printf("PDF reading is not implemented yet.\n");
    return NULL;
}


char* read_file(const char *filename) {
    if (strstr(filename, ".txt")) {
        return read_txt_file(filename);
    } else if (strstr(filename, ".pdf")) {
        return read_pdf_file(filename);
    }
    return NULL;
}

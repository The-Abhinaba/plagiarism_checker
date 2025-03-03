#include <stdio.h>
#include <stdlib.h>
#include "file_handler.h"
#include "string_matching.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {  // Ensure at least 2 files
        printf("Usage: %s <file1> <file2> [file3 file4 ...]\n", argv[0]);
        return 1;
    }

    // Read all files into memory
    char *texts[argc - 1];
    for (int i = 1; i < argc; i++) {
        texts[i - 1] = read_file(argv[i]);
        if (!texts[i - 1]) {
            fprintf(stderr, "Error reading file: %s\n", argv[i]);
            return 1;
        }
    }

    // Compare each file with every other file
    printf("\n--- Plagiarism Report ---\n");
    for (int i = 0; i < argc - 2; i++) {
        for (int j = i + 1; j < argc - 1; j++) {
            double similarity = jaccard_similarity(texts[i], texts[j]);
            printf("Similarity between %s and %s: %.2f%%\n", argv[i + 1], argv[j + 1], similarity * 100);
        }
    }

    // Free allocated memory
    for (int i = 0; i < argc - 1; i++) {
        free(texts[i]);
    }

    return 0;
}

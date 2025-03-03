#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_matching.h"
#include "utils.h"

#define MAX_WORDS 10000

void extract_unique_words(const char *text, char words[MAX_WORDS][50], int *word_count) {
    *word_count = 0;

    char temp[10000];
    strncpy(temp, text, sizeof(temp));
    temp[sizeof(temp) - 1] = '\0';

    to_lowercase(temp);
    clean_text(temp);
    trim_whitespace(temp);

    char *token = strtok(temp, " ");
    while (token && *word_count < MAX_WORDS) {
        int is_unique = 1;
        for (int i = 0; i < *word_count; i++) {
            if (strcmp(words[i], token) == 0) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            strncpy(words[*word_count], token, 50);
            (*word_count)++;
        }
        token = strtok(NULL, " ");
    }
}

double jaccard_similarity(const char *text1, const char *text2) {
    char words1[MAX_WORDS][50], words2[MAX_WORDS][50];
    int count1, count2;

    extract_unique_words(text1, words1, &count1);
    extract_unique_words(text2, words2, &count2);

    int intersection = 0;
    int union_set = count1 + count2;

    for (int i = 0; i < count1; i++) {
        for (int j = 0; j < count2; j++) {
            if (strcmp(words1[i], words2[j]) == 0) {
                intersection++;
                break;
            }
        }
    }

    return (double)intersection / (union_set - intersection);
}

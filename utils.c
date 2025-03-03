 #include <ctype.h>
 #include <string.h>
 #include "utils.h"

 void to_lowercase(char *str) {
     for (int i = 0; str[i]; i++) {
         str[i] = tolower(str[i]);
     }
 }

 void clean_text(char *str) {
     int i, j = 0;
     for (i = 0; str[i] != '\0'; i++) {
         if (isalnum(str[i]) || isspace(str[i])) {
             str[j++] = str[i];
         }
     }
     str[j] = '\0';
 }

 void trim_whitespace(char *str) {
     int start = 0, end = strlen(str) - 1;

     while (isspace(str[start])) start++;
     while (end > start && isspace(str[end])) end--;

     memmove(str, str + start, end - start + 1);
     str[end - start + 1] = '\0';
 }

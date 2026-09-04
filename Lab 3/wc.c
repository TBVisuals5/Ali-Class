#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    int c;
    int lines = 0, words = 0, chars = 0;
    int in_word = 0;

    if (argc == 1) {
        fp = stdin;
    } else {
        fp = fopen(argv[1], "r");
        if (!fp) {
            perror("wc");
            return 1;
        }
    }

    while ((c = fgetc(fp)) != EOF) {
        chars++;
        if (c == '\n') lines++;
        if (isspace(c)) {
            if (in_word) {
                words++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
    }
    if (in_word) words++;

    printf("%d %d %d", lines, words, chars);
    if (argc > 1) printf(" %s", argv[1]);
    printf("\n");

    if (fp != stdin) fclose(fp);
    return 0;
}

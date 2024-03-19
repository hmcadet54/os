#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int total = 0;
    int count = 0;

    for (int i = 1; i < argc; i++) {
        int score = atoi(argv[i]);

        if (score >= 0 && score <= 100) {
            total += score;
            count++;
        } else {
            printf("Invalid score: %s\n", argv[i]);
        }
    }

    if (count > 0) {
        float average = (float) total / count;
        printf("Average grade: %.2f\n", average);
    } else {
        printf("No valid scores provided\n");
    }

    return 0;
}

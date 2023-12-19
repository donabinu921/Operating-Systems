#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_PAGES 50

void lfu(int[], int[], int, int);

int main() {
    int i, pCount, fCount, pages[MAX_PAGES], frames[MAX_FRAMES];

    printf("Number of Frames: ");
    scanf("%d", &fCount);

    for (i = 0; i < fCount; ++i) {
        frames[i] = -1;
    }

    printf("Number of Pages: ");
    scanf("%d", &pCount);

    printf("Enter the reference string:\n");
    for (i = 0; i < pCount; ++i) {
        scanf("%d", &pages[i]);
    }

    lfu(pages, frames, pCount, fCount);

    return 0;
}

void lfu(int pages[], int frames[], int pCount, int fCount) {
    printf("\nRef.String   |\tFrames\n");
    printf("-------------------------------\n");

    int i, j, k, flag, faultCount = 0;
    int counters[MAX_FRAMES] = {0};
    int lastUse[MAX_FRAMES] = {0};  // Counter for the time of last usage

    for (i = 0; i < pCount; ++i) {
        printf("  %d\t|\t", pages[i]);
        flag = 0;

        for (j = 0; j < fCount; ++j) {
            if (frames[j] == pages[i]) {
                flag = 1;
                counters[j]++;
                lastUse[j] = i;  // Update the time of last usage
                printf("   Hit");
                break;
            }
        }

        if (flag == 0) {
            int minCounter = counters[0];
            int minIndex = 0;

            for (j = 1; j < fCount; ++j) {
                if (counters[j] < minCounter || (counters[j] == minCounter && lastUse[j] < lastUse[minIndex])) {
                    minCounter = counters[j];
                    minIndex = j;
                }
            }

            frames[minIndex] = pages[i];
            counters[minIndex] = 1;
            lastUse[minIndex] = i;  // Update the time of last usage
            faultCount++;

            for (k = 0; k < fCount; ++k) {
                printf("%d  ", frames[k]);
            }
        }

        printf("\n\n");
    }

    printf("Total Page Faults = %d\n", faultCount);
}


/*
OUTPUT:
Enter no of pages: 15
Enter the reference string: 7 0 1 2 0 3 0 4 2 3 0 3 7 7 4
Enter no of frames: 4
        7
        7       1
        7       1       2
        7       1       2       0
        3       1       2       07 0 1 2 0 3 0 4 2 3 0 3 7 7 4
        3       4       2       0
        3       7       2       0
        3       7       4       0
The no of page faults is 8
*/
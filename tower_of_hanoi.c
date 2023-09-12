#include <stdio.h>

void towerOfHanoi(int n, char rodA, char rodB, char rodC, int *moveCount) {
    if (n == 1) {
        printf("Move disc 1 from %c to %c\n", rodA, rodC);
        (*moveCount)++;
        return;
    }

    towerOfHanoi(n - 1, rodA, rodC, rodB, moveCount);

    printf("Move disc %d from %c to %c\n", n, rodA, rodC);
    (*moveCount)++;

    towerOfHanoi(n - 1, rodB, rodA, rodC, moveCount);
}

int main() {
    int n, moveCount = 0;
    printf("Enter the number of discs: ");
    scanf("%d", &n);

    towerOfHanoi(n, 'A', 'B', 'C', &moveCount);

    printf("Number of moves: %d\n", moveCount);

    return 0;
}

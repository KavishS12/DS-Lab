//Program to find Transpose of a matrix using Sparse Row Method

#include <stdio.h>

struct Sparse {
    int row;
    int column;
    int value;
};

void set(struct Sparse* s, int r, int c, int v) {
    s->row = r;
    s->column = c;
    s->value = v;
}

void display(struct Sparse* s) {
    printf("%d %d %d\n", s->row, s->column, s->value);
}

struct Sparse* nTranspose(struct Sparse a[]) {
    struct Sparse* b = (struct Sparse*)malloc((a[0].value + 1) * sizeof(struct Sparse));
    set(&b[0], a[0].column, a[0].row, a[0].value);
    int k = 1;
    for (int i = 0; i < a[0].column; i++) {
        for (int j = 1; j <= a[0].value; j++) {
            if (a[j].column == i)
                set(&b[k++], a[j].column, a[j].row, a[j].value);
        }
    }
    return b;
}

int main() {
    int m, n;
    printf("Enter the size of the matrix:\n");
    scanf("%d%d", &m, &n);

    int arr[m][n];
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
            if (arr[i][j] != 0)
                count++;
        }
    }

    struct Sparse s[count + 1];
    set(&s[0], m, n, count);

    int k = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] != 0) {
                set(&s[++k], i, j, arr[i][j]);
            }
        }
    }

    printf("Matrix before Transposing\n");
    for (int k = 0; k <= count; k++) {
        display(&s[k]);
    }

    struct Sparse* b = nTranspose(s);

    printf("Matrix after Transposing\n");
    for (int k = 0; k <= count; k++) {
        display(&b[k]);
    }

    free(b);

    return 0;
}


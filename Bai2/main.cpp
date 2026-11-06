#include <stdio.h>
#include <stdlib.h>
void nhap(float *a, int h, int c) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%f", &a[i * c + j]);
        }
    }
}
void in(const float *a, int h, int c) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < c; j++) {
            printf("%.1f ", a[i * c + j]);
        }
        printf("\n");
    }
}
int main() {
    float *a;
    int n, m;
    scanf("%d %d", &n, &m);
    a = (float*) malloc(n * m * sizeof(float));
    nhap(a, n, m);
    in(a, n, m);
    free(a);
    a = NULL;
}

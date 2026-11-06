#include <stdio.h>
#include <stdlib.h>
void nhap(float *a, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%f", a + i);
    }
}
void in(const float *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f\t", *(a + i));
    }
    printf("\n");
}
int main() {
    int n;
    scanf("%d", &n);
    float *a = (float*) malloc(n * sizeof(float));
    nhap(a, n);
    in(a, n);
    free(a);
    return 0;
}

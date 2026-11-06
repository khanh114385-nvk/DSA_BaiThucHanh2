#include <iostream>
using namespace std;
void nhap(float *a, int n) {
  for (int i = 0; i < n; i++) {
    cin >> *(a + i);
  }
}
void in(const float *a, int n) {
  for (int i = 0; i < n; i++) {
    cout << *(a + i) << "\t";
  }
  cout << endl;
}
int main() {
  int n;
  cin >> n;
  float* a = new float[n];
  nhap(a, n);
  in(a, n);
  return 0;
}

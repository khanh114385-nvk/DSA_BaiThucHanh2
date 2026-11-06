#include <iostream>
using namespace std;
void Nhap(float* a, int n) {
  for (int i = 0; i < n; i++) {
    cin >> *(a + i);
  }
}
void In(const float* a, int n) {
  for (int i = 0; i < n; i++) {
    count << *(a + i) << "\t";
  }
  count << endl;
}
int main() {
  int n;
  cin >> n;
  float* a = new float[n];
  Nhap(a, n);
  In(a, n);
  return 0;
}

int a[5] = {1, 2, 3};

int main(void) {
  a[1] = 4;
  return a[0] + a[2] + a[1];
}
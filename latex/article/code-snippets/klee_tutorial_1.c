int get_sign(int x) {
  if (x == 0)
    return 0;

  if (x < 0)
    return -1;
  else
    return 1;
}

int main() {
  int a;|\label{var:klee_tutorial_1_var_a}|
  klee_make_symbolic(&a, sizeof(a), "a");
  return get_sign(a);
}
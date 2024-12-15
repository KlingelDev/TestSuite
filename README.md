# TestSuite
Very basic testsuite to be used in combination with cmakes ctest.
# Example
```
// test executable
int main(int argc, char *argv[]) {
  struct Test *tests = CreateTests();

  AddTest(tests, "one", test01);
  AddTest(tests, "two", test02);
  AddTest(tests, "fail", TestFail);

  int r = RunTest(tests, argc, argv);

  free(tests);

  return r;
}

int Test01() {
  return 1;
}

int Test02() {
  return 1;
}

int TestFnord() {
  return 0;
}
```
Your CMakeLists.txt:
```
...

enable_testing()

add_test(NAME 01test COMMAND test01 --config one)
add_test(NAME 02test COMMAND test01 --config two)

add_test(NAME TestFail COMMAND test01 --config fail)
set_property(TEST TestFail PROPERTY WILL_FAIL TRUE)
...
```

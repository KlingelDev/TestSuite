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
  return AssertPass;
}

int Test02() {
  return AssertFail;
}

int Test03() {
  return Assert(1, IsEqualTo(1));
}

int Test04() {
  return Assert(5, IsNotEqualToZero);
}

```
Your CMakeLists.txt:
```
...

enable_testing()

add_test(NAME 01test COMMAND test01 --config one)

add_test(NAME 02test COMMAND test01 --config two)
set_property(TEST Test02 PROPERTY WILL_FAIL TRUE)

add_test(NAME TestFail COMMAND test03 --config three)
...
```

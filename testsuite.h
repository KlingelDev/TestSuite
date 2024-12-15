struct Test *CreateTests();
int AddTest(struct Test *tests, char name[], int (*func)());
int RunTest( struct Test *tests, int argc, char *argv[]);

struct Test *addElement(struct Test *last);

struct Test {
  char name[255];
  int (*func)();
  struct Test *next;
  struct Test *last;
};

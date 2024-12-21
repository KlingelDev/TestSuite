#define IsEqualToZero == 0
#define IsNotEqualToZero == !0
#define IsEqualToNull == NULL
#define IsNotEqualToNULL == !NULL
#define IsEqualTo(y) == y
#define IsNotEqualTo(y) == !y

#define IsTrue true
#define IsFalse false

#define GreaterThan(y) > y
#define LesserThan(y) < y

#define AssertThat(x, y) (x y ? 0 : 1)
#define AssertPass 0
#define AssertFail 1

struct Test *CreateTests();
int AddTest(struct Test *tests, char name[], int (*func)());
int RunTest(struct Test *tests, int argc, char *argv[]);

struct Test *addElement(struct Test *last);

struct Test {
  char name[255];
  int (*func)();
  struct Test *next;
  struct Test *last;
};


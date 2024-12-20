#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "testsuite.h"


struct Test *CreateTests() {
  return malloc(sizeof(struct Test));
}

int AddTest(struct Test *tests, char name[], int (*func)()) {
  int i = 0;
  struct Test *t = tests;
  for(;;) {
    // Missing first element
    if(!t->next && strlen(t->name) == 0) {
      strcpy(t->name, name);
      t->last = NULL;
      t->func = func;
      break;

    // append next
    } else if(!t->next) {
      i++;
      t->next = addElement(t);
      t->next->func = func;
      strcpy(t->next->name, name);
      break;
    }

    // move along the chain
    if(t->next) {
      t = t->next;
    } else {
      break;
    }

    i++;
  } // for

  return 0;
}

struct Test *addElement(struct Test *last) {
  struct Test *ct = malloc(sizeof(struct Test));

  strcpy(ct->name, "");
  ct->next = NULL;
  ct->last = last;

  return ct;

}

int RunTest( struct Test *tests, int argc, char *argv[]) {
  if(argc > 1) {
    if(strcmp(argv[1], "--config") == 0) {
      struct Test *t = tests;
      for(;;) {
        if(strcmp(t->name, argv[2]) == 0) {
          int r = t->func();
          return r;
        }

        if(!t->next) {
          break;
        } else {
          t = t->next;
        }
      }

      printf("Test \"%s\" not found.\n", argv[2]);
      return 1;
    }
  }
  printf("No arguments.\n");
  return 1;
}

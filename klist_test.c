#include "./klist.h"
#include <stdio.h>
#include <stdlib.h>

void fail(char *test_name, char *reason) {
    printf("%s failure: %s", test_name, reason);
    exit(1);
}

void test_klist_iterate() {
  typedef struct test {
    int v;
    klist_node list;
  } test;

  // make a linked list of three items.
  test t1 = {0};
  t1.v = 1;

  test t2 = {0};
  t2.v = 2;

  test t3 = {0};
  t3.v = 3;

  t1.list.next = &t2.list;
  t2.list.prev = &t1.list;
  t2.list.next = &t3.list;
  t3.list.prev = &t2.list;

  int i = 1;
  KLIST_ITERATE(&t1.list, test, list)
      if (data->v != i)
          fail("test_klist_iterate", "unexpected data->v");
      i++;
  }
}

int main(int argc, char *argv[]) {
    test_klist_iterate();
}

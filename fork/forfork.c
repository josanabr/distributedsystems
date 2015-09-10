#include <stdio.h>

int main(int argc,char **argv) {
 int i = 0;
 for (; i < 3; i++) {
  fork();
  sleep(2);
 }
}

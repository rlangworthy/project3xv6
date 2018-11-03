#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"



int main(int argc, char *argv[]){

  char *test1 = "test1";
  uv2p(test1);
  char *test2 = "test2";
  uv2p(test2);
  char *test3 = (char*)malloc(10);
  uv2p(test3);

  printf(0,"%d\n", uv2p((char*)(-10)));
  exit();

}
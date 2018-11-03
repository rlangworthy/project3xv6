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
  uv2p((void*)test1);
  char *test2 = "test2";
  uv2p((void*)test2);
  char *test3 = (char*)malloc(10);
  uv2p((void*)test3);
  exit();

}
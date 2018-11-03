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

//  char *str1 = "test1";
  //char *str2 = "test2";

//  char *mem1 = (char*)malloc(10);
  //char *mem2 = (char*)malloc(10);
  //uv2p(test3);

  printf(0,"%d\n", uv2p((char*)(-10)));
  printf(0,"%d\n", uv2p((char*)(&argc)));
  printf(0,"%d\n", uv2p((char*)(&argc -2000)));

  exit();

}
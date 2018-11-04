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

  printf(0, "Test 1: argc and argv\n");
  if(uv2p((char*)&argv)-uv2p((char*)(&argc)) = 4)
  	printf(0, "Test 1 success\n");
  else
	printf(0,"Test 1 fail\n");
  
  printf(0, "Test 2: statically allocated variables\n")
  char *str1 = "test1";
  char *str2 = "test2";
  printf(0, "%d %d\n", uv2p(str1), uv2p(str2));

  char *mem1 = (char*)malloc(10);
  char *mem2 = (char*)malloc(10);
  

  printf(0,"%d\n", uv2p((char*)(-10)));


  exit();

}
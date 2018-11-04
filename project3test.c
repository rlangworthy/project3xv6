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
  if(uv2p((char*)&argv)-uv2p((char*)(&argc)) == 4)
  	printf(0, "Test 1 Success\n");
  else
	printf(0,"Test 1 Fail\n");
  printf(0, "%d %d\n", uv2p((char*)&argv), uv2p((char*)(&argc)));

  printf(0, "Test 2: dynamically allocated variables\n");
  char *mem1 = (char*)malloc(10);
  char *mem2 = (char*)malloc(10);
  
  if(uv2p(mem2)-uv2p(mem1) == 12)
  	printf(0, "Test 2 Success\n");
  else
  	printf(0, "Test 2 Fail\n");
  printf(0,"%d\n", uv2p((char*)(-10)));


  exit();

}
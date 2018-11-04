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

  /*
	Due to the way process memory is constructed argv and argc are going to be
	next to each other in memory and also within the same page.  It's a known
	constant I can test for to see if uv2p works on valid memory addresses.
  */
  printf(0, "Test 1: argc and argv\n");
  if(uv2p((char*)&argv)-uv2p((char*)(&argc)) == 4)
  	printf(0, "Test 1 Success\n");
  else
	printf(0,"Test 1 Fail\n");

  /*
	Another test to see if uv2p also returns a location in physical memory
	for valid dynamically allocated variables as well as the static ones
	above.
  */
  printf(0, "Test 2: dynamically allocated variables\n");
  char *mem1 = (char*)malloc(10);
  
  if(uv2p(mem1) > 0)
  	printf(0, "Test 2 Success\n");
  else
  	printf(0, "Test 2 Fail\n");

  /*
	Testing a failure case for a value in the kernels portion of the address
	space.  All negative integers when cast to unsigned integers point to
	locaiton in kernel space, the choice of -1 was arbitrary.
  */
  printf(0, "Test 3: out of bounds address\n");

  if((int)uv2p((char*)(-1)) == -1)
  	printf(0, "Test 3 Success\n");
  else
  	printf(0, "Test 3 Failure\n");


  exit();

}
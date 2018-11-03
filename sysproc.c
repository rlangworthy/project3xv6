#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_uv2p(void){

  void* vaddr;
  if (argptr(0,(char **)&vaddr,0) < 0)
    return -1;
  cprintf("vaddr = %p\n",vaddr);
  uint paddr;
  pde_t *pgdir;
  pte_t *pgtab;
  pde_t *pde;
  pte_t *pte;
  
  pgdir = myproc()->pgdir;
    
  cprintf("page directory base is: %p\n",pgdir);
  pde = &pgdir[PDX(vaddr)];
  if(*pde & PTE_P){
    pgtab = (pte_t*)P2V(PTE_ADDR(*pde));
  }else{
    cprintf("pde = %d\n",*pde);
    cprintf("PTE_P = %d\n",PTE_P);
    cprintf("pte not present\n");
    return 0;
  }
  pte = &pgtab[PTX(vaddr)];
  paddr = PTE_ADDR(*pte) | PTE_FLAGS(vaddr); //PTE_FLAGS coincidentally cover the offset of the virtual address
  cprintf("the virtual address is %d\n",(int)vaddr);
  cprintf("the physical address is %d\n",paddr);
  cprintf("ebp: %d  esp: %d kstack: %d\n", myproc()->tf->ebp, myproc()->tf->esp, (int)myproc()->kstack);

  return paddr | PTE_FLAGS(vaddr);
}

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

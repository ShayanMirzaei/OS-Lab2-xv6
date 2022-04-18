#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

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

int
sys_find_next_prime_number(void)
{
    int n = myproc()->tf->ebx;
    int prime;
    while (1) {
        n++;
        prime = 1;
        for (int i = 2; i*i < n; i++) {
            if (n % i == 0) {
                prime = 0;
                break;
            }
        }
        if (prime)
            return n;
    }
}

int
sys_get_call_count(void) {

    int syscall_number;

    if(argint(0, &syscall_number) < 0)
        return -1;

    if(syscall_number < 1 || syscall_number > 32)
        return -1;

    return myproc()->syscalls[syscall_number];

}

int
sys_get_most_caller(void) {
    int syscall_number;

    if(argint(0, &syscall_number) < 0)
        return -1;

    if(syscall_number < 1 || syscall_number > 32)
        return -1;

    return get_most_caller_proc(syscall_number);
}

int
sys_wait_for_process(void) {
    int pid;

    if(argint(0, &pid) < 0)
        return -1;

    return wait_for_proc(pid);
}


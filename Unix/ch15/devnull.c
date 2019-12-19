//只在两个相关的进程间起作用，都需要同步访问
#include "apue.h"
#include <fcntl.h>
#include <sys/mman.h>

#define NLOOPS 1000
#define SIZE sizeof(long)

static int update(long *ptr)
{
  return ((*ptr)++);
}

int main(void)
{
  int fd, i, counter;
  pid_t pid;
  void *area;

  if ((fd = open("/dev/zero", O_RDWR)) < 0) //接收并忽略所有信息
    err_sys("open error");
  if ((area = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_SHARED, -1, 0)) == MAP_FAILED)
    // if ((area = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)) == MAP_FAILED)
    err_sys("mmap error");

  close(fd);
  TELL_WAIT();
  if ((pid = fork()) < 0)
    err_sys("fork error");
  else if (pid > 0)
  {
    for (i = 0; i < NLOOPS; i += 2)
    {
      if ((counter = update((long *)area)) != i)
        err_quit("parent: expected %d,got %d", i, counter);
      // printf("parent: %d %d\n", i, counter);
      TELL_CHILD(pid);
      WAIT_CHILD();
    }
  }
  else
  {
    for (i = 1; i < NLOOPS + 1; i += 2)
    {
      WAIT_PARENT();
      if ((counter = update((long *)area)) != i)
        err_quit("child:expected %d,got %d", i, counter);
      //printf("child: %d %d\n", i, counter);
      TELL_PARENT(getppid());
    }
  }
  exit(0);
}
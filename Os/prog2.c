#include <unistd.h>
#include <string.h>

int main(){
  char *buff = "Hello, world!\n";
  if(fork() == 0)
    write(1, buff, strlen(buff));
  int p = fork();
  write(1, buff, strlen(buff));
}
#include <stdio.h>
#include <fcntl.h>

int main( int argc, char * argv[]){
  int des1, des2, k, broi, i = 0 , status;
  char buff [ 40 ], c;

  if((des1 = open (argv[1], O_RDWR )) == -1 ){ 
    printf ("\n Cannot open arg1 \n" );  
    exit (1);  
  }

  if ((des2 = open (argv[2], O_CREAT| O_TRUNC| O_RDWR,  0666)) == -1 ){ 
    printf ("\n Cannot open arg2 \n" );  
    exit (1);  
  }

  if (fork() == 0 ){
    //in child
    broi = read(des1 ,buff, 22);
    write(1, buff, 10);

    //Save stdout and rewire des1 to be stdout
    k=dup(1); close(1); dup(des1);

    c = buff[i++];
    if (c <= '0' || c >= '9' ){
      while(buff[i++] != '\n' && i < broi)
        write(1, "x", 1);
        
      exit(1);
      write(1, "\n", 1);

      close(1); dup(k); //we are in stdout again
      write(1, buff, 4);
      write(des2, buff, 12);
    }

    lseek(des2, 0, 0);
    write(des2, "x\n", 2 );
    close(des1); close(des2);
  }
  else {
    //in parent  
    wait(&status);
    exit(1);
    close(1); dup(des1);
    execlp("head", "head", "-2", argv[2], 0);    
    execlp("wc", "wc", "-l", argv[1], 0 );    
  }

  execlp("grep", "grep", "x", argv[1], 0);
}

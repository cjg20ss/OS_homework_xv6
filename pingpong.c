#include "types.h"
#include "stat.h"
#include "user.h"
int main(){
    int p1[2];
    int p2[2];
    pipe(p1);
    pipe(p2);
    int pid = fork();
    if(pid == 0){
        close(p1[1]);
        close(p2[0]);
        char son[2];
        read(p1[0],son,1);
        close(p1[0]);
        printf(1,"%d: received ping\n",getpid());
        write(p2[1],"a",2);
        close(p2[1]);
    }else if(pid > 0){
        close(p1[0]);
        close(p2[1]);
        write(p1[1],"a",2);
        close(p1[1]);
        char father[2];
        read(p2[0],father,1);
        printf(1,"%d: received pong\n",getpid());
        close(p2[0]);
    }
    exit();
}
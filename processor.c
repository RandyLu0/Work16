#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
    mkfifo("r",0644);
    int n;
    while(1){
        int fin = open("w",O_RDONLY);
        int fout = open("r",O_WRONLY);
        read(fin,&n,sizeof(n));
        close(fin);
        n++;
        write(fout,&n,sizeof(n));
        close(fout);
    }
    

    return 0;
}

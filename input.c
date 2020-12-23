#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    mkfifo("w",0644);
    int n;
    while(1){
        int fin = open("w",O_WRONLY);
	    int fout = open("r",O_RDONLY);
        printf("Enter in an integer: ");
        scanf("%d", &n);
		write(fin,&n,sizeof(n));
        close(fin);
		read(fout,&n,sizeof(n));
		printf("Processed value: %d\n",n);	
        close(fout);
    }
    return 0;
}
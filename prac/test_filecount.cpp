#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main (){
    DIR *dp;
    int i;
    struct dirent *ep;     
    dp = opendir ("./cache");

    if (dp != NULL){
	while (ep = readdir (dp))
	    i++;

	(void) closedir (dp);
    }
    else{
	perror ("Couldn't open the directory");
    }
    printf("There's %d files in the current directory.\n", i);

    return 0;
}

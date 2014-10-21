#include <iostream>
#include <dirent.h>

using namespace std;

int main(){
    int file_count = 0;
    DIR * dirp;
    struct dirent * entry;

    dirp = opendir("/home/yang/code/formation/HexsqPoseCache"); /* There should be error handling after this */
    while ((entry = readdir(dirp)) != NULL) {
	if (entry->d_type == DT_REG) { /* If the entry is a regular file */
	    file_count++;
	}
    }
    closedir(dirp);
    cout<<"Number of files = "<<file_count<<endl;
    return 0;
}


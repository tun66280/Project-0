#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <limits.h> 

void dirwalk(const char *path){
struct dirent **namelist;
struct stat stbuf;
int n=scandir(path,&namelist,NULL,alphasort);
    if(n==-1){
        perror("scandir");
    }
    for(int i=0; i<n;i++){
        char fullpath[PATH_MAX]; // Define a buffer for the full path. or should i use malloc?
        snprintf(fullpath, PATH_MAX, "%s/%s", path, namelist[i]->d_name); //check snprintf ohene

        if(strcmp(namelist[i]->d_name,".")==0 || strcmp(namelist[i]->d_name,"..")==0 || strcmp(namelist[i]->d_name,".git")==0){
            continue;
        }
        printf("%s ", namelist[i]->d_name);

        if (stat(fullpath,&stbuf)==0){
        if((S_ISDIR(stbuf.st_mode))){
            printf("%s","directory! \n");

        }
        else{printf("%s","file www \n" );}
        }
        free(namelist[i]);
    }

    free(namelist);

}




int main(){

dirwalk(".");

    return 0;
}
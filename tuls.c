#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <limits.h> 

static int istarget=0; // The power of BSS Data 

void dirwalk(const char *path,char *argument,int numArguments){
struct dirent **namelist; // namelist is a pointer to a pointer to a dirent class
struct stat stbuf; //can hold information of a path
int n=scandir(path,&namelist,NULL,alphasort); // returns the number of dirent objects in a stream
    if(n==-1){  // error handling code. If n==-1 then there were no objects in a stream
        perror("scandir"); // perror returns the type of error that occured. 
    }
    for(int i=0; i<n;i++){ // we wish to iterate through the stream
        char fullpath[PATH_MAX]; // Define a buffer for the full path. or should i use malloc?
        snprintf(fullpath, PATH_MAX, "%s/%s", path, namelist[i]->d_name); //check snprintf ohene

        if(strcmp(namelist[i]->d_name,".")==0 || strcmp(namelist[i]->d_name,"..")==0 || strcmp(namelist[i]->d_name,".git")==0){
            continue; // every directory contains "." and ".." so we skip these entries within our stream
        }
        printf("%s\n ", namelist[i]->d_name); // we print the directory or file within the stream
        
        if(numArguments==2) // if we have two arguments
       
            if (stat(fullpath,&stbuf)==0){ //  we put the information of our directory into stbuf

                if(strcmp(argument,namelist[i]->d_name)==0){ // we mark our flag if we have reached our target directory
                    istarget=1;
                }




                    if(istarget==1){ //we utilize BSS data and a flag to ensure we are recursively searching the correct directory
                    if((S_ISDIR(stbuf.st_mode))){ // the S_ISDIR macro returns true if stbuf.st_mode is a directory
                     //   printf("%s am a directory \n",namelist[i]->d_name);
                        dirwalk(fullpath,argument,numArguments); //recrusively search and print directory contents 

                    }
                }
            }
        free(namelist[i]); // we are dealing with the heap so we must clean up :)
    }

    free(namelist); // we are dealing with the heap so we must clean up :)

}




int main(int argc, char **argv ){
//printf("%d",argc);
dirwalk(".",argv[1],argc); // function call. Prints dirent objects in stream if 1 arg or recursively does so for a target directory if 2 args(second arg being the target directory )

    return 0;
}
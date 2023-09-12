#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>



void dirwalk(char *pathwalk){

int  pathlength=strlen(pathwalk);
//char *path= (char *)malloc(sizeof(char)*pathlength);

//strcpy(path,pathwalk);

struct dirent **namelist;    // intialize struct type that will be used in scandir method to go through directories
struct stat st;
int n; 

n=scandir(pathwalk,&namelist,NULL,alphasort); //returns number of directories in stream

if (n == -1) {
     perror("scandir");
     exit(EXIT_FAILURE);
             }
for ( int i=0; i<n;i++)
    {
        printf(namelist[i]->d_name);
        char *newdirectName= namelist[i]->d_name+"/";
        int newLen=strlen(newdirectName);
        char *newpath= malloc(sizeof(char)*pathlength+newLen+1);
        newpath=strcat(path,newpath);
        if (stat(newpath,&st)==0){
              if (S_ISDIR(st.st_mode)) {
                dirwalk(newpath);

        }

       // printf("%s\n",namelist[i]->d_name);
        //free(namelist[n]);
    }
}











}

int main(int argc, char *argv[]){
char *pathname="/Users/animohene/Desktop/3207 C Projects/Project 0";
int  pathlength=strlen(pathname);
char *path= (char *)malloc(sizeof(char)*pathlength);

strcpy(path,pathname);


printf("%s",path);

struct dirent **namelist;    // intialize struct type that will be used in scandir method to go through directories
int n; 

if (argc==1){

n=scandir(path,&namelist,NULL,alphasort); //returns number of directories/files in stream
//printf("Number Files %d\n", n); 
if (n == -1) {
     perror("scandir");
     exit(EXIT_FAILURE);
             }
for ( int i=0; i<n;i++)
    {
        printf("%s\n",namelist[i]->d_name);
        free(namelist[n]);
    }
}


else{

f (n == -1) {
     perror("scandir"); //if none perror
     exit(EXIT_FAILURE);
             }
for ( int i=0; i<n;i++)
    {
        printf("%s\n",namelist[i]->d_name); //print each direct name collected from scandir function from stream
        free(namelist[n]); // scandir function dynmaically allocates memory for an array of pointers to pointer to a struct so we must free the memory and the heap isnt like the stack and doesnt cleam up after itself
    }
}





}



    return 0;
}
//By Logan Jones, with some help from Andrew, GeeksforGeeks, StackOverflow and Wikipedia

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <libgen.h>


//c defeinitons for prototypes
void directorySearch();
void inputError();
void inputDNE();
void findFiles();



//main
int main(int argc, char **argv) { // standard two line input
  if(argc != 3) { // if its not two i cant handle the input
    inputError(); // error message
    exit(0); // exit line as input error
  }
  //If user enters current directory to search I run this method which is less work
  if( strcmp(argv[1], ".") != 0) 
  {  // checking the directories
    if( strcmp(argv[1], "..") != 0) 
    {
      inputDNE(); //error message
      exit(0); // exit line as directroy doesnt exist
    }
  }
  findFiles(argv[1], argv[2]); // if its not current directory i need to find the right one
  exit(0); // exit line as we found it
  return 0;
}

// getcwd();
//recursive search function
void directorySearch(char *path, char *keyFile) {
    int closeDirectory;
    DIR *directoryPath; // struct holding directory info
    struct dirent *openDir; // struct to hold our directory
     
    directoryPath = opendir(path); //opening the directory
    
    while(openDir = readdir(directoryPath)){ // while there are still files
      if(strstr(openDir->d_name, keyFile) != NULL) // open it and look for our file
      {
	printf("%s \n", openDir->d_name); // printing out the file name
      }
      directorySearch(openDir->d_name,keyFile); // if its not found search again passing a new directory
    }
    closeDirectory = closedir(directoryPath); // closing our directory and stores in int as it returns 0 or -1
    if(closeDirectory != 0) {
      printf("There was an Error! \n"); // error closing the directory if 0 is returned
    }
  }
  
void searchDirectory(char *path, char *keyFile){
    
    
}

void findFiles( const char* dirName, const char *keyFile) {
    DIR* dir = opendir(dirName);
    if (dir == NULL) {
        return;
    }
    struct dirent* entity;
    entity = readdir(dir);
    while (entity != NULL) {
        
            if(strstr(entity->d_name, keyFile)){
                char path[100] = { 0 };
                strcat(path, dirname(entity->d_name));
                strcat(path, "/");
                strcat(path, entity->d_name);
                printf(path);
                printf("\n");
            
            findFiles(entity->d_name,keyFile);
        }
        entity = readdir(dir);
    }
    closedir(dir);
}


//error function for input
void inputError()
{
    printf("You did not enter a two commandline argument! ");
}


//error function for not finding the Directory
void inputDNE()
{
    printf("Your Directory does not exist or cannot be opened!");
}






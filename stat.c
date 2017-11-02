#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
    
int main(){
  char * dir_name= ".";
  printf("Statistics for directory %s:\n", dir_name);

  DIR * directory = opendir(dir_name);
  if (!directory){
    printf("%s\n", strerror(errno));
  }

  struct dirent * entry;
  entry = readdir(directory);
  if(!entry){
    printf("%s\n", strerror(errno));
  }
  int size = 0;
  while(entry){
    size += entry->d_reclen;
    entry = readdir(directory);
  }
  printf("\nTotal Directory Size: %d Bytes\n", size);
  
  rewinddir(directory);
  entry = readdir(directory);
  printf("\nDirectories:\n");
  while(entry){
    if(entry->d_type == DT_DIR){
      printf("\t%s\n", entry->d_name);
    }
    entry = readdir(directory);
  }

  rewinddir(directory);
  entry = readdir(directory);
  printf("\nRegular Files:\n");
  while(entry){
    if(entry->d_type == DT_REG){
      printf("\t%s\n", entry->d_name);
    }
    entry = readdir(directory);
  }

  closedir(directory);
}

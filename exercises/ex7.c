/*
  Copyright 2020 Bella Rose
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>

// reads the contents of those files using the
// POSIX open / read / close functions, copying the contents to stdout
void ReadAndCopy(char *directory, char* file);

int main(int argc, char** argv) {
  // make sure no bogus input
  if (argc != 2) {
    printf("Invalid input. enter a directory name.\n");
    return EXIT_FAILURE;
  }

  // open the directory
  DIR *d = opendir(argv[1]);
  if (d == NULL) {
    printf("Fail to open directory.\n");
    return EXIT_FAILURE;
  }

  // scans through the directory looking for filenames that
  // end in the four characters ".txt"
  while (true) {
    struct dirent *dp = readdir(d);
    if (dp == NULL) {
      break;
    }
    int len = strlen(dp->d_name);
    int cmp = strcmp(dp->d_name + (len-4), ".txt");
    if ((len >= 4) && (cmp == 0)) {
      ReadAndCopy(argv[1], dp->d_name);
    }
  }

  closedir(d);
  return EXIT_SUCCESS;
}


void ReadAndCopy(char *directory, char* file) {
  int dirlen = strlen(directory);
  int filelen = strlen(file);
  char *path = (char*) malloc(sizeof(char) * (dirlen + filelen + 2));

  if (path == NULL) {
    printf("Failed to allocate memory.\n");
    exit(EXIT_FAILURE);
  }
  snprintf(path, dirlen + filelen + 2, "%s/%s", directory, file);

  // open the file
  int f = open(path, O_RDONLY);
  if (f == -1) {
    printf("unable to open file.\n");
    exit(EXIT_FAILURE);
  }

  char buffer[1024];
  while (true) {
    int result = read(f, buffer, 1024);

    if (result == 0) {
      break;
    } else if ((result == -1) && (errno != EINTR)) {
      printf("unable to read file.\n");
      exit(EXIT_FAILURE);
    } else {
      // check if successfully write out the content of the file
      if (fwrite(buffer, result, 1, stdout) != 1) {
        printf("failed to write to file.\n");
        exit(EXIT_FAILURE);
      }
    }
  }
  // close the file
  close(f);

  // free malloc
  free(path);
}

#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "argparse.h"

void
gst_playbin_cmd(char *argv1, char* refrence){
   /*
   argv1 is the argv[1]
   refrence is the gst playbin command
   this function concatinates the file path to the refrence provided
   */
   char cwd[PATH_MAX];
   if (getcwd(cwd, sizeof(cwd)) != NULL) {
   } else {
       perror("getcwd() error");
   }
   char dest[PATH_MAX] = "/"; 
   strcat(dest, argv1);
   strcat(cwd, dest);
   strcat(refrence, cwd);
}

void 
argparse(int argc, char *argv[]) {
	if (argc == 1) {
	
		printf("no file provided.\n");
		printf("help: kmp {protocol}:{path} (the path must be absolute.)\n");
	
		exit(1);
	}
	else {

		printf("Playing: %s\n", argv[1]);
	
	}
}

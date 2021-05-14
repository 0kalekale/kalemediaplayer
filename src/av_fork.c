#include <sys/types.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "kmp.h"

void 
fork_audio_video(int argc, char *argv[]) {

   
   pid_t pid = fork();

   if (pid < 0) { 
       fprintf(stderr, "Fork Failed");
       exit(1);
   }

   else if (pid == 0) { 
       gst_init_main(argc, argv, argv[2]);
   }

   else { 
       gst_init_main(argc, argv, argv[3]);
   }
   wait(NULL);
}

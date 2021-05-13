#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

#include "argparse.h"

void
gst_playbin_cmd(char *argv1, char* refrence){
   /*
   REMOVE ME
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
argparse(int argc, char *argv[], char* refrence) {
	gchar *uri = NULL;

	if (argc > 1) {
		if (g_strrstr (argv[1],"rtsp://") || g_strrstr (argv[1],"http://") || g_strrstr (argv[1], "https://") ||g_strrstr (argv[1],"file://"))
		{	uri = g_strdup (argv[1]);
//			printf("%s", uri);
		}
		else{
			char* path = realpath(argv[1], NULL);
			uri = g_strdup_printf ("file://%s", path);
//			printf("%s", uri);
		}
	strcat(refrence, uri);
	}
	else {
		printf("no file provided");
		exit(0);
	}
}

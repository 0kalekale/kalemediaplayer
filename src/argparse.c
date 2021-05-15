#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

#include "argparse.h"
#include "av_fork.h"

void 
argparse(int argc, char *argv[], char* refrence) {
	gchar *uri = NULL;

	if (argc > 1) {
		if (g_strrstr (argv[1],"rtsp://") || g_strrstr (argv[1],"http://") || g_strrstr (argv[1], "https://") ||g_strrstr (argv[1],"file://"))
		{	uri = g_strdup (argv[1]);
//			printf("%s", uri);
		}
		else if (g_strrstr (argv[1], "youtube") || (g_strrstr(argv[1], "yt"))) {
			fork_audio_video(argc, argv);
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

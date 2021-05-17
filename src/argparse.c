#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

#include "argparse.h"
#include "av_fork.h"
#include "youtube_dl.h"

void 
argparse(int argc, char *argv[], char* refrence) {
	gchar *uri = NULL;

	if (argc > 1) {
		if (g_strrstr (argv[1],"rtsp://") || g_strrstr (argv[1],"file://"))
		{	uri = g_strdup (argv[1]);
//			printf("%s", uri);
		}
		else if (g_strrstr (argv[1], "youtube") || (g_strrstr(argv[1], "yt"))) {
			fork_audio_video(argc, argv);
		}
  		
 		else if (g_strrstr (argv[1], "https://" )) {
			char video_url[1024] = "\0" ;
			char audio_url[1024] = "\0";
			//strcpy(argv1, argv[1]);
			struct av_url *master = get_url(argv[1]);
			//printf("\n Video URL: %s\n", master->video);
			//printf("\n Audio URL: %s\n", master->audio);
		        strcpy(video_url, master->video);
			strcpy(audio_url, master->audio);
			printf("\n Video URL: %s\n", video_url);
			printf("\n Audio URL: %s\n", audio_url);
			free(master);			
			exit(0);	
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

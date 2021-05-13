#include <gst/gst.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

#include "kmp.h"
#include "argparse.h"

int
main (int argc, char *argv[]) {

  char filename[PATH_MAX] = "\0";  
  argparse(argc, argv, filename);
  //printf("%s", filename);   
  gst_init_main (argc, argv, filename);   

  return 0;
}

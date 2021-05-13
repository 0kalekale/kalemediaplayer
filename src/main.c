#include <gst/gst.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

#include "kmp.h"
#include "argparse.h"

int
main (int argc, char *argv[]) {
  argparse(argc, argv);   
  gst_init_main (argc, argv);   

  return 0;
}

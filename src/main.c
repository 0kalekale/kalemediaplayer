/*
    kmp - kale media player 
    Copyright (C) 2021  0kalekale

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
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

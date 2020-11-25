/* Copyright (C) Altavian, Inc - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Isaac Reed <ireed@Altavian.com>, November 2020
 */

#include <glib.h>
#include <gst/gst.h>

#include "about.h"
#include "pipelineManager.h"

void PrintSystemInfo(){
  guint gst_major, gst_minor, gst_micro, gst_nano;
  gst_version(&gst_major, &gst_minor, &gst_micro, &gst_nano);
}

int main(int argc, char **argv){

  g_debug("starting");
  g_set_application_name(PIPEMAN_NAME);

  // Check argv[] for "--version" first
  for (gint i = 1; i < argc; i++){
    const gchar *arg = argv[i];
    if (arg[0] != '-'){
      continue;
    }
    if ((strcmp (arg, "--version") == 0) || (strcmp (arg, "-v") == 0)){
      PrintSystemInfo();
      return 0;
    }
  }

  PipelineManager pipeman;

  pipeman.Run();

  return 0;
}
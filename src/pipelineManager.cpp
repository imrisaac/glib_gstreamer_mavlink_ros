/* Copyright (C) Altavian, Inc - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Isaac Reed <ireed@Altavian.com>, November 2020
 */
#include <sstream>
#include <string>
#include <iostream>

#include <chrono>
#include <cmath>
#include <future>
#include <iostream>
#include <thread>

#include <gst/gst.h>
#include <gst/controller/gstinterpolationcontrolsource.h>
#include <gst/controller/gstdirectcontrolbinding.h> 

#include "pipelineManager.h"

PipelineManager::PipelineManager(){

}

// void PipelineManager::ComponentDiscoveredCB(ComponentType component_type){
//   g_message("masdk discovered component with type: %d", unsigned(component_type));
// }

// void PipelineManager::HandleMavCommandIntCB(const mavlink_message_t &message){
//   g_debug("new mav command int");
// } 

// void PipelineManager::HandleMavCommandLongCB(const mavlink_message_t &message){
//   g_debug("new mav command long");
// }

// void PipelineManager::HandleMavCommandHeartbeatCB(const mavlink_message_t &message){
//   g_debug("new mav heartbeat");
// }

// Not exactly 30Hz closer to 30.3
gboolean PipelineManager::ThirtyHzCallback(gpointer user_data){
  PipelineManager *pipelineManager = (PipelineManager*)user_data;
  return true; 
}

gboolean PipelineManager::OneHzCallback(gpointer user_data){
  PipelineManager *pipelineManager = (PipelineManager*)user_data;
  return true;
}

gboolean PipelineManager::FiveSecCallback(gpointer user_data){
  PipelineManager *pipelineManager = (PipelineManager*)user_data;
  return true;
}

gboolean PipelineManager::TenHzCallback(gpointer user_data){
  PipelineManager *pipelineManager = (PipelineManager*)user_data;
  return true;
}

gint PipelineManager::Run(){
  GMainLoop *loop;
  GstMessage *gst_msg;

  loop = g_main_loop_new(NULL, false);

  g_timeout_add(33, ThirtyHzCallback, this);
  g_timeout_add(5000, FiveSecCallback, this);
  g_timeout_add(1000, OneHzCallback, this);
  g_timeout_add(100, TenHzCallback, this);

  g_debug("main loop running");
  g_main_loop_run(loop);
  g_main_loop_unref(loop);

  return 0;
}
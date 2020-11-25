/* Copyright (C) Altavian, Inc - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Isaac Reed <ireed@Altavian.com>, November 2020
 */

#ifndef PIPELINE_MANAGER_H
#define PIPELINE_MANAGER_H

#include <glib.h>

class PipelineManager{
public:
  PipelineManager();
  int Run();
private:

  // static void ComponentDiscoveredCB(mavsdk::ComponentType component_type);
  // static void HandleMavCommandIntCB(const mavlink_message_t &message);
  // static void HandleMavCommandLongCB(const mavlink_message_t &message);
  // static void HandleMavCommandHeartbeatCB(const mavlink_message_t &message);

  static gboolean ThirtyHzCallback(gpointer user_data);
  static gboolean OneHzCallback(gpointer user_data);
  static gboolean FiveSecCallback(gpointer user_data);
  static gboolean TenHzCallback(gpointer user_data);

};

#endif // PIPELINE_MANAGER_H
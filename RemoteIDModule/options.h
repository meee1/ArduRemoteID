/*
  control optional behaviour in the firmware at build time
 */
#pragma once

#include "board_config.h"

// enable WiFi NAN support
#define AP_WIFI_NAN_ENABLED 1

// allow enabling legacy or long range only, or both
#define AP_BLE_LEGACY_ENABLED 0 // bluetooth 4 legacy
#define AP_BLE_LONGRANGE_ENABLED 0 // bluetooth 5 long range

// start sending packets as soon we we power up,
// not waiting for location data from flight controller
#define AP_BROADCAST_ON_POWER_UP 1

// do we support DroneCAN connnection to flight controller?
#define AP_DRONECAN_ENABLED 0

// do we support MAVLink connnection to flight controller?
#define AP_MAVLINK_ENABLED 1

// define the output update rate
#define OUTPUT_RATE_HZ 10 //this is the minimum update rate according to the docs. More transmissions will increase interferency to other radio modules.

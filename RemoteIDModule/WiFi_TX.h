/*
  WiFi beacon driver
 */
#pragma once

#include "transmitter.h"

class WiFi_NAN : public Transmitter {
public:
    bool init(void) override;
    bool transmit(ODID_UAS_Data &UAS_data);

private:
    char ssid[32];
    uint8_t WiFi_mac_addr[6];
    uint8_t wifi_channel = 6;
    size_t ssid_length;
    uint8_t send_counter;
};

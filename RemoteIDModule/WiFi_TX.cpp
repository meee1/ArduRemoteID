/*
  WiFi NAN driver

  with thanks to https://github.com/sxjack/uav_electronic_ids for WiFi calls
 */

#include "WiFi_TX.h"
#include <esp_wifi.h>
#include <WiFi.h>
#include <esp_system.h>

bool WiFi_NAN::init(void)
{
    //use a local MAC address to avoid tracking transponders based on their MAC address
    uint8_t mac_addr[6];
    generate_random_mac(mac_addr);

    mac_addr[0] |= 0x02;  // set MAC local bit
    mac_addr[0] &= 0xFE;  // unset MAC multicast bit

    //set MAC address
    esp_base_mac_addr_set(mac_addr);

    wifi_config_t wifi_config {};

    WiFi.softAP("");

    esp_wifi_get_config(WIFI_IF_AP, &wifi_config);

    wifi_config.ap.ssid_hidden = 1;
    wifi_config.ap.channel = wifi_channel;

    if (esp_wifi_set_config(WIFI_IF_AP, &wifi_config) != ESP_OK) {
        return false;
    }
    if (esp_wifi_set_bandwidth(WIFI_IF_AP, WIFI_BW_HT20) != ESP_OK) {
        return false;
    }
    if (esp_read_mac(WiFi_mac_addr, ESP_MAC_WIFI_STA) != ESP_OK) {
        return false;
    }

    return true;
}

bool WiFi_NAN::transmit(ODID_UAS_Data &UAS_data)
{
    uint8_t buffer[1024] {};

    Serial.write("transmit");

    int length;
/*    if ((length = odid_wifi_build_nan_sync_beacon_frame((char *)WiFi_mac_addr,
                  buffer,sizeof(buffer))) > 0) {
        if (esp_wifi_80211_tx(WIFI_IF_AP,buffer,length,true) != ESP_OK) {
            return false;
        }
    }

    if ((length = odid_wifi_build_message_pack_nan_action_frame(&UAS_data,(char *)WiFi_mac_addr,
                  ++send_counter,
                  buffer,sizeof(buffer))) > 0) {
        if (esp_wifi_80211_tx(WIFI_IF_AP,buffer,length,true) != ESP_OK) {
            return false;
        }
    }
*/
    if ((length = odid_wifi_build_message_pack_beacon_frame(&UAS_data, (char *)WiFi_mac_addr, "SSID", 4, 100, ++send_counter,  buffer,sizeof(buffer))) > 0) {
     if (esp_wifi_80211_tx(WIFI_IF_AP,buffer,length,true) != ESP_OK) {
            return false;
        }
    }
    

    return true;
}

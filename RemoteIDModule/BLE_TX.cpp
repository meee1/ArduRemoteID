/*
  BLE TX driver

  Many thanks to Roel Schiphorst from BlueMark for his assistance with the Bluetooth code

  Also many thanks to chegewara for his sample code:
  https://github.com/Tinyu-Zhao/Arduino-Borads/blob/b584d00a81e4ac6d7b72697c674ca1bbcb8aae69/libraries/BLE/examples/BLE5_multi_advertising/BLE5_multi_advertising.ino
 */

#include "BLE_TX.h"
#include "options.h"
#include <esp_system.h>

#include <BLEDevice.h>
#include <BLEAdvertising.h>

// set max power
static const int8_t tx_power = 1;//ESP_PWR_LVL_P18;

//interval min/max are configured for 1 Hz update rate. Somehow dynamic setting of these fields fails
//shorter intervals lead to more BLE transmissions. This would result in increased power consumption and can lead to more interference to other radio systems.
static esp_ble_gap_ext_adv_params_t legacy_adv_params = {
    .type = ESP_BLE_GAP_SET_EXT_ADV_PROP_LEGACY_NONCONN,
    .interval_min = 192, //(unsigned int) 0.75*1000/(OUTPUT_RATE_HZ*6)/0.625; //allow ble controller to have some room for transmission.
    .interval_max = 267, //(unsigned int) 1000/(OUTPUT_RATE_HZ*6)/0.625;
    .channel_map = ADV_CHNL_ALL,
    .own_addr_type = BLE_ADDR_TYPE_RANDOM,
    .filter_policy = ADV_FILTER_ALLOW_SCAN_ANY_CON_WLST, // we want unicast non-connectable transmission
    .tx_power = tx_power,
    .primary_phy = ESP_BLE_GAP_PHY_1M,
    .max_skip = 0,
    .secondary_phy = ESP_BLE_GAP_PHY_1M,
    .sid = 0,
    .scan_req_notif = false,
};

static esp_ble_gap_ext_adv_params_t ext_adv_params_coded = {
    .type = ESP_BLE_GAP_SET_EXT_ADV_PROP_NONCONN_NONSCANNABLE_UNDIRECTED, //set to unicast advertising
    .interval_min = 1200, //(unsigned int) 0.75*1000/(OUTPUT_RATE_HZ)/0.625; //allow ble controller to have some room for transmission.
    .interval_max = 1600, //(unsigned int) 1000/(OUTPUT_RATE_HZ)/0.625;
    .channel_map = ADV_CHNL_ALL,
    .own_addr_type = BLE_ADDR_TYPE_RANDOM,
    .filter_policy = ADV_FILTER_ALLOW_SCAN_ANY_CON_WLST, // we want unicast non-connectable transmission
    .tx_power = tx_power,
    .primary_phy = ESP_BLE_GAP_PHY_CODED,
    .max_skip = 0,
    .secondary_phy = ESP_BLE_GAP_PHY_CODED,
    .sid = 1,
    .scan_req_notif = false,
};

static esp_ble_gap_ext_adv_params_t blename_adv_params = {
    .type = ESP_BLE_GAP_SET_EXT_ADV_PROP_LEGACY_NONCONN,
    .interval_min = 1200, //(unsigned int) 0.75*1000/(OUTPUT_RATE_HZ)/0.625; //allow ble controller to have some room for transmission.
    .interval_max = 1600,//(unsigned int) 1000/(OUTPUT_RATE_HZ)/0.625;;
    .channel_map = ADV_CHNL_ALL,
    .own_addr_type = BLE_ADDR_TYPE_RANDOM,
    .filter_policy = ADV_FILTER_ALLOW_SCAN_ANY_CON_WLST, // we want unicast non-connectable transmission
    .tx_power = tx_power,
    .primary_phy = ESP_BLE_GAP_PHY_1M,
    .max_skip = 0,
    .secondary_phy = ESP_BLE_GAP_PHY_1M,
    .sid = 2,
    .scan_req_notif = false,
};


bool BLE_TX::init(void)
{
  
    return true;
}

#define IMIN(a,b) ((a)<(b)?(a):(b))

bool BLE_TX::transmit_legacy_name(ODID_UAS_Data &UAS_data)
{
   

    return true;
}

bool BLE_TX::transmit_longrange(ODID_UAS_Data &UAS_data)
{
   

    return true;
}

bool BLE_TX::transmit_legacy(ODID_UAS_Data &UAS_data)
{
   

    return true;
}

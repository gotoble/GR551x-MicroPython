#ifndef __GR_PORTING_H__
#define __GR_PORTING_H__

#include "gr55xx_sys.h"
#include "user_app.h"
#include "gr_config.h"
#include "ble.h"
#include "modubluepy.h"

#define GR_PORT_DEBUG   1

#if GR_PORT_DEBUG > 0u
    #define gr_trace   printf
#else
    #define gr_trace
#endif

typedef struct {
    bool                    is_connected;
    bool                    is_adv_started;
    bool                    is_mtu_exchanged;
    uint8_t                 cur_connect_id;
    uint8_t                 adv_data[GR_BLE_ADV_DATA_LEN_MAX];
    uint8_t                 adv_data_len;    
    uint8_t                 scan_rsp_data[GR_BLE_SCAN_RSP_DATA_LEN_MAX];
    uint8_t                 scan_rsp_data_len;    
    gap_adv_param_t         gap_adv_param;
    gap_adv_time_param_t    gap_adv_time_param;
    gap_conn_cmp_t          gap_conn_cmp_param;
    
    bool                    is_need_sec_cfm;
    sec_cfm_enc_t           sec_cfm;
}gr_ble_gap_params_t;

typedef struct {
    bool                    is_gatt_initialized;
}gr_ble_gatt_params_t;

typedef struct {
    bool                    is_ble_initialized;         //ble stack inited ?
    gap_bdaddr_t            local_bd_addr;
}gr_ble_common_params_t;

typedef struct{
    uint16_t    cur_start_srv_index;
    uint16_t    register_srv_num;
    uint16_t    register_srv_handle[GR_BLE_MAX_SERVICES];
    uint16_t    start_handle;
}gr_srv_env_t;




typedef struct
{
    ubluepy_uuid_type_t         uuid_type;
    union
    {
        attm_desc_t             attm;
        attm_desc_128_t         attm128;
    } properties;
    uint16_t                    service_handle;     //save service handle
    uint16_t                    parent_handle;      //save parent handle
    uint16_t                    handle;             //save my onw handle, service handle's parent is 0, if service_handle == handle, it's service entity    
    ubluepy_attr_type_t         type;
    
    ubluepy_prop_t              raw_properties;
    ubluepy_permission_t        raw_permissions;
} BTGattEntity_t;

typedef struct{
    bool                isUsed;             //record this posit
    uint16_t            mServiceHandle;     //service handlle
    uint16_t            mGattNum;           //number of attribute
    ubluepy_uuid_type_t mUuidType;          //just support 16b & 128b
    void *              pAttTable;          //pointer to att table, real type is attm_desc_t * or attm_desc_128_t *    
}BTGattServiceList_t;



extern gr_ble_common_params_t       s_gr_ble_common_params_ins;
extern gr_ble_gap_params_t          s_gr_ble_gap_params_ins;
extern gr_ble_gatt_params_t         s_gr_ble_gatt_params_ins;
extern gr_srv_env_t                 s_gattsp_instance;



void        gr_ble_stack_init(void);
void        gr_gatt_service_reset(void);
char *      gr_ble_format_uuid128b_to_string(uint8_t * uuid128b, uint8_t len);
uint16_t    gr_ble_get_mpy_handle(void);
bool        gr_gatt_service_register(uint16_t service_handle);



void                    prvBTGattServiceListInit(void);
bool                    prvBTGattServiceListPut(const BTGattServiceList_t srv);
BTGattServiceList_t *   prvBTGattServiceListGet(uint16_t serviceHandle);
BTGattServiceList_t *   prvBTGattServiceListGetHead(void);
void                    prvBTGattServiceListDelete(uint16_t serviceHandle);




/*
 * transfer porting layer handle to gatt handle in ble stack
 * JUST Be called when connected
 */
uint16_t gr_gatt_transto_ble_stack_handle(uint16_t porting_handle);

/*
 * transfer gatt handle in ble stack to porting layer handle
 * JUST Be called when connected
 */
uint16_t gr_gatt_transto_porting_layer_handle(uint16_t stack_handle);


/*************************************************************************
 * mm Functions bases on py/gc for porting layer, etc.
 *************************************************************************/
 
void *      gr_malloc(size_t size);
void        gr_free(void *ptr);
void *      gr_calloc(size_t nmemb, size_t size);
void *      gr_realloc(void *ptr, size_t size);


#endif /*__GR_PORTING_H__*/

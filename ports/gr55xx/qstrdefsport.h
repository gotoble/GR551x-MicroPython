// qstrs specific to this port
//board.LED module
Q(LED)
Q(on)
Q(off)
Q(toggle)
Q(gr5515_sk)
Q(repl_info)

//board.Flash module
Q(Flash)
Q(readblocks)
Q(writeblocks)
Q(ioctl)
Q(_slash_flash)
Q(_slash_flash_slash_lib)

//utime module
Q(utime)
Q(sleep_ms)
Q(sleep_us)

//uos module
Q(uos)
Q(sysname)
Q(nodename)
Q(release)
Q(version)
Q(machine)
Q(uname)
Q(chdir)
Q(getcwd)
Q(listdir)
Q(mkdir)
Q(remove)
Q(rename)
Q(rmdir)
Q(stat)
Q(statvfs)
Q(unlink)
Q(sync)
Q(mount)
Q(umount)
Q(VfsFat)

//ble module
Q(ble)
Q(enable)
Q(disable)
Q(enabled)
Q(address)
Q(startadv)
Q(stopadv)

/*********************************** ubluepy module *********************************/
Q(ubluepy)

//UUID class
Q(UUID)
Q(binVal)

//Constants class
Q(Constants)
Q(EVT_GAP_CONNECTED)
Q(EVT_GAP_DISCONNECTED)
Q(EVT_GATTS_WRITE)
Q(UUID_CCCD)
Q(UNASSIGNED_HANDLE)
Q(INVALID_HANDLE)
Q(ADDR_TYPE_PUBLIC)
Q(ADDR_TYPE_RANDOM_STATIC)
//Constants.AdTypes
Q(AdTypes)
Q(AD_TYPE_FLAGS)
Q(AD_TYPE_16BIT_SERVICE_UUID_MORE_AVAILABLE)
Q(AD_TYPE_16BIT_SERVICE_UUID_COMPLETE)
Q(AD_TYPE_32BIT_SERVICE_UUID_MORE_AVAILABLE)
Q(AD_TYPE_32BIT_SERVICE_UUID_COMPLETE)
Q(AD_TYPE_128BIT_SERVICE_UUID_MORE_AVAILABLE)
Q(AD_TYPE_128BIT_SERVICE_UUID_COMPLETE)
Q(AD_TYPE_SHORT_LOCAL_NAME)
Q(AD_TYPE_COMPLETE_LOCAL_NAME)
Q(AD_TYPE_TX_POWER_LEVEL)
Q(AD_TYPE_CLASS_OF_DEVICE)
Q(AD_TYPE_SIMPLE_PAIRING_HASH_C)
Q(AD_TYPE_SIMPLE_PAIRING_RANDOMIZER_R)
Q(AD_TYPE_SECURITY_MANAGER_TK_VALUE)
Q(AD_TYPE_SECURITY_MANAGER_OOB_FLAGS)
Q(AD_TYPE_SLAVE_CONNECTION_INTERVAL_RANGE)
Q(AD_TYPE_SOLICITED_SERVICE_UUIDS_16BIT)
Q(AD_TYPE_SOLICITED_SERVICE_UUIDS_128BIT)
Q(AD_TYPE_SERVICE_DATA)
Q(AD_TYPE_PUBLIC_TARGET_ADDRESS)
Q(AD_TYPE_RANDOM_TARGET_ADDRESS)
Q(AD_TYPE_APPEARANCE)
Q(AD_TYPE_ADVERTISING_INTERVAL)
Q(AD_TYPE_LE_BLUETOOTH_DEVICE_ADDRESS)
Q(AD_TYPE_LE_ROLE)
Q(AD_TYPE_SIMPLE_PAIRING_HASH_C256)
Q(AD_TYPE_SIMPLE_PAIRING_RANDOMIZER_R256)
Q(AD_TYPE_SERVICE_DATA_32BIT_UUID)
Q(AD_TYPE_SERVICE_DATA_128BIT_UUID)
Q(AD_TYPE_URI)
Q(AD_TYPE_3D_INFORMATION_DATA)
Q(AD_TYPE_MANUFACTURER_SPECIFIC_DATA)
//Constants.CharacProp
Q(CharacProp)
Q(PROP_NONE)
Q(PROP_BROADCAST)
Q(PROP_READ)
Q(PROP_WRITE_WO_RESP)
Q(PROP_WRITE)
Q(PROP_NOTIFY)
Q(PROP_INDICATE)
Q(PROP_AUTH_SIGNED_WR)
Q(PROP_EXTENDED_PROP)
//Constants.AttrPerm
Q(AttrPerm)
Q(PERM_NONE)
Q(PERM_READ)
Q(PERM_READ_ENCRYPTED)
Q(PERM_READ_ENCRYPTED_MITM)
Q(PERM_WRITE)
Q(PERM_WRITE_ENCRYPTED)
Q(PERM_WRITE_ENCRYPTED_MITM)
Q(PERM_WRITE_SIGNED)
Q(PERM_WRITE_SIGNED_MITM)
//Constants.Ccd
Q(Ccd)
Q(ATTR_CCCD)
Q(ATTR_SCCD)

//delegate class
Q(DefaultDelegate)
Q(handleConnection)
Q(handleNotification)
Q(handleDiscovery)

//Descriptor
Q(Descriptor)

//Characteristic
Q(Characteristic)
Q(uuid)
Q(props)
Q(attrs)
Q(perms)
Q(with_response)
Q(read)
Q(write)
Q(supportsRead)
Q(propertiesToString)
Q(getHandle)
Q(peripheral)
Q(uuid)
Q(properties)
Q(getDescriptor)
Q(getDescriptors)
Q(addDescriptor)
Q(removeDescriptor)


//Service 
Q(Service)
Q(uuid)
Q(desc)
Q(addCharacteristic)
Q(getCharacteristic)
Q(getCharacteristics)
Q(removeCharacteristic)
Q(peripheral)
Q(PRIMARY)
Q(SECONDARY)

//Peripheral
Q(Peripheral)
Q(device_name)
Q(services)
Q(data)
Q(connectable)
Q(addr_type)
Q(withDelegate)
Q(setNotificationHandler)
Q(setConnectionHandler)
Q(getServices)
Q(addService)
Q(removeService)
Q(startServices)
Q(connect)
Q(disconnect)
Q(getServiceByUUID)
Q(getCharacteristics)
Q(getDescriptors)
Q(waitForNotifications)
Q(advertise_stop)
Q(addCharacteristic)
Q(addDescriptor)
Q(writeCharacteristic)
Q(readCharacteristic)
Q(startAdvertise)
Q(stopAdvertise)

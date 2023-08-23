#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pci.h>


#define _KMOD_ID "KMOD_PCI_CONFIG_SPACE"

/*
 * We will try to register our driver for an existing pci device
 * the following device and vendor ids belong to an VmWare NVMe device
 * but that is irrelevant to us, as we will just unbind its driver and let our driver take control
 */
#define _PCI_DEVICE_VENDOR_ID 0x15AD
#define _PCI_DEVICE_ID        0x07F0


// Function handlers for device probe and remove kernel callbacks
static int deviceProbe ( struct pci_dev *pstiPciDevice, const struct pci_device_id *pstiPciDeviceId);
static void deviceRemove ( struct pci_dev *pstiDevice );

// pci device identifier structure
static struct pci_device_id stiPciDeviceIds[] = {
  { PCI_DEVICE(_PCI_DEVICE_VENDOR_ID, _PCI_DEVICE_ID) },
  { }
};

MODULE_DEVICE_TABLE(pci, stiPciDeviceIds);

// pci device kernel callback functions handler structure
static struct pci_driver stiPciDriver = {
  .name = _KMOD_ID,
  .id_table = stiPciDeviceIds,
  .probe = deviceProbe,
  .remove = deviceRemove,
};


/*
 * @Func: Parse pci device config space and print in kernel logs
 * @Param: The binded pci device structure
 * @Return: (Boolean) Success if pci config space parsed successfully
 */
static bool printPciConfigSpace ( struct pci_dev* pstiPciDevice ) {
  u16 ui16DeviceId, ui16VendorId;
  u8 ui8CapPointer;
  u32 ui32Bar0, ui32BkpBar0;

  if ( pci_read_config_word(pstiPciDevice, 0x00, &ui16VendorId) != 0 )
    goto ERREXIT;

  pr_info("PCI_CONFIG_SPACE: [ VENDOR_ID: 0x%02X ]", ui16VendorId);

  if ( pci_read_config_word(pstiPciDevice, 0x02, &ui16DeviceId) != 0 )
    goto ERREXIT;

  pr_info("PCI_CONFIG_SPACE: [ DEVICE_ID: 0x%02X ]", ui16DeviceId);

  if ( pci_read_config_byte(pstiPciDevice, 0x34, &ui8CapPointer) != 0 )
    goto ERREXIT;

  pr_info("PCI_CONFIG_SPACE: [ CAPABILITY_POINTER: 0x%02X ]", ui8CapPointer);

  if ( ui8CapPointer )
    pr_info("PCI_CONFIG_SPACE: PCI device has capabilities");
  else
    pr_info("PCI_CONFIG_SPACE: PCI device doesn't has capabilities");

  if ( pci_read_config_dword(pstiPciDevice, 0x10, &ui32Bar0) != 0 )
    goto ERREXIT;

  pr_info("PCI_CONFIG_SPACE: [ BAR0: 0x%04X ]", ui32Bar0);

  ui32BkpBar0 = ui32Bar0;

  if ( ui32Bar0 & (1 << 0) )
    pr_info("PCI_CONFIG_SPACE: [ BAR0_TYPE: IO_SPACE ]");
  else
    pr_info("PCI_CONFIG_SPACE: [ BAR0_TYPE: MEMORY_SPACE ]");

  if ( pci_write_config_dword(pstiPciDevice, 0x10, 0xFFFFFFFF) != 0)
    goto ERREXIT;

  if ( pci_read_config_dword(pstiPciDevice, 0x10, &ui32Bar0) != 0 )
    goto ERREXIT;

  pr_info("PCI_CONFIG_SPACE: [ BAR0_SIZE: %d ]", (~ui32Bar0 & 0xFFFFFFFF) + 1);

  if ( pci_write_config_dword(pstiPciDevice, 0x10, ui32BkpBar0) != 0)
    goto ERREXIT;

  EXIT:
    pr_info("Successfully parsed the PCI device configuration space");
    return true;

  ERREXIT:
    pr_err("Failed to parse the PCI device configuration space");
    return false;
}


/*
 * @Func: Kernel callback handler for device probe
 * @Param: (1) The binded pci device structure
 *         (2) The pci device identifier structure
 * @Return: (Integer) On success: 0, On failure: -1
 */
static int deviceProbe ( struct pci_dev* pstiPciDevice, const struct pci_device_id* pstiPciDeviceId) {
  pr_info("Received kernel callback (%s) to execute function handler for pci device probe [ VENDOR: %d | DEVICE: %d ]", __func__, pstiPciDeviceId->vendor, pstiPciDeviceId->device);
  
  if ( ! printPciConfigSpace(pstiPciDevice) )
    goto ERREXIT;

  EXIT:
    return 0;

  ERREXIT:
    return -1;
}


/*
 * @Func: Kernel callback handler for device remove
 * @Param: The binded pci device structure
 * @Return: (Void) None
 */
static void deviceRemove ( struct pci_dev *pstiDevice ) {
  pr_info("Received kernel callback (%s) to execute function handler for PCI device remove", __func__);

  return;
}


/*
 * @Func: Kernel module init function
 * @Param: None
 * @Return: (Integer) On success: 0, On failure: -1
 */
static int pciModuleInit ( void ) {
  pr_info("Initializing kernel module %s and registering the module with the PCI subsystem", _KMOD_ID);

  pr_info("Registering %s driver with PCI subsystem", _KMOD_ID);
  return pci_register_driver(&stiPciDriver);
}


/*
 * @Func: Kernel module exit function
 * @Param: None
 * @Return: (Integer) On success: 0, On failure: -1
 */
static void pciModuleExit ( void ) {
  pr_info("Exiting kernel module %s and unregistering the module from the PCI subsystem", _KMOD_ID);
  pci_unregister_driver(&stiPciDriver);
}


// Some usual kmod defs
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rishabh Soni");
MODULE_DESCRIPTION("Kmod to access and parse PCI device configuration space");
MODULE_VERSION("1.1");

// Register kmod init and exit functions
module_init(pciModuleInit);
module_exit(pciModuleExit);


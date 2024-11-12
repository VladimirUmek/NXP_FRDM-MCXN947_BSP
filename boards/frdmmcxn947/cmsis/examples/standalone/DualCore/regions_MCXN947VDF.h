#ifndef REGIONS_MCXN947VDF_H
#define REGIONS_MCXN947VDF_H

//-------- <<< Use Configuration Wizard in Context Menu >>> --------------------
//------ With VS Code: Open Preview for Configuration Wizard -------------------

// <i> Device Family Pack (DFP):   NXP::MCXN947_DFP@19.0.0
// <i> Board Support Pack (BSP):   NXP::FRDM-MCXN947_BSP@19.1.0-dev19

#ifdef CPU_MCXN947VDF_cm33_core0
// <h> ROM Configuration
// =======================
// <h> __ROM0 (is rx memory: PROGRAM_FLASH0+PROGRAM_FLASH1 from DFP)
//   <o> Base address <0x0-0xFFFFFFFF:8>
//   <i> Defines base address of memory region. Default: 0x00000000
//   <i> Contains Startup and Vector Table
#define __ROM0_BASE 0x00000000
//   <o> Region size [bytes] <0x0-0xFFFFFFFF:8>
//   <i> Defines size of memory region. Default: 0x00200000
#define __ROM0_SIZE 0x00100000
// </h>

// </h>

// <h> RAM Configuration
// =======================
// <h> __RAM0 (is rw memory: SRAM+SRAMH from DFP)
//   <o> Base address <0x0-0xFFFFFFFF:8>
//   <i> Defines base address of memory region. Default: 0x20000000
//   <i> Contains uninitialized RAM, Stack, and Heap
#define __RAM0_BASE 0x20000000
//   <o> Region size [bytes] <0x0-0xFFFFFFFF:8>
//   <i> Defines size of memory region. Default: 0x00068000
#define __RAM0_SIZE 0x00030000
// </h>

// </h>

// <h> Stack / Heap Configuration
//   <o0> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
//   <o1> Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
#define __STACK_SIZE 0x00000400
#define __HEAP_SIZE 0x00010000
// </h>

// <n> Resources that are not allocated to linker regions
// <i> rx ROM:   BootROM from DFP:               BASE: 0x03000000  SIZE: 0x040000
// <i> rx ROM:   BootROM_alias from DFP:         BASE: 0x13000000  SIZE: 0x040000
// <i> rx ROM:   PROGRAM_FLASH_alias0 from DFP:  BASE: 0x10000000  SIZE: 0x100000
// <i> rx ROM:   PROGRAM_FLASH_alias1 from DFP:  BASE: 0x10100000  SIZE: 0x100000
// <i> rw RAM:   SRAMH_alias from DFP:           BASE: 0x30060000  SIZE: 0x8000
// <i> rw RAM:   SRAMX_alias from DFP:           BASE: 0x14000000  SIZE: 0x018000
// <i> rw RAM:   SRAM_alias from DFP:            BASE: 0x30000000  SIZE: 0x060000
// <i> rw RAM:   USB_RAM_alias from DFP:         BASE: 0x500ba000  SIZE: 0x1000
#endif

#ifdef CPU_MCXN947VDF_cm33_core1
// <h> ROM Configuration
// =======================
// <h> __ROM0 (is rx memory: PROGRAM_FLASH0+PROGRAM_FLASH1 from DFP)
//   <o> Base address <0x0-0xFFFFFFFF:8>
//   <i> Defines base address of memory region. Default: 0x00000000
//   <i> Contains Startup and Vector Table
#define __ROM0_BASE 0x00100000
//   <o> Region size [bytes] <0x0-0xFFFFFFFF:8>
//   <i> Defines size of memory region. Default: 0x00200000
#define __ROM0_SIZE 0x00100000
// </h>

// </h>

// <h> RAM Configuration
// =======================
// <h> __RAM0 (is rw memory: SRAM+SRAMH from DFP)
//   <o> Base address <0x0-0xFFFFFFFF:8>
//   <i> Defines base address of memory region. Default: 0x20000000
//   <i> Contains uninitialized RAM, Stack, and Heap
#define __RAM0_BASE 0x20030000
//   <o> Region size [bytes] <0x0-0xFFFFFFFF:8>
//   <i> Defines size of memory region. Default: 0x00068000
#define __RAM0_SIZE 0x00020000
// </h>

// </h>

// <h> Stack / Heap Configuration
//   <o0> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
//   <o1> Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
#define __STACK_SIZE 0x00000200
#define __HEAP_SIZE 0x00000C00
// </h>

// <n> Resources that are not allocated to linker regions
// <i> rx ROM:   BootROM from DFP:               BASE: 0x03000000  SIZE: 0x040000
// <i> rx ROM:   BootROM_alias from DFP:         BASE: 0x13000000  SIZE: 0x040000
// <i> rx ROM:   PROGRAM_FLASH_alias0 from DFP:  BASE: 0x10000000  SIZE: 0x100000
// <i> rx ROM:   PROGRAM_FLASH_alias1 from DFP:  BASE: 0x10100000  SIZE: 0x100000
// <i> rw RAM:   SRAMH_alias from DFP:           BASE: 0x30060000  SIZE: 0x8000
// <i> rw RAM:   SRAMX_alias from DFP:           BASE: 0x14000000  SIZE: 0x018000
// <i> rw RAM:   SRAM_alias from DFP:            BASE: 0x30000000  SIZE: 0x060000
// <i> rw RAM:   USB_RAM_alias from DFP:         BASE: 0x500ba000  SIZE: 0x1000
#endif

#endif /* REGIONS_MCXN947VDF_H */

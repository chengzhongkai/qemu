/*
 * Freescale i.MX31 SoC emulation
 *
 * Copyright (C) 2015 Jean-Christophe Dubois <jcd@tribudubois.net>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 */

#ifndef FSL_IMX31_H
#define FSL_IMX31_H

#include "hw/arm/arm.h"
#include "hw/intc/imx_avic.h"
#include "hw/misc/imx_ccm.h"
#include "hw/char/imx_serial.h"
#include "hw/timer/imx_gpt.h"
#include "hw/timer/imx_epit.h"
#include "exec/memory.h"

#define TYPE_FSL_IMX31 "fsl,imx31"
#define FSL_IMX31(obj) OBJECT_CHECK(FslIMX31State, (obj), TYPE_FSL_IMX31)

#define FSL_IMX31_NUM_UARTS 2
#define FSL_IMX31_NUM_EPITS 2

typedef struct FslIMX31State {
    /*< private >*/
    DeviceState parent_obj;

    /*< public >*/
    ARMCPU         cpu;
    IMXAVICState   avic;
    IMXCCMState    ccm;
    IMXSerialState uart[FSL_IMX31_NUM_UARTS];
    IMXGPTState    gpt;
    IMXEPITState   epit[FSL_IMX31_NUM_EPITS];
    MemoryRegion   secure_rom;
    MemoryRegion   rom;
    MemoryRegion   iram;
    MemoryRegion   iram_alias;
} FslIMX31State;

#define FSL_IMX31_SECURE_ROM_ADDR       0x00000000
#define FSL_IMX31_SECURE_ROM_SIZE       0x4000
#define FSL_IMX31_ROM_ADDR              0x00404000
#define FSL_IMX31_ROM_SIZE              0x4000
#define FSL_IMX31_IRAM_ALIAS_ADDR       0x10000000
#define FSL_IMX31_IRAM_ALIAS_SIZE       0xFFC0000
#define FSL_IMX31_IRAM_ADDR             0x1FFFC000
#define FSL_IMX31_IRAM_SIZE             0x4000
#define FSL_IMX31_UART1_ADDR            0x43F90000
#define FSL_IMX31_UART1_SIZE            0x4000
#define FSL_IMX31_UART2_ADDR            0x43F94000
#define FSL_IMX31_UART2_SIZE            0x4000
#define FSL_IMX31_CCM_ADDR              0x53F80000
#define FSL_IMX31_CCM_SIZE              0x4000
#define FSL_IMX31_GPT_ADDR              0x53F90000
#define FSL_IMX31_GPT_SIZE              0x4000
#define FSL_IMX31_EPIT1_ADDR            0x53F94000
#define FSL_IMX31_EPIT1_SIZE            0x4000
#define FSL_IMX31_EPIT2_ADDR            0x53F98000
#define FSL_IMX31_EPIT2_SIZE            0x4000
#define FSL_IMX31_AVIC_ADDR             0x68000000
#define FSL_IMX31_AVIC_SIZE             0x100
#define FSL_IMX31_SDRAM0_ADDR           0x80000000
#define FSL_IMX31_SDRAM0_SIZE           0x10000000
#define FSL_IMX31_SDRAM1_ADDR           0x90000000
#define FSL_IMX31_SDRAM1_SIZE           0x10000000
#define FSL_IMX31_FLASH0_ADDR           0xA0000000
#define FSL_IMX31_FLASH0_SIZE           0x8000000
#define FSL_IMX31_FLASH1_ADDR           0xA8000000
#define FSL_IMX31_FLASH1_SIZE           0x8000000
#define FSL_IMX31_CS2_ADDR              0xB0000000
#define FSL_IMX31_CS2_SIZE              0x2000000
#define FSL_IMX31_CS3_ADDR              0xB2000000
#define FSL_IMX31_CS3_SIZE              0x2000000
#define FSL_IMX31_CS4_ADDR              0xB4000000
#define FSL_IMX31_CS4_SIZE              0x2000000
#define FSL_IMX31_CS5_ADDR              0xB6000000
#define FSL_IMX31_CS5_SIZE              0x2000000
#define FSL_IMX31_NAND_ADDR             0xB8000000
#define FSL_IMX31_NAND_SIZE             0x1000

#define FSL_IMX31_EPIT2_IRQ             27
#define FSL_IMX31_EPIT1_IRQ             28
#define FSL_IMX31_GPT_IRQ               29
#define FSL_IMX31_UART2_IRQ             32
#define FSL_IMX31_UART1_IRQ             45

#endif /* FSL_IMX31_H */
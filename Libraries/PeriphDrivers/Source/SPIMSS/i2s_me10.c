/******************************************************************************
 * Copyright (C) 2023 Maxim Integrated Products, Inc., All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL MAXIM INTEGRATED BE LIABLE FOR ANY CLAIM, DAMAGES
 * OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Except as contained in this notice, the name of Maxim Integrated
 * Products, Inc. shall not be used except as stated in the Maxim Integrated
 * Products, Inc. Branding Policy.
 *
 * The mere transfer of this software does not imply any licenses
 * of trade secrets, proprietary technology, copyrights, patents,
 * trademarks, maskwork rights, or any other form of intellectual
 * property whatsoever. Maxim Integrated Products, Inc. retains all
 * ownership rights.
 *
 ******************************************************************************/

#include <stddef.h>
#include <stdint.h>
#include "mxc_errors.h"
#include "mxc_assert.h"
#include "mxc_lock.h"
#include "mxc_sys.h"
#include "mxc_pins.h"
#include "gpio.h"
#include "dma.h"
#include "i2s.h"
#include "i2s_reva.h"

int dma_channel = -1;
mxc_i2s_direction_t dir;

/* ************************************************************************* */
int MXC_I2S_Init(const mxc_i2s_config_t *cfg, void (*dma_ctz_cb)(int, int))
{
    MXC_SYS_ClockEnable(MXC_SYS_PERIPH_CLOCK_I2S);
    MXC_GPIO_Config(&gpio_cfg_i2s);

    return MXC_I2S_RevA_Init((mxc_spimss_reva_regs_t *)MXC_SPIMSS, cfg, dma_ctz_cb);
}

/* ************************************************************************* */
int MXC_I2S_Shutdown(void)
{
    MXC_SYS_ClockDisable(MXC_SYS_PERIPH_CLOCK_I2S);
    return MXC_I2S_RevA_Shutdown((mxc_spimss_reva_regs_t *)MXC_SPIMSS);
}

/* ************************************************************************* */
int MXC_I2S_Mute(void)
{
    return MXC_I2S_RevA_Mute((mxc_spimss_reva_regs_t *)MXC_SPIMSS);
}

/* ************************************************************************* */
int MXC_I2S_Unmute(void)
{
    return MXC_I2S_RevA_Unmute((mxc_spimss_reva_regs_t *)MXC_SPIMSS);
}

/* ************************************************************************* */
int MXC_I2S_Pause(void)
{
    return MXC_I2S_RevA_Pause((mxc_spimss_reva_regs_t *)MXC_SPIMSS);
}

/* ************************************************************************* */
int MXC_I2S_Unpause(void)
{
    return MXC_I2S_RevA_Unpause((mxc_spimss_reva_regs_t *)MXC_SPIMSS);
}

/* ************************************************************************* */
int MXC_I2S_Stop(void)
{
    return MXC_I2S_RevA_Stop((mxc_spimss_reva_regs_t *)MXC_SPIMSS);
}

/* ************************************************************************* */
int MXC_I2S_Start(void)
{
    return MXC_I2S_RevA_Start((mxc_spimss_reva_regs_t *)MXC_SPIMSS);
}

/* ************************************************************************* */
int MXC_I2S_DMA_ClearFlags(void)
{
    return MXC_I2S_RevA_DMA_ClearFlags();
}

/* ************************************************************************* */
int MXC_I2S_DMA_SetAddrCnt(void *src_addr, void *dst_addr, unsigned int count)
{
    return MXC_I2S_RevA_DMA_SetAddrCnt(src_addr, dst_addr, count);
}

/* ************************************************************************* */
int MXC_I2S_DMA_SetReload(void *src_addr, void *dst_addr, unsigned int count)
{
    return MXC_I2S_RevA_DMA_SetReload(src_addr, dst_addr, count);
}

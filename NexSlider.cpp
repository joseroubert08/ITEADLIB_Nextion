/**
 * @file NexSlider.cpp
 *
 * API of NexSlider. 
 *
 * @author  Wu Pengfei (email:<pengfei.wu@itead.cc>)
 * @date    2015/8/11
 * @copyright 
 * Copyright (C) 2014-2015 ITEAD Intelligent Systems Co., Ltd. \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */

#include "NexSlider.h"

/**
 * Constructor,inherited NexTouch's constructor function.
 *
 */
NexSlider::NexSlider(NexPid pid, NexCid cid, char *name, 
    NexTouchEventCb pop, void *pop_ptr)
    :NexTouch(pid, cid, name, pop, pop_ptr)
{
}

/**
 * Get the value of slider. 
 * 
 * @param number - an output parameter to save the value of slider.  
 * 
 * @retval true - success. 
 * @retval false - failed. 
 */
bool NexSlider::getValue(uint32_t *number)
{
    String cmd = String("get ");
    cmd += getObjName();
    cmd += ".val";
    sendCommand(cmd.c_str());
    return recvRetNumber(number);
}

/**
 * Set the value of slider.
 *
 * @param number - the value of slider.  
 *
 * @retval true - success. 
 * @retval false - failed. 
 */
bool NexSlider::setValue(uint32_t number)
{
    char buf[10] = {0};
    String cmd;
    
    utoa(number, buf, 10);
    cmd += getObjName();
    cmd += ".val=";
    cmd += buf;

    sendCommand(cmd.c_str());
    return recvRetCommandFinished();
}

/**
 * Register slider pop callback function. 
 *
 * @param pop - the pointer to picture pop callback function.
 * @param ptr - the parameter to be transmitted to picture pop callback function. 
 */
void NexSlider::attachPop(NexTouchEventCb pop, void *ptr)
{
    NexTouch::attachPop(pop, ptr);
}

/**
 * Unload slider pop callback function.
 *
 */
void NexSlider::detachPop(void)
{
    NexTouch::detachPop();   
}
 
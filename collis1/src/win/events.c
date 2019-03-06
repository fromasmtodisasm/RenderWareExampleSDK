/****************************************************************************
 *
 * This file is a product of Criterion Software Ltd.
 *
 * This file is provided as is with no warranties of any kind and is
 * provided without any obligation on Criterion Software Ltd.
 * or Canon Inc. to assist in its use or modification.
 *
 * Criterion Software Ltd. and Canon Inc. will not, under any
 * circumstances, be liable for any lost revenue or other damages
 * arising from the use of this file.
 *
 * Copyright (c) 2001 Criterion Software Ltd.
 * All Rights Reserved.
 *
 */

/****************************************************************************
 *
 * events.c
 *
 * Copyright (C) 2000 Criterion Software Ltd
 *
 * Author: RenderWare Team
 *
 * Purpose: Illustrates simple collision detection between an RpWorld and
 *          a line or sphere.
 ****************************************************************************/

#include "rwcore.h"

#include "skeleton.h"
#include "menu.h"

#include "collis1.h"

static RwBool Orientate = FALSE;



/*
 *****************************************************************************
 */
static RsEventStatus
HandleLeftButtonDown(RsMouseStatus *mouseStatus __RWUNUSED__)
{
    Orientate = TRUE;

    return rsEVENTPROCESSED;
}


static RsEventStatus
HandleLeftButtonUp(RsMouseStatus *mouseStatus  __RWUNUSED__)
{
    Orientate = FALSE;     

    return rsEVENTPROCESSED;
}


/*
 *****************************************************************************
 */
static RsEventStatus
HandleRightButtonDown(RsMouseStatus *mouseStatus)
{
    switch( CurrentMovementMode )
    {
        case FORWARDS:
        case BACKWARDS:
        {
            CurrentMovementMode = STOPPED;

            break;
        }

        case STOPPED:
        {
            if( !mouseStatus->control )
            {
                CurrentMovementMode = FORWARDS;
            }
            else
            {
                CurrentMovementMode = BACKWARDS;
            }  
            
            break;
        }

        default:
        {
            CurrentMovementMode = STOPPED;

            break;
        }
    }

    return rsEVENTPROCESSED;
}


/*
 *****************************************************************************
 */
static RsEventStatus
HandleRightButtonUp(RsMouseStatus *mouseStatus __RWUNUSED__)
{
    return rsEVENTNOTPROCESSED;
}


/*
 *****************************************************************************
 */
static RsEventStatus 
HandleMouseMove(RsMouseStatus *mouseStatus)
{
    if( Orientate ) 
    {
        CameraPoint(Camera, 
            -mouseStatus->delta.x * 0.05f, mouseStatus->delta.y * 0.05f);
    }

    return rsEVENTPROCESSED;
}


/*
 *****************************************************************************
 */
static RsEventStatus 
MouseHandler(RsEvent event, void *param)
{
    /*
     * Let the menu system have a look-in first...
     */
    if( MenuMouseHandler(event, param) == rsEVENTPROCESSED )
    {
        return rsEVENTPROCESSED;
    }

    /*
     * ...then the application events, if necessary...
     */
    switch( event )
    {
        case rsLEFTBUTTONDOWN:
        {
            return HandleLeftButtonDown((RsMouseStatus *)param);
        }

        case rsLEFTBUTTONUP:
        {
            return HandleLeftButtonUp((RsMouseStatus *)param);
        }

        case rsRIGHTBUTTONDOWN:
        {
            return HandleRightButtonDown((RsMouseStatus *)param);
        }

        case rsRIGHTBUTTONUP:
        {
            return HandleRightButtonUp((RsMouseStatus *)param);
        }

        case rsMOUSEMOVE:
        {
            return HandleMouseMove((RsMouseStatus *)param);
        }

        default:
        {
            return rsEVENTNOTPROCESSED;
        }
    }
}


/*
 *****************************************************************************
 */
static RsEventStatus 
HandleKeyDown(RsKeyStatus *keyStatus __RWUNUSED__)
{
    return rsEVENTNOTPROCESSED;
}


static RsEventStatus 
HandleKeyUp(RsKeyStatus *keyStatus  __RWUNUSED__)
{
    return rsEVENTNOTPROCESSED;
}


/*
 *****************************************************************************
 */
static RsEventStatus 
KeyboardHandler(RsEvent event, void *param)
{
    /*
     * Let the menu system have a look-in first...
     */
    if( MenuKeyboardHandler(event, param) == rsEVENTPROCESSED )
    {
        return rsEVENTPROCESSED;
    }

    /*
     * ...then the application events, if necessary...
     */
    switch( event )
    {
        case rsKEYDOWN:
        {
            return HandleKeyDown((RsKeyStatus *)param);
        }

        case rsKEYUP:
        {
            return HandleKeyUp((RsKeyStatus *)param);
        }

        default:
        {
            return rsEVENTNOTPROCESSED;
        }
    }
}


/*
 *****************************************************************************
 */
RwBool
AttachInputDevices(void)
{
    RsInputDeviceAttach(rsKEYBOARD, KeyboardHandler);

    RsInputDeviceAttach(rsMOUSE, MouseHandler);

    return TRUE;
}

/*
 *****************************************************************************
 */

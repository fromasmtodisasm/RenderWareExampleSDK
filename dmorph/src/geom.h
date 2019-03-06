
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
 * geom.h
 *
 * Copyright (C) 2000 Criterion Software Ltd
 *
 * Author: RenderWare Team
 *
 * Purpose: To demonstrate the DMorph plugin
 ****************************************************************************/

#ifndef GEOM_H
#define GEOM_H




#ifdef __cplusplus
extern "C"
{
#endif  /* __cplusplus */


RpGeometry * CreateSurface(int function);
RpClump * PutInClump(RpGeometry* geometry);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* GEOM_H */

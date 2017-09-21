///////////////////////////////////////////////////////////////////////////////
// irSensorsDriver.h

#ifndef __IRSENSORSDRIVER_H__
#define __IRSENSORSDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define IRSENSORSDRV_NAME        "IRSENSORS"
#define IRSENSORSDRV_Major       1
#define IRSENSORSDRV_Minor       0

#define DEVICE_CLASS CirSensorsDriver

#include "ObjDriver.h"

class CirSensorsDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl IRSENSORSDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(IRSENSORSDRV)
	VxD_Service( IRSENSORSDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __IRSENSORSDRIVER_H__
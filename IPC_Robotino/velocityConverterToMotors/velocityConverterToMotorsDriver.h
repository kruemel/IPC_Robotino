///////////////////////////////////////////////////////////////////////////////
// velocityConverterToMotorsDriver.h

#ifndef __VELOCITYCONVERTERTOMOTORSDRIVER_H__
#define __VELOCITYCONVERTERTOMOTORSDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define VELOCITYCONVERTERTOMOTORSDRV_NAME        "VELOCITYCONVERTERTOMOTORS"
#define VELOCITYCONVERTERTOMOTORSDRV_Major       1
#define VELOCITYCONVERTERTOMOTORSDRV_Minor       0

#define DEVICE_CLASS CvelocityConverterToMotorsDriver

#include "ObjDriver.h"

class CvelocityConverterToMotorsDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl VELOCITYCONVERTERTOMOTORSDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(VELOCITYCONVERTERTOMOTORSDRV)
	VxD_Service( VELOCITYCONVERTERTOMOTORSDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __VELOCITYCONVERTERTOMOTORSDRIVER_H__
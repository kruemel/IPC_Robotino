///////////////////////////////////////////////////////////////////////////////
// velocityConverterToCartesianDriver.h

#ifndef __VELOCITYCONVERTERTOCARTESIANDRIVER_H__
#define __VELOCITYCONVERTERTOCARTESIANDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define VELOCITYCONVERTERTOCARTESIANDRV_NAME        "VELOCITYCONVERTERTOCARTESIAN"
#define VELOCITYCONVERTERTOCARTESIANDRV_Major       1
#define VELOCITYCONVERTERTOCARTESIANDRV_Minor       0

#define DEVICE_CLASS CvelocityConverterToCartesianDriver

#include "ObjDriver.h"

class CvelocityConverterToCartesianDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl VELOCITYCONVERTERTOCARTESIANDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(VELOCITYCONVERTERTOCARTESIANDRV)
	VxD_Service( VELOCITYCONVERTERTOCARTESIANDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __VELOCITYCONVERTERTOCARTESIANDRIVER_H__
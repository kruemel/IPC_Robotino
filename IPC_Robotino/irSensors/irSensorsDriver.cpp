///////////////////////////////////////////////////////////////////////////////
// irSensorsDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "irSensorsDriver.h"
#include "irSensorsClassFactory.h"

DECLARE_GENERIC_DEVICE(IRSENSORSDRV)

IOSTATUS CirSensorsDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CirSensorsClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CirSensorsDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CirSensorsDriver::IRSENSORSDRV_GetVersion( )
{
	return( (IRSENSORSDRV_Major << 8) | IRSENSORSDRV_Minor );
}


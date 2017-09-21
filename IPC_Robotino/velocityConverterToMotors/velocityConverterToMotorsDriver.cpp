///////////////////////////////////////////////////////////////////////////////
// velocityConverterToMotorsDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "velocityConverterToMotorsDriver.h"
#include "velocityConverterToMotorsClassFactory.h"

DECLARE_GENERIC_DEVICE(VELOCITYCONVERTERTOMOTORSDRV)

IOSTATUS CvelocityConverterToMotorsDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CvelocityConverterToMotorsClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CvelocityConverterToMotorsDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CvelocityConverterToMotorsDriver::VELOCITYCONVERTERTOMOTORSDRV_GetVersion( )
{
	return( (VELOCITYCONVERTERTOMOTORSDRV_Major << 8) | VELOCITYCONVERTERTOMOTORSDRV_Minor );
}


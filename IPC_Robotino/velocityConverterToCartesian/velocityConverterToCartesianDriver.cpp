///////////////////////////////////////////////////////////////////////////////
// velocityConverterToCartesianDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "velocityConverterToCartesianDriver.h"
#include "velocityConverterToCartesianClassFactory.h"

DECLARE_GENERIC_DEVICE(VELOCITYCONVERTERTOCARTESIANDRV)

IOSTATUS CvelocityConverterToCartesianDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CvelocityConverterToCartesianClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CvelocityConverterToCartesianDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CvelocityConverterToCartesianDriver::VELOCITYCONVERTERTOCARTESIANDRV_GetVersion( )
{
	return( (VELOCITYCONVERTERTOCARTESIANDRV_Major << 8) | VELOCITYCONVERTERTOCARTESIANDRV_Minor );
}


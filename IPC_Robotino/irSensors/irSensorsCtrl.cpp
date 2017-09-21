// irSensorsCtrl.cpp : Implementation of CTcirSensorsCtrl
#include "TcPch.h"
#pragma hdrstop

#include "irSensorsW32.h"
#include "irSensorsCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CirSensorsCtrl

CirSensorsCtrl::CirSensorsCtrl() 
	: ITcOCFCtrlImpl<CirSensorsCtrl, CirSensorsClassFactory>() 
{
}

CirSensorsCtrl::~CirSensorsCtrl()
{
}


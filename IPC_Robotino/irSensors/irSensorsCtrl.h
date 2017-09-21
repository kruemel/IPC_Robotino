///////////////////////////////////////////////////////////////////////////////
// irSensorsCtrl.h

#ifndef __IRSENSORSCTRL_H__
#define __IRSENSORSCTRL_H__

#include <atlbase.h>
#include <atlcom.h>

#define IRSENSORSDRV_NAME "IRSENSORS"

#include "resource.h"       // main symbols
#include "irSensorsW32.h"
#include "TcBase.h"
#include "irSensorsClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CirSensorsCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CirSensorsCtrl, &CLSID_irSensorsCtrl>
	, public IirSensorsCtrl
	, public ITcOCFCtrlImpl<CirSensorsCtrl, CirSensorsClassFactory>
{
public:
	CirSensorsCtrl();
	virtual ~CirSensorsCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_IRSENSORSCTRL)
DECLARE_NOT_AGGREGATABLE(CirSensorsCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CirSensorsCtrl)
	COM_INTERFACE_ENTRY(IirSensorsCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __IRSENSORSCTRL_H__

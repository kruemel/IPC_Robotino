///////////////////////////////////////////////////////////////////////////////
// velocityConverterToMotorsCtrl.h

#ifndef __VELOCITYCONVERTERTOMOTORSCTRL_H__
#define __VELOCITYCONVERTERTOMOTORSCTRL_H__

#include <atlbase.h>
#include <atlcom.h>

#define VELOCITYCONVERTERTOMOTORSDRV_NAME "VELOCITYCONVERTERTOMOTORS"

#include "resource.h"       // main symbols
#include "velocityConverterToMotorsW32.h"
#include "TcBase.h"
#include "velocityConverterToMotorsClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CvelocityConverterToMotorsCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CvelocityConverterToMotorsCtrl, &CLSID_velocityConverterToMotorsCtrl>
	, public IvelocityConverterToMotorsCtrl
	, public ITcOCFCtrlImpl<CvelocityConverterToMotorsCtrl, CvelocityConverterToMotorsClassFactory>
{
public:
	CvelocityConverterToMotorsCtrl();
	virtual ~CvelocityConverterToMotorsCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_VELOCITYCONVERTERTOMOTORSCTRL)
DECLARE_NOT_AGGREGATABLE(CvelocityConverterToMotorsCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CvelocityConverterToMotorsCtrl)
	COM_INTERFACE_ENTRY(IvelocityConverterToMotorsCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __VELOCITYCONVERTERTOMOTORSCTRL_H__

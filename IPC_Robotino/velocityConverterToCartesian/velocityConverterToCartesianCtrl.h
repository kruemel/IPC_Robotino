///////////////////////////////////////////////////////////////////////////////
// velocityConverterToCartesianCtrl.h

#ifndef __VELOCITYCONVERTERTOCARTESIANCTRL_H__
#define __VELOCITYCONVERTERTOCARTESIANCTRL_H__

#include <atlbase.h>
#include <atlcom.h>

#define VELOCITYCONVERTERTOCARTESIANDRV_NAME "VELOCITYCONVERTERTOCARTESIAN"

#include "resource.h"       // main symbols
#include "velocityConverterToCartesianW32.h"
#include "TcBase.h"
#include "velocityConverterToCartesianClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CvelocityConverterToCartesianCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CvelocityConverterToCartesianCtrl, &CLSID_velocityConverterToCartesianCtrl>
	, public IvelocityConverterToCartesianCtrl
	, public ITcOCFCtrlImpl<CvelocityConverterToCartesianCtrl, CvelocityConverterToCartesianClassFactory>
{
public:
	CvelocityConverterToCartesianCtrl();
	virtual ~CvelocityConverterToCartesianCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_VELOCITYCONVERTERTOCARTESIANCTRL)
DECLARE_NOT_AGGREGATABLE(CvelocityConverterToCartesianCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CvelocityConverterToCartesianCtrl)
	COM_INTERFACE_ENTRY(IvelocityConverterToCartesianCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __VELOCITYCONVERTERTOCARTESIANCTRL_H__

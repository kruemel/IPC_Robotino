///////////////////////////////////////////////////////////////////////////////
// velocityConverterToCartesian.cpp
#include "TcPch.h"
#pragma hdrstop

#include "velocityConverterToCartesian.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
DEFINE_THIS_FILE()

///////////////////////////////////////////////////////////////////////////////
// CvelocityConverterToCartesian
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Collection of interfaces implemented by module CvelocityConverterToCartesian
BEGIN_INTERFACE_MAP(CvelocityConverterToCartesian)
	INTERFACE_ENTRY_ITCOMOBJECT()
	INTERFACE_ENTRY(IID_ITcADI, ITcADI)
	INTERFACE_ENTRY(IID_ITcWatchSource, ITcWatchSource)
///<AutoGeneratedContent id="InterfaceMap">
	INTERFACE_ENTRY(IID_ITcCyclic, ITcCyclic)
///</AutoGeneratedContent>
END_INTERFACE_MAP()

IMPLEMENT_ITCOMOBJECT(CvelocityConverterToCartesian)
IMPLEMENT_ITCOMOBJECT_SETSTATE_LOCKOP2(CvelocityConverterToCartesian)
IMPLEMENT_ITCADI(CvelocityConverterToCartesian)
IMPLEMENT_ITCWATCHSOURCE(CvelocityConverterToCartesian)


///////////////////////////////////////////////////////////////////////////////
// Set parameters of CvelocityConverterToCartesian 
BEGIN_SETOBJPARA_MAP(CvelocityConverterToCartesian)
	SETOBJPARA_DATAAREA_MAP()
///<AutoGeneratedContent id="SetObjectParameterMap">
	SETOBJPARA_VALUE(PID_TcTraceLevel, m_TraceLevelMax)
	SETOBJPARA_VALUE(PID_velocityConverterToCartesianParameter, m_Parameter)
	SETOBJPARA_ITFPTR(PID_Ctx_TaskOid, m_spCyclicCaller)
///</AutoGeneratedContent>
END_SETOBJPARA_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get parameters of CvelocityConverterToCartesian 
BEGIN_GETOBJPARA_MAP(CvelocityConverterToCartesian)
	GETOBJPARA_DATAAREA_MAP()
///<AutoGeneratedContent id="GetObjectParameterMap">
	GETOBJPARA_VALUE(PID_TcTraceLevel, m_TraceLevelMax)
	GETOBJPARA_VALUE(PID_velocityConverterToCartesianParameter, m_Parameter)
	GETOBJPARA_ITFPTR(PID_Ctx_TaskOid, m_spCyclicCaller)
///</AutoGeneratedContent>
END_GETOBJPARA_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get watch entries of CvelocityConverterToCartesian
BEGIN_OBJPARAWATCH_MAP(CvelocityConverterToCartesian)
	OBJPARAWATCH_DATAAREA_MAP()
///<AutoGeneratedContent id="ObjectParameterWatchMap">
///</AutoGeneratedContent>
END_OBJPARAWATCH_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get data area members of CvelocityConverterToCartesian
BEGIN_OBJDATAAREA_MAP(CvelocityConverterToCartesian)
///<AutoGeneratedContent id="ObjectDataAreaMap">
	OBJDATAAREA_VALUE(ADI_velocityConverterToCartesianInputs, m_Inputs)
	OBJDATAAREA_VALUE(ADI_velocityConverterToCartesianOutputs, m_Outputs)
///</AutoGeneratedContent>
END_OBJDATAAREA_MAP()


///////////////////////////////////////////////////////////////////////////////
CvelocityConverterToCartesian::CvelocityConverterToCartesian()
	: m_Trace(m_TraceLevelMax, m_spSrv)
	, m_counter(0)
{
	v0 = 0.0;
	v1 = 0.0;
	v2 = 0.0;
	f_rcv = 7.02;

///<AutoGeneratedContent id="MemberInitialization">
	m_TraceLevelMax = tlAlways;
	memset(&m_Parameter, 0, sizeof(m_Parameter));
	memset(&m_Inputs, 0, sizeof(m_Inputs));
	memset(&m_Outputs, 0, sizeof(m_Outputs));
///</AutoGeneratedContent>
}

///////////////////////////////////////////////////////////////////////////////
CvelocityConverterToCartesian::~CvelocityConverterToCartesian() 
{
}


///////////////////////////////////////////////////////////////////////////////
// State Transitions 
///////////////////////////////////////////////////////////////////////////////
IMPLEMENT_ITCOMOBJECT_SETOBJSTATE_IP_PI(CvelocityConverterToCartesian)

///////////////////////////////////////////////////////////////////////////////
// State transition from PREOP to SAFEOP
//
// Initialize input parameters 
// Allocate memory
HRESULT CvelocityConverterToCartesian::SetObjStatePS(PTComInitDataHdr pInitData)
{
	m_Trace.Log(tlVerbose, FENTERA);
	HRESULT hr = S_OK;
	IMPLEMENT_ITCOMOBJECT_EVALUATE_INITDATA(pInitData);

	// TODO: Add initialization code

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from SAFEOP to OP
//
// Register with other TwinCAT objects
HRESULT CvelocityConverterToCartesian::SetObjStateSO()
{
	m_Trace.Log(tlVerbose, FENTERA);
	HRESULT hr = S_OK;

	// TODO: Add any additional initialization


	// If following call is successful the CycleUpdate method will be called, 
	// possibly even before method has been left.
	hr = FAILED(hr) ? hr : AddModuleToCaller(); 

	// Cleanup if transition failed at some stage
	if ( FAILED(hr) )
	{
		RemoveModuleFromCaller(); 
	}

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from OP to SAFEOP
HRESULT CvelocityConverterToCartesian::SetObjStateOS()
{
	m_Trace.Log(tlVerbose, FENTERA);

	HRESULT hr = S_OK;

	RemoveModuleFromCaller(); 

	// TODO: Add any additional deinitialization

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from SAFEOP to PREOP
HRESULT CvelocityConverterToCartesian::SetObjStateSP()
{
	HRESULT hr = S_OK;
	m_Trace.Log(tlVerbose, FENTERA);

	// TODO: Add deinitialization code

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///<AutoGeneratedContent id="ImplementationOf_ITcCyclic">
HRESULT CvelocityConverterToCartesian::CycleUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context)
{
	HRESULT hr = S_OK;

/*
% assembly of the three separate positive motor velocities(resolution:
% 1Byte) and their rotation direction to positive and / or negative
% longitudinal, lateral & rotational velocities(in milimeters per
% second)


% inputs :  velocityMotor0	(from 0 to 255)
%			velocityMotor1	(from 0 to 255)
%			velocityMotor2	(from 0 to 255)

%			directionMotor0 (rotating direction of motor1, 0 := counter-clockwise, 1 := clockwise)
%			directionMotor1 (rotating direction of motor2, 0 := counter-clockwise, 1 := clockwise)
%			directionMotor2 (rotating direction of motor3, 0 := counter-clockwise, 1 := clockwise)

% outputs: velocityX (longitudinal velocity in milimeters per second)
%          velocityY (lateral velocity in milimeters per second)
%          theta     (rotational velocity in milimeters per second)


% assembly of absolute motor velocity and rotating direction to %
% longitudinal, lateral & rotational velocity for every motor   %
*/

	if (m_Inputs.directionMotor0 == 0) {
		v0 = -m_Inputs.velocityMotor0;
	}
	else {
		v0 = m_Inputs.velocityMotor0;
	}

	if (m_Inputs.directionMotor1 == 0) {
		v1 = -m_Inputs.velocityMotor1;
	}
	else {
		v1 = m_Inputs.velocityMotor1;
	}

	if (m_Inputs.directionMotor2 == 0) {
		v2 = -m_Inputs.velocityMotor2;
	}
	else {
		v2 = m_Inputs.velocityMotor2;
	}

/*
% conversion of the separate motor velocities from a value between - 255
% and 255 to millimeters
*/

	v0 = v0 * f_rcv;
	v1 = v1 * f_rcv;
	v2 = v2 * f_rcv;

/*
% conversion from three separate motor velocities to longitudinal,
% lateral & rotational velocity
*/
		m_Outputs.velocityX = (v2 - v0) / (2.0 * cosdg_(30.0));     //in mm / s
		m_Outputs.velocityY= (v0 - 2.0 * v1 + v2) / 3.0;            //in mm / s
		m_Outputs.theta= (v0 + v1 + v2) / (3.0 * 135.0);			//in rad / s

	return hr;
}
///</AutoGeneratedContent>

///////////////////////////////////////////////////////////////////////////////
HRESULT CvelocityConverterToCartesian::AddModuleToCaller()
{
	m_Trace.Log(tlVerbose, FENTERA);

	HRESULT hr = S_OK;
	if ( m_spCyclicCaller.HasOID() )
	{
		if ( SUCCEEDED_DBG(hr = m_spSrv->TcQuerySmartObjectInterface(m_spCyclicCaller)) )
		{
			if ( FAILED(hr = m_spCyclicCaller->AddModule(m_spCyclicCaller, THIS_CAST(ITcCyclic))) )
			{
				m_spCyclicCaller = NULL;
			}
		}
	}
	else
	{
		hr = ADS_E_INVALIDOBJID; 
		SUCCEEDED_DBGT(hr, "Invalid OID specified for caller task");
	}

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
VOID CvelocityConverterToCartesian::RemoveModuleFromCaller()
{
	m_Trace.Log(tlVerbose, FENTERA);

	if ( m_spCyclicCaller )
	{
		m_spCyclicCaller->RemoveModule(m_spCyclicCaller);
	}
	m_spCyclicCaller	= NULL;

	m_Trace.Log(tlVerbose, FLEAVEA);
}


///////////////////////////////////////////////////////////////////////////////
// velocityConverterToMotors.cpp
#include "TcPch.h"
#pragma hdrstop

#include "velocityConverterToMotors.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
DEFINE_THIS_FILE()

///////////////////////////////////////////////////////////////////////////////
// CvelocityConverterToMotors
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Collection of interfaces implemented by module CvelocityConverterToMotors
BEGIN_INTERFACE_MAP(CvelocityConverterToMotors)
	INTERFACE_ENTRY_ITCOMOBJECT()
	INTERFACE_ENTRY(IID_ITcADI, ITcADI)
	INTERFACE_ENTRY(IID_ITcWatchSource, ITcWatchSource)
///<AutoGeneratedContent id="InterfaceMap">
	INTERFACE_ENTRY(IID_ITcCyclic, ITcCyclic)
///</AutoGeneratedContent>
END_INTERFACE_MAP()

IMPLEMENT_ITCOMOBJECT(CvelocityConverterToMotors)
IMPLEMENT_ITCOMOBJECT_SETSTATE_LOCKOP2(CvelocityConverterToMotors)
IMPLEMENT_ITCADI(CvelocityConverterToMotors)
IMPLEMENT_ITCWATCHSOURCE(CvelocityConverterToMotors)


///////////////////////////////////////////////////////////////////////////////
// Set parameters of CvelocityConverterToMotors 
BEGIN_SETOBJPARA_MAP(CvelocityConverterToMotors)
	SETOBJPARA_DATAAREA_MAP()
///<AutoGeneratedContent id="SetObjectParameterMap">
	SETOBJPARA_VALUE(PID_TcTraceLevel, m_TraceLevelMax)
	SETOBJPARA_VALUE(PID_velocityConverterToMotorsParameter, m_Parameter)
	SETOBJPARA_ITFPTR(PID_Ctx_TaskOid, m_spCyclicCaller)
///</AutoGeneratedContent>
END_SETOBJPARA_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get parameters of CvelocityConverterToMotors 
BEGIN_GETOBJPARA_MAP(CvelocityConverterToMotors)
	GETOBJPARA_DATAAREA_MAP()
///<AutoGeneratedContent id="GetObjectParameterMap">
	GETOBJPARA_VALUE(PID_TcTraceLevel, m_TraceLevelMax)
	GETOBJPARA_VALUE(PID_velocityConverterToMotorsParameter, m_Parameter)
	GETOBJPARA_ITFPTR(PID_Ctx_TaskOid, m_spCyclicCaller)
///</AutoGeneratedContent>
END_GETOBJPARA_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get watch entries of CvelocityConverterToMotors
BEGIN_OBJPARAWATCH_MAP(CvelocityConverterToMotors)
	OBJPARAWATCH_DATAAREA_MAP()
///<AutoGeneratedContent id="ObjectParameterWatchMap">
///</AutoGeneratedContent>
END_OBJPARAWATCH_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get data area members of CvelocityConverterToMotors
BEGIN_OBJDATAAREA_MAP(CvelocityConverterToMotors)
///<AutoGeneratedContent id="ObjectDataAreaMap">
	OBJDATAAREA_VALUE(ADI_velocityConverterToMotorsInputs, m_Inputs)
	OBJDATAAREA_VALUE(ADI_velocityConverterToMotorsOutputs, m_Outputs)
///</AutoGeneratedContent>
END_OBJDATAAREA_MAP()


///////////////////////////////////////////////////////////////////////////////
CvelocityConverterToMotors::CvelocityConverterToMotors()
	: m_Trace(m_TraceLevelMax, m_spSrv)
	, m_counter(0)
{
	vX = 0.0;
	vY = 0.0;
	vTheta = 0.0;
	v0 = 0.0;
	v1 = 0.0;
	v2 = 0.0;
	f = 1 / 7.02;

///<AutoGeneratedContent id="MemberInitialization">
	m_TraceLevelMax = tlAlways;
	memset(&m_Parameter, 0, sizeof(m_Parameter));
	memset(&m_Inputs, 0, sizeof(m_Inputs));
	memset(&m_Outputs, 0, sizeof(m_Outputs));
///</AutoGeneratedContent>
}

///////////////////////////////////////////////////////////////////////////////
CvelocityConverterToMotors::~CvelocityConverterToMotors() 
{
}


///////////////////////////////////////////////////////////////////////////////
// State Transitions 
///////////////////////////////////////////////////////////////////////////////
IMPLEMENT_ITCOMOBJECT_SETOBJSTATE_IP_PI(CvelocityConverterToMotors)

///////////////////////////////////////////////////////////////////////////////
// State transition from PREOP to SAFEOP
//
// Initialize input parameters 
// Allocate memory
HRESULT CvelocityConverterToMotors::SetObjStatePS(PTComInitDataHdr pInitData)
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
HRESULT CvelocityConverterToMotors::SetObjStateSO()
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
HRESULT CvelocityConverterToMotors::SetObjStateOS()
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
HRESULT CvelocityConverterToMotors::SetObjStateSP()
{
	HRESULT hr = S_OK;
	m_Trace.Log(tlVerbose, FENTERA);

	// TODO: Add deinitialization code

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///<AutoGeneratedContent id="ImplementationOf_ITcCyclic">
HRESULT CvelocityConverterToMotors::CycleUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context)
{
	HRESULT hr = S_OK;
	/*
	% conversion from positive and / or negative longitudinal, lateral and
	% rotational velocities(in milimeters per second) to three separate
	% positive motor velocities(resolution: 1Byte) and their rotation
	% direction

	% inputs:  velocityX (longitudinal velocity in milimeters per second)
	%          velocityY (lateral velocity in milimeters per second)
	%          theta     (rotational velocity in milimeters per second)

	% outputs : velocityMotor0	(from 0 to 255)
	%			velocityMotor1	(from 0 to 255)
	%			velocityMotor2	(from 0 to 255)

	%			directionMotor0 (rotating direction of motor1, 1 := counter-clockwise, 3 := clockwise)
	%			directionMotor1 (rotating direction of motor2, 1 := counter-clockwise, 3 := clockwise)
	%			directionMotor2 (rotating direction of motor3, 1 := counter-clockwise, 3 := clockwise)


	% conversion from longitudinal, lateral & rotational velocity to the
	% three separate motor velocities
	*/

	//Maximal Speed
	if (m_Inputs.velocityX > 500) {
		vX = 500;
	}
	else {
		vX = m_Inputs.velocityX;
	}
	
	if (m_Inputs.velocityY > 500) {
		vY = 500;
	}
	else{
		vY = m_Inputs.velocityY;
	}
	
	if (m_Inputs.theta > 3.14) {
		vTheta =3.14;
	}
	else {
		vTheta = m_Inputs.theta;
	}


	v0 = (-vX * cosdg_(30.0))	+ (vY * cosdg_(60.0))	+ (vTheta * 135.0); //cosd function of cos in Degrees!!!
	v1 = 0.0					+ (-vY)					+ (vTheta * 135.0);
	v2 = (vX * cosdg_(30.0))	+ (vY * cosdg_(60.0))	+ (vTheta * 135.0);
	
	/*
	% conversion of the separate motor velocities from millimeters to a
	% value between - 255 and 255
	*/
	
	v0 = v0 * f;
	v1 = v1 * f;
	v2 = v2 * f;
	/*
	% division of motor velocities into absolute velocity and rotating
	% direction
	*/
	if (v0 < 0) {
		m_Outputs.directionMotor0 = 1;
		m_Outputs.velocityMotor0 = -v0;
	}
	else {
		m_Outputs.directionMotor0 = 3;
		m_Outputs.velocityMotor0 = v0;
	}

	if (v1 < 0) {
		m_Outputs.directionMotor1 = 1;
		m_Outputs.velocityMotor1 = -v1;
	}
	else {
		m_Outputs.directionMotor1 = 3;
		m_Outputs.velocityMotor1 = v1;
	}

	if (v2 < 0) {
		m_Outputs.directionMotor2 = 1;
		m_Outputs.velocityMotor2 = -v2;
	}
	else {
		m_Outputs.directionMotor2 = 3;
		m_Outputs.velocityMotor2 = v2;
	}
	return hr;
}
///</AutoGeneratedContent>

///////////////////////////////////////////////////////////////////////////////
HRESULT CvelocityConverterToMotors::AddModuleToCaller()
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
VOID CvelocityConverterToMotors::RemoveModuleFromCaller()
{
	m_Trace.Log(tlVerbose, FENTERA);

	if ( m_spCyclicCaller )
	{
		m_spCyclicCaller->RemoveModule(m_spCyclicCaller);
	}
	m_spCyclicCaller	= NULL;

	m_Trace.Log(tlVerbose, FLEAVEA);
}


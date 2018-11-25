#include"Gate_Cfg.h"

/*---------------------------------------------------------------------------*/
/* �����֐��錾                                                              */
/*---------------------------------------------------------------------------*/
static bool stopRequested;

/*---------------------------------------------------------------------------*/
/* ���J�֐�                                                                  */
/*---------------------------------------------------------------------------*/

/*****************************************************************************/
/* ���C������: �����S���c��̓I�ȑ���͐ӔC�� or �����֐��Ŏ��{            */
/*****************************************************************************/
void GateInit(void)
{
	GateImplSet( gateConfig.initGate );
	stopRequested = false;
}

void GateRefresh(void)
{
	bool valid;
	
	valid = GateImplValidate();

	if (valid != true)
	{
		GateImplSet(gateConfig.failSafeGate);
	}
}

void GateRequestStop(void)
{
	stopRequested = true;
}

void GateUpdate(void)
{
	if (stopRequested == true)
	{
		GateImplSet(true);
	}
}

bool GateIsExecutable(void)
{
	bool ret;
	ret = GateImplGet();

	return ret;
}

#include"Gate_Cfg.h"

/*---------------------------------------------------------------------------*/
/* “à•”ŠÖ”éŒ¾                                                              */
/*---------------------------------------------------------------------------*/
static bool stopRequested;

/*---------------------------------------------------------------------------*/
/* ŒöŠJŠÖ”                                                                  */
/*---------------------------------------------------------------------------*/

/*****************************************************************************/
/* ƒƒCƒ“ˆ—: §Œä‚ğ’S‚¤c‹ï‘Ì“I‚È‘€ì‚ÍÓ”CÒ or “à•”ŠÖ”‚ÅÀ{            */
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

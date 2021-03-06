#include"Gate_Cfg.h"

/*---------------------------------------------------------------------------*/
/* 内部関数宣言                                                              */
/*---------------------------------------------------------------------------*/
static bool stopRequested;

/*---------------------------------------------------------------------------*/
/* 公開関数                                                                  */
/*---------------------------------------------------------------------------*/

/*****************************************************************************/
/* メイン処理: 制御を担う…具体的な操作は責任者 or 内部関数で実施            */
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

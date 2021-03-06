#include"Mode_Cfg.h"
#include"Mode.h"

/*---------------------------------------------------------------------------*/
/* 型定義                                                                    */
/*---------------------------------------------------------------------------*/
typedef struct {
	unsigned int nextMode;
	bool isRequested;
} ModeTransitionRequest;

/*---------------------------------------------------------------------------*/
/* 内部変数                                                                  */
/*---------------------------------------------------------------------------*/
ModeTransitionRequest state;

/*---------------------------------------------------------------------------*/
/* 公開関数                                                                  */
/*---------------------------------------------------------------------------*/
/*****************************************************************************/
/* 初期化 */
/*****************************************************************************/
void ModeInit(void)
{
	unsigned int initMode = modeConfig.initMode;
	ModeImplSet(initMode);

	state.nextMode = initMode;
	state.isRequested = false;
}

/*****************************************************************************/
/* モード遷移要求(範囲外は受け付けずエラーを返す) */
/*****************************************************************************/
int ModeRequestTransition(unsigned int nextMode)
{
	int ret = 0;

	if (nextMode < modeConfig.totalModes)
	{
		/* DI */
		state.nextMode = nextMode;
		state.isRequested = true;
		/* EI */
	}
	else
	{
		/* 負の値がエラー、範囲外とか */
		ret = -1;
	}
	return ret;
}

/*****************************************************************************/
/* モード遷移(Managerでコール) */
/*****************************************************************************/
void ModeTransit(void)
{
	ModeImplSet( state.nextMode );
	state.isRequested = false;
}

/*****************************************************************************/
/* モードのリフレッシュ(Managerでコール) */
/*****************************************************************************/
void ModeRefresh(void)
{
	bool valid;

	valid = ModeImplValidate();
	/* 保存の仕方によっていろいろやる */
	if (valid != true)
	{
		ModeImplSet( modeConfig.failSafeMode );
	}
}

/*****************************************************************************/
/* モードの取得(リフレッシュしていて値が保証できている前提) */
/*****************************************************************************/
unsigned int ModeGet(void)
{
	unsigned int mode = ModeImplGet();
	return mode;
}

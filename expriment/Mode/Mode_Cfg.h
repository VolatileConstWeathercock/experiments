#pragma once
#include"Mode.h"
/*****************************************************************************/
/* モードを保持する                                                          */
/*****************************************************************************/

/*---------------------------------------------------------------------------*/
/* 型定義                                                                    */
/*---------------------------------------------------------------------------*/
typedef struct {
	unsigned int initMode;     /* 初期値 */
	unsigned int failSafeMode; /* 化けた時に移行する */
	unsigned int totalModes;   /* 総モード数 */
} ModeConfig;

/*---------------------------------------------------------------------------*/
/* 公開定数                                                                  */
/*---------------------------------------------------------------------------*/
extern volatile const ModeConfig modeConfig;

/*---------------------------------------------------------------------------*/
/* モジュール内関数                                                          */
/*---------------------------------------------------------------------------*/
void ModeImplSet(unsigned int mode);
bool ModeImplValidate(void);
unsigned int ModeImplGet(void);

#pragma once
/*****************************************************************************/
/* モードを保持する                                                          */
/* 範囲内の値を保持することを保証する。                                      */
/* RAM化けに対しても何らかの方法で対策する…内部は隠蔽する。                 */
/*****************************************************************************/

/*---------------------------------------------------------------------------*/
/* 公開関数                                                                  */
/*---------------------------------------------------------------------------*/

/*****************************************************************************/
/* 初期化 */
/*****************************************************************************/
void ModeInit(void);

/*****************************************************************************/
/* モード遷移要求(範囲外は受け付けずエラーを返す) */
/*****************************************************************************/
int ModeRequestTransition(unsigned int nextMode);

/*****************************************************************************/
/* モード遷移(Managerでコール) */
/*****************************************************************************/
void ModeTransit(void);

/*****************************************************************************/
/* モードのリフレッシュ(Managerでコール) */
/*****************************************************************************/
void ModeRefresh(void);

/*****************************************************************************/
/* モードの取得 */
/*****************************************************************************/
unsigned int ModeGet(void);


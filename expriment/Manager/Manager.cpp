#include<Task/Task.h>
#include<Mode/Mode.h>
#include<Gate/Gate.h>
#include"Manager_Cfg.h"
#include"Manager.h"

/*---------------------------------------------------------------------------*/
/* 内部関数宣言                                                              */
/*---------------------------------------------------------------------------*/
/* モードに応じたタスクを実行 */
static bool ManagerExecute(unsigned int mode);

/*---------------------------------------------------------------------------*/
/* 公開関数                                                                  */
/*---------------------------------------------------------------------------*/
void ManagerInit(void)
{
	ModeInit();
	GateInit();
}

/*****************************************************************************/
/* メイン処理: 制御を担う…具体的な操作は責任者 or 内部関数で実施            */
/*****************************************************************************/
void ManagerMain(void)
{
	unsigned int mode = 0U;
	bool isInterruptable = true;
	bool isExecutable = true;

	/* リフレッシュ処理 */
	ModeRefresh();
	GateRefresh();

	/* 実行可能か確認する */
	isExecutable = GateIsExecutable();

	/* 実行可能なら登録された関数を実行する */
	if (isExecutable == true)
	{
		mode = ModeGet();
		isInterruptable = ManagerExecute(mode);

		/* 中断可能なら次の状態へ遷移する */
		if (isInterruptable == true)
		{
			ModeTransit();
		}

		/* 更新 */
		GateUpdate();
	}
}

/*****************************************************************************/
/* 実行: 具体的な操作を担う…と言っても関数を呼ぶだけ                        */
/* 大抵の場合べた書きされるのだけど…具体的な操作と制御を分けておきたい      */
/*****************************************************************************/
static bool ManagerExecute(unsigned int mode)
{
	TaskList list;
	bool isInterruptable = true;

	/* 補足: 普通はポインタでよいが、volatile constにするとこれは必要な処理になる */
	list = managerConfig.lists[mode];
	isInterruptable = TaskListExecute(&list);

	return isInterruptable;
}

#include"Task.h"
/*****************************************************************************/
/* タスク(周期的に呼びたい関数)                                              */
/*****************************************************************************/

/*---------------------------------------------------------------------------*/
/* 公開関数                                                                  */
/*---------------------------------------------------------------------------*/

/*****************************************************************************/
/* タスク列の実行 */
/* 与えられたタスクリストのタスクを実行する。中断できるならtrueを返す。 */
/* 中断できない = 時間がかかる処理の途中で、以降も周期処理が必要 */
/*****************************************************************************/
bool TaskListExecute(const TaskList* pList)
{
	TaskList list = *pList;  /* 普通はいらないけど、相手がvolatile constだと必要 */
	unsigned int index;
	bool isInterruptable = true;

	for (index = 0U; index < list.length; index++)
	{
		isInterruptable &= list.tasks[index].execute();
	}
	return isInterruptable;
}


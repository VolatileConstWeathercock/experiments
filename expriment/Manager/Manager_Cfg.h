#pragma once
#include<Task/Task.h>
/*---------------------------------------------------------------------------*/
/* 型定義                                                                    */
/*---------------------------------------------------------------------------*/
typedef struct {
	const TaskList* lists;
} ManagerConfig;

/* Modeとの整合性はどうとるか */
extern const ManagerConfig managerConfig;

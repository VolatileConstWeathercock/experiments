#include"Manager.h"
#include"Manager_Cfg.h"

#include<stdio.h>
/*---------------------------------------------------------------------------*/
/* ì‡ïîä÷êî                                                                  */
/*---------------------------------------------------------------------------*/
static bool DummyModeA(void)
{
	printf("[A]\n");
	return false;
}

static bool DummyModeB(void)
{
	printf("[B]\n");
	return false;
}

static bool DummyModeC(void)
{
	printf("[C]\n");
	return false;
}

#define ToTaskList( array ) { &array[0], ((unsigned int)(sizeof(array)/sizeof(array[0]))) }
static const Task TaskArrayA[] = { DummyModeA, DummyModeA };
static const Task TaskArrayB[] = { DummyModeB };
static const Task TaskArrayC[] = { DummyModeC, DummyModeC, DummyModeC };

static const TaskList taskLists[] = {
	ToTaskList(TaskArrayA),
	ToTaskList(TaskArrayB),
	ToTaskList(TaskArrayC)
};
const ManagerConfig managerConfig = {
	&taskLists[0]
};

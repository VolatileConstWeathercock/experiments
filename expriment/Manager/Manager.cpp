#include<Task/Task.h>
#include<Mode/Mode.h>
#include<Gate/Gate.h>
#include"Manager_Cfg.h"
#include"Manager.h"

/*---------------------------------------------------------------------------*/
/* �����֐��錾                                                              */
/*---------------------------------------------------------------------------*/
/* ���[�h�ɉ������^�X�N�����s */
static bool ManagerExecute(unsigned int mode);

/*---------------------------------------------------------------------------*/
/* ���J�֐�                                                                  */
/*---------------------------------------------------------------------------*/
void ManagerInit(void)
{
	ModeInit();
	GateInit();
}

/*****************************************************************************/
/* ���C������: �����S���c��̓I�ȑ���͐ӔC�� or �����֐��Ŏ��{            */
/*****************************************************************************/
void ManagerMain(void)
{
	unsigned int mode = 0U;
	bool isInterruptable = true;
	bool isExecutable = true;

	/* ���t���b�V������ */
	ModeRefresh();
	GateRefresh();

	/* ���s�\���m�F���� */
	isExecutable = GateIsExecutable();

	/* ���s�\�Ȃ�o�^���ꂽ�֐������s���� */
	if (isExecutable == true)
	{
		mode = ModeGet();
		isInterruptable = ManagerExecute(mode);

		/* ���f�\�Ȃ玟�̏�Ԃ֑J�ڂ��� */
		if (isInterruptable == true)
		{
			ModeTransit();
		}

		/* �X�V */
		GateUpdate();
	}
}

/*****************************************************************************/
/* ���s: ��̓I�ȑ����S���c�ƌ����Ă��֐����ĂԂ���                        */
/* ���̏ꍇ�ׂ����������̂����ǁc��̓I�ȑ���Ɛ���𕪂��Ă�������      */
/*****************************************************************************/
static bool ManagerExecute(unsigned int mode)
{
	TaskList list;
	bool isInterruptable = true;

	/* �⑫: ���ʂ̓|�C���^�ł悢���Avolatile const�ɂ���Ƃ���͕K�v�ȏ����ɂȂ� */
	list = managerConfig.lists[mode];
	isInterruptable = TaskListExecute(&list);

	return isInterruptable;
}

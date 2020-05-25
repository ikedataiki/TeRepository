#include"DxLib.h"
#include"keycheck.h"

int newKey[KEY_MAX];
int trgKeyDown[KEY_MAX];
int trgKeyUp[KEY_MAX];

int oldKey[KEY_MAX];

XINPUT_STATE xBox360input;//xBox360�p�b�h�Ή��p�̊Ǘ��p�\����(Dxkib�ŗL)

//-------�L�[�`�F�b�N�̏�����
void CheckKeyInit()
{
	//------�L�[���S�N���A
	for (int i = 0; i < KEY_MAX; i++)
	{
		newKey[i] = 0;		//����̃t���[���̓���
		oldKey[i] = 0;		//�O��̃t���[���̓���
		trgKeyDown[i] = 0;	//�L�[�_�E��
		trgKeyUp[i] = 0;	//�L�[�A�b�v
	}
}


//--------�L�[�`�F�b�N���C������
//--------���Q�[�����[�v�Ŗ���Ăяo���ď�ɍŐV��Ԃɂ��Ă����܂�
void CheckKey()
{
	for (int i = 0; i < KEY_MAX; i++)
	{
		newKey[i] = 0;		
		trgKeyDown[i] = 0;
		trgKeyUp[i] = 0;	
	}

	// =====�@�L�[�{�[�h�̓��̓`�F�b�N
	//1P
	if (CheckHitKey(KEY_INPUT_UP))newKey[_1P_UP] = 1;
	if (CheckHitKey(KEY_INPUT_RIGHT))newKey[_1P_RIGHT] = 1;
	if (CheckHitKey(KEY_INPUT_DOWN))newKey[_1P_DOWN] = 1;
	if (CheckHitKey(KEY_INPUT_LEFT))newKey[_1P_LEFT] = 1;
	if (CheckHitKey(KEY_INPUT_LSHIFT))newKey[_1P_A] = 1;
	if (CheckHitKey(KEY_INPUT_LCONTROL))newKey[_1P_B] = 1;
	

	////2P
	if (CheckHitKey(KEY_INPUT_W))newKey[_2P_UP] = 1;
	if (CheckHitKey(KEY_INPUT_D))newKey[_2P_RIGHT] = 1;
	if (CheckHitKey(KEY_INPUT_S))newKey[_2P_DOWN] = 1;
	if (CheckHitKey(KEY_INPUT_A))newKey[_2P_LEFT] = 1;


	if (CheckHitKey(KEY_INPUT_I))newKey[CAM_ZOOM_IN] = 1;
	if (CheckHitKey(KEY_INPUT_O))newKey[CAM_ZOOM_OUT] = 1;
	if (CheckHitKey(KEY_INPUT_SPACE))newKey[SPACE] = 1;
	//if (CheckHitKey(KEY_INPUT_LSHIFT))newKey[_2P_A] = 1;
	//if (CheckHitKey(KEY_INPUT_LCONTROL))newKey[_2P_B] = 1;


	// =====3�Q�[���p�b�h�̓��̓`�F�b�N
	//for (int i = 0; i < PAD_MAX; i++)
	//{

	//}
	GetJoypadXInputState(DX_INPUT_KEY_PAD1,&xBox360input);//PAD1�����o
	if (xBox360input.Buttons[XINPUT_BUTTON_DPAD_UP])newKey[_1P_UP] = 1;//�f�W�^�������{�^����
	if (xBox360input.Buttons[XINPUT_BUTTON_DPAD_RIGHT])newKey[_1P_RIGHT] = 1;//�f�W�^�������{�^���E
	if (xBox360input.Buttons[XINPUT_BUTTON_DPAD_DOWN])newKey[_1P_DOWN] = 1;//�f�W�^�������{�^����
	if (xBox360input.Buttons[XINPUT_BUTTON_DPAD_LEFT])newKey[_1P_LEFT] = 1;//�f�W�^�������{�^����
	if (xBox360input.Buttons[XINPUT_BUTTON_START])newKey[_1P_START] = 1; //START�{�^��
	if (xBox360input.Buttons[XINPUT_BUTTON_BACK])newKey[_1P_SELECT] = 1;//BACK�{�^��

	if (xBox360input.Buttons[XINPUT_BUTTON_LEFT_THUMB])newKey[_1P_xTHUMB_L] = 1;//���X�e�B�b�N��������
	if (xBox360input.Buttons[XINPUT_BUTTON_RIGHT_THUMB])newKey[_1P_xTHUMB_R] = 1;//�E�X�e�B�b�N��������
	if (xBox360input.Buttons[XINPUT_BUTTON_LEFT_SHOULDER])newKey[_1P_LB] = 1;//LB�{�^��
	if (xBox360input.Buttons[XINPUT_BUTTON_RIGHT_SHOULDER])newKey[_1P_RB] = 1;//RB�{�^��

	if (xBox360input.Buttons[XINPUT_BUTTON_A])newKey[_1P_A] = 1;//A�{�^��
	if (xBox360input.Buttons[XINPUT_BUTTON_B])newKey[_1P_B] = 1;//B�{�^��
	if (xBox360input.Buttons[XINPUT_BUTTON_X])newKey[_1P_X] = 1;//X�{�^��
	if (xBox360input.Buttons[XINPUT_BUTTON_Y])newKey[_1P_Y] = 1;//Y�{�^��
	
	newKey[_1P_xLEFT_TRIGGER] = (int)xBox360input.LeftTrigger;		//���g���K�[(0�`255)
	newKey[_1P_xRIGHT_TRIGGER] = (int)xBox360input.RightTrigger;	//�E�g���K�[(0�`255)
	newKey[_1P_xThumbLX] = (int)xBox360input.ThumbLX;	//���X�e�B�b�N�̉����l(-32768 �`32767)
	newKey[_1P_xThumbLY] = (int)xBox360input.ThumbLY;	//���X�e�B�b�N�̏c���l(-32768 �`32767)
	newKey[_1P_xThumbRX] = (int)xBox360input.ThumbRX;	//�E�X�e�B�b�N�̉����l(-32768 �`32767)
	newKey[_1P_xThumbRY] = (int)xBox360input.ThumbRY;	//�E�X�e�B�b�N�̏c���l(-32768 �`32767)


	//----------�g���K���(�L�[�A�b�v�A�L�[�_�E��)�̍X�V
	for (int i = 0; i < KEY_MAX; i++)
	{
		if (oldKey[i] == 0 && newKey[i] == 1)trgKeyDown[i] = 1;//�L�[�_�E���ݒ�
		if (oldKey[i] == 1 && newKey[i] == 0)trgKeyUp[i] = 1;//�L�[�A�b�v�ݒ�
		oldKey[i] = newKey[i];		//�O��̃t���[�����͍쐬
	}
}
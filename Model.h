#pragma once

class Model
{
public:
	int model;		//���f���f�[�^�p
	VECTOR pos;		//���f���̍��W
	VECTOR rol;		//���f���̉�]
	VECTOR scl;		//���f���̑傫��
	VECTOR target;	//���_�̏ꏊ
	float dir;		//����p
	float modelspeed;	//���f���̈ړ��X�s�[�h

	//�A�j���[�V�����ݒ�
	int atachIndex;		//�A�j���ԍ��o�^
	float totaltime;	//�Đ�����
	float playTime;		//�Đ��ӏ�
public:
	Model();
	~Model();
	void Init(void);
	void Update(void);
	void Render(void);
};

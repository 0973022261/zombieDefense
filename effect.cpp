#include "stdafx.h"
#include "effect.h"
#include "animation.h"


effect::effect()
	:	_effectImage(NULL),
		_effectAnimation(NULL),
		_isRunning(false),
		_x(0), 
		_y(0)
{
}


effect::~effect()
{

}

HRESULT effect::init(image* effectImage, int frameW, int frameH, int fps, float elapsedTime)
{
	//����Ʈ �̹����� ���ٸ� �������� ����
	if (!effectImage) return E_FAIL;

	_isRunning = false;
	_effectImage = effectImage;
	_elapsedTime = elapsedTime;

	//����Ʈ�ִϸ��̼��� ������ ���� �����Ѵ�
	if (!_effectAnimation) _effectAnimation = new animation;

	_effectAnimation->init(_effectImage->getWidth(), _effectImage->getHeight(), frameW, frameH);
	_effectAnimation->setDefPlayFrame(false, false);
	_effectAnimation->setFPS(fps);
	_effectAnimation->stop();


	return S_OK;
}
void effect::release(void)
{
	_effectImage = NULL;
	SAFE_DELETE(_effectAnimation);

}

void effect::update(void)
{
	//�ִϸ��̼��� Ȱ��ȭ �Ǿ����� �ʴٸ� ���ư��ÿ�
	if (!_isRunning) return;

	_effectAnimation->frameUpdate(_elapsedTime);

	if (!_effectAnimation->isPlay()) killEffect();
}

void effect::render(float mapx, float mapy)
{
	if (!_isRunning) return;

	RECT rcTemp;
	RECT rcFocus = RectMake(mapx, mapy, WINSIZEX, WINSIZEY);
	RECT rcEffect = RectMake(_x, _y, _effectImage->getWidth(), _effectImage->getHeight());
	int x, y;

	if (!IntersectRect(&rcTemp, &rcEffect, &rcFocus)) return;

	x = rcEffect.left - rcFocus.left;
	y = rcEffect.top - rcFocus.top;

	_effectImage->aniRender(getMemDC(), x, y, _effectAnimation);
}


void effect::startEffect(int x, int y)
{
	//�̹����� �ִϸ��̼��̳� ���� �ϳ��� ������ �ȵǾ��ִٸ�
	if (!_effectImage || !_effectAnimation) return;

	//����Ʈ ž ��ǥ�� ������ǥ��
	_x = x - (_effectAnimation->getFrameWidth() / 2);
	_y = y - (_effectAnimation->getFrameHeight() / 2);

	_isRunning = true;
	_effectAnimation->start();
}

void effect::killEffect(void)
{
	_isRunning = false;
}


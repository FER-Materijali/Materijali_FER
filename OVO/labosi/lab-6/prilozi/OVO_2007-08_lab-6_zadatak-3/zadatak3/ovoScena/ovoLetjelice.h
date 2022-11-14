/* ************************************************ *
 *  Zlatko Dukic, 2006.g.							*
 * Laboratorijske vjezbe iz kolegija				*
 * Osnove virtualnih okruzenja						*
 * ************************************************ */

#pragma once

#include <osg/Node>
#include <osg/AnimationPath>


#define AVION_PATH  "C:\\Program Files\\OpenSceneGraph\\data\\cessna.osg"
#define GLIDER_PATH "C:\\Program Files\\OpenSceneGraph\\data\\glider.osg"

class ovoLetjelice
{
private:
	// interne metode koje stvaraju put i ucitavaju letjelice
	osg::Node* ovoLetjelice::createMovingModel(const osg::Vec3& center, float radius);
	osg::AnimationPath* ovoLetjelice::createAnimationPath(const osg::Vec3& center,float radius,double looptime);

public:
	// konstruktori - ne koriste se eksplicitno
	ovoLetjelice(void);
	~ovoLetjelice(void);

	// metoda koja radi sav posao oko letjelica, jedino nju treba vidjeti iz main-a
	osg::Node* ovoLetjelice::stvoriLetjelice();

};

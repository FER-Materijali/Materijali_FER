/* ************************************************ *
 *  Zlatko Dukic, 2006.g.							*
 * Laboratorijske vjezbe iz kolegija				*
 * Osnove virtualnih okruzenja						*
 * ************************************************ */

#pragma once
#include <osg/Node>

#define TEREN_PATH "C:\\Program Files\\OpenSceneGraph\\data\\Models\\JoeDirt\\JoeDirt.flt"

class ovoTeren
{
private:
	// svor u kojeg cemo ucitati teren
	osg::Node* terenNode;


public:

	// konstruktor i destruktor
	ovoTeren(void);
	~ovoTeren(void);

	// metoda koja stvara teren
	osg::Node* stvoriTeren();
};

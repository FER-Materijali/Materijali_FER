/* ************************************************ *
 *  Zlatko Dukic, 2006.g.							*
 * Laboratorijske vjezbe iz kolegija				*
 * Osnove virtualnih okruzenja						*
 * ************************************************ */

#pragma once

#include <osg/Node>
#include <osg/MatrixTransform>

#define TENK_PATH "C:\\Program Files\\OpenSceneGraph\\data\\Models\\t72-tank\\t72-tank_des.flt"

class ovoTenk
{
public:
	ovoTenk(void);
	~ovoTenk(void);
	osg::Node* stvoriTenk();
	osg::MatrixTransform* tenkMatrixTransform();
};

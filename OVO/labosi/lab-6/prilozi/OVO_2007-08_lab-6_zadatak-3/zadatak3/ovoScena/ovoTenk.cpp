/* ************************************************ *
 *  Zlatko Dukic, 2006.g.							*
 * Laboratorijske vjezbe iz kolegija				*
 * Osnove virtualnih okruzenja						*
 * ************************************************ */

#include ".\ovotenk.h"

#include <osg/Node>
#include <osgDB/ReadFile>
//#include <osg/MatrxTransform>
#include <stdio.h>

ovoTenk::ovoTenk(void)
{
}

ovoTenk::~ovoTenk(void)
{
}

osg::Node* ovoTenk::stvoriTenk()
{
	osg::Node* root = osgDB::readNodeFile(TENK_PATH);
	printf("Ucitan tenk.\n");
	return root;
}

osg::MatrixTransform* ovoTenk::tenkMatrixTransform()
{
	osg::MatrixTransform* tMT = new osg::MatrixTransform;
	tMT->setDataVariance(osg::Object::DYNAMIC);
	// sklairanje, translacija, rotacija
	tMT->setMatrix(	osg::Matrixd::scale(3,3,3) * 
						osg::Matrixd::translate(0,10,8) *
						osg::Matrixd::rotate(90*3.141592654/180.0, 0.0, 0.0, 1.0));
	printf("Stvorena matrica za postavljanje tenka u scenu.\n");
	return tMT;
}
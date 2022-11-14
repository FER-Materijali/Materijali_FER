/* ************************************************ *
 *  Zlatko Dukic, 2006.g.							*
 * Laboratorijske vjezbe iz kolegija				*
 * Osnove virtualnih okruzenja						*
 * ************************************************ */

#include ".\ovoteren.h"
#include <osgDB/ReadFile>
#include <stdio.h>


ovoTeren::ovoTeren(void)
{
	// incijaliziramo cvor tipa Node deklariran u zaglavlju
	terenNode = NULL;
}

ovoTeren::~ovoTeren(void)
{
}

osg::Node* ovoTeren::stvoriTeren()
{
	terenNode = osgDB::readNodeFile(TEREN_PATH);
	printf("Ucitan teren u cvor.\n");
	return terenNode;
}
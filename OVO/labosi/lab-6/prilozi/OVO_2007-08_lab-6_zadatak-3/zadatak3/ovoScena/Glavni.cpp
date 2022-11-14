/* ************************************************ *
 *  Zlatko Dukic, 2006.g.							*
 * Laboratorijske vjezbe iz kolegija				*
 * Osnove virtualnih okruzenja						*
 * ************************************************ */

#include <osg/Node>
#include <osg/Geometry>
#include <osg/Notify>
#include <osg/MatrixTransform>
#include <osgProducer/Viewer>

#include "ovoDim.h"
#include "ovoLetjelice.h"
#include "ovoTenk.h"
#include "ovoTeren.h"
#include "ovoSunce.h"


int main()
{
	// ukljucimo nivo 'rjecitosti' na WARN kako ne bi ispisavo stvari koje nas ne zanimaju
	// nego samo ozbiljnija upozorenja
	osg::setNotifyLevel(osg::WARN);

    // inicijaliziramo viewer
    osgProducer::Viewer viewer;

	// stvorimo korijenski cvor kojemu cemo dodavati djecu (avion, teren, tenk...)
	osg::Group* rootCvor = new osg::Group;



	/************ Inicijalizacija klasa i cvorova ******************/ 
	
	// kod za inicijalizaciju cvorova ovdje

	/***************************************************************/



	/************ postavljanje grafa scene ************/
	
	// kod za dodavanje u scenu ovdje

    /***************************************************/




    // postavimo viewer na standardne opcije (nacin na koji ce osvjezavat prikaz)
    viewer.setUpViewer(osgProducer::Viewer::STANDARD_SETTINGS);
    
    // recimo vieweru sto da iscrta (ukljucuje cvor i svu njegovu djecu)
	// dakle, postaviti treba samo korijenski cvor grafa
    viewer.setSceneData(rootCvor);

    // stvori prozor za iscrtavanje i pokreni sve dretve potrebne za rad
    viewer.realize();

    while( !viewer.done() )
    {
        // cekaj sve dretve da obave posao
        viewer.sync();

        // prolazak kroz graf i osvjezavanje svih promijenjenih varijabli
        viewer.update();
         
        // iscrtaj scenu (najnoviju)
        viewer.frame();        
    }
    
    // prije izlaska pricekati da svi threadovi zavrse
    viewer.sync();
    
    return 0;
}

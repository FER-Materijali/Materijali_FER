/* ************************************************ *
 *  Zlatko Dukic, 2006.g.							*
 * Laboratorijske vjezbe iz kolegija				*
 * Osnove virtualnih okruzenja						*
 * ************************************************ */

#pragma once

#include <osg/Billboard>
#include <osg/Drawable>
#include <osg/Image>
#include <osg/MatrixTransform>

#define SUNCE_PATH "C:\\Program Files\\OpenSceneGraph\\data\\SolarSystem\\sun256128.jpg"

class ovoSunce
{
private:
	// parametri kojima u konstruktorima definiramo mjsto gdje ce se sunce nalaziti
	double azimut;		// od sjevera se okrecemo u desno za 'azimut' stupnjeva
	double elevacija;	// dizemo objekt prema sredistu nebeskog svoda za 'elevacija' stupnjeva
	double distanca;	// udaljenost od sredista terena za 'distanca' arbitratnih jedinica (metara)

public:
	// konstruktor koji ima cvrsto odredjene vrijednosti polozaja sunca
	ovoSunce(void);
	// kontruktor koji preko parametara prima polozaj sunca
	ovoSunce(double, double, double);
	// destruktor
	~ovoSunce(void);

	// metoda koja stvara sunce kao billboard
	osg::Billboard* stvoriSunce();
	// NEBITNO za labos - metoda koja stvara cetverokut (radi aureole)
	osg::Drawable* createSquare(const osg::Vec3& corner,const osg::Vec3& width,const osg::Vec3& height, osg::Image* image=NULL);
	// NEBITNO za labos - metoda koja stvara aureolu (racuna gradaciju boja)
	osg::Image* createBillboardImage(const osg::Vec4& centerColour, unsigned int size, float power);
	// metoda koja na temelju azimuta, elevacije i distance racuna gdje postaviti sunce u virualnom prostoru
	osg::MatrixTransform* sunceMatrixTransform();
};

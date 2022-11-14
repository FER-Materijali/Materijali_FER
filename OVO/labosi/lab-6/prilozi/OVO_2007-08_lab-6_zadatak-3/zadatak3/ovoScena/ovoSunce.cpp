/* ************************************************ *
 *  Zlatko Dukic, 2006.g.							*
 * Laboratorijske vjezbe iz kolegija				*
 * Osnove virtualnih okruzenja						*
 * ************************************************ */

#include ".\ovosunce.h"

#include <osgDB/ReadFile>
#include <osg/Node>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/Transform>
#include <osg/MatrixTransform>
#include <osg/StateSet>
#include <osg/Shape>
#include <osg/ShapeDrawable>
#include <osg/Texture2D>
#include <osg/Billboard>
#include <osg/Material>

#include <math.h>
#include <stdio.h>


/* Defaultni konstruktor postavlja sunce na fiksnu vrijednost u prostoru */
ovoSunce::ovoSunce(void)
{
	azimut    = 30;
	elevacija = 20;
	distanca  = 300;
}

/* Konstruktor pomocu kojeg pozicioniramo sunce u prostor */
ovoSunce::ovoSunce(double a, double e, double d)
{
	azimut    = a;
	elevacija = e;
	distanca  = d;
}

ovoSunce::~ovoSunce(void)
{
}

/* Pozicioniranje sunca i podešavanje velièine pomoæu skaliranja i translacije */
osg::MatrixTransform* ovoSunce::sunceMatrixTransform()
{
	osg::MatrixTransform* sunMT = new osg::MatrixTransform;
    const double pi = 3.1415926535;
	double azimuth2_rad = (90-azimut) * pi / 180.0;
	double elevation_rad = elevacija* pi / 180.0;
	double r = distanca;
	double r_elevation = cos(elevation_rad) * r;
	double translateX = r_elevation * cos(azimuth2_rad);
	double translateY = r_elevation * sin(azimuth2_rad);
	double translateZ = r * sin(elevation_rad);

	sunMT->setDataVariance(osg::Object::DYNAMIC);
	sunMT->setMatrix(	osg::Matrixd::scale(5,5,5) * 
						//osg::Matrixd::translate(bSphere.center()) * 
						osg::Matrixd::translate(translateX,translateY,translateZ) );
	printf("Stvorena matrica za postavljanje sunca u scenu.\n");
	return sunMT;
}

/* Pomocu ostalih funkcija iz ove klase stvara sunce i aureolu	*
 * Interesantan je dio zaduzen za definiranje teksture			*
 * Pogledati definiranje billboarda i njegovog skupa stanja		*
 * Zbog aureole izvedba je nesto slozenija, ali dovljna da		*
 * pokaze nacin na koji se postavlja tekstura u stateset		*/
osg::Billboard* ovoSunce::stvoriSunce()
{	
	osg::Sphere* sfera = new osg::Sphere( osg::Vec3(0,0,0), 1.0f );
	osg::ShapeDrawable* sferaSD = new osg::ShapeDrawable( sfera );
	osg::Image* sunImage = osgDB::readImageFile(SUNCE_PATH);
	
	// deklaracije potrebne za stvaranje sunca kao billboard-a
	// i 'lijepljenje' teksture na njemu
	osg::Billboard* sunBB = new osg::Billboard();
	osg::StateSet* sunBBSS = new osg::StateSet();
	osg::Texture2D* sunTexture2D = new osg::Texture2D();

	// postavi ponasanje billboarda
	sunBB->setMode(osg::Billboard::Mode::POINT_ROT_EYE );

	//sunTexture2D->setDataVariance(osg::Object::DYNAMIC);
	if( !sunTexture2D )
	{
		printf("GRESKA: Ne mogu otvoriti teksturu sunca.\n");
		exit(EXIT_FAILURE);
	}
	sunTexture2D->setImage( sunImage );
	//sunTexture2D->setWrap( osg::Texture::WRAP_S, osg::Texture::REPEAT );
	//sunTexture2D->setWrap( osg::Texture::WRAP_T, osg::Texture::REPEAT );

	// iskljucivanje osvjetljenja (ovaj model nece biti osvjetljen uopce)
	sunBBSS->setMode( GL_LIGHTING, osg::StateAttribute::OFF );
	// dodavanje teksture u stateset
	sunBBSS->setTextureAttributeAndModes(0, sunTexture2D, osg::StateAttribute::ON );
	// podesavanje materijala - nepotrebno ali ostavljeno da se stekne uvid u mogucnosti material property-a
	osg::Material* material = new osg::Material;
	material->setShininess( osg::Material::Face::FRONT_AND_BACK , 1.0f );
	material->setDataVariance( osg::Object::DYNAMIC );
	material->setSpecular( osg::Material::Face::FRONT_AND_BACK ,osg::Vec4(0.2f,0.2f,0.2f,0.2f) );
	material->setEmission( osg::Material::Face::FRONT_AND_BACK, osg::Vec4( 1.0f, 1.0f, 0.0f, 1.0f ) );
    sunBBSS->setAttributeAndModes( material, osg::StateAttribute::OFF );
	sunBBSS->setRenderingHint( osg::StateSet::TRANSPARENT_BIN );
	sunBBSS->setMode(GL_BLEND, osg::StateAttribute::ON);
	sunBBSS->setMode(GL_BLEND_DST , osg::StateAttribute::ON);
	
	// cvoru billboard tipa dodjelimo skup stanja unutar kojeg smo definirali teksturu (i materijal)
	sunBB->setStateSet( sunBBSS );
	sferaSD->setStateSet( sunBBSS );
	// konacno dodajemo kuglu koja definira samo sunce u billboard
	sunBB->addDrawable( sferaSD );
	// i jos dodajemo aureolu oko kugle
	sunBB->addDrawable(
        createSquare(	osg::Vec3(-5.0f,0.0f,-5.0f),
						osg::Vec3(10.0f,0.0f,0.0f),
						osg::Vec3(0.0f,0.0f,10.0f),
						createBillboardImage( osg::Vec4( 1.0, 1.0, 0.9f, 1.0f), 64, 1.0) ),
						osg::Vec3(0.0f,0.0f,0.0f)	
					);
	printf("Stvoreno sunce kao billboard.\n");
	return sunBB;
}

// stvara aureolu oko sunca - nije potrebno analizirati
osg::Image* ovoSunce::createBillboardImage(const osg::Vec4& centerColour, unsigned int size, float power)
{
    osg::Vec4 backgroundColour = centerColour;
    backgroundColour[3] = 0.0f;
    
    osg::Image* image = new osg::Image;
    image->allocateImage(size,size,1,GL_RGBA,GL_UNSIGNED_BYTE);
          
    float mid = (float(size)-1)*0.5f;
    float div = 2.0f/float(size);
    for(unsigned int r=0;r<size;++r)
    {
        unsigned char* ptr = image->data(0,r,0);
        for(unsigned int c=0;c<size;++c)
        {
            float dx = (float(c) - mid)*div;
            float dy = (float(r) - mid)*div;
            float r = powf(1.0f-sqrtf(dx*dx+dy*dy),power);
            if (r<0.0f) r=0.0f;
            osg::Vec4 color = centerColour*r+backgroundColour*(1.0f-r);
            // color.set(1.0f,1.0f,1.0f,0.5f);
            *ptr++ = (unsigned char)((color[0])*255.0f);
            *ptr++ = (unsigned char)((color[1])*255.0f);
            *ptr++ = (unsigned char)((color[2])*255.0f);
            *ptr++ = (unsigned char)((color[3])*255.0f);
        }
    }
    return image;
}


// stvara cetverokut - nije potrebno analizirati
osg::Drawable* ovoSunce::createSquare(const osg::Vec3& corner,const osg::Vec3& width,const osg::Vec3& height, osg::Image* image)//=NULL)
{
    // set up the Geometry.
    osg::Geometry* geom = new osg::Geometry;

    osg::Vec3Array* coords = new osg::Vec3Array(4);
    (*coords)[0] = corner;
    (*coords)[1] = corner+width;
    (*coords)[2] = corner+width+height;
    (*coords)[3] = corner+height;

    geom->setVertexArray(coords);

    osg::Vec3Array* norms = new osg::Vec3Array(1);
    (*norms)[0] = width^height;
    (*norms)[0].normalize();
    
    geom->setNormalArray(norms);
    geom->setNormalBinding(osg::Geometry::BIND_OVERALL);

    osg::Vec2Array* tcoords = new osg::Vec2Array(4);
    (*tcoords)[0].set(0.0f,0.0f);
    (*tcoords)[1].set(1.0f,0.0f);
    (*tcoords)[2].set(1.0f,1.0f);
    (*tcoords)[3].set(0.0f,1.0f);
    geom->setTexCoordArray(0,tcoords);
    
    osg::Vec4Array* colours = new osg::Vec4Array(1);
    (*colours)[0].set(1.0f,1.0f,1.0f,1.0f);
    geom->setColorArray(colours);
    geom->setColorBinding(osg::Geometry::BIND_OVERALL);

    geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS,0,4));
    
    if (image)
    {
        osg::StateSet* stateset = new osg::StateSet;
        osg::Texture2D* texture = new osg::Texture2D;
        texture->setImage(image);
        stateset->setTextureAttributeAndModes(0,texture,osg::StateAttribute::ON);
        stateset->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
        stateset->setMode(GL_BLEND, osg::StateAttribute::ON);
        stateset->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
        geom->setStateSet(stateset);
    }
	    
    return geom;
}


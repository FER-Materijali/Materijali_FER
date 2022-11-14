/* ************************************************ *
 *  Zlatko Dukic, 2006.g.							*
 * Laboratorijske vjezbe iz kolegija				*
 * Osnove virtualnih okruzenja						*
 * ************************************************ */

#include ".\ovodim.h"

ovoDim::ovoDim(void)
{
}

ovoDim::~ovoDim(void)
{
}

osg::Group* ovoDim::stvoriDim()
{
	osg::Group* root = new osg::Group;
	osgParticle::Particle ptemplate;	// obrazac za cestice, radi lakse manipulacije
    osgParticle::ParticleSystem *ps = new osgParticle::ParticleSystem;
    osgParticle::ModularEmitter *emitter = new osgParticle::ModularEmitter;
	osgParticle::RandomRateCounter *rrc = new osgParticle::RandomRateCounter;
    osg::Geode *geode = new osg::Geode;
    osgParticle::ParticleSystemUpdater *psu = new osgParticle::ParticleSystemUpdater;
	
	
	ptemplate.setLifeTime(5);	// duljina trajanja zivota cestice (sekunde)
    ptemplate.setSizeRange(osgParticle::rangef(2.75f, 6.0f));	// velicina cestice (na pocetku zivota, na kraju zivota)
    ptemplate.setAlphaRange(osgParticle::rangef(0.0f, 1.5f));	// prozirnost -- || --
    ptemplate.setColorRange(osgParticle::rangev4(		
        osg::Vec4(0.29, 0.3f, 0.25f, 1.5f),							// boja na pocetku zivota
        osg::Vec4(0.8, 0.8f, 0.8f, 0.2f)));						// boja na kraju zivota  (RGBA,vrijednosti od 0.0 do 1.0)
    ptemplate.setRadius(1.5f);									// inicijalna velicina cestica
    ptemplate.setMass(0.05f);									// masa cestica - interesantna kod simulacija vjetra i sl.

	ps->setDefaultAttributes(DIM_PATH, false, false);			// postavljanje teksture koju se smatra cesticom
    
	emitter->setParticleSystem(ps);
	emitter->setParticleTemplate(ptemplate);
	emitter->setCounter(rrc);
    
	rrc->setRateRange(20, 30);									// kolicina ispucanih cestica
    root->addChild(emitter);
    root->addChild(geode);
					geode->addDrawable(ps);
    root->addChild(psu);
					psu->addParticleSystem(ps);
	
	printf("Stvoren dim.\n");
	return root; 
}


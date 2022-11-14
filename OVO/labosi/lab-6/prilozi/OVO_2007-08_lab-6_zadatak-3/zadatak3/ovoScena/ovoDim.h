/* ************************************************ *
 *  Zlatko Dukic, 2006.g.							*
 * Laboratorijske vjezbe iz kolegija				*
 * Osnove virtualnih okruzenja						*
 * ************************************************ */

#pragma once

#include <osg/Group>
#include <osg/Geode>
#include <osgParticle/Particle>
#include <osgParticle/ParticleSystem>
#include <osgParticle/ParticleSystemUpdater>
#include <osgParticle/ModularEmitter>
#include <osgParticle/RandomRateCounter>
#include <osgParticle/SectorPlacer>
#include <osgParticle/RadialShooter>

#define DIM_PATH "C:\\Program Files\\OpenSceneGraph\\data\\Images\\smoke.rgb"

class ovoDim
{
 
public:
	ovoDim(void);
	~ovoDim(void);

	osg::Group* ovoDim::stvoriDim();
	
};

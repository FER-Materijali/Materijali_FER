/* ************************************************ *
 *  Zlatko Dukic, 2006.g.							*
 * Laboratorijske vjezbe iz kolegija				*
 * Osnove virtualnih okruzenja						*
 * ************************************************ */

#include ".\ovoletjelice.h"

#include <osg/Notify>
#include <osg/MatrixTransform>
#include <osg/PositionAttitudeTransform>
#include <osg/Geometry>
#include <osg/Geode>

#include <osgDB/Registry>
#include <osgDB/ReadFile>

#include <osgGA/TrackballManipulator>
#include <osgGA/FlightManipulator>
#include <osgGA/DriveManipulator>


ovoLetjelice::ovoLetjelice(void)
{
}

ovoLetjelice::~ovoLetjelice(void)
{
}

/* Metoda kojoj se pristupi svakih 'delta' vremena kako bi se izracunala nova pozicija objekata */
osg::AnimationPath* ovoLetjelice::createAnimationPath(const osg::Vec3& center,float radius,double looptime)
{
    // set up the animation path 
    osg::AnimationPath* animationPath = new osg::AnimationPath;
    animationPath->setLoopMode(osg::AnimationPath::LOOP);
    
    int numSamples = 40;
    float yaw = 0.0f;
    float yaw_delta = 2.0f*osg::PI/((float)numSamples-1.0f);
    float roll = osg::inDegrees(20.0f);
    
    double time=0.0f;
    double time_delta = looptime/(double)numSamples;
	double visina = 0;
    for(int i=0;i<numSamples;++i)
    {
		visina = 92 - 4*i;
		osg::Vec3 position(center+osg::Vec3(sinf(yaw)*radius,cosf(yaw)*radius,visina));
		if(i>20)
		{	
			visina = 16 + 4*(i-20);
			position = osg::Vec3(center+osg::Vec3(sinf(yaw)*radius,cosf(yaw)*radius,visina));
		}
		osg::Quat rotation(osg::Quat(roll,osg::Vec3(0.0,1.0,0.0))*osg::Quat(-(yaw+osg::inDegrees(90.0f)),osg::Vec3(0.0,0.0,1.0)));
        
        animationPath->insert(time,osg::AnimationPath::ControlPoint(position,rotation));

        yaw += yaw_delta;
        time += time_delta;

    }
    return animationPath;    
}

/* Metoda ucitava letjelice i postavlja im geometrijske parametre		*
 * Takodjer se postavlja UpdateCallback kako bi se znalo koju			*
 * funkciju pozvati kada se ukaze potreba za novim racunanjem pozicije	*/
osg::Node* ovoLetjelice::createMovingModel(const osg::Vec3& center, float radius)
{
    float animationLength = 10.0f;
    osg::AnimationPath* animationPath = createAnimationPath(center,radius,animationLength);
    osg::Group* model = new osg::Group;
    osg::Node* glider = osgDB::readNodeFile(GLIDER_PATH);
    if (glider)
    {
        const osg::BoundingSphere& bs = glider->getBound();
        float size = radius/bs.radius()*0.1f;
        osg::MatrixTransform* positioned = new osg::MatrixTransform;
        positioned->setDataVariance(osg::Object::STATIC);
        positioned->setMatrix(osg::Matrix::translate(-bs.center())*
                                     osg::Matrix::scale(size,size,size)*
                                     osg::Matrix::rotate(osg::inDegrees(-90.0f),0.0f,0.0f,1.0f));
        positioned->addChild(glider);
        osg::PositionAttitudeTransform* xform = new osg::PositionAttitudeTransform;    
		// postavlja se metoda koju je potrebno pozvati svaki put kad se zahtjeva 'update'
        xform->setUpdateCallback(new osg::AnimationPathCallback(animationPath,0.0,1.0));
        xform->addChild(positioned);
        model->addChild(xform);
    }
    osg::Node* cessna = osgDB::readNodeFile(AVION_PATH);
    if (cessna)
    {
        const osg::BoundingSphere& bs = cessna->getBound();
        float size = radius/bs.radius()*0.1f;
        osg::MatrixTransform* positioned = new osg::MatrixTransform;
        positioned->setDataVariance(osg::Object::STATIC);
        positioned->setMatrix(osg::Matrix::translate(-bs.center())*
									//osg::Matrix::translate(osg::Vec3f(0.0, 0.0, 100.0)) *
                                     osg::Matrix::scale(size,size,size)*
                                     osg::Matrix::rotate(osg::inDegrees(180.0f),0.0f,0.0f,1.0f) 
									 //* osg::Matrix::rotate(osg::inDegrees(0.0f),1.0f,0.0f,0.0f)
									 );
        positioned->addChild(cessna);
        osg::MatrixTransform* xform = new osg::MatrixTransform;
		// postavlja se metoda koju je potrebno pozvati svaki put kad se zahtjeva 'update'
        xform->setUpdateCallback(new osg::AnimationPathCallback(animationPath,0.0f,0.5));
        xform->addChild(positioned);
        model->addChild(xform);
    }
    return model;
}

osg::Node* ovoLetjelice::stvoriLetjelice()
{
    osg::Vec3 center(0.0f,0.0f,0.0f);
    float radius = 200.0f;
    osg::Group* root = new osg::Group;
    osg::Node* movingModel = createMovingModel(center,radius*0.8f);
    root->addChild(movingModel);
	printf("Letjelice stvorene.\n");
    return root;
}


#include "../include/my.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

int main()
{
  IrrlichtDevice *device = createDevice( video::EDT_SOFTWARE, dimension2d<u32>(WIDTH, LENGTH), 16, false, false, false, 0);

  // Quitte s'il y a un problème
  if (!device)
		return EXIT_FAILURE;

  // Gère le nom de la fenêtre
  device->setWindowCaption(L"Bomberman");

  // On créé des pointeurs sur nos différents éléments utiles
  IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();

  // On affiche une fenêtre de texte
  guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!", rect<s32>(10,10,260,22), true);

  // Creates the mesh
  IAnimatedMesh* mesh = smgr->getMesh("./irrlicht-1.8.4/media/sydney.md2");
	if (!mesh)
	{
		device->drop();
		return EXIT_FAILURE;
	}

  // Create animated scene node
	IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode(mesh);

  if (node)
	{
		node->setMaterialFlag(EMF_LIGHTING, false);
		node->setMD2Animation(scene::EMAT_STAND);
		node->setMaterialTexture(0, driver->getTexture("./irrlicht-1.8.4/media/sydney.bmp"));
	}

  // Creates a camera
  smgr->addCameraSceneNode(0, vector3df(0,60,0), vector3df(0,5,0));

  while(device->run())
	{
    driver->beginScene(true, true, SColor(255,100,101,140));
		smgr->drawAll();
		guienv->drawAll();
		driver->endScene();
	}
  device->drop();
  return EXIT_SUCCESS;
}

#ifndef CONSTANT_H
#define CONSTANT_H

//======================================================================//
//						RELEASE / DELETE POINTER						//
//======================================================================//
#define SAFE_RELEASE(p)		{ if (p) { (p)->Release(); (p) = NULL; } }	
#define SAFE_DELETE(p)		{ if (p) { delete(p); (p) = NULL; } }		

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


#define GRAVITY 1.0f
#define VELREDUCE_BY_WALL 0.1f
#define VELREDUCE_BY_FRICTION 0.05f


#endif
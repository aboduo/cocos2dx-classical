/****************************************************************************
 Author: Luma (stubma@gmail.com)
 
 https://github.com/stubma/cocos2dx-better
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#ifndef __CCTMXTiledMap_h__
#define __CCTMXTiledMap_h__

#include "ccTypes.h"
#include "CCTMXMapInfo.h"

using namespace std;

NS_CC_BEGIN

class CCTMXLayer;
class CCTMXObjectGroup;

/**
 * TMX tile map class. Every layer in TMX map is a CCTMXLayer class and
 * also child node of it.
 *
 * enhancement:
 * 1. supports multiple tileset
 * 2. supports object and debug render
 *
 * \note
 * This is a re-implementation for TMX map. Cocos2d-x TMX support is defective, so I write my own.
 */
class CC_DLL CCTMXTiledMap : public CCNodeRGBA {
protected:
	CCTMXTiledMap();
	
public:
	virtual ~CCTMXTiledMap();
	
	/**
	 * Static constructor
	 *
	 * @param file tmx file path
	 * @return CCTMXTiledMap instance
	 */
	static CCTMXTiledMap* create(const string& file);
	
	/// init with tmx file
	virtual bool initWithXMLFile(const string& file);
	
	/// get a tmx layer by name
	CCTMXLayer* getLayer(const string& name);
	
	/// get a tmx layer by index
	CCTMXLayer* getLayerAt(int index);
	
	/// get a object group by name
	CCTMXObjectGroup* getObjectGroup(const string& name);
	
	/// get property
	string getProperty(const string& name);
	
	/// set tile property
	string getTileProperty(int gid, const string& name);
	
    /// get tile properties
    CCDictionary* getTileProperties(int gid);
    
	/// get orientation
	cbTMXOrientation getOrientation() { return m_mapInfo->getOrientation(); }
	
	/**
	 * Convert a point from node to TMX coordinate space
	 *
	 * @param p point in node space
	 * @return point in TMX space
	 */
	CCPoint nodeToTMXSpace(CCPoint p);
	
	/**
	 * Convert a point from TMX to node coordinate space
	 *
	 * @param p point in TMX space
	 * @return point in node space
	 */
	CCPoint tmxToNodeSpace(CCPoint p);
    
    /// get map size in tiles
    CCSize getMapSize() { return CCSizeMake(m_mapWidth, m_mapHeight); }
    
    /// get tile size in pixels
    CCSize getTileSize() { return CCSizeMake(m_tileWidth, m_tileHeight); }
	
	/// map width in tiles
	CC_SYNTHESIZE(int, m_mapWidth, MapWidth);
    
    /// map height in tiles
	CC_SYNTHESIZE(int, m_mapHeight, MapHeight);
	
	/// tiles width in pixels
	CC_SYNTHESIZE(float, m_tileWidth, TileWidth);
    
    /// tile height in pixels
	CC_SYNTHESIZE(float, m_tileHeight, TileHeight);
    
    /// map info
    CC_SYNTHESIZE(CCTMXMapInfo*, m_mapInfo, MapInfo);
	
    /// true means debug draw object outline
    CC_SYNTHESIZE_BOOL_SETTER(m_debugDrawObjects, DebugDrawObjects);
};

NS_CC_END

#endif // __CCTMXTiledMap_h__

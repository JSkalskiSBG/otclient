/*
 * Copyright (c) 2010-2017 OTClient <https://github.com/edubart/otclient>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H

#include <framework/core/declarations.h>
#include <framework/graphics/declarations.h>
#include "const.h"

//@bindsingleton g_sprites
class SpriteManager
{
public:
    SpriteManager();

    void terminate();

    bool loadSpr(std::string file);
    void unload();

    void saveSpr(std::string fileName);

    uint32 getSignature() { return m_signature; }
    int getSpritesCount() { return m_spritesCount; }

    ImagePtr getSpriteImage(int id);
    bool isLoaded() { return m_loaded; }

	uint8_t getMaxElevation() { return uint8_t(m_spritesFactor * Otc::MAX_ELEVATION); }
	int getSpritesSize() { return m_spritesFactor * Otc::TILE_PIXELS; }
	int getSpritesFactor() { return m_spritesFactor; }
	void setSpritesFactor(int spritesFactor) { m_spritesFactor = spritesFactor; }

private:
    stdext::boolean<false> m_loaded;
    uint32 m_signature;
    int m_spritesCount;
    int m_spritesOffset;
    FileStreamPtr m_spritesFile;
    int m_spritesFactor;

};

extern SpriteManager g_sprites;

#endif

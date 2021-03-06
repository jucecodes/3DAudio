/*
 OpenGLWindow.h
 
 Represents a window that renders OpenGL.

 Copyright (C) 2017  Andrew Barker
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
 The author can be contacted via email at andrew.barker.12345@gmail.com.
*/

#ifndef OpenGLWindow_h
#define OpenGLWindow_h

#include "../JuceLibraryCode/JuceHeader.h"

class OpenGLWindow
{
public:
    OpenGLWindow(OpenGLContext* context) noexcept : context(context) {}
    void checkResized(int w, int h) noexcept
    {
        if (w != width || h != height) {
            resized = true;
            width  = w;
            height = h;
        }
    }
    void saveResized() noexcept
    {
        resized = false;
    }
    float getAspect() const noexcept
    {
        return ((float)height) / width;
    }
    OpenGLContext* context = nullptr;
    int width = 0, height = 0;
    float frameRate = 30; 
    bool resized = true;
};

#endif /* OpenGLWindow_h */

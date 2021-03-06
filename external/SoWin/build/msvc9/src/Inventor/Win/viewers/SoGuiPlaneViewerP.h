#ifndef SOGUIPLANEVIEWERP_H
#define SOGUIPLANEVIEWERP_H

// src\Inventor\Win\viewers\SoGuiPlaneViewerP.h.  Generated from SoGuiPlaneViewerP.h.in by configure.

/**************************************************************************\
 * Copyright (c) Kongsberg Oil & Gas Technologies AS
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 
 * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * 
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 
 * Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
\**************************************************************************/

#ifndef SOWIN_INTERNAL
#error this is a private header file
#endif /* !SOWIN_INTERNAL */

#include <Inventor/SbLinear.h>

class SoWinPlaneViewer;

// ************************************************************************

// This class contains private data and methods used within the
// SoGuiPlaneViewer class.

class SoGuiPlaneViewerP
{
public:
  ~SoGuiPlaneViewerP();

  void commonConstructor(void);

  void pan(const SbVec2f & thispos, const SbVec2f & prevpos);
  void rotateZ(const float angle) const;

  void viewPlaneX(void) const;
  void viewPlaneY(void) const;
  void viewPlaneZ(void) const;

  void setCanvasSize(const SbVec2s size);
  void setPointerLocation(const SbVec2s location);
  int getPointerXMotion(void) const;
  int getPointerYMotion(void) const;
  float getPointerOrigoAngle(void) const;
  float getPointerOrigoMotionAngle(void) const;

  void updateAnchorScenegraph(void) const;

  enum PlaneViewerMode {
    SCENEGRAPH_INTERACT_MODE,

    IDLE_MODE,

    DOLLY_MODE,
    TRANSLATE_MODE,

    ROTZ_WAIT_MODE,
    ROTZ_MODE,

    SEEK_WAIT_MODE,
    SEEK_MODE
  } mode;

  void changeMode(PlaneViewerMode newmode);
  void setCursorRepresentation(PlaneViewerMode mode);

  struct pointerdata {
    SbVec2s now;
    SbVec2s then;
  } pointer;
  SbVec2s canvas;

  SbBool ctrldown;
  SbBool shiftdown;
  SbBool button1down;
  SbBool button3down;

  SbPlane panningplane;

  class SoDrawStyle * lineds[2];

  class SoNode * superimposition;
  struct superdata {
    class SoCoordinate3 * coords;
    class SoOrthographicCamera * camera;
  } super;

protected:
  SoGuiPlaneViewerP(SoWinPlaneViewer * publ);
  SoWinPlaneViewer * pub;
};

// ************************************************************************

#endif // ! SOGUIPLANEVIEWERP_H

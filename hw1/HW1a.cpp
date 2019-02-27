// ===============================================================
// Computer Graphics Homework Solutions
// Copyright (C) 2019 by George Wolberg
//
// HW1a.cpp - HW1a class
//
// Written by: George Wolberg, 2019
// Modified by: Peter Butler, 2019
// ===============================================================

#include "HW1a.h"

// init array of 16 vertices for letter 'P'
float Vertices[] = {
	-0.5f , -0.75f,
	-0.5f , -0.5f,
	-0.5f , -0.25f,
	-0.5f ,  0.0f,
	-0.5f ,  0.25f,
	-0.5f ,  0.5f,
	-0.25f,  0.75f,
	 0.0f ,  0.75f,
	 0.25f,  0.75f,
	 0.5f ,  0.75f,
	 0.75f,  0.5f,
	 0.75f,  0.25f,
	 0.5f ,  0.0f,
	 0.25f,  0.0f,
	 0.0f ,  0.0f,
	-0.25f,  0.0f
};

static int DrawModes[] = {
	GL_POINTS,
	GL_LINES,
	GL_LINE_STRIP,
	GL_LINE_LOOP,
	GL_TRIANGLES,
	GL_TRIANGLE_STRIP,
	GL_TRIANGLE_FAN,
	GL_QUADS,
	GL_POLYGON
};

static int g_w, g_h;    // XXX code written by PB, 2019

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::HW1a:
//
// HW1a constructor.
//
HW1a::HW1a(const QGLFormat &glf, QWidget *parent)
	: HW(glf, parent)
{
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::initializeGL:
//
// Initialization routine before display loop.
// Gets called once before the first time resizeGL() or paintGL() is called.
//
void
HW1a::initializeGL()
{
    // XXX Code written by PB 2019
    // init vertex and color buffers
    initializeGLFunctions();

    // Set background color and opacity:
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // set foreground color (default opacity):
    glColor3f(1.0f, 1.0f, 1.0f);
    // XXX End PB code
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::resizeGL:
//
// Resize event handler.
// The input parameters are the window width (w) and height (h).
//
void
HW1a::resizeGL(int w, int h)
{

    // XXX Code written by PB 2019
    /* determine aspect ratio (ar), set max width (xmax) & max height (ymax) for
       viewing area: */
    int xmax, ymax;
    float ar = (float) w/h;
    if(ar > 1.0) {
        xmax = ar;
        ymax = 1.;
    } else {
        xmax = 1.;
        ymax = 1/ar;
    }

    // pass w,h to global variables g_w, g_h
    g_w = w; g_h = h;

    // Set projection matrix, load orthographic projection into matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-xmax, xmax, -ymax, ymax, -1.0, 1.0);
    // XXX End PB code
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::paintGL:
//
// Update GL scene.
//
void
HW1a::paintGL()
{
    // XXX Code written by PB 2019
    glClear(GL_COLOR_BUFFER_BIT);

    // divide w,h into 3 (for 3x3 matrix of viewports)
    int w = g_w/3;
    int h = g_h/3;

    int mode = 0;  // offset for selecting mode in DrawModesp[]

    /*  iterate across x,y coords of window, placing new viewports with a unique GL 
        drawing in each new viewport created, utilizing the same pairs of vertex
        coordinates */
    for (int y=0; y<3; y++) {
        for (int x=0; x<3; x++) {
            glViewport(x*w, y*h, w, h);
            glBegin(DrawModes[mode++]);
                for(int i=0; i<32; i+=2)
                    glVertex2f(Vertices[i], Vertices[i+1]); 
            glEnd();
            glFlush();
        }
    }
    // XXX End PB code
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::controlPanel:
//
// Create control panel groupbox.
//
QGroupBox*
HW1a::controlPanel()
{
	// init group box
	QGroupBox *groupBox = new QGroupBox("Homework 1a");
	groupBox->setStyleSheet(GroupBoxStyle);

	return(groupBox);
}

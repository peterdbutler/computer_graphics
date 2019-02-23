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
#include <stdio.h>

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

static int g_w, g_h;    // code written by PB, 2019

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
    // Code written by PB 2019
    // init vertex and color buffers
    initializeGLFunctions();

    // Set background color and opacity:
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // set foreground color (default opacity):
    glColor3f(1.0f, 1.0f, 1.0f);
    // End PB code
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
    // Code written by PB 2019
    // NOTE: don't create viewport here, do it in paintGL()
    // NOTE: use global variable to pass w,h to paintGL()
    float xmax, ymax;
    float ar = (float) w/h;
    if(ar > 1.0) {
        xmax = ar;
        ymax = 1.;
    } else {
        xmax = 1.;
        ymax = 1/ar;
    }

    g_w = w;
    g_h = h;
    // glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-xmax, xmax, -ymax, ymax, -1.0, 1.0);
    // g_w = w;
    // g_h = h;
    // End PB code
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::paintGL:
//
// Update GL scene.
//
void
HW1a::paintGL()
{
    // Code written by PB 2019
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    for (int y=0; y<3; y++) {
        for (int x=0; x<3; x++) {
            // TODO: glViewport divsion math...
            int w = g_w/3;
            int h = g_h/3;
            glViewport( x*w, y*h, (x+1)*w, (y+1)*h);

            glBegin(DrawModes[8]); // x+y]);
                int i = 0, j = 1;
                while(i < 16) {
                    //glVertex2f(Vertices[i], Vertices[j]); 
                    i += 2;
                    //j += 2;
                    // TODO: for loop this....
                    glVertex2f(Vertices[ 0], Vertices[ 1]); 
                    glVertex2f(Vertices[ 2], Vertices[ 3]); 
                    glVertex2f(Vertices[ 4], Vertices[ 5]); 
                    glVertex2f(Vertices[ 6], Vertices[ 7]); 
                    glVertex2f(Vertices[ 8], Vertices[ 9]); 
                    glVertex2f(Vertices[10], Vertices[11]); 
                    glVertex2f(Vertices[12], Vertices[13]); 
                    glVertex2f(Vertices[14], Vertices[15]); 
                    glVertex2f(Vertices[16], Vertices[17]); 
                    glVertex2f(Vertices[18], Vertices[19]); 
                    glVertex2f(Vertices[20], Vertices[21]); 
                    glVertex2f(Vertices[22], Vertices[23]); 
                    glVertex2f(Vertices[24], Vertices[25]); 
                    glVertex2f(Vertices[26], Vertices[27]); 
                    glVertex2f(Vertices[28], Vertices[29]); 
                    glVertex2f(Vertices[30], Vertices[31]); 
                }
            glEnd();
            glFlush();
            /*
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
            }; */
        }
    }
    // End PB code
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

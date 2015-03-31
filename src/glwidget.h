#ifndef GLWIDGET_H
#define GLWIDGET_H
#include "GL/glew.h"
#include <QGLWidget>
#include <QTimer>
#ifdef __APPLE__
#include <glu.h>
#else
#include <GL/glu.h>
#endif
#include "sphere.h"
#include "hairpatch.h"
#include "shaderprogram.h"

class HairObject;
class Simulation;

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget(QGLFormat format, QWidget *parent = 0);
    ~GLWidget();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

protected slots:
    /** Repaints the canvas. Called 60 times per second by m_timer. */
    void tick();

private:
    HairObject *m_hairObject;
    Simulation *m_testSimulation;

    ShaderProgram m_program;

    QTimer m_timer; /** Timer calls tick() 60 times per second. */
    float m_fps;
    int m_increment; /** Incremented on every call to paintGL. */
};

#endif // GLWIDGET_H

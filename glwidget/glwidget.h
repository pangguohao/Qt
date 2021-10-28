#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = nullptr);
    ~GLWidget();

    void initializeGL();// ��ʼ��
    void paintGL();// ������
    void setUp();
    void compileShader();
    QOpenGLShaderProgram *program;
};

#endif // GLWIDGET_H

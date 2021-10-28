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

    void initializeGL();// 初始化
    void paintGL();// 主绘制
    void setUp();
    void compileShader();
    QOpenGLShaderProgram *program;
};

#endif // GLWIDGET_H

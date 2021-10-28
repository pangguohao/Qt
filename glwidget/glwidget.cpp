#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent):QOpenGLWidget(parent)
{

}

// 初始化OpenGL
void GLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    setUp();
    compileShader();

}
// 编译shader
void GLWidget::compileShader()
{
    std::ifstream vs("E:\\Documents\\Qt\\qtWindows\\normal.vs");
    std::string vertexCode;
    std::string fragmentCode;
    if (vs.is_open())
    {
        std::string line;
        while (getline(vs, line)) {
            vertexCode.append(line);
            vertexCode.append("\n");
        }
        vs.close();
    }
    vs.open("E:\\Documents\\Qt\\qtWindows\\normal.fs");
    //qDebug()<<"8989"<<endl;
    if (vs.is_open()) {
        std::string line;
        while (getline(vs, line)) {
            fragmentCode.append(line);
            fragmentCode.append("\n");
        }
        vs.close();
    }
    qDebug() << "hhhh" << endl;
    QOpenGLShader *vshader = new QOpenGLShader(QOpenGLShader::Vertex, this);
    vshader->compileSourceCode(vertexCode.c_str());
    QOpenGLShader *fshader = new QOpenGLShader(QOpenGLShader::Fragment, this);
    fshader->compileSourceCode(fragmentCode.c_str());
    program = new QOpenGLShaderProgram;
    program->addShader(vshader);
    program->addShader(fshader);
    //program->bindAttributeLocation("vertex", PROGRAM_VERTEX_ATTRIBUTE);
    //program->bindAttributeLocation("texCoord", PROGRAM_TEXCOORD_ATTRIBUTE);
    program->link();
    program->bind();
    //program->setUniformValue("texture", 0);
}
// 传递数据到VBO
void GLWidget::setUp()
{
    int coords[3][2] = { -1, -1, 0, 1, 1, -1 };
    QVector<float> vertData;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 2; ++j)
            vertData.append(coords[i][j]);
    vbo.create();
    vbo.bind();
    vbo.allocate(vertData.constData(), vertData.count() * sizeof(float));
}

// 主绘制函数
void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    program->enableAttributeArray(PROGRAM_VERTEX_ATTRIBUTE);
    //program->enableAttributeArray(PROGRAM_TEXCOORD_ATTRIBUTE);
    program->setAttributeBuffer(PROGRAM_VERTEX_ATTRIBUTE, GL_FLOAT, 0, 2, 2 * sizeof(float));
    //program->setAttributeBuffer(PROGRAM_VERTEX_ATTRIBUTE, GL_FLOAT, 0, 3, 0 * sizeof(GLfloat));
    //program->setAttributeBuffer(PROGRAM_TEXCOORD_ATTRIBUTE, GL_FLOAT, 3 * sizeof(GLfloat), 2, 5 * sizeof(GLfloat));
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

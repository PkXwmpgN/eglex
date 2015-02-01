#include <eglex/surface.h>
#include <GLES2/gl2.h>

GLuint g_program = 0;

GLuint LoadShader(GLenum type, const char *source)
{
    GLuint shader = glCreateShader(type);
    if (!shader)
        return 0;

    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    GLint compiled;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

    if (!compiled)
    {
        glDeleteShader(shader);
        return 0;
    }
    return shader;
}

GLuint CreateProgramObject()
{
    GLuint programObject = glCreateProgram();
    if (!programObject)
        return 0;

    const char * vShader =
        "attribute vec4 vPosition;    \n"
        "void main()                  \n"
        "{                            \n"
        "   gl_Position = vPosition;  \n"
        "}                            \n";

    const char * fShader =
        "precision mediump float;					  \n"
        "void main()                                  \n"
        "{                                            \n"
        "  gl_FragColor = vec4 ( 1.0, 1.0, 0.0, 0.0 );\n"
        "}                                            \n";

 
    glAttachShader(programObject, LoadShader(GL_VERTEX_SHADER, vShader));
    glAttachShader(programObject, LoadShader(GL_FRAGMENT_SHADER, fShader));
   
    glBindAttribLocation(programObject, 0, "vPosition");
    glLinkProgram(programObject);

    GLint linked;
    glGetProgramiv(programObject, GL_LINK_STATUS, &linked);

    if (!linked)
    {
        glDeleteProgram(programObject);
        return 0;
    }
    return programObject;
}

void Init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glViewport(0, 0, 600, 800);
    g_program = CreateProgramObject();
}

void Draw(egl::surface & surface)
{
    GLfloat vertices[] = 
    { 
        0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f 
    };

    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(g_program);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vertices);
    glEnableVertexAttribArray(0);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    surface.swap_buffers();

}


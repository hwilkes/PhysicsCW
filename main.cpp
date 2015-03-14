#include <iostream>
#include "world.h"
#include <btBulletDynamicsCommon.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <cmath>

using namespace std;

char* filetobuf(char *file) {
    FILE *fptr;
    long length;
    char *buf;
    fprintf(stderr, "Loading %s\n", file);
    fptr = fopen(file, "rb");
    if (!fptr) {
            fprintf(stderr, "failed to open %s\n", file);
            return NULL;
            }
    fseek(fptr, 0, SEEK_END);
    length = ftell(fptr);
    buf = (char*)malloc(length + 1);
    fseek(fptr, 0, SEEK_SET);
    fread(buf, length, 1, fptr);
    fclose(fptr);
    buf[length] = 0;
    return buf;
    }

void check(char *where) {
    char * what;
    int err = glGetError();
    if(err == 0) {

            return;
            }
    if(err == GL_INVALID_ENUM)
        what = "GL_INVALID_ENUM";
    else if(err == GL_INVALID_VALUE)
        what = "GL_INVALID_VALUE";
    else if(err == GL_INVALID_OPERATION)
        what = "GL_INVALID_OPERATION";
    else if(err == GL_INVALID_FRAMEBUFFER_OPERATION)
        what = "GL_INVALID_FRAMEBUFFER_OPERATION";
    else if(err == GL_OUT_OF_MEMORY)
        what = "GL_OUT_OF_MEMORY";
    else
        what = "Unknown Error";
    fprintf(stderr, "Error (%d) %s  at %s\n", err, what, where);
    exit(1);
    }


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

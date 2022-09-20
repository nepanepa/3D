#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#define PI 3.14159265358979323846

#pragma comment(lib, "OpenGL32")

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;

        glClearColor(1.0, 1.0, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3ub(254, 0, 0);
        glBegin(GL_LINES);
        glVertex3f(-1.0, 0.0, 0.0);
        glVertex3f(1.0, 0.0, 0.0);
        glEnd();
        glColor3ub(31, 255, 0);
        glBegin(GL_LINES);
        glVertex3f(0.0, -1.0, 0.0);
        glVertex3f(0.0, 1.0, 0.0);
        glEnd();

        int i;

        GLfloat x = .0f; GLfloat y = .0f; GLfloat radius = 1.0f;
        int trainleAmount = 40;

        GLfloat twicePi = 2.0f * PI;

        glBegin(GL_LINE_STRIP);
        glColor3ub(43, 78, 88);
        glVertex2f(x, y);
        for (i = 0; i <= trainleAmount; i++)
        {
            glVertex2f(
                x + (radius * cos(i * twicePi / trainleAmount)),
                y + (radius * sin(i * twicePi / trainleAmount))
            );
        }
        glEnd();
        glFinish();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();

    exit(EXIT_SUCCESS);
}
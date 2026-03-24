#include <GL/glut.h>
#include <math.h>

#define NUM_CLOUDS 5

float cloudX[NUM_CLOUDS] = {-1.2f, -0.5f, 0.2f, -1.8f, -0.9f};
float cloudY[NUM_CLOUDS] = {0.65f, 0.8f, 0.6f, 0.75f, 0.7f};
float cloudSpeed[NUM_CLOUDS] = {0.0009f, 0.0012f, 0.0008f, 0.001f, 0.0007f};

// Draw circle
void drawCircle(float cx, float cy, float r) {
    int segments = 100;
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * 3.1416f * i / segments;
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

// Draw fluffy cloud (3 front, 2 back)
void drawCloud(float x, float y, float scale) {
    glColor3f(1.0, 1.0, 1.0);

    // Back layer
    drawCircle(x - 0.09f * scale, y + 0.02f * scale, 0.08f * scale);
    drawCircle(x + 0.09f * scale, y + 0.02f * scale, 0.08f * scale);

    // Front layer
    drawCircle(x - 0.12f * scale, y, 0.1f * scale);
    drawCircle(x, y + 0.03f * scale, 0.12f * scale);
    drawCircle(x + 0.12f * scale, y, 0.1f * scale);
}

// Gradient background
void drawGradientSky() {
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.6f, 0.95f); glVertex2f(-1.0f, 1.0f);  
    glColor3f(0.5f, 0.8f, 1.0f);  glVertex2f(1.0f, 1.0f);   
    glColor3f(0.9f, 0.95f, 1.0f); glVertex2f(1.0f, -1.0f);  
    glColor3f(0.7f, 0.85f, 1.0f); glVertex2f(-1.0f, -1.0f); 
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawGradientSky();

    // Draw all clouds
    for (int i = 0; i < NUM_CLOUDS; i++) {
        float scale = 0.9f + (i * 0.05f); // Slight size variation
        drawCloud(cloudX[i], cloudY[i], scale);
    }

    glutSwapBuffers();
}

void update(int value) {
    // Move each cloud
    for (int i = 0; i < NUM_CLOUDS; i++) {
        cloudX[i] += cloudSpeed[i];
        if (cloudX[i] > 1.5f) {
            cloudX[i] = -1.5f; // Reset position
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // ~60 FPS
}

void init() {
    glClearColor(1, 1, 1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Multiple Realistic Clouds");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}

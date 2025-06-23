#include <GL/glut.h>
#include <cmath>

// Movement variables
float cloudMove = 0.0f;
float carMove = 0.0f;
float planeMove = 0.0f;
float trainMove = 0.0f;

void init() {
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f); // sky blue background
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

// Draw sun
void drawSun() {
    glColor3f(1.0f, 1.0f, 0.0f);
    float cx = 0.8f, cy = 0.8f, r = 0.1f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 100; i++) {
        float angle = 2 * M_PI * i / 100;
        glVertex2f(cx + cos(angle) * r, cy + sin(angle) * r);
    }
    glEnd();
}

// Draw moving clouds
void drawClouds() {
    glColor3f(1.0f, 1.0f, 1.0f);
    float cx = -0.8f + cloudMove / 100.0f, cy = 0.7f;
    for (int i = 0; i < 3; i++) {
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx + i * 0.1f, cy);
        for (int j = 0; j <= 100; j++) {
            float angle = 2 * M_PI * j / 100;
            glVertex2f(cx + i * 0.1f + cos(angle) * 0.05f, cy + sin(angle) * 0.05f);
        }
        glEnd();
    }
}

// Draw moving airplane
void drawPlane() {
    float x = -1.2f + planeMove / 100.0f;
    glColor3f(0.9f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(x, 0.5f);
    glVertex2f(x + 0.1f, 0.52f);
    glVertex2f(x + 0.2f, 0.5f);
    glVertex2f(x + 0.1f, 0.48f);
    glEnd();
}

// Draw moving car
void drawCar() {
    float x = -1.0f + carMove / 100.0f;
    glColor3f(0.1f, 0.1f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(x, -0.8f);
    glVertex2f(x + 0.2f, -0.8f);
    glVertex2f(x + 0.2f, -0.7f);
    glVertex2f(x, -0.7f);
    glEnd();

    // Wheels
    glColor3f(0.0f, 0.0f, 0.0f);
    for (int i = 0; i < 2; i++) {
        float cx = x + 0.05f + i * 0.1f, cy = -0.8f;
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);
        for (int j = 0; j <= 100; j++) {
            float angle = 2 * M_PI * j / 100;
            glVertex2f(cx + cos(angle) * 0.02f, cy + sin(angle) * 0.02f);
        }
        glEnd();
    }
}

// Draw moving train
void drawTrain() {
    float x = -1.2f + trainMove / 100.0f;
    glColor3f(0.6f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(x, -0.6f);
    glVertex2f(x + 0.5f, -0.6f);
    glVertex2f(x + 0.5f, -0.4f);
    glVertex2f(x, -0.4f);
    glEnd();

    // Windows
    glColor3f(0.8f, 0.9f, 1.0f);
    for (int i = 0; i < 3; i++) {
        float wx = x + 0.05f + i * 0.15f;
        glBegin(GL_QUADS);
        glVertex2f(wx, -0.45f);
        glVertex2f(wx + 0.1f, -0.45f);
        glVertex2f(wx + 0.1f, -0.42f);
        glVertex2f(wx, -0.42f);
        glEnd();
    }
}

// Station clock
void drawClock() {
    glColor3f(0.9f, 0.9f, 0.9f);
    float cx = -0.6f, cy = -0.05f, r = 0.05f;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * M_PI * i / 100;
        glVertex2f(cx + cos(angle) * r, cy + sin(angle) * r);
    }
    glEnd();

    // Hands (12:15)
    glLineWidth(2.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(cx, cy);
    glVertex2f(cx, cy + 0.03f); // hour
    glVertex2f(cx, cy);
    glVertex2f(cx + 0.035f, cy); // minute
    glEnd();
}

// Platform sign
void drawPlatformBoard() {
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(-0.7f, -0.3f);
    glVertex2f(-0.4f, -0.3f);
    glVertex2f(-0.4f, -0.22f);
    glVertex2f(-0.7f, -0.22f);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f);
    glRasterPos2f(-0.68f, -0.27f);
    const unsigned char* text = (const unsigned char*)"Platform 1";
    for (int i = 0; text[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}

// Station building
void drawStation() {
    glColor3f(0.7f, 0.4f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(-0.9f, -0.3f);
    glVertex2f(-0.3f, -0.3f);
    glVertex2f(-0.3f, 0.2f);
    glVertex2f(-0.9f, 0.2f);
    glEnd();

    // Station text
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(-0.75f, 0.1f);
    const unsigned char* stationText = (const unsigned char*)"STATION";
    for (int i = 0; stationText[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, stationText[i]);

    drawClock();
    drawPlatformBoard();
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawSun();
    drawClouds();
    drawPlane();
    drawCar();
    drawTrain();
    drawStation();

    glFlush();
}

// Arrow key handler
void spe_key(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_RIGHT:
            cloudMove += 5.0f;
            carMove += 5.0f;
            planeMove += 8.0f;
            break;
        case GLUT_KEY_LEFT:
            cloudMove -= 5.0f;
            carMove -= 5.0f;
            planeMove -= 8.0f;
            break;
        case GLUT_KEY_UP:
            trainMove += 10.0f;
            break;
        case GLUT_KEY_DOWN:
            trainMove -= 10.0f;
            break;
    }
    glutPostRedisplay();
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("City Scene Simulation");
    init();
    glutDisplayFunc(display);
    glutSpecialFunc(spe_key);
    glutMainLoop();
    return 0;
}

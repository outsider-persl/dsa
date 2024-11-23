#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <unistd.h> // 替代 Sleep
using namespace std;

const int W = 55;
int ChangeCorrd(int xx, int yy) { return (W - yy) * W * 2 + (xx * 2 + (2 * (W - yy))) - 1; }

float Z_buffer[W + 3][W + 3];
char* buffer = new char[((W) * ((W + 1) * 2)) + 1];
float angle = 0.07333, angle2 = 0.03, angle3 = 0.1;

void clearScreen() {
    // ANSI 转义序列清屏
    cout << "\033[2J\033[H";
}

void setPixel(int x, int y, char ch) {
    buffer[ChangeCorrd(x, y)] = ch;
    buffer[ChangeCorrd(x, y) - 1] = ch;
}

class Vector3f {
public:
    float x = 0.0, y = 0.0, z = 0.0;
    Vector3f() {}
    Vector3f(float a, float b, float c) : x(a), y(b), z(c) {}
    Vector3f operator/(float r) const { return Vector3f(x / r, y / r, z / r); }
    Vector3f operator+(const Vector3f& v1) const { return Vector3f(x + v1.x, y + v1.y, z + v1.z); }
    Vector3f operator-(const Vector3f& v1) const { return Vector3f(x - v1.x, y - v1.y, z - v1.z); }
};
Vector3f crossProduct(const Vector3f& a, const Vector3f& b) { return Vector3f(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); }

struct Vector4f {
    float x, y, z, w = 1.0;
    Vector4f(float xx = 0.0f, float yy = 0.0f, float zz = 0.0f, float ww = 1.0f)
        : x(xx), y(yy), z(zz), w(ww) {}
};
Vector4f toVector4f(Vector3f v) { return Vector4f{v.x, v.y, v.z, 1}; }
Vector3f toVector3f(Vector4f v) { return Vector3f{v.x, v.y, v.z}; }

class Matrix4D {
public:
    Matrix4D() {}
    Matrix4D(float a11, float a12, float a13, float a14,
             float a21, float a22, float a23, float a24,
             float a31, float a32, float a33, float a34,
             float a41, float a42, float a43, float a44) {
        m[0][0] = a11; m[0][1] = a12; m[0][2] = a13; m[0][3] = a14;
        m[1][0] = a21; m[1][1] = a22; m[1][2] = a23; m[1][3] = a24;
        m[2][0] = a31; m[2][1] = a32; m[2][2] = a33; m[2][3] = a34;
        m[3][0] = a41; m[3][1] = a42; m[3][2] = a43; m[3][3] = a44;
    }
    Vector4f MVP(const Vector4f& R) const {
        Vector4f result(0.0f, 0.0f, 0.0f, 0.0f);
        result.x = m[0][0] * R.x + m[0][1] * R.y + m[0][2] * R.z + m[0][3] * R.w;
        result.y = m[1][0] * R.x + m[1][1] * R.y + m[1][2] * R.z + m[1][3] * R.w;
        result.z = m[2][0] * R.x + m[2][1] * R.y + m[2][2] * R.z + m[2][3] * R.w;
        result.w = m[3][0] * R.x + m[3][1] * R.y + m[3][2] * R.z + m[3][3] * R.w;
        return result;
    }
    float m[4][4];
};

struct Face {
    Face() {}
    Face(Vector3f a, Vector3f b, Vector3f c, Vector3f d)
        : node1(a), node2(b), node3(c), node4(d) {
        Cen = (node1 + node3) / 2;
    }
    Vector3f node1, node2, node3, node4, Cen;
};

struct Cube {
    Face face[6];
    char color[6] = {'-', '+', '=', '@', '*', '#'};
    Cube() {
        face[0] = Face(Vector3f(12, 12, 12), Vector3f(43, 12, 12), Vector3f(43, 43, 12), Vector3f(12, 43, 12));
        face[1] = Face(Vector3f(43, 12, 12), Vector3f(43, 12, 43), Vector3f(43, 43, 43), Vector3f(43, 43, 12));
        face[2] = Face(Vector3f(43, 12, 43), Vector3f(12, 12, 43), Vector3f(12, 43, 43), Vector3f(43, 43, 43));
        face[3] = Face(Vector3f(12, 12, 43), Vector3f(12, 12, 12), Vector3f(12, 43, 12), Vector3f(12, 43, 43));
        face[4] = Face(Vector3f(12, 12, 12), Vector3f(43, 12, 12), Vector3f(43, 12, 43), Vector3f(12, 12, 43));
        face[5] = Face(Vector3f(12, 43, 12), Vector3f(43, 43, 12), Vector3f(43, 43, 43), Vector3f(12, 43, 43));
    }
    bool isHitScreenPlane(Vector3f pos, Vector3f node1, Vector3f node2, Vector3f node3, Vector3f node4) {
        if (pos.x == node1.x || pos.y == node1.y) return false;
        Vector3f e1 = node2 - node1; Vector3f e2 = node3 - node2;
        Vector3f e3 = node4 - node3; Vector3f e4 = node1 - node4;
        Vector3f p1 = pos - node1; Vector3f p2 = pos - node2;
        Vector3f p3 = pos - node3; Vector3f p4 = pos - node4;
        Vector3f t1 = crossProduct(e1, p1); Vector3f t2 = crossProduct(e2, p2);
        Vector3f t3 = crossProduct(e3, p3); Vector3f t4 = crossProduct(e4, p4);
        if ((t1.z >= 0 && t2.z >= 0 && t3.z >= 0 && t4.z >= 0) || 
            (t1.z <= 0 && t2.z <= 0 && t3.z <= 0 && t4.z <= 0))
            return true;
        return false;
    }
} cube;

int main() {
    while (1) {
        memset(Z_buffer, 100, sizeof Z_buffer);
        for (int k = 0; k < ((W) * ((W + 1) * 2)) + 1; k++) buffer[k] = ' ';
        for (int y = 0; y <= W; y++) buffer[y * W * 2 + y * 2] = '\n';
        Matrix4D RotationMat1(cos(angle), sin(angle), 0, 0, 
                             -sin(angle), cos(angle), 0, 0, 
                              0, 0, 1, 0, 
                              0, 0, 0, 1);
        Matrix4D RotationMat2(cos(angle2), 0, -sin(angle2), 0, 
                               0, 1, 0, 0, 
                               sin(angle2), 0, cos(angle2), 0, 
                               0, 0, 0, 1);
        Matrix4D RotationMat3(1, 0, 0, 0, 
                               0, cos(angle3), sin(angle3), 0, 
                               0, -sin(angle3), cos(angle3), 0, 
                               0, 0, 0, 1);
        for (int i = 0; i < 6; i++) {
            Vector3f p1 = cube.face[i].node1;
            Vector3f p2 = cube.face[i].node2;
            Vector3f p3 = cube.face[i].node3;
            Vector3f p4 = cube.face[i].node4;

            Vector4f rp1 = RotationMat1.MVP(toVector4f(p1));
            rp1 = RotationMat2.MVP(rp1);
            rp1 = RotationMat3.MVP(rp1);

            Vector4f rp2 = RotationMat1.MVP(toVector4f(p2));
            rp2 = RotationMat2.MVP(rp2);
            rp2 = RotationMat3.MVP(rp2);

            Vector4f rp3 = RotationMat1.MVP(toVector4f(p3));
            rp3 = RotationMat2.MVP(rp3);
            rp3 = RotationMat3.MVP(rp3);

            Vector4f rp4 = RotationMat1.MVP(toVector4f(p4));
            rp4 = RotationMat2.MVP(rp4);
            rp4 = RotationMat3.MVP(rp4);

            p1 = toVector3f(rp1);
            p2 = toVector3f(rp2);
            p3 = toVector3f(rp3);
            p4 = toVector3f(rp4);

            for (int x = 0; x <= W; x++) {
                for (int y = 0; y <= W; y++) {
                    Vector3f pos = Vector3f(x, y, 0);
                    if (cube.isHitScreenPlane(pos, p1, p2, p3, p4)) {
                        float dist = sqrt(pow(pos.x - cube.face[i].Cen.x, 2) + 
                                          pow(pos.y - cube.face[i].Cen.y, 2) + 
                                          pow(cube.face[i].Cen.z, 2));
                        if (Z_buffer[x][y] > dist) {
                            Z_buffer[x][y] = dist;
                            setPixel(x, y, cube.color[i]);
                        }
                    }
                }
            }
        }

        // 输出结果
        clearScreen();
        for (int k = 0; k < ((W) * ((W + 1) * 2)) + 1; k++) {
            cout << buffer[k];
        }

        angle += 0.03f;
        angle2 += 0.05f;
        angle3 += 0.02f;

        // 延迟 50 毫秒
        usleep(50000);
    }

    delete[] buffer;
    return 0;
}

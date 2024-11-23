#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 定义二维向量
struct Vector2D {
    double x, y;
    Vector2D(double x_val, double y_val) : x(x_val), y(y_val) {}
};

// 定义 2x2 矩阵
struct Matrix2x2 {
    double m[2][2];
    Matrix2x2(double a, double b, double c, double d) {
        m[0][0] = a; m[0][1] = b;
        m[1][0] = c; m[1][1] = d;
    }

    // 矩阵乘以向量
    Vector2D transform(const Vector2D& v) const {
        double new_x = m[0][0] * v.x + m[0][1] * v.y;
        double new_y = m[1][0] * v.x + m[1][1] * v.y;
        return Vector2D(new_x, new_y);
    }
};

// 打印二维字符矩阵
void printGrid(const vector<vector<char>>& grid) {
    for (const auto& row : grid) {
        for (char cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
}

// 将向量绘制到字符网格中
void drawVector(vector<vector<char>>& grid, const Vector2D& vec, char marker = '*') {
    int x = round(vec.x + grid.size() / 2); // 偏移到网格中心
    int y = round(-vec.y + grid[0].size() / 2); // y 轴反向，偏移到网格中心
    if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
        grid[y][x] = marker;
    }
}

// 绘制网格的中心点
void drawOrigin(vector<vector<char>>& grid) {
    int center = grid.size() / 2;
    grid[center][center] = '+'; // 原点标记为 '+'
}

int main() {
    const int grid_size = 11; // 定义网格大小（奇数以保证中心点存在）
    vector<vector<char>> grid(grid_size, vector<char>(grid_size, '.'));

    // 绘制原点
    drawOrigin(grid);

    // 原始向量
    Vector2D vec(1.0, 1.0);

    // 将原始向量绘制到网格
    drawVector(grid, vec, 'O');
    cout << "Original Vector:" << endl;
    printGrid(grid);
    cout << endl;

    // 清空网格并绘制原点
    grid.assign(grid_size, vector<char>(grid_size, '.'));
    drawOrigin(grid);

    // 1. 缩放变换
    Matrix2x2 scaling(0.0, 2.0, 0.0, 3.0); // 缩放 x 方向 2 倍，y 方向 3 倍
    Vector2D scaled = scaling.transform(vec);
    drawVector(grid, scaled, 'S');
    cout << "After Scaling:" << endl;
    printGrid(grid);
    cout << endl;

    // 清空网格并绘制原点
    grid.assign(grid_size, vector<char>(grid_size, '.'));
    drawOrigin(grid);

    // 2. 旋转变换（逆时针 45 度）
    double theta = M_PI / 4; // 弧度
    Matrix2x2 rotation(cos(theta), -sin(theta), sin(theta), cos(theta));
    Vector2D rotated = rotation.transform(vec);
    drawVector(grid, rotated, 'R');
    cout << "After Rotation:" << endl;
    printGrid(grid);
    cout << endl;

    // 清空网格并绘制原点
    grid.assign(grid_size, vector<char>(grid_size, '.'));
    drawOrigin(grid);

    // 3. 剪切变换
    Matrix2x2 shear(1.0, 1.0, 0.0, 1.0); // 水平剪切
    Vector2D sheared = shear.transform(vec);
    drawVector(grid, sheared, 'H');
    cout << "After Shear:" << endl;
    printGrid(grid);
    cout << endl;

    return 0;
}

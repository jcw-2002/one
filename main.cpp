#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "SmartCar.h"

using namespace std;

// 将智能汽车信息保存到文件
void saveToFile(const vector<SmartCar>& cars, const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& car : cars) {
            outFile << car.id << " "
                    << car.assignedStudent.id << " "
                    << car.assignedStudent.name << endl;
        }
        outFile.close();
    } else {
        cout << "无法打开文件进行写入！" << endl;
    }
}

// 从文件加载智能汽车信息
void loadFromFile(vector<SmartCar>& cars, const string& filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string carId, studentId, studentName;
        for (auto& car : cars) {
            inFile >> carId >> studentId >> studentName;
            car.id = carId;
            Student student;
            student.id = studentId;
            student.name = studentName;
            car.assignStudent(student);
        }
        inFile.close();
    } else {
        cout << "无法打开文件进行读取！" << endl;
    }
}

// 主函数
int main() {
    vector<SmartCar> cars;
    vector<Student> students;

    // 创建 10 个具有唯一 ID 的智能汽车对象
    for (int i = 1; i <= 10; ++i) {
        string carId = "cqusn" + to_string(10000000 + i);
        SmartCar car(carId);
        cars.push_back(car);
    }

    // 输入学生数据并将其分配给汽车
    for (int i = 1; i <= 10; ++i) {
        Student student;
        student.id = "202400" + to_string(i);
        student.name = "Student" + to_string(i);
        cars[i - 1].assignStudent(student);
        students.push_back(student);
    }

    // 将汽车数据保存到文件
    string filename = "SmartCarData.txt";
    saveToFile(cars, filename);

    // 从文件加载数据
    loadFromFile(cars, filename);

    // 使用下一个和上一个控制显示汽车信息
    int index = 0;
    char command;
    while (true) {
        cars[index].displayInfo();

        cout << "输入'n'表示下一个，'p'表示上一个，或'q'退出： ";
        cin >> command;

        // 检查输入并适当地调整索引
        if (command == 'n') {
            if (index < cars.size() - 1) {  // 防止溢出
                ++index;
            } else {
                cout << "已经在最后一辆汽车了！" << endl;
            }
        } else if (command == 'p') {
            if (index > 0) {  // 防止下溢
                --index;
            } else {
                cout << "已经在第一辆汽车了！" << endl;
            }
        } else if (command == 'q') {
            break;
        } else {
            cout << "无效命令！请输入'n'、'p'或'q'。" << endl;
        }
    }

    return 0;
}
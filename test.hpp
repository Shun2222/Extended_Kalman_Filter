#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

struct log{
    double x;
    double y; //あとで追加
};

class SensorOutputTask{
private:
    const std::vector<log> m_logs; 
public:
    explicit SensorOutputTask(std::vector<log> logs);
    ~SensorOutputTask();

    void output();
    void writelog(std::ostream & os, int i);
    void writelogs(std::ostream & os);
};

void sensorOutput(std::vector<log> logs);
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream iFile("./2520.countDigits.cpp");//文件路径一定要核对
    if (iFile.is_open())
    {
        std::string str;
        while (std::getline(iFile,str))
        {
            std::cout << str << std::endl;
        }
    }
    else
    {
        std::cerr << "无法打开文件" << std::endl;
        return 1; // 如果文件打开失败，返回错误代码
    }
}
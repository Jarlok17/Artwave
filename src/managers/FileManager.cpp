#include "FileManager.hpp"

#include <iostream>
#include <fstream>

namespace art
{
    void FileManager::createARTFile(const std::string &filename)
    {
        std::ofstream file(filename, std::ios::binary);
        if (file.is_open())
        {
            file.write(reinterpret_cast<const char*>(&version), sizeof(version));
            file.write(projectName.c_str(), projectName.size());
            writeDataToFile(file);

            file.close();
            std::cout << "Файл .art успішно створено: " << filename << std::endl;
        }
        else
        {
            std::cerr << "Помилка відкриття файлу для створення!" << std::endl;
        }
    }

    void FileManager::readARTFile(const std::string &filename)
    {
        std::ifstream file(filename, std::ios::binary);
        if (file.is_open())
        {
            file.read(reinterpret_cast<char*>(&version), sizeof(version));

            char name[50];
            file.read(name, sizeof(name));

            readDataFromFile(file);

            file.close();
            std::cout << "Файл .art успішно відкрито: " << filename << std::endl;
        }
        else
        {
            std::cerr << "Помилка відкриття файлу для читання!" << std::endl;
        }
    }

    void FileManager::openARTFile(const std::string &filename)
    {
        readARTFile(filename);
    }

    void FileManager::writeDataToFile(std::ofstream &file)
    {
        for (const auto &data : projectData)
        {
            file.write(data.c_str(), data.size());
        }
    }

    void FileManager::readDataFromFile(std::ifstream &file)
    {
        char buffer[256];
        while (file.read(buffer, sizeof(buffer)))
        {
            std::string data(buffer, file.gcount());
            projectData.push_back(data);
        }
    }
}

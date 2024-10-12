#pragma once

#include <string>
#include <vector>

namespace art
{
    class FileManager
    {
        public:
            void createARTFile(const std::string &filename);
            void readARTFile(const std::string &filename);
            void openARTFile(const std::string &filename);
        private:
            void writeDataToFile(std::ofstream &file);
            void readDataFromFile(std::ifstream &file);

            std::string version = "0.1.0";
            std::string projectName = "MyProject";
            std::vector<std::string> projectData;

    };
}

/**
 * @file CommandLine.h
 * @author Michael Speckhart (msspeck394@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-01-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

//Command line argument struct that will make parsing arguments easier
//Will also have useful methods, such as a string search for certain arguments
//Key properties such as num threads, port number, etc
#pragma once

#include <vector>
#include <string>

/**
 * @brief Standard namespace for any classes or methods defined by this program to not interfere with std namespace
 * 
 */
namespace mspeck {

    struct CommandLine {
        private:
            std::vector<std::string> tokens;
        
        public:
            CommandLine(int argc, char **argv) {
                for (int i = 0; i < argc; ++i) {
                    tokens.push_back(std::string(argv[i]));
                }
            }

            static void getHelp() {
                std::cout << "Help!\n";
            }
    };

}



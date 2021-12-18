#include "gtest/gtest.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <dirent.h>
#include <cstring>

const char* PID_DIR = "/proc";
const char* CMDLINE_FILENAME = "/cmdline";
const std::string filename = "/home/eren-keskin-pc/Desktop/upwork/process_output/processes-outputs-gtest/test.txt";
static constexpr uint16_t BUF_SIZE = 1024;
std::ofstream file;

bool isNumber(const char* str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }

    return true;
}

void processCommandLineName(char* pid) {
    int i = 0;
    char line[101];
    char file_path[101] = "";
    char buffer[BUF_SIZE];

    strcat(file_path, PID_DIR);
    strcat(file_path, "/");
    strcat(file_path, pid);
    strcat(file_path, CMDLINE_FILENAME);
    FILE* filestream = fopen(file_path, "r");
    if (filestream) {
        fscanf(filestream, "%100s", line);
        for (i = strlen(line) - 1; i >= 0; i--) {
            if (line[i] == '/') {
                break;
            }
        }
        if ((strstr(line, "my_current_process")) ) {
            std::cout << "my_current_process" << std::endl;
        }
        // printf("%10s%10s%s\n", pid, "", line + i + 1);
        if(!(strstr(line, "my_current_process")) || !(strstr(line, "a1_test"))) {
            memset(buffer, 0, sizeof(buffer));
            snprintf(buffer, sizeof(buffer), "%10s%10s%s\n", pid, "", line + i + 1);
            file.open(filename, std::ofstream::out | std::ofstream::app);
            file << buffer;
            file.close();
        }

        fclose(filestream);
    }
}

void processesPids() {
    struct dirent* dir;
    DIR* d = opendir(PID_DIR);
    char buffer[BUF_SIZE];

    //printf("%10s%10s%s\n", "PID", "", "Process Name");
    snprintf(buffer, sizeof(buffer), "%10s%10s%s\n", "PID", "", "Process Name");
    file.open(filename, std::ofstream::out | std::ofstream::app);
    file << buffer;
    file.close();
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_type == DT_DIR && isNumber(dir->d_name)) {
                processCommandLineName(dir->d_name);
            }
        }
        closedir(d);
    }
}

TEST(processIdbyNames, sum_zero) {
    if (std::ifstream(filename)) {
        if (remove(filename.c_str()) != 0) {
            std::cout << "Error deleting file" << std::endl;
        } else {
            std::cout << "File successfully deleted" << std::endl;
        }
    }

    processesPids();

    std::ifstream a("/home/eren-keskin-pc/Desktop/upwork/process_output/processes-outputs-gtest/test.txt");
    // std::ifstream a("/home/eren-keskin-pc/Desktop/upwork/process_output/processes-outputs-gtest/out1.txt");
    std::ifstream b("/home/eren-keskin-pc/Desktop/upwork/A1 code/build/out31.txt");

    std::string genfile((std::istreambuf_iterator<char>(a)), std::istreambuf_iterator<char>());
    std::string genfile2((std::istreambuf_iterator<char>(b)), std::istreambuf_iterator<char>());

    ASSERT_EQ(genfile, genfile2);
}

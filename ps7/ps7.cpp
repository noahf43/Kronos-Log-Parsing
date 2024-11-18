// Copyright 2023
// By: Noah Fay

// compile with
// g++ stdin_boost.cpp -lboost_regex

// regex_match example
#include<stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <boost/regex.hpp>
#include <boost/date_time.hpp>


int main(int argc, char* argv[]) {
    boost::regex timestamp_regex("\\d{4}-\\d{2}-\\d{2} \\d{2}:\\d{2}:\\d{2}");
    boost::regex serverStart(".*server started.*");
    boost::regex success_regex(".*oejs\\.AbstractConnector:Started SelectChannelConnector@.*");
    std::string line;
    std::string timestamp_str;
    boost::posix_time::time_duration elapsedTime;
    bool server_started = false;
    bool success = false;
    bool failed = false;
    boost::posix_time::ptime startTime, endTime;
    int lineNumber = 0;
    std::ofstream output("device[1-6]_intouch.log.rpt");
    while (getline(std::cin, line)) {
        ++lineNumber;
        boost::smatch matches;
        if (boost::regex_search(line, matches, timestamp_regex)) {
            timestamp_str = matches.str();
        }
        if (regex_search(line, serverStart)) {
            if (server_started) {
                output << "failure" << std::endl;    // already started
                std::cout << "failure" << std::endl;
                failed = true;
            }
            server_started = true;     // starts new server
            startTime = boost::posix_time::time_from_string(timestamp_str);
        std::cout << "(line " << lineNumber << ")" << "Server Started " << startTime << std::endl;
        output << "(line " << lineNumber << ")" << "Server Started " << startTime << std::endl;
        }
        if (server_started && regex_search(line, success_regex)) {
            success = true;
            boost::smatch matches;
            if (boost::regex_search(line, matches, timestamp_regex)) {
                timestamp_str = matches.str();
                endTime = boost::posix_time::time_from_string(timestamp_str);
            }
        }
        if (success) {
            std::cout << "(line " << lineNumber << ")" << "Server Started " << endTime << std::endl;
            output << "(line " << lineNumber << ")" << "Server Started " << endTime << std::endl;
            elapsedTime = endTime - startTime;
            std::cout << "Elapsed time: " << elapsedTime << std::endl;   // elapsed time
            output << "Elapsed time: " << elapsedTime << std::endl;
            server_started = false;
            success = false;
        }
    }
    if (server_started) {
        std::cout << "failure" << std::endl;  // end of file
        output << "failure" << std::endl;
        failed = true;
    }
    if (failed) {
        return 1;
    }
    return 0;
}

/*
 * ILogging.h
 *
 *  Created on: 26.11.2021
 *      Author: ph
 */

#ifndef UTIL_LOGGING_ILOGGING_H_
#define UTIL_LOGGING_ILOGGING_H_

#include <omnetpp.h>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace omnetpp;

/**
 * Interface for logging.
 */
class ILogging {
public:
    std::string delimiter = ",";    //!< output delimiter
    std::string fileName;           //!< output file name
    std::ofstream file;             //!< output file
    cModule *moduleName;            //!< name of module logged from

    /**
     * Constructor.
     * @param moduleName name of module logged from
     * @param fileName file name
     */
    ILogging(cModule *moduleName, std::string fileName){
        this->fileName = fileName;
        this->moduleName = moduleName;
        // open and close file once to delete previous contents
        file.open(fileName);
        file.close();
    }
    /**
     * Log data.
     */
    void log(){
        file.open(fileName, std::ios::out |std::ios_base::app);
        file << moduleName << delimiter << simTime().dbl() << delimiter << logString() << "\n";
        file.close();
    }

    /** (*virtual method*)
     * Log string to be defined in classes implemening this interface.
     */
    virtual std::string logString() = 0;
};



#endif /* UTIL_LOGGING_ILOGGING_H_ */

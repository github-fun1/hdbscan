/**
 * logger.c
 *
 *  Created on: 13 October 2019
 *      Author: junior
 *
 * Copyright 2019 Onalenna Junior Makhura
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * \file logger.c
 * \author Onalenna Junior Makhura (ojmakhura@roguesystems.co.bw)
 *
 * \brief Logging facility implementation
 *
 * \date 2019-10-13
 *
 * \copyright Copyright (c) 2019
 *
 */

#include "hdbscan/logger.h"
#include "config.h"
#include <string.h>
#include <assert.h>
#include <time.h>

static FILE* log_file;
static char* getDateString() {
    // Initialize and get current time
    time_t t = time( NULL );

    // Allocate space for date string
    char* date = (char*)malloc( 100 );

    // Format the time correctly
    strftime(date, 100, "[%F %T]", localtime(&t));

    return date;
}

void logger_init()
{
    log_file = NULL; //! Make sure the log file pointer is null
    /*!
     * \brief Only open the file if the library was compiled for debugging
     * 
     */
#ifdef DEBUG
    if(log_file == NULL) {
    	
        log_file = fopen("hdbscan.log", "a");

        if(log_file == NULL) {
            printf("Log file not opened.");
        }
    }
#endif
}

void logger_write(enum LOGTYPE type, const char* str) {

    /** Must check the file is open if we logging to it */
#ifdef DEBUG
    assert(log_file != NULL);
#endif

    char* date = getDateString();
    const char* tp;

    if(type == FATAL) {
        tp = "FATAL";
    } else if (type == ERROR) {
        tp = "ERROR";
    } else if (type == INFO) {
        tp = "INFO";
    } else if (type == WARN)  {
        tp = "WARN";
    } else {
        tp = "";
    }
    
    /** If the LOGTYPE is none, we do not add the timestamp information to the log */
    if(type != NONE) {
        size_t sz = strlen(date) + strlen(tp) + strlen(str) + 10;
        char buffer[sz];
        sprintf(buffer, "%s %s: %s", date, tp, str);
    #ifdef DEBUG
        fprintf(log_file, "%s", buffer);
    #else
        printf("%s", buffer);
    #endif
    } else {
    #ifdef DEBUG
        fprintf(log_file, "%s", str);
    #else
        printf("%s", str);
    #endif
    }
    free(date);
}

void logger_close() {
#ifdef DEBUG
    assert(log_file != NULL);
    fclose(log_file);
#endif
}

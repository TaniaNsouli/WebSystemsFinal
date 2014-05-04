//
//  allofit.h
//  WebSystemsFinal
//
//  Created by Lyle Moffitt on 5/3/14.
//  Copyright (c) 2014 Lyle Moffitt. All rights reserved.
//

#ifndef __WebSystemsFinal__allofit__
#define __WebSystemsFinal__allofit__

#include <iostream>
#include <string> 


#include "httpServer.h"
#include "security.h"
#include "users.h"
#include "Logger.h"
#include "Scheduler.h"
#include "fileHandler.h"




class allofit
{
public:
    httpServer      _httpserver; //tcp server
    
    security        _security (*this);
    
    user_set        _user_set;
    
    logger          _logger;
    
    scheduler       _scheduler;
    
    file_handler    _file_handler (*this);
    
};

class handler
{
     allofit & _aott;
    
public:
    handler(allofit & _all):_aott(_all){}
    
    user* member;
    tcpConnection* tcp;
    // gets intro file fro file handler
    // passes file through TCP
    // gets response (usrnm and pswd)
    // checks usrnm and pswd with security
    // if correct, enter
    // otherwise, send create user form
    // auto create
    // log size of intro file and signup file 
    // sum should be updated in box in scheduler
    // create send time in box time in scheduler
    std::string send_hello();
    // while{
    //     sends form asking what joke they want
    //     get joke from file handler
    //     record
    //     ask if another
    //     get next joke
    //     wait user's interval 
    // }
    // until exit
    void getJoke(std::string usr_pswd);
    
    
};





#endif /* defined(__WebSystemsFinal__allofit__) */

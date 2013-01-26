#pragma once

#include <glog/logging.h>

#ifndef WRP_GLOG_ENABLED
  #define WRP_GLOG_ENABLED
#endif

#ifdef WRP_GLOG_ENABLED
  #define L(a,b) LOG(a) << b
#else
  #define L(a,b) 
#endif 

namespace WonderRabbitProject { namespace glog {

  enum class OUT
  { DEFAULT
  , STDERR
  };
  
  void initialize(const OUT out, const char* name)
  {
    google::InitGoogleLogging(name);
    switch(out)
    {
    case OUT::STDERR:
      google::LogToStderr();
    default:;
    }
    L(INFO, "glog initialized");
  }

} }


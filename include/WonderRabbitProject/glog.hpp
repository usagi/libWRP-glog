#pragma once

#ifndef NDEBUG
  #include <glog/logging.h>
  #ifndef WRP_GLOG_ENABLED
    #define WRP_GLOG_ENABLED
  #endif
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
  
  inline void initialize(const OUT out, const char* name)
  {
#ifdef WRP_GLOG_ENABLED
    google::InitGoogleLogging(name);
    switch(out)
    {
    case OUT::STDERR:
      google::LogToStderr();
    default:;
    }
    L(INFO, "glog initialized");
#endif
  }

} }


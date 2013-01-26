#include <WonderRabbitProject/glog.hpp>

int main(){
  using namespace WonderRabbitProject;
  glog::initialize(glog::OUT::STDERR, "00_glog-test");
  L(INFO,"TEST LOGGING " << 12345);
}


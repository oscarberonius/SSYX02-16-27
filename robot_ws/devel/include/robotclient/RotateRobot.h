// Generated by gencpp from file robotclient/RotateRobot.msg
// DO NOT EDIT!


#ifndef ROBOTCLIENT_MESSAGE_ROTATEROBOT_H
#define ROBOTCLIENT_MESSAGE_ROTATEROBOT_H

#include <ros/service_traits.h>


#include <robotclient/RotateRobotRequest.h>
#include <robotclient/RotateRobotResponse.h>


namespace robotclient
{

struct RotateRobot
{

typedef RotateRobotRequest Request;
typedef RotateRobotResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct RotateRobot
} // namespace robotclient


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::robotclient::RotateRobot > {
  static const char* value()
  {
    return "95b88eb44c4cda7e8bd208bebdd2aee8";
  }

  static const char* value(const ::robotclient::RotateRobot&) { return value(); }
};

template<>
struct DataType< ::robotclient::RotateRobot > {
  static const char* value()
  {
    return "robotclient/RotateRobot";
  }

  static const char* value(const ::robotclient::RotateRobot&) { return value(); }
};


// service_traits::MD5Sum< ::robotclient::RotateRobotRequest> should match 
// service_traits::MD5Sum< ::robotclient::RotateRobot > 
template<>
struct MD5Sum< ::robotclient::RotateRobotRequest>
{
  static const char* value()
  {
    return MD5Sum< ::robotclient::RotateRobot >::value();
  }
  static const char* value(const ::robotclient::RotateRobotRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::robotclient::RotateRobotRequest> should match 
// service_traits::DataType< ::robotclient::RotateRobot > 
template<>
struct DataType< ::robotclient::RotateRobotRequest>
{
  static const char* value()
  {
    return DataType< ::robotclient::RotateRobot >::value();
  }
  static const char* value(const ::robotclient::RotateRobotRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::robotclient::RotateRobotResponse> should match 
// service_traits::MD5Sum< ::robotclient::RotateRobot > 
template<>
struct MD5Sum< ::robotclient::RotateRobotResponse>
{
  static const char* value()
  {
    return MD5Sum< ::robotclient::RotateRobot >::value();
  }
  static const char* value(const ::robotclient::RotateRobotResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::robotclient::RotateRobotResponse> should match 
// service_traits::DataType< ::robotclient::RotateRobot > 
template<>
struct DataType< ::robotclient::RotateRobotResponse>
{
  static const char* value()
  {
    return DataType< ::robotclient::RotateRobot >::value();
  }
  static const char* value(const ::robotclient::RotateRobotResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // ROBOTCLIENT_MESSAGE_ROTATEROBOT_H
// Generated by gencpp from file robotclient/Floats.msg
// DO NOT EDIT!


#ifndef ROBOTCLIENT_MESSAGE_FLOATS_H
#define ROBOTCLIENT_MESSAGE_FLOATS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace robotclient
{
template <class ContainerAllocator>
struct Floats_
{
  typedef Floats_<ContainerAllocator> Type;

  Floats_()
    : data()  {
      data.assign(0.0);
  }
  Floats_(const ContainerAllocator& _alloc)
    : data()  {
      data.assign(0.0);
  }



   typedef boost::array<float, 2>  _data_type;
  _data_type data;




  typedef boost::shared_ptr< ::robotclient::Floats_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::robotclient::Floats_<ContainerAllocator> const> ConstPtr;

}; // struct Floats_

typedef ::robotclient::Floats_<std::allocator<void> > Floats;

typedef boost::shared_ptr< ::robotclient::Floats > FloatsPtr;
typedef boost::shared_ptr< ::robotclient::Floats const> FloatsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::robotclient::Floats_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::robotclient::Floats_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace robotclient

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'robotclient': ['/home/multipos2/SSYX02-16-27/robot_ws/src/robotclient/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::robotclient::Floats_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robotclient::Floats_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robotclient::Floats_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robotclient::Floats_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robotclient::Floats_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robotclient::Floats_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::robotclient::Floats_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3a423cd43be5532c6a3def568afe4aec";
  }

  static const char* value(const ::robotclient::Floats_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3a423cd43be5532cULL;
  static const uint64_t static_value2 = 0x6a3def568afe4aecULL;
};

template<class ContainerAllocator>
struct DataType< ::robotclient::Floats_<ContainerAllocator> >
{
  static const char* value()
  {
    return "robotclient/Floats";
  }

  static const char* value(const ::robotclient::Floats_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::robotclient::Floats_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32[2] data\n\
";
  }

  static const char* value(const ::robotclient::Floats_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::robotclient::Floats_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.data);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct Floats_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::robotclient::Floats_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::robotclient::Floats_<ContainerAllocator>& v)
  {
    s << indent << "data[]" << std::endl;
    for (size_t i = 0; i < v.data.size(); ++i)
    {
      s << indent << "  data[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.data[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBOTCLIENT_MESSAGE_FLOATS_H

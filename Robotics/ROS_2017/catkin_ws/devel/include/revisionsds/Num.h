// Generated by gencpp from file revisionsds/Num.msg
// DO NOT EDIT!


#ifndef REVISIONSDS_MESSAGE_NUM_H
#define REVISIONSDS_MESSAGE_NUM_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace revisionsds
{
template <class ContainerAllocator>
struct Num_
{
  typedef Num_<ContainerAllocator> Type;

  Num_()
    : valint(0)
    , valinttwo(0)
    , valfloat(0.0)  {
    }
  Num_(const ContainerAllocator& _alloc)
    : valint(0)
    , valinttwo(0)
    , valfloat(0.0)  {
  (void)_alloc;
    }



   typedef int64_t _valint_type;
  _valint_type valint;

   typedef int64_t _valinttwo_type;
  _valinttwo_type valinttwo;

   typedef float _valfloat_type;
  _valfloat_type valfloat;




  typedef boost::shared_ptr< ::revisionsds::Num_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::revisionsds::Num_<ContainerAllocator> const> ConstPtr;

}; // struct Num_

typedef ::revisionsds::Num_<std::allocator<void> > Num;

typedef boost::shared_ptr< ::revisionsds::Num > NumPtr;
typedef boost::shared_ptr< ::revisionsds::Num const> NumConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::revisionsds::Num_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::revisionsds::Num_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace revisionsds

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'revisionsds': ['/home/samy/catkin_ws/src/revisionsds/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::revisionsds::Num_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::revisionsds::Num_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::revisionsds::Num_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::revisionsds::Num_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::revisionsds::Num_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::revisionsds::Num_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::revisionsds::Num_<ContainerAllocator> >
{
  static const char* value()
  {
    return "573e6d965152a0f87d8b826f7a5df63c";
  }

  static const char* value(const ::revisionsds::Num_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x573e6d965152a0f8ULL;
  static const uint64_t static_value2 = 0x7d8b826f7a5df63cULL;
};

template<class ContainerAllocator>
struct DataType< ::revisionsds::Num_<ContainerAllocator> >
{
  static const char* value()
  {
    return "revisionsds/Num";
  }

  static const char* value(const ::revisionsds::Num_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::revisionsds::Num_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 valint\n\
int64 valinttwo\n\
float32 valfloat\n\
\n\
";
  }

  static const char* value(const ::revisionsds::Num_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::revisionsds::Num_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.valint);
      stream.next(m.valinttwo);
      stream.next(m.valfloat);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Num_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::revisionsds::Num_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::revisionsds::Num_<ContainerAllocator>& v)
  {
    s << indent << "valint: ";
    Printer<int64_t>::stream(s, indent + "  ", v.valint);
    s << indent << "valinttwo: ";
    Printer<int64_t>::stream(s, indent + "  ", v.valinttwo);
    s << indent << "valfloat: ";
    Printer<float>::stream(s, indent + "  ", v.valfloat);
  }
};

} // namespace message_operations
} // namespace ros

#endif // REVISIONSDS_MESSAGE_NUM_H

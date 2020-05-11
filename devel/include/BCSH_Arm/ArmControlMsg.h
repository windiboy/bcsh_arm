// Generated by gencpp from file BCSH_Arm/ArmControlMsg.msg
// DO NOT EDIT!


#ifndef BCSH_ARM_MESSAGE_ARMCONTROLMSG_H
#define BCSH_ARM_MESSAGE_ARMCONTROLMSG_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace BCSH_Arm
{
template <class ContainerAllocator>
struct ArmControlMsg_
{
  typedef ArmControlMsg_<ContainerAllocator> Type;

  ArmControlMsg_()
    : current(0.0)
    , velocity(0.0)
    , position(0.0)  {
    }
  ArmControlMsg_(const ContainerAllocator& _alloc)
    : current(0.0)
    , velocity(0.0)
    , position(0.0)  {
  (void)_alloc;
    }



   typedef float _current_type;
  _current_type current;

   typedef float _velocity_type;
  _velocity_type velocity;

   typedef float _position_type;
  _position_type position;





  typedef boost::shared_ptr< ::BCSH_Arm::ArmControlMsg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::BCSH_Arm::ArmControlMsg_<ContainerAllocator> const> ConstPtr;

}; // struct ArmControlMsg_

typedef ::BCSH_Arm::ArmControlMsg_<std::allocator<void> > ArmControlMsg;

typedef boost::shared_ptr< ::BCSH_Arm::ArmControlMsg > ArmControlMsgPtr;
typedef boost::shared_ptr< ::BCSH_Arm::ArmControlMsg const> ArmControlMsgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::BCSH_Arm::ArmControlMsg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::BCSH_Arm::ArmControlMsg_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace BCSH_Arm

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'BCSH_Arm': ['/home/yang/my_ws/src/BCSH_Arm/msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::BCSH_Arm::ArmControlMsg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::BCSH_Arm::ArmControlMsg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::BCSH_Arm::ArmControlMsg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::BCSH_Arm::ArmControlMsg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::BCSH_Arm::ArmControlMsg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::BCSH_Arm::ArmControlMsg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::BCSH_Arm::ArmControlMsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "18fa895f16fc658be1fe0c85d6e1dfb7";
  }

  static const char* value(const ::BCSH_Arm::ArmControlMsg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x18fa895f16fc658bULL;
  static const uint64_t static_value2 = 0xe1fe0c85d6e1dfb7ULL;
};

template<class ContainerAllocator>
struct DataType< ::BCSH_Arm::ArmControlMsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "BCSH_Arm/ArmControlMsg";
  }

  static const char* value(const ::BCSH_Arm::ArmControlMsg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::BCSH_Arm::ArmControlMsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 current\n"
"float32 velocity\n"
"float32 position\n"
;
  }

  static const char* value(const ::BCSH_Arm::ArmControlMsg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::BCSH_Arm::ArmControlMsg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.current);
      stream.next(m.velocity);
      stream.next(m.position);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ArmControlMsg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::BCSH_Arm::ArmControlMsg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::BCSH_Arm::ArmControlMsg_<ContainerAllocator>& v)
  {
    s << indent << "current: ";
    Printer<float>::stream(s, indent + "  ", v.current);
    s << indent << "velocity: ";
    Printer<float>::stream(s, indent + "  ", v.velocity);
    s << indent << "position: ";
    Printer<float>::stream(s, indent + "  ", v.position);
  }
};

} // namespace message_operations
} // namespace ros

#endif // BCSH_ARM_MESSAGE_ARMCONTROLMSG_H
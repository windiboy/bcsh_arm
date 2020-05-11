// Generated by gencpp from file manipulation_msgs/GraspPlanningResponse.msg
// DO NOT EDIT!


#ifndef MANIPULATION_MSGS_MESSAGE_GRASPPLANNINGRESPONSE_H
#define MANIPULATION_MSGS_MESSAGE_GRASPPLANNINGRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <manipulation_msgs/Grasp.h>
#include <manipulation_msgs/GraspPlanningErrorCode.h>

namespace manipulation_msgs
{
template <class ContainerAllocator>
struct GraspPlanningResponse_
{
  typedef GraspPlanningResponse_<ContainerAllocator> Type;

  GraspPlanningResponse_()
    : grasps()
    , error_code()  {
    }
  GraspPlanningResponse_(const ContainerAllocator& _alloc)
    : grasps(_alloc)
    , error_code(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector< ::manipulation_msgs::Grasp_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::manipulation_msgs::Grasp_<ContainerAllocator> >::other >  _grasps_type;
  _grasps_type grasps;

   typedef  ::manipulation_msgs::GraspPlanningErrorCode_<ContainerAllocator>  _error_code_type;
  _error_code_type error_code;





  typedef boost::shared_ptr< ::manipulation_msgs::GraspPlanningResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::manipulation_msgs::GraspPlanningResponse_<ContainerAllocator> const> ConstPtr;

}; // struct GraspPlanningResponse_

typedef ::manipulation_msgs::GraspPlanningResponse_<std::allocator<void> > GraspPlanningResponse;

typedef boost::shared_ptr< ::manipulation_msgs::GraspPlanningResponse > GraspPlanningResponsePtr;
typedef boost::shared_ptr< ::manipulation_msgs::GraspPlanningResponse const> GraspPlanningResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::manipulation_msgs::GraspPlanningResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::manipulation_msgs::GraspPlanningResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace manipulation_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'household_objects_database_msgs': ['/home/yang/my_ws/src/ros_exploring/household_objects_database_msgs/msg'], 'shape_msgs': ['/opt/ros/melodic/share/shape_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/melodic/share/actionlib_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/melodic/share/sensor_msgs/cmake/../msg'], 'object_recognition_msgs': ['/opt/ros/melodic/share/object_recognition_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/melodic/share/geometry_msgs/cmake/../msg'], 'manipulation_msgs': ['/home/yang/my_ws/src/ros_exploring/manipulation_msgs/msg', '/home/yang/my_ws/devel/share/manipulation_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::manipulation_msgs::GraspPlanningResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::manipulation_msgs::GraspPlanningResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::manipulation_msgs::GraspPlanningResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::manipulation_msgs::GraspPlanningResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::manipulation_msgs::GraspPlanningResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::manipulation_msgs::GraspPlanningResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::manipulation_msgs::GraspPlanningResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ff7a88c4aec40207164535a24dc9c440";
  }

  static const char* value(const ::manipulation_msgs::GraspPlanningResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xff7a88c4aec40207ULL;
  static const uint64_t static_value2 = 0x164535a24dc9c440ULL;
};

template<class ContainerAllocator>
struct DataType< ::manipulation_msgs::GraspPlanningResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "manipulation_msgs/GraspPlanningResponse";
  }

  static const char* value(const ::manipulation_msgs::GraspPlanningResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::manipulation_msgs::GraspPlanningResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
"\n"
"Grasp[] grasps\n"
"\n"
"\n"
"GraspPlanningErrorCode error_code\n"
"\n"
"\n"
"================================================================================\n"
"MSG: manipulation_msgs/Grasp\n"
"# A name for this grasp\n"
"string id\n"
"\n"
"# The internal posture of the hand for the pre-grasp\n"
"# only positions are used\n"
"sensor_msgs/JointState pre_grasp_posture\n"
"\n"
"# The internal posture of the hand for the grasp\n"
"# positions and efforts are used\n"
"sensor_msgs/JointState grasp_posture\n"
"\n"
"# The position of the end-effector for the grasp \n"
"geometry_msgs/PoseStamped grasp_pose\n"
"\n"
"# The estimated probability of success for this grasp, or some other\n"
"# measure of how \"good\" it is.\n"
"float64 grasp_quality\n"
"\n"
"# The approach motion\n"
"GripperTranslation approach\n"
"\n"
"# The retreat motion\n"
"GripperTranslation retreat\n"
"\n"
"# the maximum contact force to use while grasping (<=0 to disable)\n"
"float32 max_contact_force\n"
"\n"
"# an optional list of obstacles that we have semantic information about\n"
"# and that can be touched/pushed/moved in the course of grasping\n"
"string[] allowed_touch_objects\n"
"\n"
"================================================================================\n"
"MSG: sensor_msgs/JointState\n"
"# This is a message that holds data to describe the state of a set of torque controlled joints. \n"
"#\n"
"# The state of each joint (revolute or prismatic) is defined by:\n"
"#  * the position of the joint (rad or m),\n"
"#  * the velocity of the joint (rad/s or m/s) and \n"
"#  * the effort that is applied in the joint (Nm or N).\n"
"#\n"
"# Each joint is uniquely identified by its name\n"
"# The header specifies the time at which the joint states were recorded. All the joint states\n"
"# in one message have to be recorded at the same time.\n"
"#\n"
"# This message consists of a multiple arrays, one for each part of the joint state. \n"
"# The goal is to make each of the fields optional. When e.g. your joints have no\n"
"# effort associated with them, you can leave the effort array empty. \n"
"#\n"
"# All arrays in this message should have the same size, or be empty.\n"
"# This is the only way to uniquely associate the joint name with the correct\n"
"# states.\n"
"\n"
"\n"
"Header header\n"
"\n"
"string[] name\n"
"float64[] position\n"
"float64[] velocity\n"
"float64[] effort\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/PoseStamped\n"
"# A Pose with reference coordinate frame and timestamp\n"
"Header header\n"
"Pose pose\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Pose\n"
"# A representation of pose in free space, composed of position and orientation. \n"
"Point position\n"
"Quaternion orientation\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
"\n"
"================================================================================\n"
"MSG: manipulation_msgs/GripperTranslation\n"
"# defines a translation for the gripper, used in pickup or place tasks\n"
"# for example for lifting an object off a table or approaching the table for placing\n"
"\n"
"# the direction of the translation\n"
"geometry_msgs/Vector3Stamped direction\n"
"\n"
"# the desired translation distance\n"
"float32 desired_distance\n"
"\n"
"# the min distance that must be considered feasible before the\n"
"# grasp is even attempted\n"
"float32 min_distance\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Vector3Stamped\n"
"# This represents a Vector3 with reference coordinate frame and timestamp\n"
"Header header\n"
"Vector3 vector\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Vector3\n"
"# This represents a vector in free space. \n"
"# It is only meant to represent a direction. Therefore, it does not\n"
"# make sense to apply a translation to it (e.g., when applying a \n"
"# generic rigid transformation to a Vector3, tf2 will only apply the\n"
"# rotation). If you want your data to be translatable too, use the\n"
"# geometry_msgs/Point message instead.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"================================================================================\n"
"MSG: manipulation_msgs/GraspPlanningErrorCode\n"
"# Error codes for grasp and place planning\n"
"\n"
"# plan completed as expected\n"
"int32 SUCCESS = 0\n"
"\n"
"# tf error encountered while transforming\n"
"int32 TF_ERROR = 1 \n"
"\n"
"# some other error\n"
"int32 OTHER_ERROR = 2\n"
"\n"
"# the actual value of this error code\n"
"int32 value\n"
;
  }

  static const char* value(const ::manipulation_msgs::GraspPlanningResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::manipulation_msgs::GraspPlanningResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.grasps);
      stream.next(m.error_code);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GraspPlanningResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::manipulation_msgs::GraspPlanningResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::manipulation_msgs::GraspPlanningResponse_<ContainerAllocator>& v)
  {
    s << indent << "grasps[]" << std::endl;
    for (size_t i = 0; i < v.grasps.size(); ++i)
    {
      s << indent << "  grasps[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::manipulation_msgs::Grasp_<ContainerAllocator> >::stream(s, indent + "    ", v.grasps[i]);
    }
    s << indent << "error_code: ";
    s << std::endl;
    Printer< ::manipulation_msgs::GraspPlanningErrorCode_<ContainerAllocator> >::stream(s, indent + "  ", v.error_code);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MANIPULATION_MSGS_MESSAGE_GRASPPLANNINGRESPONSE_H

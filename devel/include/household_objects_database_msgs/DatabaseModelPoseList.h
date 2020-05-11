// Generated by gencpp from file household_objects_database_msgs/DatabaseModelPoseList.msg
// DO NOT EDIT!


#ifndef HOUSEHOLD_OBJECTS_DATABASE_MSGS_MESSAGE_DATABASEMODELPOSELIST_H
#define HOUSEHOLD_OBJECTS_DATABASE_MSGS_MESSAGE_DATABASEMODELPOSELIST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <household_objects_database_msgs/DatabaseModelPose.h>

namespace household_objects_database_msgs
{
template <class ContainerAllocator>
struct DatabaseModelPoseList_
{
  typedef DatabaseModelPoseList_<ContainerAllocator> Type;

  DatabaseModelPoseList_()
    : model_list()  {
    }
  DatabaseModelPoseList_(const ContainerAllocator& _alloc)
    : model_list(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector< ::household_objects_database_msgs::DatabaseModelPose_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::household_objects_database_msgs::DatabaseModelPose_<ContainerAllocator> >::other >  _model_list_type;
  _model_list_type model_list;





  typedef boost::shared_ptr< ::household_objects_database_msgs::DatabaseModelPoseList_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::household_objects_database_msgs::DatabaseModelPoseList_<ContainerAllocator> const> ConstPtr;

}; // struct DatabaseModelPoseList_

typedef ::household_objects_database_msgs::DatabaseModelPoseList_<std::allocator<void> > DatabaseModelPoseList;

typedef boost::shared_ptr< ::household_objects_database_msgs::DatabaseModelPoseList > DatabaseModelPoseListPtr;
typedef boost::shared_ptr< ::household_objects_database_msgs::DatabaseModelPoseList const> DatabaseModelPoseListConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::household_objects_database_msgs::DatabaseModelPoseList_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::household_objects_database_msgs::DatabaseModelPoseList_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace household_objects_database_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'household_objects_database_msgs': ['/home/yang/my_ws/src/ros_exploring/household_objects_database_msgs/msg'], 'shape_msgs': ['/opt/ros/melodic/share/shape_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/melodic/share/sensor_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/melodic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'object_recognition_msgs': ['/opt/ros/melodic/share/object_recognition_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/melodic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::household_objects_database_msgs::DatabaseModelPoseList_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::household_objects_database_msgs::DatabaseModelPoseList_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::household_objects_database_msgs::DatabaseModelPoseList_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::household_objects_database_msgs::DatabaseModelPoseList_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::household_objects_database_msgs::DatabaseModelPoseList_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::household_objects_database_msgs::DatabaseModelPoseList_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::household_objects_database_msgs::DatabaseModelPoseList_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f0bb2aa8d2ededee0ffe0f5d2107e099";
  }

  static const char* value(const ::household_objects_database_msgs::DatabaseModelPoseList_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf0bb2aa8d2ededeeULL;
  static const uint64_t static_value2 = 0x0ffe0f5d2107e099ULL;
};

template<class ContainerAllocator>
struct DataType< ::household_objects_database_msgs::DatabaseModelPoseList_<ContainerAllocator> >
{
  static const char* value()
  {
    return "household_objects_database_msgs/DatabaseModelPoseList";
  }

  static const char* value(const ::household_objects_database_msgs::DatabaseModelPoseList_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::household_objects_database_msgs::DatabaseModelPoseList_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# stores a list of possible database models recognition results\n"
"DatabaseModelPose[] model_list\n"
"================================================================================\n"
"MSG: household_objects_database_msgs/DatabaseModelPose\n"
"# Informs that a specific model from the Model Database has been \n"
"# identified at a certain location\n"
"\n"
"# the database id of the model\n"
"int32 model_id\n"
"\n"
"# if the object was recognized by the ORK pipeline, its type will be in here\n"
"# if this is not empty, then the string in here will be converted to a household_objects_database id\n"
"# leave this empty if providing an id in the model_id field\n"
"object_recognition_msgs/ObjectType type\n"
"\n"
"# the pose that it can be found in\n"
"geometry_msgs/PoseStamped pose\n"
"\n"
"# a measure of the confidence level in this detection result\n"
"float32 confidence\n"
"\n"
"# the name of the object detector that generated this detection result\n"
"string detector_name\n"
"\n"
"================================================================================\n"
"MSG: object_recognition_msgs/ObjectType\n"
"################################################## OBJECT ID #########################################################\n"
"\n"
"# Contains information about the type of a found object. Those two sets of parameters together uniquely define an\n"
"# object\n"
"\n"
"# The key of the found object: the unique identifier in the given db\n"
"string key\n"
"\n"
"# The db parameters stored as a JSON/compressed YAML string. An object id does not make sense without the corresponding\n"
"# database. E.g., in object_recognition, it can look like: \"{'type':'CouchDB', 'root':'http://localhost'}\"\n"
"# There is no conventional format for those parameters and it's nice to keep that flexibility.\n"
"# The object_recognition_core as a generic DB type that can read those fields\n"
"# Current examples:\n"
"# For CouchDB:\n"
"#   type: 'CouchDB'\n"
"#   root: 'http://localhost:5984'\n"
"#   collection: 'object_recognition'\n"
"# For SQL household database:\n"
"#   type: 'SqlHousehold'\n"
"#   host: 'wgs36'\n"
"#   port: 5432\n"
"#   user: 'willow'\n"
"#   password: 'willow'\n"
"#   name: 'household_objects'\n"
"#   module: 'tabletop'\n"
"string db\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/PoseStamped\n"
"# A Pose with reference coordinate frame and timestamp\n"
"Header header\n"
"Pose pose\n"
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
;
  }

  static const char* value(const ::household_objects_database_msgs::DatabaseModelPoseList_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::household_objects_database_msgs::DatabaseModelPoseList_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.model_list);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct DatabaseModelPoseList_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::household_objects_database_msgs::DatabaseModelPoseList_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::household_objects_database_msgs::DatabaseModelPoseList_<ContainerAllocator>& v)
  {
    s << indent << "model_list[]" << std::endl;
    for (size_t i = 0; i < v.model_list.size(); ++i)
    {
      s << indent << "  model_list[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::household_objects_database_msgs::DatabaseModelPose_<ContainerAllocator> >::stream(s, indent + "    ", v.model_list[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // HOUSEHOLD_OBJECTS_DATABASE_MSGS_MESSAGE_DATABASEMODELPOSELIST_H

// Generated by gencpp from file household_objects_database_msgs/GetModelMeshResponse.msg
// DO NOT EDIT!


#ifndef HOUSEHOLD_OBJECTS_DATABASE_MSGS_MESSAGE_GETMODELMESHRESPONSE_H
#define HOUSEHOLD_OBJECTS_DATABASE_MSGS_MESSAGE_GETMODELMESHRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <household_objects_database_msgs/DatabaseReturnCode.h>
#include <shape_msgs/Mesh.h>

namespace household_objects_database_msgs
{
template <class ContainerAllocator>
struct GetModelMeshResponse_
{
  typedef GetModelMeshResponse_<ContainerAllocator> Type;

  GetModelMeshResponse_()
    : return_code()
    , mesh()  {
    }
  GetModelMeshResponse_(const ContainerAllocator& _alloc)
    : return_code(_alloc)
    , mesh(_alloc)  {
  (void)_alloc;
    }



   typedef  ::household_objects_database_msgs::DatabaseReturnCode_<ContainerAllocator>  _return_code_type;
  _return_code_type return_code;

   typedef  ::shape_msgs::Mesh_<ContainerAllocator>  _mesh_type;
  _mesh_type mesh;





  typedef boost::shared_ptr< ::household_objects_database_msgs::GetModelMeshResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::household_objects_database_msgs::GetModelMeshResponse_<ContainerAllocator> const> ConstPtr;

}; // struct GetModelMeshResponse_

typedef ::household_objects_database_msgs::GetModelMeshResponse_<std::allocator<void> > GetModelMeshResponse;

typedef boost::shared_ptr< ::household_objects_database_msgs::GetModelMeshResponse > GetModelMeshResponsePtr;
typedef boost::shared_ptr< ::household_objects_database_msgs::GetModelMeshResponse const> GetModelMeshResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::household_objects_database_msgs::GetModelMeshResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::household_objects_database_msgs::GetModelMeshResponse_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::household_objects_database_msgs::GetModelMeshResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::household_objects_database_msgs::GetModelMeshResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::household_objects_database_msgs::GetModelMeshResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::household_objects_database_msgs::GetModelMeshResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::household_objects_database_msgs::GetModelMeshResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::household_objects_database_msgs::GetModelMeshResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::household_objects_database_msgs::GetModelMeshResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "350330c487efb062c09ffe1ab80683de";
  }

  static const char* value(const ::household_objects_database_msgs::GetModelMeshResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x350330c487efb062ULL;
  static const uint64_t static_value2 = 0xc09ffe1ab80683deULL;
};

template<class ContainerAllocator>
struct DataType< ::household_objects_database_msgs::GetModelMeshResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "household_objects_database_msgs/GetModelMeshResponse";
  }

  static const char* value(const ::household_objects_database_msgs::GetModelMeshResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::household_objects_database_msgs::GetModelMeshResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
"\n"
"DatabaseReturnCode return_code\n"
"\n"
"\n"
"shape_msgs/Mesh mesh\n"
"\n"
"\n"
"================================================================================\n"
"MSG: household_objects_database_msgs/DatabaseReturnCode\n"
"# return codes for database-related services\n"
"\n"
"int32 UNKNOWN_ERROR = 1\n"
"int32 DATABASE_NOT_CONNECTED = 2\n"
"int32 DATABASE_QUERY_ERROR = 3\n"
"int32 SUCCESS = -1\n"
"\n"
"int32 code\n"
"================================================================================\n"
"MSG: shape_msgs/Mesh\n"
"# Definition of a mesh\n"
"\n"
"# list of triangles; the index values refer to positions in vertices[]\n"
"MeshTriangle[] triangles\n"
"\n"
"# the actual vertices that make up the mesh\n"
"geometry_msgs/Point[] vertices\n"
"\n"
"================================================================================\n"
"MSG: shape_msgs/MeshTriangle\n"
"# Definition of a triangle's vertices\n"
"uint32[3] vertex_indices\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
;
  }

  static const char* value(const ::household_objects_database_msgs::GetModelMeshResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::household_objects_database_msgs::GetModelMeshResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.return_code);
      stream.next(m.mesh);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetModelMeshResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::household_objects_database_msgs::GetModelMeshResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::household_objects_database_msgs::GetModelMeshResponse_<ContainerAllocator>& v)
  {
    s << indent << "return_code: ";
    s << std::endl;
    Printer< ::household_objects_database_msgs::DatabaseReturnCode_<ContainerAllocator> >::stream(s, indent + "  ", v.return_code);
    s << indent << "mesh: ";
    s << std::endl;
    Printer< ::shape_msgs::Mesh_<ContainerAllocator> >::stream(s, indent + "  ", v.mesh);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HOUSEHOLD_OBJECTS_DATABASE_MSGS_MESSAGE_GETMODELMESHRESPONSE_H

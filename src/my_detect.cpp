#include <ros/ros.h>
#include <vision_msgs/Detection2DArray.h>
#include <fstream>
#include <string>
#include <vector>

std::string label_file_path;
std::vector<std::string> labels;

void detectionCallback(const vision_msgs::Detection2DArray::ConstPtr &msg)
{
    for (const auto &detection : msg->detections)
    {
        // Get the class and position of the detection
        if(detection.results[0].id==0)
        {
            std::string class_name = labels[detection.results[0].id];

            double x = detection.bbox.center.x;
            double y = detection.bbox.center.y;

            // Print the class and position
            ROS_INFO_STREAM("Detected a " << class_name << " at (" << x << ", " << y << ")");
        }
    }
}

int main(int argc, char **argv)
{
    // Initialize the ROS node
    ros::init(argc, argv, "my_detect");
    ros::NodeHandle nh("~");

    if (!nh.getParam("classes_path", label_file_path))
    {
        ROS_ERROR("Failed to get classes_path parameter");
        return 0;
    }

    std::ifstream file(label_file_path);
    std::string line;
    
    while (std::getline(file, line))
    {
        labels.push_back(line);
    }

    // Subscribe to the /yolov7/yolov7 topic
    ros::Subscriber sub = nh.subscribe("/yolov7/yolov7", 10, detectionCallback);

    // Spin the node
    ros::spin();

    return 0;
}
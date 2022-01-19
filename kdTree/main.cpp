#include <iostream>
#include <string>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl-1.12/pcl/kdtree/kdtree_flann.h>

int main() {
	std::string filename;
	std::cout<<"Enter the name of the pcd file (*.pcd)"<<std::endl;
	std::cin>>filename;

	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
	if(pcl::io::loadPCDFile(filename, *cloud) == -1) {
		std::cout<<"Cannot open the file. Please try again"<<std::endl;
		return -1;
	}

	pcl::KdTreeFLANN<pcl::PointXYZ> tree;
	tree.setInputCloud(cloud);

	pcl::PointXYZ p(12, 13, 15);
	std::vector <int> indices;
	std::vector <float> squaredDist;

	if(tree.nearestKSearch(p, 100, indices, squaredDist) > 0) {
		std::cout<<"nearby 100 points found"<<std::endl;
	}

	if(tree.radiusSearch(p, 25.00, indices, squaredDist) > 0) {
		std::cout<<"Nearby "<<indices.size()<<" points found within 25.00 radius"<<std::endl;
	}

	return 0;
}
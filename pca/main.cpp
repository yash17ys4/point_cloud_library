#include <iostream>
#include <string>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/common/pca.h>

int main() {
	std::string filename;
	std::cout<<"Enter the name of the pcd file (*.pcd)"<<std::endl;
	std::cin>>filename;

	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
	if(pcl::io::loadPCDFile(filename, *cloud) == -1) {
		std::cout<<"Cannot open the file. Please try again"<<std::endl;
		return -1;
	}

	pcl::PCA<pcl::PointXYZ> pca;
	pca.setInputCloud(cloud);
	// pca.initCompute();
	auto eigenValues = pca.getEigenValues();
	auto eigenVectors = pca.getEigenVectors();

	std::cout<<eigenValues<<std::endl;
	std::cout<<eigenVectors<<std::endl;

	return 0;
}
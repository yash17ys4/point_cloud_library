#include <iostream>
#include <fstream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

int
main ()
{
	std::string filename;
	std::cout<<"Enter the txt filename ( without .txt extension)"<<std::endl;
	std::cin>>filename;

	std::fstream fs;
	fs.open(filename + ".txt", std::ios::in);
	if(!fs) {
		std::cout<<"File cannot be openend"<<std::endl;
		return -1;
	}

	pcl::PointCloud<pcl::PointXYZ> cloud;
	double a, b, c;
	do {
		fs>>a>>b>>c;
		cloud.push_back(pcl::PointXYZ(a, b, c));
	} while(!fs.eof());

	pcl::io::savePCDFileASCII (filename + ".pcd", cloud);
	std::cerr << "Saved " << cloud.size () << " data points to "<< filename <<".pcd"<< std::endl;

	// for (const auto& point: cloud)
	// 	std::cerr << "    " << point.x << " " << point.y << " " << point.z << std::endl;

	return (0);
}
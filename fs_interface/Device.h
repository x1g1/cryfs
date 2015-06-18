#pragma once
#ifndef FSPP_DEVICE_H_
#define FSPP_DEVICE_H_

#include <boost/filesystem.hpp>
#include <messmer/cpp-utils/unique_ref.h>
#include <sys/statvfs.h>

namespace fspp {
class Node;

class Device {
public:
	virtual ~Device() {}

	virtual void statfs(const boost::filesystem::path &path, struct ::statvfs *fsstat) = 0;
	virtual boost::optional<cpputils::unique_ref<Node>> Load(const boost::filesystem::path &path) = 0;
};

}

#endif
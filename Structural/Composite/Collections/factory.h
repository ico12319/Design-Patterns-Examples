#pragma once
#include "normal_collection.h"
#include "sorted_collection.h"
#include "collection_union.h"
#include "collection_intersection.h"


std::pair<collection*,collection*> create(const std::string& file_name1,const std::string& file_name2);


collection* run(const std::string& file_name1,const std::string& file_name2);


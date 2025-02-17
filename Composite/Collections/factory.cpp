#include "factory.h"

static std::string read_collection_type(){
    std::string collection_type;
    std::cin >> collection_type;
    return collection_type;
}

static std::vector<int> read_from_file(const std::string& file_name){
    std::ifstream file(file_name);
    int dummy;
    std::vector<int> res;
    while(file >> dummy){
        if(file.eof())
            break;
        res.push_back(dummy);
    }
    return res;
}

std::pair<collection*,collection*> create(const std::string& file_name1,const std::string& file_name2){
    std::vector<int> container1 = read_from_file(file_name1);
    std::vector<int> container2 = read_from_file(file_name2);
    collection* left;
    collection* right;
    
    if(std::is_sorted(container1.begin(), container1.end()) && std::is_sorted(container2.begin(), container2.end())){
        left = new sorted_collection(container1);
        right = new sorted_collection(container2);
    }
    else if(std::is_sorted(container1.begin(), container1.end())){
        left = new sorted_collection(container1);
        right = new normal_collection(container2);
    }
    else if(std::is_sorted(container2.begin(),container2.end())){
        left = new normal_collection(container1);
        right = new sorted_collection(container2);
    }
    else{
        left = new normal_collection(container1);
        right = new normal_collection(container2);
    }
    
    return std::make_pair(left, right);
}

collection* run(const std::string& file_name1,const std::string& file_name2){
    collection_operation* to_return;
    auto left_right = create(file_name1, file_name2);
    auto collection_type = read_collection_type();
    if(collection_type == "Union")
        to_return = new collection_union(left_right.first,left_right.second);
    else if(collection_type == "Intersection")
        to_return = new collection_intersection(left_right.first,left_right.second);
    else
        throw std::invalid_argument("Invalid collection type!");
    return to_return;
}


#include "controler/mapper.hpp"

#include <iostream>

int main(int argc, char * const argv[])
{
    Mapper mapper{Mapper::APC40_mappings()};

    auto [midi, trace] = mycelium::map_event<
        std::string, 
        std::unordered_multimap<std::string, const binding_t*>,
        mycelium::optopoulpe_map_traits>("blur_enable t", mapper.command_to_midi_map);

    std::cout << trace << std::endl;

    return 0;
}
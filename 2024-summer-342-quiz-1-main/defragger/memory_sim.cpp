#include "memory_sim.hpp"

void MemorySim::defrag() {
    std::cout << "Defragging '" << std::string(memory_blocks) << "'" << std::endl;

    /*
     * TODO: Add the code to defragment the memory.
     *  See the unit test "fancy_test" for example of how defragment works.
     */
}

void MemorySim::setContent(const std::string &content) {
    size_t length = content.length();
    if (length == 0) {
        printf("no data to set");
        return;
    }
    int num_of_char_to_copy = std::fmin(capacity, content.length());    // TODO: Why the fmin function?
    for (int i = 0; i < num_of_char_to_copy; ++i) {
        memory_blocks[i] = (content[i] == ' ') ? '.' : content[i];
        if (memory_blocks[i] != '.') {
            number_of_used_byte++;
        }
    }
    if (content.length() > capacity) {
        printf("WARNING: content was clipped due to memory size limitation");
    }
}

std::string MemorySim::getContent() {
    char *ret = new char[number_of_used_byte];
    for (int i = 0; i < number_of_used_byte; ++i) {
        ret[i] = memory_blocks[i];
    }
    return std::string(ret);
}
